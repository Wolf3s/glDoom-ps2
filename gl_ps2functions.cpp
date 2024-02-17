/*
** File: gl_ps2functions.h
** Project: glDoom Re-ps2
** Author: André Guilherme
** Creation Date: 02/14/2024
** Description:
** Adds some unused ps2gl implementations and add unsupported OpenGL 1.2 functions 
** License: Public domain/ID License 
*/

#include <GL/gl.h>
#include <ps2gl/debug.h>

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