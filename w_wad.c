// Emacs style mode select   -*- C -*- 
//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 1993-1996 by id Software, Inc.
//
// This source is available for distribution and/or modification
// only under the terms of the DOOM Source Code License as
// published by id Software. All rights reserved.
//
// The source is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// FITNESS FOR A PARTICULAR PURPOSE. See the DOOM Source Code License
// for more details.
//
// $Log:$
//
// DESCRIPTION:
//	Handles WAD file header, directory, lump I/O.
//
//-----------------------------------------------------------------------------


static const char
rcsid[] = "$Id: w_wad.c,v 1.5 1997/02/03 16:47:57 b1 Exp $";

#ifdef NORMALUNIX
#include <ctype.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <malloc.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <alloca.h>
#else
#include <stdio.h>
#include <stdlib.h>
#ifdef _MSC_VER
#include <io.h>
#else
#include <unistd.h>
#endif
#include <inttypes.h>
#include <malloc.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#endif
#include <ctype.h>

#include "doomtype.h"
#include "m_swap.h"
#include "i_system.h"
#include "z_zone.h"

#ifndef O_BINARY
#define O_BINARY		0
#endif

#ifdef __GNUG__
#pragma implementation "w_wad.h"
#endif
#include "w_wad.h"

#include "doomlib.h"
#ifndef __PS2__
#ifdef IMPL
static long filelength_(int handle)
{
    long sz;
    LSeek(handle, 0L, SEEK_END);
    sz = Tell(handle);
    LSeek(handle, 0L, SEEK_SET);
    return sz;
}
#else
#define filelength_ _filelength 
#endif
#endif
//
// GLOBALS
//

// Location of each lump on disk.
lumpinfo_t*		lumpinfo;		
int			numlumps;

void**			lumpcache;

#if defined(_WIN32) && defined(__PS2__)
static void strupr(char* s)
{
    while (*s) { *s = toupper(*s); s++; }
}
#endif

void
ExtractFileBase
( char*		path,
  char*		dest )
{
    char*	src;
    int		length;

    src = path + strlen(path) - 1;
    
    // back up until a \ or the start
    while (src != path
	   && *(src-1) != '\\'
	   && *(src-1) != '/')
    {
	    src--;
    }
    
    // copy up to eight characters
    memset (dest,0,8);
    length = 0;
    
    while (*src && *src != '.')
    {
	if (++length == 9)
	    I_Error ("Filename base of %s >8 chars",path);

	*dest++ = toupper((int)*src++);
    }
}

//
// LUMP BASED ROUTINES.
//

//
// W_AddFile
// All files are optional, but at least one file must be
//  found (PWAD, if all required lumps are present).
// Files with a .wad extension are wadlink files
//  with multiple lumps.
// Other files are single lumps with the base filename
//  for the lump name.
//
// If filename starts with a tilde, the file is handled
//  specially to allow map reloads.
// But: the reload feature is a fragile hack...

int	    reloadlump;
char*	reloadname;

