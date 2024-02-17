/*
** File: gl_ps2functions.h
** Project: glDoom Re
** Author: André Guilherme
** Creation Date: 08/30/2023
** Description:
** Adds some unused ps2gl implementations and add unsupported OpenGL 1.2 functions 
** License: Public domain/ID License 
*/

#include "gl_ps2functions.h"
#include <ps2s/debug_macros.h>

#define mNotImplemented(_msg, _args...) mWarn("(in %s) not implemented" _msg, __FUNCTION__, ##_args)

//#define GL_FUNC_DEBUG printf
#define GL_FUNC_DEBUG(msg, ...)

void glFogi(GLenum pname,
            GLint param)
{
    GL_FUNC_DEBUG("%s\n", __FUNCTION__);

    mNotImplemented();
}

void glReadBuffer(GLenum mode)
{
    GL_FUNC_DEBUG("%s\n", __FUNCTION__);

    mNotImplemented();
}

void glPolygonOffset(GLfloat factor, GLfloat units)
{
    GL_FUNC_DEBUG("%s\n", __FUNCTION__);

    mNotImplemented();
}