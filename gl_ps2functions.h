/*
** File: gl_ps2functions.h
** Project: glDoom Re
** Author: André Guilherme
** Creation Date: 08/30/2023
** Description:
** Adds some unused ps2gl implementations and add unsupported OpenGL 1.2 functions 
** License: Public domain/ID License 
*/

#ifndef __GL_PS2FUNCTIONS__
#define __GL_PS2FUNCTIONS__

#ifdef __cplusplus
extern "C"
{
#endif

typedef unsigned int GLenum;
typedef int GLint;
typedef float GLfloat;

void glFogi(GLenum pname,
            GLint param);

void glReadBuffer(GLenum mode); 

void glPolygonOffset( GLfloat factor, GLfloat units);

#ifdef __cplusplus
}
#endif

#endif