void W_AddFile (char *filename)
{
    wadinfo_t		header;
    lumpinfo_t*     lump_p;
    unsigned		i;
    int			    handle;
    int			    length;
    int			    startlump;
    filelump_t*     fileinfo;
    filelump_t		singleinfo;
    int			    storehandle;
    
    // open the file and add to directory

    // handle reload indicator.
    if (filename[0] == '~')
    {
        filename++;
        reloadname = filename;
        reloadlump = numlumps;
    }
		
    if ( (handle = Open (filename,O_RDONLY | O_BINARY)) == -1)
       {
	        printf(" couldn't open %s\n",filename);
	        return;
       }

    printf(" adding %s\n", filename);
    startlump = numlumps;
	
    if (strcasecmp(filename + strlen(filename) -3 ,"wad"))
    {
	    // single lump file
#ifdef __PS2__
        struct stat st;

	    // single lump file
        if (fstat(handle, &st))
        {
            /* Detects if the file is not accessible or does not exist. */
        }
#endif
	    fileinfo = &singleinfo;
	    singleinfo.filepos = 0;
#ifdef __PS2__
	    singleinfo.size = DLONG(st.st_size);
#else
	    singleinfo.size = DLONG(filelength_(handle));
#endif
	    ExtractFileBase (filename, singleinfo.name);
	    numlumps++;
    }
    else 
    {
	    // WAD file
	    Read (handle, &header, sizeof(header));
	    if (strncmp(header.identification,"IWAD",4))
	    {
	        // Homebrew levels?
	        if (strncmp(header.identification,"PWAD",4))
	        {
		        I_Error ("Wad file %s doesn't have IWAD "
			         "or PWAD id\n", filename);
	        }
	    
	    // ???modifiedgame = true;		
	    }
	    header.numlumps = DLONG(header.numlumps);
	    header.infotableofs = DLONG(header.infotableofs);
	    length = header.numlumps*sizeof(filelump_t);
	    fileinfo = alloca (length);
	    LSeek (handle, header.infotableofs, SEEK_SET);
	    Read (handle, fileinfo, length);
	    numlumps += header.numlumps;
    }
    
    // Fill in lumpinfo
    lumpinfo = realloc(lumpinfo, numlumps * sizeof(lumpinfo_t));

    if (!lumpinfo)
	    I_Error ("Couldn't realloc lumpinfo");

    lump_p = &lumpinfo[startlump];
	
    storehandle = reloadname ? -1 : handle;
	
    for (i = (unsigned int)startlump ; i < (unsigned int)numlumps ; i++, lump_p++, fileinfo++)
    {
	    lump_p->handle = storehandle;
	    lump_p->position = DLONG(fileinfo->filepos);
	    lump_p->size = DLONG(fileinfo->size);
	    strncpy(lump_p->name, fileinfo->name, 8);
    }
    if (reloadname)
	    Close (handle);
}

//
// W_Reload
// Flushes any of the reloadable lumps in memory
//  and reloads the directory.
//
void W_Reload(void)
{
    wadinfo_t		header;
    int			    lumpcount;
    lumpinfo_t*     lump_p;
    unsigned		i;
    int			    handle;
    int			    length;
    filelump_t*     fileinfo;
	
    if (!reloadname)
	    return;
		
    if ((handle = Open(reloadname,O_RDONLY | O_BINARY)) == -1)
	    I_Error ("W_Reload: couldn't open %s",reloadname);

    Read(handle, &header, sizeof(header));
    lumpcount = DLONG(header.numlumps);
    header.infotableofs = DLONG(header.infotableofs);
    length = lumpcount*sizeof(filelump_t);
    fileinfo = alloca(length);
    LSeek(handle, header.infotableofs, SEEK_SET);
    Read(handle, fileinfo, length);
    
    // Fill in lumpinfo
    lump_p = &lumpinfo[reloadlump];
	
    for (i=(unsigned int)reloadlump ;
	    i<(unsigned int)reloadlump+lumpcount ;
	    i++,lump_p++, fileinfo++)
    {
	if (lumpcache[i])
	    Z_Free (lumpcache[i]);

	    lump_p->position = DLONG(fileinfo->filepos);
	    lump_p->size = DLONG(fileinfo->size);
    }
    Close (handle);
}

//
// W_InitMultipleFiles
// Pass a null terminated list of files to use.
// All files are optional, but at least one file
//  must be found.
// Files with a .wad extension are idlink files
//  with multiple lumps.
// Other files are single lumps with the base filename
//  for the lump name.
// Lump names can appear multiple times.
// The name searcher looks backwards, so a later file
//  does override all earlier ones.
//
void W_InitMultipleFiles(char** filenames)
{	
    int	size;
    
    // open all the files, load headers, and count lumps
    numlumps = 0;

    // will be realloced as lumps are added
    lumpinfo = malloc(1);	

    for ( ; *filenames ; filenames++)
	    W_AddFile(*filenames);

    if (!numlumps)
	    I_Error("W_InitFiles: no files found");
    
    // set up caching
    size = numlumps * sizeof(*lumpcache);
    lumpcache = malloc(size);
    
    if (!lumpcache)
	    I_Error("Couldn't allocate lumpcache");

    memset(lumpcache,0, size);
}

//
// W_InitFile
// Just initialize from a single file.
//
void W_InitFile(char* filename)
{
    char* names[2];

    names[0] = filename;
    names[1] = NULL;
    W_InitMultipleFiles(names);
}

//
// W_NumLumps
//
int W_NumLumps(void)
{
    return numlumps;
}

