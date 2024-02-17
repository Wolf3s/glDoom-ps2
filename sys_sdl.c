/////////////////////////////////////////////////////////////////////////////////////
// Windows and Linux Includes...
/////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#ifdef _MSC_VER
#include <direct.h>
#endif

#include <math.h>
#include <time.h>
#ifdef __PS2__
#include <GL/gl.h>
#else
#include <glad/glad.h>
#endif
#include <SDL.h>
#ifdef __PS2__
#include <debug.h>
#include <libmc.h>
#include <sbv_patches.h>
#include <sifrpc.h>
#include <loadfile.h>
#include <kernel.h>
#define NEWLIB_PORT_AWARE
#include <fileXio.h>
#include <fileio.h>
#endif

/////////////////////////////////////////////////////////////////////////////////////
// Application Includes...
/////////////////////////////////////////////////////////////////////////////////////
#include "sys_sdl.h"

/////////////////////////////////////////////////////////////////////////////////////
// "GLDoom" Includes...
/////////////////////////////////////////////////////////////////////////////////////
#include "doomdef.h"
#include "doomstat.h"
#include "d_event.h"
#include "d_main.h"
#include "g_game.h"
#include "m_argv.h"
#include "i_system.h"
#include "st_lib.h"
#include "v_video.h"
#include "z_zone.h"
#include "gldefs.h"
#include "r_main.h"

#include "gl_video.h"
#include "mathlib.h"
#include "sdl_input.h"
#include "sdl_video.h"

/////////////////////////////////////////////////////////////////////////////////////
// OpenGL Defines and Data
/////////////////////////////////////////////////////////////////////////////////////

// Functions
void   I_ShutdownGraphics( void );

// Data

FILE       *dbg_file;

int             SkyWide, SkyHigh, GLSkyTex;

extern int       iCurrMode;

/////////////////////////////////////////////////////////////////////////////////////
// Application Defines and Data
/////////////////////////////////////////////////////////////////////////////////////

SDL_Window* pWindow;

extern devinfo_t DevInfo;

#define MUSIC_NONE      0
#define MUSIC_CDAUDIO   1
#define MUSIC_MIDI      2

#define RENDER_GL       0
#define RENDER_D3D      1

#define KS_KEYUP        0
#define KS_KEYDOWN    255

/////////////////////////////////////////////////////////////////////////////////////
// Game states -- these are the modes in which the outer game loop can be
/////////////////////////////////////////////////////////////////////////////////////
#define GAME_START  0
#define GAME_SPLASH 1
#define GAME_MENU   2
#define GAME_PLAY   3
#define GAME_EXIT   4
#define GAME_QUIT   5
#define GAME_LIMBO  6
#define GAME_PAUSE  7

int     GameMode = GAME_START;

extern  int  version;
extern  char revision;

extern byte *screens[5];
extern GameMode_t gamemode;

char         szMsgText[2048];
char         *window_title[50];

extern devinfo_t DevInfo;

extern       video_t     video;

char        szMidiFile[] = "DOOMSONG.MID";

int         MusicType = MUSIC_MIDI;
int         RenderType = RENDER_GL;
dboolean        bQuit = false;

void  Cleanup(void);
void  InitData();
void  ParseCommand(int,char**);
void  EvaluateParameters(char**);
dboolean  CreateMainWindow( int, int, int, dboolean);

void ClearLog(char *szFileName);
void lfprintf(char *message, ... );

int   glDoomAC;
char *glDoomAV[256];

void  D_DoomMain(void);
void  MY_DoomSetup(void);
void  MY_DoomLoop(void);
void  glDoomExit(void);

unsigned char szBadWadMessage[] = { "glDoom Re is unable to determine the game type\n"
                                    "of the game WAD file. Please make sure that:\n"
                                    "1. You have your game wad in the current directory,\n"
                                    "2. You have it named one of the standard wad names OR\n"
                                    "   you have used the -game parameter to specify it,\n"
                                    "3. That you have not moved the game without changing\n"
                                    "   its location in the gldoom.ini file in your windows\n"
                                    "   system directory." };

dboolean  notop = false;
dboolean wasWiped = false;

/////////////////////////////////////////////////////////////////////////////////////
// Windows Defines and Data
/////////////////////////////////////////////////////////////////////////////////////

extern int    keylink;

char      szDbgName[] = "glDoom.dbg";

