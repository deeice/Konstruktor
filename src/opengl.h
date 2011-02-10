/* LDRrenderer: LDraw model rendering library which based on libLDR                  *
 * To obtain more information about LDraw, visit http://www.ldraw.org                *
 * Distributed in terms of the General Public License v2                             *
 *                                                                                   *
 * Author: (c)2006-2010 Park "segfault" J. K. <mastermind_at_planetmono_dot_org>     */

#ifndef _RENDERER_OPENGL_H_
#define _RENDERER_OPENGL_H_

#if defined(WIN32)
#include <windows.h>
#include <wingdi.h>
typedef char GLchar;
#endif

#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glu.h>
#if !defined(WIN32)
#include <GL/glx.h>
#endif
#include <GL/glext.h>

#endif