//
// W_CheckNumForName
// Returns -1 if name not found.
//
int W_CheckNumForName(char* name)
{
    union {
        char	s[9];
        int	    x[2];

    } name8;

    int		    v1;
    int		    v2;
    lumpinfo_t* lump_p;

    // make the name into two integers for easy compares
    strncpy(name8.s,name,8);

    // in case the name was a full 8 chars
    name8.s[8] = 0;

    // case insensitive
    D_strupper(name8.s);		

    v1 = name8.x[0];
    v2 = name8.x[1];

    // scan backwards so patch lump files take precedence
    lump_p = lumpinfo + numlumps;

    while (lump_p-- != lumpinfo)
    {
        if (*(int*)lump_p->name == v1
            && *(int*)&lump_p->name[4] == v2)
        {
            return lump_p - lumpinfo;
        }
    }

    // TFB. Not found.
    return -1;
}

//
// W_GetNumForName
// Calls W_CheckNumForName, but bombs out if not found.
//
int W_GetNumForName(char* name)
{
    int	i;

    i = W_CheckNumForName(name);

    if (i == -1)
        I_Error("W_GetNumForName: %s not found!", name);

    return i;
}

//
// W_LumpLength
// Returns the buffer size needed to load the given lump.
//
int W_LumpLength(int lump)
{
    if (lump >= numlumps)
        I_Error("W_LumpLength: %i >= numlumps", lump);

    return lumpinfo[lump].size;
}

//
// W_ReadLump
// Loads the lump into the given buffer,
//  which must be >= W_LumpLength().
//
void
W_ReadLump
( int		lump,
  void*		dest )
{
    int		    c;
    lumpinfo_t* l;
    int		    handle;
	
    if (lump >= numlumps)
	    I_Error ("W_ReadLump: %i >= numlumps",lump);

    l = lumpinfo+lump;
	
    // ??? I_BeginRead ();
	
    if (l->handle == -1)
    {
	// reloadable file, so use open / read / close
	if ( (handle = Open (reloadname,O_RDONLY | O_BINARY)) == -1)
	    I_Error ("W_ReadLump: couldn't open %s",reloadname);
    }
    else
	handle = l->handle;
		
    LSeek (handle, l->position, SEEK_SET);
    c = Read (handle, dest, l->size);

    if (c < l->size)
	    I_Error ("W_ReadLump: only read %i of %i on lump %i",
		 c,l->size,lump);	

    if (l->handle == -1)
	Close (handle);
		
    // ??? I_EndRead ();
}

//
// W_CacheLumpNum
//
void*
W_CacheLumpNum
(int		lump,
 int		tag)
{
    byte* ptr;

    if ((unsigned)lump >= (unsigned)numlumps)
        I_Error("W_CacheLumpNum: %i >= numlumps", lump);

    if (!lumpcache[lump])
    {
        // read the lump in

        //printf ("cache miss on lump %i\n",lump);
        ptr = Z_Malloc(W_LumpLength(lump), tag, &lumpcache[lump]);
        W_ReadLump(lump, lumpcache[lump]);
    }
    else
    {
        //printf ("cache hit on lump %i\n",lump);
        Z_ChangeTag(lumpcache[lump], tag);
    }

    return lumpcache[lump];
}

//
// W_CacheLumpName
//
void*
W_CacheLumpName
(char* name,
 int   tag)
{
    return W_CacheLumpNum(W_GetNumForName(name), tag);
}

//
// W_Profile
//
int		info[2500][10];
int		profilecount;

void W_Profile (void)
{
    int		    i;
    memblock_t* block;
    void*       ptr;
    char	    ch;
    FILE*       f;
    int		    j;
    char	    name[9];
	
    for (i = 0; i < numlumps; i++)
    {
        ptr = lumpcache[i];
        if (!ptr)
        {
            ch = ' ';
            continue;
        }
        else
        {
            block = (memblock_t*)((byte*)ptr - sizeof(memblock_t));
            if (block->tag < PU_PURGELEVEL)
                ch = 'S';
            else
                ch = 'P';
        }
        info[i][profilecount] = ch;
    }
    profilecount++;
	
    f = fopen("waddump.txt", "w");
    name[8] = 0;

    for (i = 0; i < numlumps; i++)
    {
        memcpy(name, lumpinfo[i].name, 8);

        for (j = 0; j < 8; j++)
            if (!name[j])
                break;

        for (; j < 8; j++)
            name[j] = ' ';

        fprintf(f, "%s ", name);

        for (j = 0; j < profilecount; j++)
            fprintf(f, "    %c", info[i][j]);

        fprintf(f, "\n");
    }
    fclose(f);
}