#ifdef __PS2__
///
/// PS2 SPECIFIC CODE.
///

#define IMPORT_BIN2C(_T) \
    extern unsigned char _T[]; \
    extern unsigned int size_##_T

IMPORT_BIN2C(iomanX_irx);
IMPORT_BIN2C(fileXio_irx);
IMPORT_BIN2C(sio2man_irx);
IMPORT_BIN2C(mcman_irx);
IMPORT_BIN2C(mcserv_irx);
IMPORT_BIN2C(padman_irx);
IMPORT_BIN2C(libsd_irx);
IMPORT_BIN2C(usbd_irx);
//IMPORT_BIN2C(usb_mass_irx);
IMPORT_BIN2C(bdm_irx);
IMPORT_BIN2C(bdmfs_fatfs_irx);
IMPORT_BIN2C(usbmass_bd_irx);

#define LOAD_IRX(_irx, argc, arglist) \
    ID = SifExecModuleBuffer(&_irx, size_##_irx, argc, arglist, &RET); \
    scr_printf("%s: id:%d, ret:%d\n", #_irx, ID, RET); \
    sleep(8000);
#define LOAD_IRX_NARG(_irx) LOAD_IRX(_irx, 0, NULL)

static void reset_IOP() {
	SifInitRpc(0);
	#if !defined(DEBUG) || defined(BUILD_FOR_PCSX2)
	/* Comment this line if you don't wanna debug the output */
	while(!SifIopReset("", 0)){};
	#endif
	while(!SifIopSync()){};
	SifInitRpc(0);
	sbv_patch_enable_lmb();
	sbv_patch_disable_prefix_check();
}

static void initMC(void)
{
   int ret;
   // mc variables
   int mc_Type, mc_Free, mc_Format;

   
   printf("initMC: Initializing Memory Card\n");

   ret = mcInit(MC_TYPE_XMC);
   
   if( ret < 0 ) {
	printf("initMC: failed to initialize memcard server.\n");
   } else {
       printf("initMC: memcard server started successfully.\n");
   }
   
   // Since this is the first call, -1 should be returned.
   // makes me sure that next ones will work !
   mcGetInfo(0, 0, &mc_Type, &mc_Free, &mc_Format); 
   mcSync(MC_WAIT, NULL, &ret);
}

static void waitUntilUsbDeviceIsReady() {
  struct stat buffer;
  int ret = -1;
  int retries = 50;

  while (ret != 0 && retries > 0) {
    ret = stat("mass:/", &buffer);
    /* Wait until the device is ready */
    nopdelay();

    retries--;
  }
}

#endif

int main(int argc, char** szCmdLine)
   {
#ifdef __PS2__
   int ID, RET;
#endif      
    ClearLog(szDbgName);
#ifdef __PS2__
    reset_IOP();
    init_scr();
#endif
    // parse up the command line...
    ParseCommand(argc, szCmdLine);
#ifdef __PS2__
    LOAD_IRX_NARG(iomanX_irx);
    LOAD_IRX_NARG(fileXio_irx);
    fileXioInit();
    LOAD_IRX_NARG(sio2man_irx);
    LOAD_IRX_NARG(mcman_irx);
    LOAD_IRX_NARG(mcserv_irx);
    initMC();
    LOAD_IRX_NARG(padman_irx);
    LOAD_IRX_NARG(libsd_irx);
    LOAD_IRX_NARG(usbd_irx);
    //Here would add DS4/DS3 support.
    LOAD_IRX_NARG(bdm_irx);
    LOAD_IRX_NARG(bdmfs_fatfs_irx);
    LOAD_IRX_NARG(usbmass_bd_irx);
    waitUntilUsbDeviceIsReady();
#endif
    FindResponseFile();

    InitData();

    // look at the command line parameters
    EvaluateParameters(szCmdLine);
  
    // Create the main program window, start up OpenGL and create our viewport
    if (!CreateMainWindow(video.width, video.height, video.bpp, video.fullscreen))
        I_Error("int main(): Unable to create main SDL2 window!");

    GetVideoInfo();
    GetModeList(szDbgName);

    /*lfprintf("Current resolution: %d x %d x %d bpp\n", DevInfo.width, DevInfo.height, DevInfo.bpp);
    lfprintf("Resolution requested: %d x %d x %d bpp\n", video.width, video.height, video.bpp);*/

    if (video.fullscreen == false)
       {
        printf("Display: %dx%d\n", video.width, video.height);
       }
    else
       {
        printf("Display: %dx%dx%d bpp\n", video.width, video.height, video.bpp);
       }

    bQuit = false;

    printf("Beginning DOOM code startup...\n");
    D_DoomMain();
    if ((gamemode == netabort) || (gamemode == undetermined))
       {
        I_Quit();
        I_ShutdownGraphics();
        if (gamemode == undetermined)
           {
            printf(szBadWadMessage);
           }
        return 0;
       }

    printf("Command line: %s\n", szCmdLine);
    printf("Beginning DOOM data setup...\n");
    MY_DoomSetup();

    GameMode = GAME_START;

    printf("Starting game loop...\n");
    while (!bQuit)
	   {

        // check for user input
        I_GetEvent();

        if (GameMode == GAME_PLAY)
           MY_DoomLoop();
        else
        if (GameMode == GAME_QUIT)
           I_Quit();
        else
        if (GameMode == GAME_START)
           GameMode = GAME_PLAY;
       }
    Cleanup();

    return 0;
   }

dboolean ResizeMainWindow(char *mode)
   {
    // Unused for now, need to fix some fov clipping..
#if 0
    char *parm;
    int   width, height;
    int   t_width, t_height;
    int   x, y, sx, sy, ex, ey;

    if ((parm = strtok(mode, " ")) != NULL)
       {
        width = atoi(parm);
        if ((parm = strtok(NULL, " ")) != NULL)
           {
            height = atoi(parm);
            t_width = video.width;
            t_height = video.height;
            video.width = width;
            video.height = height;

            if (video.fullscreen == true)
               {
                // can't do this right without shutting down OpenGL
                // and restarting it.  But don't want to reload ALL
                // the game graphics used so far.  Later on maybe...
                return false;

                if (SetVideoMode() == false)
                   {
                    video.width = t_width;
                    video.height = t_height;
                   }
                else
                   {
                    x = y = 0;
                    sx = video.width;
                    sy = video.height;
                    SDL_SetWindowSize(pWindow, sx, sy);
                    SDL_SetWindowPosition(pWindow, x, y);
                    //R_InitViewData();
                    return true;
                   }
//                would need to release rendering context here
//                and create new one then reload all GL graphics... ugh...
               }
            else
               {
                
                // Center the window on the screen
                x = SDL_WINDOWPOS_CENTERED;
                y = SDL_WINDOWPOS_CENTERED;
                sx = video.width;
                sy = video.height;
                /*
                  Check to be sure the requested window size fits on the screen and
                  adjust each dimension to fit if the requested size does not fit.
                */
                if ((sx <= DevInfo.width) && (sy <= DevInfo.height))
                   {
                    SDL_SetWindowSize(pWindow, sx, sy);
                    SDL_SetWindowPosition(pWindow, x, y);
                    //R_InitViewData();
                    return true;
                   }
                else
                   {
                    video.width = t_width;
                    video.height = t_height;
                   }
               }
            R_InitViewData();
           }
       }
    return false;
#else
    return false;
#endif
   }


// Make sure the cursor is visible and release
// the memory used for the parameter list
void Cleanup()
   {
    int  i;
//    char DoomDir[_MAX_PATH];
//    char tstr[16];

    SDL_ShowCursor(SDL_ENABLE);

    for (i = 4; i >= 0; i--)
        free(screens[i]);
    M_FreeParms();
   }

dboolean CreateMainWindow(int width, int height, int bpp, dboolean fullscreen)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        I_Error("Failed to init SDL");
 
#ifdef _DEBUG
    sprintf(window_title, "GLDOOM-RE %d.%d%c - Compiled on %s at %s", version/100, version%100, revision, __DATE__, __TIME__);
#else
    sprintf((char* const)window_title, "GLDOOM-RE");
#endif

    pWindow = SDL_CreateWindow((const char*)window_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height, SDL_WINDOW_OPENGL | (fullscreen ? true : false) | SDL_WINDOW_INPUT_GRABBED | SDL_WINDOW_ALLOW_HIGHDPI);
  
    SDL_SetRelativeMouseMode(SDL_TRUE);
    SDL_SetHintWithPriority(SDL_HINT_MOUSE_RELATIVE_MODE_WARP, "1", SDL_HINT_OVERRIDE);

    if (!pWindow)
    {
        I_Error("Failed to create a SDL window!");
    }

    SDL_ShowWindow(pWindow);

    R_InitViewData();

    printf("glDoom Re Version %d.%d%c\n", version/100, version%100, revision);
    printf("Starting OpenGL...\n");
    SDL_ShowCursor(SDL_DISABLE);

    if (StartUpOpenGL() == false)
    {        
        return false;
    }

    return true;
}


void InitData()
   {
    // Set the "Doom" screen variables to default
    SCREENWIDTH = 320;
    SCREENHEIGHT = 200;

    video.nearclip = 1.5f;
    video.farclip = 5000.0f;

    // Set user "definable" data
    video.allowsoft     = false;
    video.width         = DEF_WIDTH;
    video.height        = DEF_HEIGHT;
    video.bpp           = DEF_COLORB;
    video.fullscreen = false;
	video.wide = true;
    video.bpp  = DEF_COLORB;
    video.fov  = 90;
    video.fovy = ml_MakeFovY(video.fov, (float)video.width / (float)video.height);
}


// could just do myargc = __argc and myargv = __argv
void ParseCommand(int argc, char** szCmdLine)
   {
    int i = 1;
    char cwd[_MAX_PATH];

    if (Getcwd(cwd, _MAX_PATH))
    {
        M_InitParms();

        M_AddParm(cwd);
    }
    while (i <= argc)
       {
        M_AddParm(*szCmdLine++);
        i++;
       }
   }

void EvaluateParameters(char** szCmdLine)
   {
    int  p;

    if (myargc < 2)
       {
        return;
       }

    p = M_CheckParm("-notop");
    if (p != 0)
       {
        notop = true;
       }

    p = M_CheckParm("-window");
    if (p != 0)
       {
        video.fullscreen = false;
       }

    p = M_CheckParm("-fullscreen");
    if (p)
    {
        video.fullscreen = true;
    }

    p = M_CheckParm("-width");
    if (p && p < myargc-1)
       {
        video.width = atoi(myargv[p+1]);
       }

    p = M_CheckParm("-height");
    if (p && p < myargc-1)
       {
        video.height = atoi(myargv[p+1]);
       }

    p = M_CheckParm("-bpp");
    if (p && p < myargc-1)
       {
        video.bpp = atoi(myargv[p+1]);
        if (video.bpp != 15 && video.bpp != 16 && video.bpp != 24 && video.bpp != 32)
           {
            video.bpp = 16;
           }
       }

    p = M_CheckParm("-allowsoft");
    if (p != 0)
       {
        video.allowsoft = true;
       }

    p = M_CheckParm("-wide");
    if (p != 0)
       {
        video.wide = true;
       }

	// 04/03/2010 - BAL Need to be able to support wide monitors
	if (true != video.wide)
	{
	    if ((int)(video.width * 3) != (int)(video.height * 4))
		{
			printf("Invalid aspect ratio requested...resetting to %dx%d.\n", DEF_WIDTH, DEF_HEIGHT);
			video.width = DEF_WIDTH;
			video.height = DEF_HEIGHT;
		}
	}

    // Now unused, will re-implement this later
#if 0
    p = M_CheckParm("-fov");
    if (p && p < myargc-1)
    {
        video.fov = atof(myargv[p+1]);
        if (video.fov < FOV_MIN || video.fov > FOV_MAX)
            video.fov = FOV_DEF;

    }
#endif

    video.fovy = ml_MakeFovY(video.fov, (float)video.width / (float)video.height);
}

void glDoomExit()
   {
    GameMode = GAME_LIMBO;
    if (demorecording)
       {
        if (demotype == DEMO_I)
           G_EndDemo();
        else
           G_EndDemo_II();
       }

    I_ShutdownGraphics();
    SDL_DestroyWindow(pWindow);
   };

extern dboolean paused;

void ClearLog(char *szFileName)
   {
    FILE       *fn;

    fn = fopen(szFileName, "w");
    fclose(fn);
   }

void lfprintf(char *message, ... )
   {
    va_list	argptr;
    FILE *log_file;

    log_file = fopen(szDbgName, "a+");
    va_start (argptr,message);
    vfprintf (log_file,message,argptr);
    va_end (argptr);
    fclose(log_file);
   }

void _dprintf(char *message, ... )
   {
    va_list	argptr;

    va_start (argptr,message);
    vfprintf (dbg_file,message,argptr);
    va_end (argptr);
   }
