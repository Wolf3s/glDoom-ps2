// win_kbrd.c
//
// This module handles the DirectInput startup code and initializes
// the keyboard interface as well as handling the keyboard input
// and shutting down the keyboard interface and DirectInput.

#include <stdio.h>
#ifdef __PS2__
#include <SDL.h>
#else
#include "thirdparty/SDL2/include/SDL.h"
#endif
#include "doomtype.h"
#include "d_main.h"
#include "d_event.h"
#include "sys_sdl.h"

extern dboolean keystates[256];
unsigned char        KeyState[256]; // current keys states
short                si_Kbd[256];   // previous keys states

extern int           keylink;

void lfprintf(char *message, ... );

void I_ReleaseKeyboard()
   {
   }

void I_SetupKeyboard()
{
    int k;
    // Set the keyboard buffer to "all keys up"
    for (k = 0; k < 256; k++)
        si_Kbd[k] = SDL_KEYUP;
}

void I_CheckKeyboard()
{
    static  event_t  event[256];
    int i;
    for (i = 1; i < 256; i++)
    {
        // key released
        if (!keystates[i] && (si_Kbd[i] == SDL_KEYDOWN))
        {
            event[i].type = ev_keyup;
            event[i].data1 = i;
            D_PostEvent(&event[i]);
            si_Kbd[i] = SDL_KEYUP;
        }

        // key pressed
        if (keystates[i] && (si_Kbd[i] == SDL_KEYUP))
        {
            event[i].type = ev_keydown;
            event[i].data1 = i;
            D_PostEvent(&event[i]);
            si_Kbd[i] = SDL_KEYDOWN;
        }
    }
}
