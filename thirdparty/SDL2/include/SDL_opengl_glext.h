#ifndef __gl_glext_h_
#define __gl_glext_h_ 1

#ifdef __cplusplus
extern "C" {
#endif

/*
** Copyright 2013-2020 The Khronos Group Inc.
** SPDX-License-Identifier: MIT
**
** This header is generated from the Khronos OpenGL / OpenGL ES XML
** API Registry. The current version of the Registry, generator scripts
** used to make the header, and the header can be found at
**   https://github.com/KhronosGroup/OpenGL-Registry
*/

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#include <windows.h>
#endif

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPI
#define GLAPI extern
#endif

#define GL_GLEXT_VERSION 20220530

/*#include <KHR/khrplatform.h>*/
#ifndef __khrplatform_h_
#define __khrplatform_h_

/*
** Copyright (c) 2008-2018 The Khronos Group Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and/or associated documentation files (the
** "Materials"), to deal in the Materials without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Materials, and to
** permit persons to whom the Materials are furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Materials.
**
** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
*/

/* Khronos platform-specific types and definitions.
 *
 * The master copy of khrplatform.h is maintained in the Khronos EGL
 * Registry repository at https://github.com/KhronosGroup/EGL-Registry
 * The last semantic modification to khrplatform.h was at commit ID:
 *      67a3e0864c2d75ea5287b9f3d2eb74a745936692
 *
 * Adopters may modify this file to suit their platform. Adopters are
 * encouraged to submit platform specific modifications to the Khronos
 * group so that they can be included in future versions of this file.
 * Please submit changes by filing pull requests or issues on
 * the EGL Registry repository linked above.
 *
 *
 * See the Implementer's Guidelines for information about where this file
 * should be located on your system and for more details of its use:
 *    http://www.khronos.org/registry/implementers_guide.pdf
 *
 * This file should be included as
 *        #include <KHR/khrplatform.h>
 * by Khronos client API header files that use its types and defines.
 *
 * The types in khrplatform.h should only be used to define API-specific types.
 *
 * Types defined in khrplatform.h:
 *    khronos_int8_t              signed   8  bit
 *    khronos_uint8_t             unsigned 8  bit
 *    khronos_int16_t             signed   16 bit
 *    khronos_uint16_t            unsigned 16 bit
 *    khronos_int32_t             signed   32 bit
 *    khronos_uint32_t            unsigned 32 bit
 *    khronos_int64_t             signed   64 bit
 *    khronos_uint64_t            unsigned 64 bit
 *    khronos_intptr_t            signed   same number of bits as a pointer
 *    khronos_uintptr_t           unsigned same number of bits as a pointer
 *    khronos_ssize_t             signed   size
 *    khronos_usize_t             unsigned size
 *    khronos_float_t             signed   32 bit floating point
 *    khronos_time_ns_t           unsigned 64 bit time in nanoseconds
 *    khronos_utime_nanoseconds_t unsigned time interval or absolute time in
 *                                         nanoseconds
 *    khronos_stime_nanoseconds_t signed time interval in nanoseconds
 *    khronos_boolean_enum_t      enumerated boolean type. This should
 *      only be used as a base type when a client API's boolean type is
 *      an enum. Client APIs which use an integer or other type for
 *      booleans cannot use this as the base type for their boolean.
 *
 * Tokens defined in khrplatform.h:
 *
 *    KHRONOS_FALSE, KHRONOS_TRUE Enumerated boolean false/true values.
 *
 *    KHRONOS_SUPPORT_INT64 is 1 if 64 bit integers are supported; otherwise 0.
 *    KHRONOS_SUPPORT_FLOAT is 1 if floats are supported; otherwise 0.
 *
 * Calling convention macros defined in this file:
 *    KHRONOS_APICALL
 *    KHRONOS_APIENTRY
 *    KHRONOS_APIATTRIBUTES
 *
 * These may be used in function prototypes as:
 *
 *      KHRONOS_APICALL void KHRONOS_APIENTRY funcname(
 *                                  int arg1,
 *                                  int arg2) KHRONOS_APIATTRIBUTES;
 */

#if defined(__SCITECH_SNAP__) && !defined(KHRONOS_STATIC)
#   define KHRONOS_STATIC 1
#endif

/*-------------------------------------------------------------------------
 * Definition of KHRONOS_APICALL
 *-------------------------------------------------------------------------
 * This precedes the return type of the function in the function prototype.
 */
#if defined(KHRONOS_STATIC)
    /* If the preprocessor constant KHRONOS_STATIC is defined, make the
     * header compatible with static linking. */
#   define KHRONOS_APICALL
#elif defined(_WIN32)
#   define KHRONOS_APICALL __declspec(dllimport)
#elif defined (__SYMBIAN32__)
#   define KHRONOS_APICALL IMPORT_C
#elif defined(__ANDROID__)
#   define KHRONOS_APICALL __attribute__((visibility("default")))
#else
#   define KHRONOS_APICALL
#endif

/*-------------------------------------------------------------------------
 * Definition of KHRONOS_APIENTRY
 *-------------------------------------------------------------------------
 * This follows the return type of the function  and precedes the function
 * name in the function prototype.
 */
#if defined(_WIN32) && !defined(_WIN32_WCE) && !defined(__SCITECH_SNAP__)
    /* Win32 but not WinCE */
#   define KHRONOS_APIENTRY __stdcall
#else
#   define KHRONOS_APIENTRY
#endif

/*-------------------------------------------------------------------------
 * Definition of KHRONOS_APIATTRIBUTES
 *-------------------------------------------------------------------------
 * This follows the closing parenthesis of the function prototype arguments.
 */
#if defined (__ARMCC_2__)
#define KHRONOS_APIATTRIBUTES __softfp
#else
#define KHRONOS_APIATTRIBUTES
#endif

/*-------------------------------------------------------------------------
 * basic type definitions
 *-----------------------------------------------------------------------*/
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || defined(__GNUC__) || defined(__SCO__) || defined(__USLC__)


/*
 * Using <stdint.h>
 */
#include <stdint.h>
typedef int32_t                 khronos_int32_t;
typedef uint32_t                khronos_uint32_t;
typedef int64_t                 khronos_int64_t;
typedef uint64_t                khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1
/*
 * To support platform where unsigned long cannot be used interchangeably with
 * inptr_t (e.g. CHERI-extended ISAs), we can use the stdint.h intptr_t.
 * Ideally, we could just use (u)intptr_t everywhere, but this could result in
 * ABI breakage if khronos_uintptr_t is changed from unsigned long to
 * unsigned long long or similar (this results in different C++ name mangling).
 * To avoid changes for existing platforms, we restrict usage of intptr_t to
 * platforms where the size of a pointer is larger than the size of long.
 */
#if defined(__SIZEOF_LONG__) && defined(__SIZEOF_POINTER__)
#if __SIZEOF_POINTER__ > __SIZEOF_LONG__
#define KHRONOS_USE_INTPTR_T
#endif
#endif

#elif defined(__VMS ) || defined(__sgi)

/*
 * Using <inttypes.h>
 */
#include <inttypes.h>
typedef int32_t                 khronos_int32_t;
typedef uint32_t                khronos_uint32_t;
typedef int64_t                 khronos_int64_t;
typedef uint64_t                khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif defined(_WIN32) && !defined(__SCITECH_SNAP__)

/*
 * Win32
 */
typedef __int32                 khronos_int32_t;
typedef unsigned __int32        khronos_uint32_t;
typedef __int64                 khronos_int64_t;
typedef unsigned __int64        khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif defined(__sun__) || defined(__digital__)

/*
 * Sun or Digital
 */
typedef int                     khronos_int32_t;
typedef unsigned int            khronos_uint32_t;
#if defined(__arch64__) || defined(_LP64)
typedef long int                khronos_int64_t;
typedef unsigned long int       khronos_uint64_t;
#else
typedef long long int           khronos_int64_t;
typedef unsigned long long int  khronos_uint64_t;
#endif /* __arch64__ */
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif 0

/*
 * Hypothetical platform with no float or int64 support
 */
typedef int                     khronos_int32_t;
typedef unsigned int            khronos_uint32_t;
#define KHRONOS_SUPPORT_INT64   0
#define KHRONOS_SUPPORT_FLOAT   0

#else

/*
 * Generic fallback
 */
#include <stdint.h>
typedef int32_t                 khronos_int32_t;
typedef uint32_t                khronos_uint32_t;
typedef int64_t                 khronos_int64_t;
typedef uint64_t                khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#endif


/*
 * Types that are (so far) the same on all platforms
 */
typedef signed   char          khronos_int8_t;
typedef unsigned char          khronos_uint8_t;
typedef signed   short int     khronos_int16_t;
typedef unsigned short int     khronos_uint16_t;

/*
 * Types that differ between LLP64 and LP64 architectures - in LLP64,
 * pointers are 64 bits, but 'long' is still 32 bits. Win64 appears
 * to be the only LLP64 architecture in current use.
 */
#ifdef KHRONOS_USE_INTPTR_T
typedef intptr_t               khronos_intptr_t;
typedef uintptr_t              khronos_uintptr_t;
#elif defined(_WIN64)
typedef signed   long long int khronos_intptr_t;
typedef unsigned long long int khronos_uintptr_t;
#else
typedef signed   long  int     khronos_intptr_t;
typedef unsigned long  int     khronos_uintptr_t;
#endif

#if defined(_WIN64)
typedef signed   long long int khronos_ssize_t;
typedef unsigned long long int khronos_usize_t;
#else
typedef signed   long  int     khronos_ssize_t;
typedef unsigned long  int     khronos_usize_t;
#endif

#if KHRONOS_SUPPORT_FLOAT
/*
 * Float type
 */
typedef          float         khronos_float_t;
#endif

#if KHRONOS_SUPPORT_INT64
/* Time types
 *
 * These types can be used to represent a time interval in nanoseconds or
 * an absolute Unadjusted System Time.  Unadjusted System Time is the number
 * of nanoseconds since some arbitrary system event (e.g. since the last
 * time the system booted).  The Unadjusted System Time is an unsigned
 * 64 bit value that wraps back to 0 every 584 years.  Time intervals
 * may be either signed or unsigned.
 */
typedef khronos_uint64_t       khronos_utime_nanoseconds_t;
typedef khronos_int64_t        khronos_stime_nanoseconds_t;
#endif

/*
 * Dummy value used to pad enum types to 32 bits.
 */
#ifndef KHRONOS_MAX_ENUM
#define KHRONOS_MAX_ENUM 0x7FFFFFFF
#endif

/*
 * Enumerated boolean type
 *
 * Values other than zero should be considered to be true.  Therefore
 * comparisons should not be made against KHRONOS_TRUE.
 */
typedef enum {
    KHRONOS_FALSE = 0,
    KHRONOS_TRUE  = 1,
    KHRONOS_BOOLEAN_ENUM_FORCE_SIZE = KHRONOS_MAX_ENUM
} khronos_boolean_enum_t;

#endif /* __khrplatform_h_ */

/* Generated C header for:
 * API: gl
 * Profile: compatibility
 * Versions considered: .*
 * Versions emitted: 1\.[2-9]|[234]\.[0-9]
 * Default extensions included: gl
 * Additional extensions included: _nomatch_^
 * Extensions removed: _nomatch_^
 */

#ifndef GL_VERSION_1_2
#define GL_VERSION_1_2 1
#define GL_UNSIGNED_BYTE_3_3_2            0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4         0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1         0x8034
#define GL_UNSIGNED_INT_8_8_8_8           0x8035
#define GL_UNSIGNED_INT_10_10_10_2        0x8036
#define GL_TEXTURE_BINDING_3D             0x806A
#define GL_PACK_SKIP_IMAGES               0x806B
#define GL_PACK_IMAGE_HEIGHT              0x806C
#define GL_UNPACK_SKIP_IMAGES             0x806D
#define GL_UNPACK_IMAGE_HEIGHT            0x806E
#define GL_TEXTURE_3D                     0x806F
#define GL_PROXY_TEXTURE_3D               0x8070
#define GL_TEXTURE_DEPTH                  0x8071
#define GL_TEXTURE_WRAP_R                 0x8072
#define GL_MAX_3D_TEXTURE_SIZE            0x8073
#define GL_UNSIGNED_BYTE_2_3_3_REV        0x8362
#define GL_UNSIGNED_SHORT_5_6_5           0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV       0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV     0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV     0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV       0x8367
#define GL_UNSIGNED_INT_2_10_10_10_REV    0x8368
#define GL_BGR                            0x80E0
#define GL_BGRA                           0x80E1
#define GL_MAX_ELEMENTS_VERTICES          0x80E8
#define GL_MAX_ELEMENTS_INDICES           0x80E9
#define GL_CLAMP_TO_EDGE                  0x812F
#define GL_TEXTURE_MIN_LOD                0x813A
#define GL_TEXTURE_MAX_LOD                0x813B
#define GL_TEXTURE_BASE_LEVEL             0x813C
#define GL_TEXTURE_MAX_LEVEL              0x813D
#define GL_SMOOTH_POINT_SIZE_RANGE        0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY  0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE        0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY  0x0B23
#define GL_ALIASED_LINE_WIDTH_RANGE       0x846E
#define GL_RESCALE_NORMAL                 0x803A
#define GL_LIGHT_MODEL_COLOR_CONTROL      0x81F8
#define GL_SINGLE_COLOR                   0x81F9
#define GL_SEPARATE_SPECULAR_COLOR        0x81FA
#define GL_ALIASED_POINT_SIZE_RANGE       0x846D
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
typedef void (APIENTRYP PFNGLTEXIMAGE3DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawRangeElements (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
GLAPI void APIENTRY glTexImage3D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glCopyTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#endif
#endif /* GL_VERSION_1_2 */

#ifndef GL_VERSION_1_3
#define GL_VERSION_1_3 1
#define GL_TEXTURE0                       0x84C0
#define GL_TEXTURE1                       0x84C1
#define GL_TEXTURE2                       0x84C2
#define GL_TEXTURE3                       0x84C3
#define GL_TEXTURE4                       0x84C4
#define GL_TEXTURE5                       0x84C5
#define GL_TEXTURE6                       0x84C6
#define GL_TEXTURE7                       0x84C7
#define GL_TEXTURE8                       0x84C8
#define GL_TEXTURE9                       0x84C9
#define GL_TEXTURE10                      0x84CA
#define GL_TEXTURE11                      0x84CB
#define GL_TEXTURE12                      0x84CC
#define GL_TEXTURE13                      0x84CD
#define GL_TEXTURE14                      0x84CE
#define GL_TEXTURE15                      0x84CF
#define GL_TEXTURE16                      0x84D0
#define GL_TEXTURE17                      0x84D1
#define GL_TEXTURE18                      0x84D2
#define GL_TEXTURE19                      0x84D3
#define GL_TEXTURE20                      0x84D4
#define GL_TEXTURE21                      0x84D5
#define GL_TEXTURE22                      0x84D6
#define GL_TEXTURE23                      0x84D7
#define GL_TEXTURE24                      0x84D8
#define GL_TEXTURE25                      0x84D9
#define GL_TEXTURE26                      0x84DA
#define GL_TEXTURE27                      0x84DB
#define GL_TEXTURE28                      0x84DC
#define GL_TEXTURE29                      0x84DD
#define GL_TEXTURE30                      0x84DE
#define GL_TEXTURE31                      0x84DF
#define GL_ACTIVE_TEXTURE                 0x84E0
#define GL_MULTISAMPLE                    0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE       0x809E
#define GL_SAMPLE_ALPHA_TO_ONE            0x809F
#define GL_SAMPLE_COVERAGE                0x80A0
#define GL_SAMPLE_BUFFERS                 0x80A8
#define GL_SAMPLES                        0x80A9
#define GL_SAMPLE_COVERAGE_VALUE          0x80AA
#define GL_SAMPLE_COVERAGE_INVERT         0x80AB
#define GL_TEXTURE_CUBE_MAP               0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP       0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X    0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X    0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y    0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z    0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP         0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE      0x851C
#define GL_COMPRESSED_RGB                 0x84ED
#define GL_COMPRESSED_RGBA                0x84EE
#define GL_TEXTURE_COMPRESSION_HINT       0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE  0x86A0
#define GL_TEXTURE_COMPRESSED             0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS     0x86A3
#define GL_CLAMP_TO_BORDER                0x812D
#define GL_CLIENT_ACTIVE_TEXTURE          0x84E1
#define GL_MAX_TEXTURE_UNITS              0x84E2
#define GL_TRANSPOSE_MODELVIEW_MATRIX     0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX    0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX       0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX         0x84E6
#define GL_MULTISAMPLE_BIT                0x20000000
#define GL_NORMAL_MAP                     0x8511
#define GL_REFLECTION_MAP                 0x8512
#define GL_COMPRESSED_ALPHA               0x84E9
#define GL_COMPRESSED_LUMINANCE           0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA     0x84EB
#define GL_COMPRESSED_INTENSITY           0x84EC
#define GL_COMBINE                        0x8570
#define GL_COMBINE_RGB                    0x8571
#define GL_COMBINE_ALPHA                  0x8572
#define GL_SOURCE0_RGB                    0x8580
#define GL_SOURCE1_RGB                    0x8581
#define GL_SOURCE2_RGB                    0x8582
#define GL_SOURCE0_ALPHA                  0x8588
#define GL_SOURCE1_ALPHA                  0x8589
#define GL_SOURCE2_ALPHA                  0x858A
#define GL_OPERAND0_RGB                   0x8590
#define GL_OPERAND1_RGB                   0x8591
#define GL_OPERAND2_RGB                   0x8592
#define GL_OPERAND0_ALPHA                 0x8598
#define GL_OPERAND1_ALPHA                 0x8599
#define GL_OPERAND2_ALPHA                 0x859A
#define GL_RGB_SCALE                      0x8573
#define GL_ADD_SIGNED                     0x8574
#define GL_INTERPOLATE                    0x8575
#define GL_SUBTRACT                       0x84E7
#define GL_CONSTANT                       0x8576
#define GL_PRIMARY_COLOR                  0x8577
#define GL_PREVIOUS                       0x8578
#define GL_DOT3_RGB                       0x86AE
#define GL_DOT3_RGBA                      0x86AF
typedef void (APIENTRYP PFNGLACTIVETEXTUREPROC) (GLenum texture);
typedef void (APIENTRYP PFNGLSAMPLECOVERAGEPROC) (GLfloat value, GLboolean invert);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEPROC) (GLenum target, GLint level, void *img);
typedef void (APIENTRYP PFNGLCLIENTACTIVETEXTUREPROC) (GLenum texture);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DPROC) (GLenum target, GLdouble s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DVPROC) (GLenum target, const GLdouble *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FPROC) (GLenum target, GLfloat s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FVPROC) (GLenum target, const GLfloat *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IPROC) (GLenum target, GLint s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IVPROC) (GLenum target, const GLint *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SPROC) (GLenum target, GLshort s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SVPROC) (GLenum target, const GLshort *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DPROC) (GLenum target, GLdouble s, GLdouble t);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DVPROC) (GLenum target, const GLdouble *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FPROC) (GLenum target, GLfloat s, GLfloat t);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FVPROC) (GLenum target, const GLfloat *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IPROC) (GLenum target, GLint s, GLint t);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IVPROC) (GLenum target, const GLint *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SPROC) (GLenum target, GLshort s, GLshort t);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SVPROC) (GLenum target, const GLshort *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DVPROC) (GLenum target, const GLdouble *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FVPROC) (GLenum target, const GLfloat *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IPROC) (GLenum target, GLint s, GLint t, GLint r);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IVPROC) (GLenum target, const GLint *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SPROC) (GLenum target, GLshort s, GLshort t, GLshort r);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SVPROC) (GLenum target, const GLshort *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DVPROC) (GLenum target, const GLdouble *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FVPROC) (GLenum target, const GLfloat *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IPROC) (GLenum target, GLint s, GLint t, GLint r, GLint q);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IVPROC) (GLenum target, const GLint *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SPROC) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SVPROC) (GLenum target, const GLshort *v);
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXFPROC) (const GLfloat *m);
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXDPROC) (const GLdouble *m);
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXFPROC) (const GLfloat *m);
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXDPROC) (const GLdouble *m);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glActiveTexture (GLenum texture);
GLAPI void APIENTRY glSampleCoverage (GLfloat value, GLboolean invert);
GLAPI void APIENTRY glCompressedTexImage3D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTexImage2D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTexImage1D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glGetCompressedTexImage (GLenum target, GLint level, void *img);
GLAPI void APIENTRY glClientActiveTexture (GLenum texture);
GLAPI void APIENTRY glMultiTexCoord1d (GLenum target, GLdouble s);
GLAPI void APIENTRY glMultiTexCoord1dv (GLenum target, const GLdouble *v);
GLAPI void APIENTRY glMultiTexCoord1f (GLenum target, GLfloat s);
GLAPI void APIENTRY glMultiTexCoord1fv (GLenum target, const GLfloat *v);
GLAPI void APIENTRY glMultiTexCoord1i (GLenum target, GLint s);
GLAPI void APIENTRY glMultiTexCoord1iv (GLenum target, const GLint *v);
GLAPI void APIENTRY glMultiTexCoord1s (GLenum target, GLshort s);
GLAPI void APIENTRY glMultiTexCoord1sv (GLenum target, const GLshort *v);
GLAPI void APIENTRY glMultiTexCoord2d (GLenum target, GLdouble s, GLdouble t);
GLAPI void APIENTRY glMultiTexCoord2dv (GLenum target, const GLdouble *v);
GLAPI void APIENTRY glMultiTexCoord2f (GLenum target, GLfloat s, GLfloat t);
GLAPI void APIENTRY glMultiTexCoord2fv (GLenum target, const GLfloat *v);
GLAPI void APIENTRY glMultiTexCoord2i (GLenum target, GLint s, GLint t);
GLAPI void APIENTRY glMultiTexCoord2iv (GLenum target, const GLint *v);
GLAPI void APIENTRY glMultiTexCoord2s (GLenum target, GLshort s, GLshort t);
GLAPI void APIENTRY glMultiTexCoord2sv (GLenum target, const GLshort *v);
GLAPI void APIENTRY glMultiTexCoord3d (GLenum target, GLdouble s, GLdouble t, GLdouble r);
GLAPI void APIENTRY glMultiTexCoord3dv (GLenum target, const GLdouble *v);
GLAPI void APIENTRY glMultiTexCoord3f (GLenum target, GLfloat s, GLfloat t, GLfloat r);
GLAPI void APIENTRY glMultiTexCoord3fv (GLenum target, const GLfloat *v);
GLAPI void APIENTRY glMultiTexCoord3i (GLenum target, GLint s, GLint t, GLint r);
GLAPI void APIENTRY glMultiTexCoord3iv (GLenum target, const GLint *v);
GLAPI void APIENTRY glMultiTexCoord3s (GLenum target, GLshort s, GLshort t, GLshort r);
GLAPI void APIENTRY glMultiTexCoord3sv (GLenum target, const GLshort *v);
GLAPI void APIENTRY glMultiTexCoord4d (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
GLAPI void APIENTRY glMultiTexCoord4dv (GLenum target, const GLdouble *v);
GLAPI void APIENTRY glMultiTexCoord4f (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
GLAPI void APIENTRY glMultiTexCoord4fv (GLenum target, const GLfloat *v);
GLAPI void APIENTRY glMultiTexCoord4i (GLenum target, GLint s, GLint t, GLint r, GLint q);
GLAPI void APIENTRY glMultiTexCoord4iv (GLenum target, const GLint *v);
GLAPI void APIENTRY glMultiTexCoord4s (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
GLAPI void APIENTRY glMultiTexCoord4sv (GLenum target, const GLshort *v);
GLAPI void APIENTRY glLoadTransposeMatrixf (const GLfloat *m);
GLAPI void APIENTRY glLoadTransposeMatrixd (const GLdouble *m);
GLAPI void APIENTRY glMultTransposeMatrixf (const GLfloat *m);
GLAPI void APIENTRY glMultTransposeMatrixd (const GLdouble *m);
#endif
#endif /* GL_VERSION_1_3 */

#ifndef GL_VERSION_1_4
#define GL_VERSION_1_4 1
#define GL_BLEND_DST_RGB                  0x80C8
#define GL_BLEND_SRC_RGB                  0x80C9
#define GL_BLEND_DST_ALPHA                0x80CA
#define GL_BLEND_SRC_ALPHA                0x80CB
#define GL_POINT_FADE_THRESHOLD_SIZE      0x8128
#define GL_DEPTH_COMPONENT16              0x81A5
#define GL_DEPTH_COMPONENT24              0x81A6
#define GL_DEPTH_COMPONENT32              0x81A7
#define GL_MIRRORED_REPEAT                0x8370
#define GL_MAX_TEXTURE_LOD_BIAS           0x84FD
#define GL_TEXTURE_LOD_BIAS               0x8501
#define GL_INCR_WRAP                      0x8507
#define GL_DECR_WRAP                      0x8508
#define GL_TEXTURE_DEPTH_SIZE             0x884A
#define GL_TEXTURE_COMPARE_MODE           0x884C
#define GL_TEXTURE_COMPARE_FUNC           0x884D
#define GL_POINT_SIZE_MIN                 0x8126
#define GL_POINT_SIZE_MAX                 0x8127
#define GL_POINT_DISTANCE_ATTENUATION     0x8129
#define GL_GENERATE_MIPMAP                0x8191
#define GL_GENERATE_MIPMAP_HINT           0x8192
#define GL_FOG_COORDINATE_SOURCE          0x8450
#define GL_FOG_COORDINATE                 0x8451
#define GL_FRAGMENT_DEPTH                 0x8452
#define GL_CURRENT_FOG_COORDINATE         0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE      0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE    0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER   0x8456
#define GL_FOG_COORDINATE_ARRAY           0x8457
#define GL_COLOR_SUM                      0x8458
#define GL_CURRENT_SECONDARY_COLOR        0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE     0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE     0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE   0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER  0x845D
#define GL_SECONDARY_COLOR_ARRAY          0x845E
#define GL_TEXTURE_FILTER_CONTROL         0x8500
#define GL_DEPTH_TEXTURE_MODE             0x884B
#define GL_COMPARE_R_TO_TEXTURE           0x884E
#define GL_BLEND_COLOR                    0x8005
#define GL_BLEND_EQUATION                 0x8009
#define GL_CONSTANT_COLOR                 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR       0x8002
#define GL_CONSTANT_ALPHA                 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA       0x8004
#define GL_FUNC_ADD                       0x8006
#define GL_FUNC_REVERSE_SUBTRACT          0x800B
#define GL_FUNC_SUBTRACT                  0x800A
#define GL_MIN                            0x8007
#define GL_MAX                            0x8008
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEPROC) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSPROC) (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSPROC) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVPROC) (GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLPOINTPARAMETERIPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLPOINTPARAMETERIVPROC) (GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLFOGCOORDFPROC) (GLfloat coord);
typedef void (APIENTRYP PFNGLFOGCOORDFVPROC) (const GLfloat *coord);
typedef void (APIENTRYP PFNGLFOGCOORDDPROC) (GLdouble coord);
typedef void (APIENTRYP PFNGLFOGCOORDDVPROC) (const GLdouble *coord);
typedef void (APIENTRYP PFNGLFOGCOORDPOINTERPROC) (GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BPROC) (GLbyte red, GLbyte green, GLbyte blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BVPROC) (const GLbyte *v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DPROC) (GLdouble red, GLdouble green, GLdouble blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DVPROC) (const GLdouble *v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FPROC) (GLfloat red, GLfloat green, GLfloat blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FVPROC) (const GLfloat *v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IPROC) (GLint red, GLint green, GLint blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IVPROC) (const GLint *v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SPROC) (GLshort red, GLshort green, GLshort blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SVPROC) (const GLshort *v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBPROC) (GLubyte red, GLubyte green, GLubyte blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBVPROC) (const GLubyte *v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIPROC) (GLuint red, GLuint green, GLuint blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIVPROC) (const GLuint *v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USPROC) (GLushort red, GLushort green, GLushort blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USVPROC) (const GLushort *v);
typedef void (APIENTRYP PFNGLSECONDARYCOLORPOINTERPROC) (GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLWINDOWPOS2DPROC) (GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLWINDOWPOS2DVPROC) (const GLdouble *v);
typedef void (APIENTRYP PFNGLWINDOWPOS2FPROC) (GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLWINDOWPOS2FVPROC) (const GLfloat *v);
typedef void (APIENTRYP PFNGLWINDOWPOS2IPROC) (GLint x, GLint y);
typedef void (APIENTRYP PFNGLWINDOWPOS2IVPROC) (const GLint *v);
typedef void (APIENTRYP PFNGLWINDOWPOS2SPROC) (GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLWINDOWPOS2SVPROC) (const GLshort *v);
typedef void (APIENTRYP PFNGLWINDOWPOS3DPROC) (GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLWINDOWPOS3DVPROC) (const GLdouble *v);
typedef void (APIENTRYP PFNGLWINDOWPOS3FPROC) (GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLWINDOWPOS3FVPROC) (const GLfloat *v);
typedef void (APIENTRYP PFNGLWINDOWPOS3IPROC) (GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLWINDOWPOS3IVPROC) (const GLint *v);
typedef void (APIENTRYP PFNGLWINDOWPOS3SPROC) (GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLWINDOWPOS3SVPROC) (const GLshort *v);
typedef void (APIENTRYP PFNGLBLENDCOLORPROC) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC) (GLenum mode);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBlendFuncSeparate (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GLAPI void APIENTRY glMultiDrawArrays (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
GLAPI void APIENTRY glMultiDrawElements (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
GLAPI void APIENTRY glPointParameterf (GLenum pname, GLfloat param);
GLAPI void APIENTRY glPointParameterfv (GLenum pname, const GLfloat *params);
GLAPI void APIENTRY glPointParameteri (GLenum pname, GLint param);
GLAPI void APIENTRY glPointParameteriv (GLenum pname, const GLint *params);
GLAPI void APIENTRY glFogCoordf (GLfloat coord);
GLAPI void APIENTRY glFogCoordfv (const GLfloat *coord);
GLAPI void APIENTRY glFogCoordd (GLdouble coord);
GLAPI void APIENTRY glFogCoorddv (const GLdouble *coord);
GLAPI void APIENTRY glFogCoordPointer (GLenum type, GLsizei stride, const void *pointer);
GLAPI void APIENTRY glSecondaryColor3b (GLbyte red, GLbyte green, GLbyte blue);
GLAPI void APIENTRY glSecondaryColor3bv (const GLbyte *v);
GLAPI void APIENTRY glSecondaryColor3d (GLdouble red, GLdouble green, GLdouble blue);
GLAPI void APIENTRY glSecondaryColor3dv (const GLdouble *v);
GLAPI void APIENTRY glSecondaryColor3f (GLfloat red, GLfloat green, GLfloat blue);
GLAPI void APIENTRY glSecondaryColor3fv (const GLfloat *v);
GLAPI void APIENTRY glSecondaryColor3i (GLint red, GLint green, GLint blue);
GLAPI void APIENTRY glSecondaryColor3iv (const GLint *v);
GLAPI void APIENTRY glSecondaryColor3s (GLshort red, GLshort green, GLshort blue);
GLAPI void APIENTRY glSecondaryColor3sv (const GLshort *v);
GLAPI void APIENTRY glSecondaryColor3ub (GLubyte red, GLubyte green, GLubyte blue);
GLAPI void APIENTRY glSecondaryColor3ubv (const GLubyte *v);
GLAPI void APIENTRY glSecondaryColor3ui (GLuint red, GLuint green, GLuint blue);
GLAPI void APIENTRY glSecondaryColor3uiv (const GLuint *v);
GLAPI void APIENTRY glSecondaryColor3us (GLushort red, GLushort green, GLushort blue);
GLAPI void APIENTRY glSecondaryColor3usv (const GLushort *v);
GLAPI void APIENTRY glSecondaryColorPointer (GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI void APIENTRY glWindowPos2d (GLdouble x, GLdouble y);
GLAPI void APIENTRY glWindowPos2dv (const GLdouble *v);
GLAPI void APIENTRY glWindowPos2f (GLfloat x, GLfloat y);
GLAPI void APIENTRY glWindowPos2fv (const GLfloat *v);
GLAPI void APIENTRY glWindowPos2i (GLint x, GLint y);
GLAPI void APIENTRY glWindowPos2iv (const GLint *v);
GLAPI void APIENTRY glWindowPos2s (GLshort x, GLshort y);
GLAPI void APIENTRY glWindowPos2sv (const GLshort *v);
GLAPI void APIENTRY glWindowPos3d (GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glWindowPos3dv (const GLdouble *v);
GLAPI void APIENTRY glWindowPos3f (GLfloat x, GLfloat y, GLfloat z);
GLAPI void APIENTRY glWindowPos3fv (const GLfloat *v);
GLAPI void APIENTRY glWindowPos3i (GLint x, GLint y, GLint z);
GLAPI void APIENTRY glWindowPos3iv (const GLint *v);
GLAPI void APIENTRY glWindowPos3s (GLshort x, GLshort y, GLshort z);
GLAPI void APIENTRY glWindowPos3sv (const GLshort *v);
GLAPI void APIENTRY glBlendColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLAPI void APIENTRY glBlendEquation (GLenum mode);
#endif
#endif /* GL_VERSION_1_4 */

#ifndef GL_VERSION_1_5
#define GL_VERSION_1_5 1
typedef khronos_ssize_t GLsizeiptr;
typedef khronos_intptr_t GLintptr;
#define GL_BUFFER_SIZE                    0x8764
#define GL_BUFFER_USAGE                   0x8765
#define GL_QUERY_COUNTER_BITS             0x8864
#define GL_CURRENT_QUERY                  0x8865
#define GL_QUERY_RESULT                   0x8866
#define GL_QUERY_RESULT_AVAILABLE         0x8867
#define GL_ARRAY_BUFFER                   0x8892
#define GL_ELEMENT_ARRAY_BUFFER           0x8893
#define GL_ARRAY_BUFFER_BINDING           0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING   0x8895
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_READ_ONLY                      0x88B8
#define GL_WRITE_ONLY                     0x88B9
#define GL_READ_WRITE                     0x88BA
#define GL_BUFFER_ACCESS                  0x88BB
#define GL_BUFFER_MAPPED                  0x88BC
#define GL_BUFFER_MAP_POINTER             0x88BD
#define GL_STREAM_DRAW                    0x88E0
#define GL_STREAM_READ                    0x88E1
#define GL_STREAM_COPY                    0x88E2
#define GL_STATIC_DRAW                    0x88E4
#define GL_STATIC_READ                    0x88E5
#define GL_STATIC_COPY                    0x88E6
#define GL_DYNAMIC_DRAW                   0x88E8
#define GL_DYNAMIC_READ                   0x88E9
#define GL_DYNAMIC_COPY                   0x88EA
#define GL_SAMPLES_PASSED                 0x8914
#define GL_SRC1_ALPHA                     0x8589
#define GL_VERTEX_ARRAY_BUFFER_BINDING    0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING    0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING     0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING     0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING 0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING 0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING 0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING    0x889E
#define GL_FOG_COORD_SRC                  0x8450
#define GL_FOG_COORD                      0x8451
#define GL_CURRENT_FOG_COORD              0x8453
#define GL_FOG_COORD_ARRAY_TYPE           0x8454
#define GL_FOG_COORD_ARRAY_STRIDE         0x8455
#define GL_FOG_COORD_ARRAY_POINTER        0x8456
#define GL_FOG_COORD_ARRAY                0x8457
#define GL_FOG_COORD_ARRAY_BUFFER_BINDING 0x889D
#define GL_SRC0_RGB                       0x8580
#define GL_SRC1_RGB                       0x8581
#define GL_SRC2_RGB                       0x8582
#define GL_SRC0_ALPHA                     0x8588
#define GL_SRC2_ALPHA                     0x858A
typedef void (APIENTRYP PFNGLGENQUERIESPROC) (GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLDELETEQUERIESPROC) (GLsizei n, const GLuint *ids);
typedef GLboolean (APIENTRYP PFNGLISQUERYPROC) (GLuint id);
typedef void (APIENTRYP PFNGLBEGINQUERYPROC) (GLenum target, GLuint id);
typedef void (APIENTRYP PFNGLENDQUERYPROC) (GLenum target);
typedef void (APIENTRYP PFNGLGETQUERYIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTIVPROC) (GLuint id, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUIVPROC) (GLuint id, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLBINDBUFFERPROC) (GLenum target, GLuint buffer);
typedef void (APIENTRYP PFNGLDELETEBUFFERSPROC) (GLsizei n, const GLuint *buffers);
typedef void (APIENTRYP PFNGLGENBUFFERSPROC) (GLsizei n, GLuint *buffers);
typedef GLboolean (APIENTRYP PFNGLISBUFFERPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLBUFFERDATAPROC) (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
typedef void (APIENTRYP PFNGLBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
typedef void (APIENTRYP PFNGLGETBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, void *data);
typedef void *(APIENTRYP PFNGLMAPBUFFERPROC) (GLenum target, GLenum access);
typedef GLboolean (APIENTRYP PFNGLUNMAPBUFFERPROC) (GLenum target);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETBUFFERPOINTERVPROC) (GLenum target, GLenum pname, void **params);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glGenQueries (GLsizei n, GLuint *ids);
GLAPI void APIENTRY glDeleteQueries (GLsizei n, const GLuint *ids);
GLAPI GLboolean APIENTRY glIsQuery (GLuint id);
GLAPI void APIENTRY glBeginQuery (GLenum target, GLuint id);
GLAPI void APIENTRY glEndQuery (GLenum target);
GLAPI void APIENTRY glGetQueryiv (GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetQueryObjectiv (GLuint id, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetQueryObjectuiv (GLuint id, GLenum pname, GLuint *params);
GLAPI void APIENTRY glBindBuffer (GLenum target, GLuint buffer);
GLAPI void APIENTRY glDeleteBuffers (GLsizei n, const GLuint *buffers);
GLAPI void APIENTRY glGenBuffers (GLsizei n, GLuint *buffers);
GLAPI GLboolean APIENTRY glIsBuffer (GLuint buffer);
GLAPI void APIENTRY glBufferData (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
GLAPI void APIENTRY glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
GLAPI void APIENTRY glGetBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, void *data);
GLAPI void *APIENTRY glMapBuffer (GLenum target, GLenum access);
GLAPI GLboolean APIENTRY glUnmapBuffer (GLenum target);
GLAPI void APIENTRY glGetBufferParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetBufferPointerv (GLenum target, GLenum pname, void **params);
#endif
#endif /* GL_VERSION_1_5 */

#ifndef GL_VERSION_2_0
#define GL_VERSION_2_0 1
typedef char GLchar;
#define GL_BLEND_EQUATION_RGB             0x8009
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED    0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE       0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE     0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE       0x8625
#define GL_CURRENT_VERTEX_ATTRIB          0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE      0x8642
#define GL_VERTEX_ATTRIB_ARRAY_POINTER    0x8645
#define GL_STENCIL_BACK_FUNC              0x8800
#define GL_STENCIL_BACK_FAIL              0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL   0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS   0x8803
#define GL_MAX_DRAW_BUFFERS               0x8824
#define GL_DRAW_BUFFER0                   0x8825
#define GL_DRAW_BUFFER1                   0x8826
#define GL_DRAW_BUFFER2                   0x8827
#define GL_DRAW_BUFFER3                   0x8828
#define GL_DRAW_BUFFER4                   0x8829
#define GL_DRAW_BUFFER5                   0x882A
#define GL_DRAW_BUFFER6                   0x882B
#define GL_DRAW_BUFFER7                   0x882C
#define GL_DRAW_BUFFER8                   0x882D
#define GL_DRAW_BUFFER9                   0x882E
#define GL_DRAW_BUFFER10                  0x882F
#define GL_DRAW_BUFFER11                  0x8830
#define GL_DRAW_BUFFER12                  0x8831
#define GL_DRAW_BUFFER13                  0x8832
#define GL_DRAW_BUFFER14                  0x8833
#define GL_DRAW_BUFFER15                  0x8834
#define GL_BLEND_EQUATION_ALPHA           0x883D
#define GL_MAX_VERTEX_ATTRIBS             0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_IMAGE_UNITS        0x8872
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS  0x8B4A
#define GL_MAX_VARYING_FLOATS             0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE                    0x8B4F
#define GL_FLOAT_VEC2                     0x8B50
#define GL_FLOAT_VEC3                     0x8B51
#define GL_FLOAT_VEC4                     0x8B52
#define GL_INT_VEC2                       0x8B53
#define GL_INT_VEC3                       0x8B54
#define GL_INT_VEC4                       0x8B55
#define GL_BOOL                           0x8B56
#define GL_BOOL_VEC2                      0x8B57
#define GL_BOOL_VEC3                      0x8B58
#define GL_BOOL_VEC4                      0x8B59
#define GL_FLOAT_MAT2                     0x8B5A
#define GL_FLOAT_MAT3                     0x8B5B
#define GL_FLOAT_MAT4                     0x8B5C
#define GL_SAMPLER_1D                     0x8B5D
#define GL_SAMPLER_2D                     0x8B5E
#define GL_SAMPLER_3D                     0x8B5F
#define GL_SAMPLER_CUBE                   0x8B60
#define GL_SAMPLER_1D_SHADOW              0x8B61
#define GL_SAMPLER_2D_SHADOW              0x8B62
#define GL_DELETE_STATUS                  0x8B80
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_VALIDATE_STATUS                0x8B83
#define GL_INFO_LOG_LENGTH                0x8B84
#define GL_ATTACHED_SHADERS               0x8B85
#define GL_ACTIVE_UNIFORMS                0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH      0x8B87
#define GL_SHADER_SOURCE_LENGTH           0x8B88
#define GL_ACTIVE_ATTRIBUTES              0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH    0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION       0x8B8C
#define GL_CURRENT_PROGRAM                0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN      0x8CA0
#define GL_LOWER_LEFT                     0x8CA1
#define GL_UPPER_LEFT                     0x8CA2
#define GL_STENCIL_BACK_REF               0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK        0x8CA4
#define GL_STENCIL_BACK_WRITEMASK         0x8CA5
#define GL_VERTEX_PROGRAM_TWO_SIDE        0x8643
#define GL_POINT_SPRITE                   0x8861
#define GL_COORD_REPLACE                  0x8862
#define GL_MAX_TEXTURE_COORDS             0x8871
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC) (GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLDRAWBUFFERSPROC) (GLsizei n, const GLenum *bufs);
typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEPROC) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC) (GLenum face, GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILMASKSEPARATEPROC) (GLenum face, GLuint mask);
typedef void (APIENTRYP PFNGLATTACHSHADERPROC) (GLuint program, GLuint shader);
typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONPROC) (GLuint program, GLuint index, const GLchar *name);
typedef void (APIENTRYP PFNGLCOMPILESHADERPROC) (GLuint shader);
typedef GLuint (APIENTRYP PFNGLCREATEPROGRAMPROC) (void);
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROC) (GLenum type);
typedef void (APIENTRYP PFNGLDELETEPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLDELETESHADERPROC) (GLuint shader);
typedef void (APIENTRYP PFNGLDETACHSHADERPROC) (GLuint program, GLuint shader);
typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void (APIENTRYP PFNGLGETACTIVEATTRIBPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLGETATTACHEDSHADERSPROC) (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
typedef GLint (APIENTRYP PFNGLGETATTRIBLOCATIONPROC) (GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLGETPROGRAMIVPROC) (GLuint program, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETPROGRAMINFOLOGPROC) (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFNGLGETSHADERIVPROC) (GLuint shader, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETSHADERINFOLOGPROC) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFNGLGETSHADERSOURCEPROC) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
typedef GLint (APIENTRYP PFNGLGETUNIFORMLOCATIONPROC) (GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLGETUNIFORMFVPROC) (GLuint program, GLint location, GLfloat *params);
typedef void (APIENTRYP PFNGLGETUNIFORMIVPROC) (GLuint program, GLint location, GLint *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVPROC) (GLuint index, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVPROC) (GLuint index, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVPROC) (GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC) (GLuint index, GLenum pname, void **pointer);
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPROC) (GLuint program);
typedef GLboolean (APIENTRYP PFNGLISSHADERPROC) (GLuint shader);
typedef void (APIENTRYP PFNGLLINKPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLSHADERSOURCEPROC) (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
typedef void (APIENTRYP PFNGLUSEPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLUNIFORM1FPROC) (GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLUNIFORM2FPROC) (GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLUNIFORM3FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLUNIFORM4FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLUNIFORM1IPROC) (GLint location, GLint v0);
typedef void (APIENTRYP PFNGLUNIFORM2IPROC) (GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLUNIFORM3IPROC) (GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLUNIFORM4IPROC) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLUNIFORM1FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM2FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM3FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM4FVPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM1IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM2IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM3IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM4IVPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DPROC) (GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FPROC) (GLuint index, GLfloat x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SPROC) (GLuint index, GLshort x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DPROC) (GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FPROC) (GLuint index, GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SPROC) (GLuint index, GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SPROC) (GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NBVPROC) (GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NIVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NSVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBPROC) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBVPROC) (GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUSVPROC) (GLuint index, const GLushort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4BVPROC) (GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4IVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SPROC) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVPROC) (GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4USVPROC) (GLuint index, const GLushort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBlendEquationSeparate (GLenum modeRGB, GLenum modeAlpha);
GLAPI void APIENTRY glDrawBuffers (GLsizei n, const GLenum *bufs);
GLAPI void APIENTRY glStencilOpSeparate (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
GLAPI void APIENTRY glStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask);
GLAPI void APIENTRY glStencilMaskSeparate (GLenum face, GLuint mask);
GLAPI void APIENTRY glAttachShader (GLuint program, GLuint shader);
GLAPI void APIENTRY glBindAttribLocation (GLuint program, GLuint index, const GLchar *name);
GLAPI void APIENTRY glCompileShader (GLuint shader);
GLAPI GLuint APIENTRY glCreateProgram (void);
GLAPI GLuint APIENTRY glCreateShader (GLenum type);
GLAPI void APIENTRY glDeleteProgram (GLuint program);
GLAPI void APIENTRY glDeleteShader (GLuint shader);
GLAPI void APIENTRY glDetachShader (GLuint program, GLuint shader);
GLAPI void APIENTRY glDisableVertexAttribArray (GLuint index);
GLAPI void APIENTRY glEnableVertexAttribArray (GLuint index);
GLAPI void APIENTRY glGetActiveAttrib (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GLAPI void APIENTRY glGetActiveUniform (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GLAPI void APIENTRY glGetAttachedShaders (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
GLAPI GLint APIENTRY glGetAttribLocation (GLuint program, const GLchar *name);
GLAPI void APIENTRY glGetProgramiv (GLuint program, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetProgramInfoLog (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLAPI void APIENTRY glGetShaderiv (GLuint shader, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetShaderInfoLog (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLAPI void APIENTRY glGetShaderSource (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
GLAPI GLint APIENTRY glGetUniformLocation (GLuint program, const GLchar *name);
GLAPI void APIENTRY glGetUniformfv (GLuint program, GLint location, GLfloat *params);
GLAPI void APIENTRY glGetUniformiv (GLuint program, GLint location, GLint *params);
GLAPI void APIENTRY glGetVertexAttribdv (GLuint index, GLenum pname, GLdouble *params);
GLAPI void APIENTRY glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetVertexAttribiv (GLuint index, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetVertexAttribPointerv (GLuint index, GLenum pname, void **pointer);
GLAPI GLboolean APIENTRY glIsProgram (GLuint program);
GLAPI GLboolean APIENTRY glIsShader (GLuint shader);
GLAPI void APIENTRY glLinkProgram (GLuint program);
GLAPI void APIENTRY glShaderSource (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
GLAPI void APIENTRY glUseProgram (GLuint program);
GLAPI void APIENTRY glUniform1f (GLint location, GLfloat v0);
GLAPI void APIENTRY glUniform2f (GLint location, GLfloat v0, GLfloat v1);
GLAPI void APIENTRY glUniform3f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI void APIENTRY glUniform4f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI void APIENTRY glUniform1i (GLint location, GLint v0);
GLAPI void APIENTRY glUniform2i (GLint location, GLint v0, GLint v1);
GLAPI void APIENTRY glUniform3i (GLint location, GLint v0, GLint v1, GLint v2);
GLAPI void APIENTRY glUniform4i (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI void APIENTRY glUniform1fv (GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glUniform2fv (GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glUniform3fv (GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glUniform4fv (GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glUniform1iv (GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glUniform2iv (GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glUniform3iv (GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glUniform4iv (GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glUniformMatrix2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glValidateProgram (GLuint program);
GLAPI void APIENTRY glVertexAttrib1d (GLuint index, GLdouble x);
GLAPI void APIENTRY glVertexAttrib1dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttrib1f (GLuint index, GLfloat x);
GLAPI void APIENTRY glVertexAttrib1fv (GLuint index, const GLfloat *v);
GLAPI void APIENTRY glVertexAttrib1s (GLuint index, GLshort x);
GLAPI void APIENTRY glVertexAttrib1sv (GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttrib2d (GLuint index, GLdouble x, GLdouble y);
GLAPI void APIENTRY glVertexAttrib2dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttrib2f (GLuint index, GLfloat x, GLfloat y);
GLAPI void APIENTRY glVertexAttrib2fv (GLuint index, const GLfloat *v);
GLAPI void APIENTRY glVertexAttrib2s (GLuint index, GLshort x, GLshort y);
GLAPI void APIENTRY glVertexAttrib2sv (GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttrib3d (GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glVertexAttrib3dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttrib3f (GLuint index, GLfloat x, GLfloat y, GLfloat z);
GLAPI void APIENTRY glVertexAttrib3fv (GLuint index, const GLfloat *v);
GLAPI void APIENTRY glVertexAttrib3s (GLuint index, GLshort x, GLshort y, GLshort z);
GLAPI void APIENTRY glVertexAttrib3sv (GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttrib4Nbv (GLuint index, const GLbyte *v);
GLAPI void APIENTRY glVertexAttrib4Niv (GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttrib4Nsv (GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttrib4Nub (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
GLAPI void APIENTRY glVertexAttrib4Nubv (GLuint index, const GLubyte *v);
GLAPI void APIENTRY glVertexAttrib4Nuiv (GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttrib4Nusv (GLuint index, const GLushort *v);
GLAPI void APIENTRY glVertexAttrib4bv (GLuint index, const GLbyte *v);
GLAPI void APIENTRY glVertexAttrib4d (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void APIENTRY glVertexAttrib4dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttrib4f (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void APIENTRY glVertexAttrib4fv (GLuint index, const GLfloat *v);
GLAPI void APIENTRY glVertexAttrib4iv (GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttrib4s (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
GLAPI void APIENTRY glVertexAttrib4sv (GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttrib4ubv (GLuint index, const GLubyte *v);
GLAPI void APIENTRY glVertexAttrib4uiv (GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttrib4usv (GLuint index, const GLushort *v);
GLAPI void APIENTRY glVertexAttribPointer (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
#endif
#endif /* GL_VERSION_2_0 */

#ifndef GL_VERSION_2_1
#define GL_VERSION_2_1 1
#define GL_PIXEL_PACK_BUFFER              0x88EB
#define GL_PIXEL_UNPACK_BUFFER            0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING      0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING    0x88EF
#define GL_FLOAT_MAT2x3                   0x8B65
#define GL_FLOAT_MAT2x4                   0x8B66
#define GL_FLOAT_MAT3x2                   0x8B67
#define GL_FLOAT_MAT3x4                   0x8B68
#define GL_FLOAT_MAT4x2                   0x8B69
#define GL_FLOAT_MAT4x3                   0x8B6A
#define GL_SRGB                           0x8C40
#define GL_SRGB8                          0x8C41
#define GL_SRGB_ALPHA                     0x8C42
#define GL_SRGB8_ALPHA8                   0x8C43
#define GL_COMPRESSED_SRGB                0x8C48
#define GL_COMPRESSED_SRGB_ALPHA          0x8C49
#define GL_CURRENT_RASTER_SECONDARY_COLOR 0x845F
#define GL_SLUMINANCE_ALPHA               0x8C44
#define GL_SLUMINANCE8_ALPHA8             0x8C45
#define GL_SLUMINANCE                     0x8C46
#define GL_SLUMINANCE8                    0x8C47
#define GL_COMPRESSED_SLUMINANCE          0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA    0x8C4B
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glUniformMatrix2x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix3x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix2x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix4x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix3x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glUniformMatrix4x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
#endif
#endif /* GL_VERSION_2_1 */

#ifndef GL_VERSION_3_0
#define GL_VERSION_3_0 1
typedef khronos_uint16_t GLhalf;
#define GL_COMPARE_REF_TO_TEXTURE         0x884E
#define GL_CLIP_DISTANCE0                 0x3000
#define GL_CLIP_DISTANCE1                 0x3001
#define GL_CLIP_DISTANCE2                 0x3002
#define GL_CLIP_DISTANCE3                 0x3003
#define GL_CLIP_DISTANCE4                 0x3004
#define GL_CLIP_DISTANCE5                 0x3005
#define GL_CLIP_DISTANCE6                 0x3006
#define GL_CLIP_DISTANCE7                 0x3007
#define GL_MAX_CLIP_DISTANCES             0x0D32
#define GL_MAJOR_VERSION                  0x821B
#define GL_MINOR_VERSION                  0x821C
#define GL_NUM_EXTENSIONS                 0x821D
#define GL_CONTEXT_FLAGS                  0x821E
#define GL_COMPRESSED_RED                 0x8225
#define GL_COMPRESSED_RG                  0x8226
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x00000001
#define GL_RGBA32F                        0x8814
#define GL_RGB32F                         0x8815
#define GL_RGBA16F                        0x881A
#define GL_RGB16F                         0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER    0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS       0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET       0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET       0x8905
#define GL_CLAMP_READ_COLOR               0x891C
#define GL_FIXED_ONLY                     0x891D
#define GL_MAX_VARYING_COMPONENTS         0x8B4B
#define GL_TEXTURE_1D_ARRAY               0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY         0x8C19
#define GL_TEXTURE_2D_ARRAY               0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY         0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY       0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY       0x8C1D
#define GL_R11F_G11F_B10F                 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV   0x8C3B
#define GL_RGB9_E5                        0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV       0x8C3E
#define GL_TEXTURE_SHARED_SIZE            0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS    0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_PRIMITIVES_GENERATED           0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_RASTERIZER_DISCARD             0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS            0x8C8C
#define GL_SEPARATE_ATTRIBS               0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER      0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_RGBA32UI                       0x8D70
#define GL_RGB32UI                        0x8D71
#define GL_RGBA16UI                       0x8D76
#define GL_RGB16UI                        0x8D77
#define GL_RGBA8UI                        0x8D7C
#define GL_RGB8UI                         0x8D7D
#define GL_RGBA32I                        0x8D82
#define GL_RGB32I                         0x8D83
#define GL_RGBA16I                        0x8D88
#define GL_RGB16I                         0x8D89
#define GL_RGBA8I                         0x8D8E
#define GL_RGB8I                          0x8D8F
#define GL_RED_INTEGER                    0x8D94
#define GL_GREEN_INTEGER                  0x8D95
#define GL_BLUE_INTEGER                   0x8D96
#define GL_RGB_INTEGER                    0x8D98
#define GL_RGBA_INTEGER                   0x8D99
#define GL_BGR_INTEGER                    0x8D9A
#define GL_BGRA_INTEGER                   0x8D9B
#define GL_SAMPLER_1D_ARRAY               0x8DC0
#define GL_SAMPLER_2D_ARRAY               0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW        0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW        0x8DC4
#define GL_SAMPLER_CUBE_SHADOW            0x8DC5
#define GL_UNSIGNED_INT_VEC2              0x8DC6
#define GL_UNSIGNED_INT_VEC3              0x8DC7
#define GL_UNSIGNED_INT_VEC4              0x8DC8
#define GL_INT_SAMPLER_1D                 0x8DC9
#define GL_INT_SAMPLER_2D                 0x8DCA
#define GL_INT_SAMPLER_3D                 0x8DCB
#define GL_INT_SAMPLER_CUBE               0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY           0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY           0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D        0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D        0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D        0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE      0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY  0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY  0x8DD7
#define GL_QUERY_WAIT                     0x8E13
#define GL_QUERY_NO_WAIT                  0x8E14
#define GL_QUERY_BY_REGION_WAIT           0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT        0x8E16
#define GL_BUFFER_ACCESS_FLAGS            0x911F
#define GL_BUFFER_MAP_LENGTH              0x9120
#define GL_BUFFER_MAP_OFFSET              0x9121
#define GL_DEPTH_COMPONENT32F             0x8CAC
#define GL_DEPTH32F_STENCIL8              0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
#define GL_INVALID_FRAMEBUFFER_OPERATION  0x0506
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_FRAMEBUFFER_DEFAULT            0x8218
#define GL_FRAMEBUFFER_UNDEFINED          0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT       0x821A
#define GL_MAX_RENDERBUFFER_SIZE          0x84E8
#define GL_DEPTH_STENCIL                  0x84F9
#define GL_UNSIGNED_INT_24_8              0x84FA
#define GL_DEPTH24_STENCIL8               0x88F0
#define GL_TEXTURE_STENCIL_SIZE           0x88F1
#define GL_TEXTURE_RED_TYPE               0x8C10
#define GL_TEXTURE_GREEN_TYPE             0x8C11
#define GL_TEXTURE_BLUE_TYPE              0x8C12
#define GL_TEXTURE_ALPHA_TYPE             0x8C13
#define GL_TEXTURE_DEPTH_TYPE             0x8C16
#define GL_UNSIGNED_NORMALIZED            0x8C17
#define GL_FRAMEBUFFER_BINDING            0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING       0x8CA6
#define GL_RENDERBUFFER_BINDING           0x8CA7
#define GL_READ_FRAMEBUFFER               0x8CA8
#define GL_DRAW_FRAMEBUFFER               0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING       0x8CAA
#define GL_RENDERBUFFER_SAMPLES           0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE           0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED        0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS          0x8CDF
#define GL_COLOR_ATTACHMENT0              0x8CE0
#define GL_COLOR_ATTACHMENT1              0x8CE1
#define GL_COLOR_ATTACHMENT2              0x8CE2
#define GL_COLOR_ATTACHMENT3              0x8CE3
#define GL_COLOR_ATTACHMENT4              0x8CE4
#define GL_COLOR_ATTACHMENT5              0x8CE5
#define GL_COLOR_ATTACHMENT6              0x8CE6
#define GL_COLOR_ATTACHMENT7              0x8CE7
#define GL_COLOR_ATTACHMENT8              0x8CE8
#define GL_COLOR_ATTACHMENT9              0x8CE9
#define GL_COLOR_ATTACHMENT10             0x8CEA
#define GL_COLOR_ATTACHMENT11             0x8CEB
#define GL_COLOR_ATTACHMENT12             0x8CEC
#define GL_COLOR_ATTACHMENT13             0x8CED
#define GL_COLOR_ATTACHMENT14             0x8CEE
#define GL_COLOR_ATTACHMENT15             0x8CEF
#define GL_COLOR_ATTACHMENT16             0x8CF0
#define GL_COLOR_ATTACHMENT17             0x8CF1
#define GL_COLOR_ATTACHMENT18             0x8CF2
#define GL_COLOR_ATTACHMENT19             0x8CF3
#define GL_COLOR_ATTACHMENT20             0x8CF4
#define GL_COLOR_ATTACHMENT21             0x8CF5
#define GL_COLOR_ATTACHMENT22             0x8CF6
#define GL_COLOR_ATTACHMENT23             0x8CF7
#define GL_COLOR_ATTACHMENT24             0x8CF8
#define GL_COLOR_ATTACHMENT25             0x8CF9
#define GL_COLOR_ATTACHMENT26             0x8CFA
#define GL_COLOR_ATTACHMENT27             0x8CFB
#define GL_COLOR_ATTACHMENT28             0x8CFC
#define GL_COLOR_ATTACHMENT29             0x8CFD
#define GL_COLOR_ATTACHMENT30             0x8CFE
#define GL_COLOR_ATTACHMENT31             0x8CFF
#define GL_DEPTH_ATTACHMENT               0x8D00
#define GL_STENCIL_ATTACHMENT             0x8D20
#define GL_FRAMEBUFFER                    0x8D40
#define GL_RENDERBUFFER                   0x8D41
#define GL_RENDERBUFFER_WIDTH             0x8D42
#define GL_RENDERBUFFER_HEIGHT            0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT   0x8D44
#define GL_STENCIL_INDEX1                 0x8D46
#define GL_STENCIL_INDEX4                 0x8D47
#define GL_STENCIL_INDEX8                 0x8D48
#define GL_STENCIL_INDEX16                0x8D49
#define GL_RENDERBUFFER_RED_SIZE          0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE        0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE         0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE        0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE        0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE      0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_MAX_SAMPLES                    0x8D57
#define GL_INDEX                          0x8222
#define GL_TEXTURE_LUMINANCE_TYPE         0x8C14
#define GL_TEXTURE_INTENSITY_TYPE         0x8C15
#define GL_FRAMEBUFFER_SRGB               0x8DB9
#define GL_HALF_FLOAT                     0x140B
#define GL_MAP_READ_BIT                   0x0001
#define GL_MAP_WRITE_BIT                  0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT       0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT      0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT         0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT         0x0020
#define GL_COMPRESSED_RED_RGTC1           0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1    0x8DBC
#define GL_COMPRESSED_RG_RGTC2            0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2     0x8DBE
#define GL_RG                             0x8227
#define GL_RG_INTEGER                     0x8228
#define GL_R8                             0x8229
#define GL_R16                            0x822A
#define GL_RG8                            0x822B
#define GL_RG16                           0x822C
#define GL_R16F                           0x822D
#define GL_R32F                           0x822E
#define GL_RG16F                          0x822F
#define GL_RG32F                          0x8230
#define GL_R8I                            0x8231
#define GL_R8UI                           0x8232
#define GL_R16I                           0x8233
#define GL_R16UI                          0x8234
#define GL_R32I                           0x8235
#define GL_R32UI                          0x8236
#define GL_RG8I                           0x8237
#define GL_RG8UI                          0x8238
#define GL_RG16I                          0x8239
#define GL_RG16UI                         0x823A
#define GL_RG32I                          0x823B
#define GL_RG32UI                         0x823C
#define GL_VERTEX_ARRAY_BINDING           0x85B5
#define GL_CLAMP_VERTEX_COLOR             0x891A
#define GL_CLAMP_FRAGMENT_COLOR           0x891B
#define GL_ALPHA_INTEGER                  0x8D97
typedef void (APIENTRYP PFNGLCOLORMASKIPROC) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
typedef void (APIENTRYP PFNGLGETBOOLEANI_VPROC) (GLenum target, GLuint index, GLboolean *data);
typedef void (APIENTRYP PFNGLGETINTEGERI_VPROC) (GLenum target, GLuint index, GLint *data);
typedef void (APIENTRYP PFNGLENABLEIPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLDISABLEIPROC) (GLenum target, GLuint index);
typedef GLboolean (APIENTRYP PFNGLISENABLEDIPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKPROC) (GLenum primitiveMode);
typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKPROC) (void);
typedef void (APIENTRYP PFNGLBINDBUFFERRANGEPROC) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLBINDBUFFERBASEPROC) (GLenum target, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSPROC) (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLCLAMPCOLORPROC) (GLenum target, GLenum clamp);
typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERPROC) (GLuint id, GLenum mode);
typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERPROC) (void);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIPOINTERPROC) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIIVPROC) (GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIUIVPROC) (GLuint index, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IPROC) (GLuint index, GLint x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IPROC) (GLuint index, GLint x, GLint y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IPROC) (GLuint index, GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IPROC) (GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIPROC) (GLuint index, GLuint x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIPROC) (GLuint index, GLuint x, GLuint y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIPROC) (GLuint index, GLuint x, GLuint y, GLuint z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIPROC) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIVPROC) (GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4BVPROC) (GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4SVPROC) (GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UBVPROC) (GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4USVPROC) (GLuint index, const GLushort *v);
typedef void (APIENTRYP PFNGLGETUNIFORMUIVPROC) (GLuint program, GLint location, GLuint *params);
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONPROC) (GLuint program, GLuint color, const GLchar *name);
typedef GLint (APIENTRYP PFNGLGETFRAGDATALOCATIONPROC) (GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLUNIFORM1UIPROC) (GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLUNIFORM2UIPROC) (GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLUNIFORM3UIPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLUNIFORM4UIPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLUNIFORM1UIVPROC) (GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLUNIFORM2UIVPROC) (GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLUNIFORM3UIVPROC) (GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLUNIFORM4UIVPROC) (GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLTEXPARAMETERIIVPROC) (GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXPARAMETERIUIVPROC) (GLenum target, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIUIVPROC) (GLenum target, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLCLEARBUFFERIVPROC) (GLenum buffer, GLint drawbuffer, const GLint *value);
typedef void (APIENTRYP PFNGLCLEARBUFFERUIVPROC) (GLenum buffer, GLint drawbuffer, const GLuint *value);
typedef void (APIENTRYP PFNGLCLEARBUFFERFVPROC) (GLenum buffer, GLint drawbuffer, const GLfloat *value);
typedef void (APIENTRYP PFNGLCLEARBUFFERFIPROC) (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef const GLubyte *(APIENTRYP PFNGLGETSTRINGIPROC) (GLenum name, GLuint index);
typedef GLboolean (APIENTRYP PFNGLISRENDERBUFFERPROC) (GLuint renderbuffer);
typedef void (APIENTRYP PFNGLBINDRENDERBUFFERPROC) (GLenum target, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSPROC) (GLsizei n, const GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLGENRENDERBUFFERSPROC) (GLsizei n, GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef GLboolean (APIENTRYP PFNGLISFRAMEBUFFERPROC) (GLuint framebuffer);
typedef void (APIENTRYP PFNGLBINDFRAMEBUFFERPROC) (GLenum target, GLuint framebuffer);
typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC) (GLsizei n, const GLuint *framebuffers);
typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSPROC) (GLsizei n, GLuint *framebuffers);
typedef GLenum (APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC) (GLenum target);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC) (GLenum target, GLenum attachment, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGENERATEMIPMAPPROC) (GLenum target);
typedef void (APIENTRYP PFNGLBLITFRAMEBUFFERPROC) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void *(APIENTRYP PFNGLMAPBUFFERRANGEPROC) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef void (APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC) (GLenum target, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLBINDVERTEXARRAYPROC) (GLuint array);
typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSPROC) (GLsizei n, const GLuint *arrays);
typedef void (APIENTRYP PFNGLGENVERTEXARRAYSPROC) (GLsizei n, GLuint *arrays);
typedef GLboolean (APIENTRYP PFNGLISVERTEXARRAYPROC) (GLuint array);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glColorMaski (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
GLAPI void APIENTRY glGetBooleani_v (GLenum target, GLuint index, GLboolean *data);
GLAPI void APIENTRY glGetIntegeri_v (GLenum target, GLuint index, GLint *data);
GLAPI void APIENTRY glEnablei (GLenum target, GLuint index);
GLAPI void APIENTRY glDisablei (GLenum target, GLuint index);
GLAPI GLboolean APIENTRY glIsEnabledi (GLenum target, GLuint index);
GLAPI void APIENTRY glBeginTransformFeedback (GLenum primitiveMode);
GLAPI void APIENTRY glEndTransformFeedback (void);
GLAPI void APIENTRY glBindBufferRange (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void APIENTRY glBindBufferBase (GLenum target, GLuint index, GLuint buffer);
GLAPI void APIENTRY glTransformFeedbackVaryings (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
GLAPI void APIENTRY glGetTransformFeedbackVarying (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
GLAPI void APIENTRY glClampColor (GLenum target, GLenum clamp);
GLAPI void APIENTRY glBeginConditionalRender (GLuint id, GLenum mode);
GLAPI void APIENTRY glEndConditionalRender (void);
GLAPI void APIENTRY glVertexAttribIPointer (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI void APIENTRY glGetVertexAttribIiv (GLuint index, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetVertexAttribIuiv (GLuint index, GLenum pname, GLuint *params);
GLAPI void APIENTRY glVertexAttribI1i (GLuint index, GLint x);
GLAPI void APIENTRY glVertexAttribI2i (GLuint index, GLint x, GLint y);
GLAPI void APIENTRY glVertexAttribI3i (GLuint index, GLint x, GLint y, GLint z);
GLAPI void APIENTRY glVertexAttribI4i (GLuint index, GLint x, GLint y, GLint z, GLint w);
GLAPI void APIENTRY glVertexAttribI1ui (GLuint index, GLuint x);
GLAPI void APIENTRY glVertexAttribI2ui (GLuint index, GLuint x, GLuint y);
GLAPI void APIENTRY glVertexAttribI3ui (GLuint index, GLuint x, GLuint y, GLuint z);
GLAPI void APIENTRY glVertexAttribI4ui (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLAPI void APIENTRY glVertexAttribI1iv (GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttribI2iv (GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttribI3iv (GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttribI4iv (GLuint index, const GLint *v);
GLAPI void APIENTRY glVertexAttribI1uiv (GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttribI2uiv (GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttribI3uiv (GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttribI4uiv (GLuint index, const GLuint *v);
GLAPI void APIENTRY glVertexAttribI4bv (GLuint index, const GLbyte *v);
GLAPI void APIENTRY glVertexAttribI4sv (GLuint index, const GLshort *v);
GLAPI void APIENTRY glVertexAttribI4ubv (GLuint index, const GLubyte *v);
GLAPI void APIENTRY glVertexAttribI4usv (GLuint index, const GLushort *v);
GLAPI void APIENTRY glGetUniformuiv (GLuint program, GLint location, GLuint *params);
GLAPI void APIENTRY glBindFragDataLocation (GLuint program, GLuint color, const GLchar *name);
GLAPI GLint APIENTRY glGetFragDataLocation (GLuint program, const GLchar *name);
GLAPI void APIENTRY glUniform1ui (GLint location, GLuint v0);
GLAPI void APIENTRY glUniform2ui (GLint location, GLuint v0, GLuint v1);
GLAPI void APIENTRY glUniform3ui (GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI void APIENTRY glUniform4ui (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI void APIENTRY glUniform1uiv (GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glUniform2uiv (GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glUniform3uiv (GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glUniform4uiv (GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glTexParameterIiv (GLenum target, GLenum pname, const GLint *params);
GLAPI void APIENTRY glTexParameterIuiv (GLenum target, GLenum pname, const GLuint *params);
GLAPI void APIENTRY glGetTexParameterIiv (GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetTexParameterIuiv (GLenum target, GLenum pname, GLuint *params);
GLAPI void APIENTRY glClearBufferiv (GLenum buffer, GLint drawbuffer, const GLint *value);
GLAPI void APIENTRY glClearBufferuiv (GLenum buffer, GLint drawbuffer, const GLuint *value);
GLAPI void APIENTRY glClearBufferfv (GLenum buffer, GLint drawbuffer, const GLfloat *value);
GLAPI void APIENTRY glClearBufferfi (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
GLAPI const GLubyte *APIENTRY glGetStringi (GLenum name, GLuint index);
GLAPI GLboolean APIENTRY glIsRenderbuffer (GLuint renderbuffer);
GLAPI void APIENTRY glBindRenderbuffer (GLenum target, GLuint renderbuffer);
GLAPI void APIENTRY glDeleteRenderbuffers (GLsizei n, const GLuint *renderbuffers);
GLAPI void APIENTRY glGenRenderbuffers (GLsizei n, GLuint *renderbuffers);
GLAPI void APIENTRY glRenderbufferStorage (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glGetRenderbufferParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI GLboolean APIENTRY glIsFramebuffer (GLuint framebuffer);
GLAPI void APIENTRY glBindFramebuffer (GLenum target, GLuint framebuffer);
GLAPI void APIENTRY glDeleteFramebuffers (GLsizei n, const GLuint *framebuffers);
GLAPI void APIENTRY glGenFramebuffers (GLsizei n, GLuint *framebuffers);
GLAPI GLenum APIENTRY glCheckFramebufferStatus (GLenum target);
GLAPI void APIENTRY glFramebufferTexture1D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void APIENTRY glFramebufferTexture2D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLAPI void APIENTRY glFramebufferTexture3D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
GLAPI void APIENTRY glFramebufferRenderbuffer (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI void APIENTRY glGetFramebufferAttachmentParameteriv (GLenum target, GLenum attachment, GLenum pname, GLint *params);
GLAPI void APIENTRY glGenerateMipmap (GLenum target);
GLAPI void APIENTRY glBlitFramebuffer (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLAPI void APIENTRY glRenderbufferStorageMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glFramebufferTextureLayer (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void *APIENTRY glMapBufferRange (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLAPI void APIENTRY glFlushMappedBufferRange (GLenum target, GLintptr offset, GLsizeiptr length);
GLAPI void APIENTRY glBindVertexArray (GLuint array);
GLAPI void APIENTRY glDeleteVertexArrays (GLsizei n, const GLuint *arrays);
GLAPI void APIENTRY glGenVertexArrays (GLsizei n, GLuint *arrays);
GLAPI GLboolean APIENTRY glIsVertexArray (GLuint array);
#endif
#endif /* GL_VERSION_3_0 */

#ifndef GL_VERSION_3_1
#define GL_VERSION_3_1 1
#define GL_SAMPLER_2D_RECT                0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW         0x8B64
#define GL_SAMPLER_BUFFER                 0x8DC2
#define GL_INT_SAMPLER_2D_RECT            0x8DCD
#define GL_INT_SAMPLER_BUFFER             0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT   0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER    0x8DD8
#define GL_TEXTURE_BUFFER                 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE        0x8C2B
#define GL_TEXTURE_BINDING_BUFFER         0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_TEXTURE_RECTANGLE              0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE      0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE        0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE     0x84F8
#define GL_R8_SNORM                       0x8F94
#define GL_RG8_SNORM                      0x8F95
#define GL_RGB8_SNORM                     0x8F96
#define GL_RGBA8_SNORM                    0x8F97
#define GL_R16_SNORM                      0x8F98
#define GL_RG16_SNORM                     0x8F99
#define GL_RGB16_SNORM                    0x8F9A
#define GL_RGBA16_SNORM                   0x8F9B
#define GL_SIGNED_NORMALIZED              0x8F9C
#define GL_PRIMITIVE_RESTART              0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX        0x8F9E
#define GL_COPY_READ_BUFFER               0x8F36
#define GL_COPY_WRITE_BUFFER              0x8F37
#define GL_UNIFORM_BUFFER                 0x8A11
#define GL_UNIFORM_BUFFER_BINDING         0x8A28
#define GL_UNIFORM_BUFFER_START           0x8A29
#define GL_UNIFORM_BUFFER_SIZE            0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS      0x8A2B
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS    0x8A2C
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS    0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS    0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS    0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE         0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS          0x8A36
#define GL_UNIFORM_TYPE                   0x8A37
#define GL_UNIFORM_SIZE                   0x8A38
#define GL_UNIFORM_NAME_LENGTH            0x8A39
#define GL_UNIFORM_BLOCK_INDEX            0x8A3A
#define GL_UNIFORM_OFFSET                 0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE           0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE          0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR           0x8A3E
#define GL_UNIFORM_BLOCK_BINDING          0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE        0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH      0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS  0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_INVALID_INDEX                  0xFFFFFFFFu
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDPROC) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
typedef void (APIENTRYP PFNGLTEXBUFFERPROC) (GLenum target, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLPRIMITIVERESTARTINDEXPROC) (GLuint index);
typedef void (APIENTRYP PFNGLCOPYBUFFERSUBDATAPROC) (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLGETUNIFORMINDICESPROC) (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC) (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC) (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
typedef GLuint (APIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC) (GLuint program, const GLchar *uniformBlockName);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
typedef void (APIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawArraysInstanced (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
GLAPI void APIENTRY glDrawElementsInstanced (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
GLAPI void APIENTRY glTexBuffer (GLenum target, GLenum internalformat, GLuint buffer);
GLAPI void APIENTRY glPrimitiveRestartIndex (GLuint index);
GLAPI void APIENTRY glCopyBufferSubData (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLAPI void APIENTRY glGetUniformIndices (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
GLAPI void APIENTRY glGetActiveUniformsiv (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetActiveUniformName (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
GLAPI GLuint APIENTRY glGetUniformBlockIndex (GLuint program, const GLchar *uniformBlockName);
GLAPI void APIENTRY glGetActiveUniformBlockiv (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetActiveUniformBlockName (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
GLAPI void APIENTRY glUniformBlockBinding (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
#endif
#endif /* GL_VERSION_3_1 */

#ifndef GL_VERSION_3_2
#define GL_VERSION_3_2 1
typedef struct __GLsync *GLsync;
typedef khronos_uint64_t GLuint64;
typedef khronos_int64_t GLint64;
#define GL_CONTEXT_CORE_PROFILE_BIT       0x00000001
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define GL_LINES_ADJACENCY                0x000A
#define GL_LINE_STRIP_ADJACENCY           0x000B
#define GL_TRIANGLES_ADJACENCY            0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY       0x000D
#define GL_PROGRAM_POINT_SIZE             0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_GEOMETRY_SHADER                0x8DD9
#define GL_GEOMETRY_VERTICES_OUT          0x8916
#define GL_GEOMETRY_INPUT_TYPE            0x8917
#define GL_GEOMETRY_OUTPUT_TYPE           0x8918
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES   0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS   0x9122
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS  0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS  0x9125
#define GL_CONTEXT_PROFILE_MASK           0x9126
#define GL_DEPTH_CLAMP                    0x864F
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION        0x8E4D
#define GL_LAST_VERTEX_CONVENTION         0x8E4E
#define GL_PROVOKING_VERTEX               0x8E4F
#define GL_TEXTURE_CUBE_MAP_SEAMLESS      0x884F
#define GL_MAX_SERVER_WAIT_TIMEOUT        0x9111
#define GL_OBJECT_TYPE                    0x9112
#define GL_SYNC_CONDITION                 0x9113
#define GL_SYNC_STATUS                    0x9114
#define GL_SYNC_FLAGS                     0x9115
#define GL_SYNC_FENCE                     0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE     0x9117
#define GL_UNSIGNALED                     0x9118
#define GL_SIGNALED                       0x9119
#define GL_ALREADY_SIGNALED               0x911A
#define GL_TIMEOUT_EXPIRED                0x911B
#define GL_CONDITION_SATISFIED            0x911C
#define GL_WAIT_FAILED                    0x911D
#define GL_TIMEOUT_IGNORED                0xFFFFFFFFFFFFFFFFull
#define GL_SYNC_FLUSH_COMMANDS_BIT        0x00000001
#define GL_SAMPLE_POSITION                0x8E50
#define GL_SAMPLE_MASK                    0x8E51
#define GL_SAMPLE_MASK_VALUE              0x8E52
#define GL_MAX_SAMPLE_MASK_WORDS          0x8E59
#define GL_TEXTURE_2D_MULTISAMPLE         0x9100
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE   0x9101
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY   0x9102
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_TEXTURE_SAMPLES                0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_SAMPLER_2D_MULTISAMPLE         0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE     0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY   0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
#define GL_MAX_COLOR_TEXTURE_SAMPLES      0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES      0x910F
#define GL_MAX_INTEGER_SAMPLES            0x9110
typedef void (APIENTRYP PFNGLDRAWELEMENTSBASEVERTEXPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
typedef void (APIENTRYP PFNGLPROVOKINGVERTEXPROC) (GLenum mode);
typedef GLsync (APIENTRYP PFNGLFENCESYNCPROC) (GLenum condition, GLbitfield flags);
typedef GLboolean (APIENTRYP PFNGLISSYNCPROC) (GLsync sync);
typedef void (APIENTRYP PFNGLDELETESYNCPROC) (GLsync sync);
typedef GLenum (APIENTRYP PFNGLCLIENTWAITSYNCPROC) (GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (APIENTRYP PFNGLWAITSYNCPROC) (GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (APIENTRYP PFNGLGETINTEGER64VPROC) (GLenum pname, GLint64 *data);
typedef void (APIENTRYP PFNGLGETSYNCIVPROC) (GLsync sync, GLenum pname, GLsizei count, GLsizei *length, GLint *values);
typedef void (APIENTRYP PFNGLGETINTEGER64I_VPROC) (GLenum target, GLuint index, GLint64 *data);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERI64VPROC) (GLenum target, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVPROC) (GLenum pname, GLuint index, GLfloat *val);
typedef void (APIENTRYP PFNGLSAMPLEMASKIPROC) (GLuint maskNumber, GLbitfield mask);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawElementsBaseVertex (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
GLAPI void APIENTRY glDrawRangeElementsBaseVertex (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
GLAPI void APIENTRY glDrawElementsInstancedBaseVertex (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
GLAPI void APIENTRY glMultiDrawElementsBaseVertex (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
GLAPI void APIENTRY glProvokingVertex (GLenum mode);
GLAPI GLsync APIENTRY glFenceSync (GLenum condition, GLbitfield flags);
GLAPI GLboolean APIENTRY glIsSync (GLsync sync);
GLAPI void APIENTRY glDeleteSync (GLsync sync);
GLAPI GLenum APIENTRY glClientWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout);
GLAPI void APIENTRY glWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout);
GLAPI void APIENTRY glGetInteger64v (GLenum pname, GLint64 *data);
GLAPI void APIENTRY glGetSynciv (GLsync sync, GLenum pname, GLsizei count, GLsizei *length, GLint *values);
GLAPI void APIENTRY glGetInteger64i_v (GLenum target, GLuint index, GLint64 *data);
GLAPI void APIENTRY glGetBufferParameteri64v (GLenum target, GLenum pname, GLint64 *params);
GLAPI void APIENTRY glFramebufferTexture (GLenum target, GLenum attachment, GLuint texture, GLint level);
GLAPI void APIENTRY glTexImage2DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTexImage3DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glGetMultisamplefv (GLenum pname, GLuint index, GLfloat *val);
GLAPI void APIENTRY glSampleMaski (GLuint maskNumber, GLbitfield mask);
#endif
#endif /* GL_VERSION_3_2 */

#ifndef GL_VERSION_3_3
#define GL_VERSION_3_3 1
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR    0x88FE
#define GL_SRC1_COLOR                     0x88F9
#define GL_ONE_MINUS_SRC1_COLOR           0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA           0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS   0x88FC
#define GL_ANY_SAMPLES_PASSED             0x8C2F
#define GL_SAMPLER_BINDING                0x8919
#define GL_RGB10_A2UI                     0x906F
#define GL_TEXTURE_SWIZZLE_R              0x8E42
#define GL_TEXTURE_SWIZZLE_G              0x8E43
#define GL_TEXTURE_SWIZZLE_B              0x8E44
#define GL_TEXTURE_SWIZZLE_A              0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA           0x8E46
#define GL_TIME_ELAPSED                   0x88BF
#define GL_TIMESTAMP                      0x8E28
#define GL_INT_2_10_10_10_REV             0x8D9F
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONINDEXEDPROC) (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
typedef GLint (APIENTRYP PFNGLGETFRAGDATAINDEXPROC) (GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLGENSAMPLERSPROC) (GLsizei count, GLuint *samplers);
typedef void (APIENTRYP PFNGLDELETESAMPLERSPROC) (GLsizei count, const GLuint *samplers);
typedef GLboolean (APIENTRYP PFNGLISSAMPLERPROC) (GLuint sampler);
typedef void (APIENTRYP PFNGLBINDSAMPLERPROC) (GLuint unit, GLuint sampler);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIPROC) (GLuint sampler, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIVPROC) (GLuint sampler, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFPROC) (GLuint sampler, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFVPROC) (GLuint sampler, GLenum pname, const GLfloat *param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC) (GLuint sampler, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC) (GLuint sampler, GLenum pname, const GLuint *param);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC) (GLuint sampler, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC) (GLuint sampler, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC) (GLuint sampler, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC) (GLuint sampler, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLQUERYCOUNTERPROC) (GLuint id, GLenum target);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTI64VPROC) (GLuint id, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUI64VPROC) (GLuint id, GLenum pname, GLuint64 *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBDIVISORPROC) (GLuint index, GLuint divisor);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFNGLVERTEXP2UIPROC) (GLenum type, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXP2UIVPROC) (GLenum type, const GLuint *value);
typedef void (APIENTRYP PFNGLVERTEXP3UIPROC) (GLenum type, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXP3UIVPROC) (GLenum type, const GLuint *value);
typedef void (APIENTRYP PFNGLVERTEXP4UIPROC) (GLenum type, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXP4UIVPROC) (GLenum type, const GLuint *value);
typedef void (APIENTRYP PFNGLTEXCOORDP1UIPROC) (GLenum type, GLuint coords);
typedef void (APIENTRYP PFNGLTEXCOORDP1UIVPROC) (GLenum type, const GLuint *coords);
typedef void (APIENTRYP PFNGLTEXCOORDP2UIPROC) (GLenum type, GLuint coords);
typedef void (APIENTRYP PFNGLTEXCOORDP2UIVPROC) (GLenum type, const GLuint *coords);
typedef void (APIENTRYP PFNGLTEXCOORDP3UIPROC) (GLenum type, GLuint coords);
typedef void (APIENTRYP PFNGLTEXCOORDP3UIVPROC) (GLenum type, const GLuint *coords);
typedef void (APIENTRYP PFNGLTEXCOORDP4UIPROC) (GLenum type, GLuint coords);
typedef void (APIENTRYP PFNGLTEXCOORDP4UIVPROC) (GLenum type, const GLuint *coords);
typedef void (APIENTRYP PFNGLMULTITEXCOORDP1UIPROC) (GLenum texture, GLenum type, GLuint coords);
typedef void (APIENTRYP PFNGLMULTITEXCOORDP1UIVPROC) (GLenum texture, GLenum type, const GLuint *coords);
typedef void (APIENTRYP PFNGLMULTITEXCOORDP2UIPROC) (GLenum texture, GLenum type, GLuint coords);
typedef void (APIENTRYP PFNGLMULTITEXCOORDP2UIVPROC) (GLenum texture, GLenum type, const GLuint *coords);
typedef void (APIENTRYP PFNGLMULTITEXCOORDP3UIPROC) (GLenum texture, GLenum type, GLuint coords);
typedef void (APIENTRYP PFNGLMULTITEXCOORDP3UIVPROC) (GLenum texture, GLenum type, const GLuint *coords);
typedef void (APIENTRYP PFNGLMULTITEXCOORDP4UIPROC) (GLenum texture, GLenum type, GLuint coords);
typedef void (APIENTRYP PFNGLMULTITEXCOORDP4UIVPROC) (GLenum texture, GLenum type, const GLuint *coords);
typedef void (APIENTRYP PFNGLNORMALP3UIPROC) (GLenum type, GLuint coords);
typedef void (APIENTRYP PFNGLNORMALP3UIVPROC) (GLenum type, const GLuint *coords);
typedef void (APIENTRYP PFNGLCOLORP3UIPROC) (GLenum type, GLuint color);
typedef void (APIENTRYP PFNGLCOLORP3UIVPROC) (GLenum type, const GLuint *color);
typedef void (APIENTRYP PFNGLCOLORP4UIPROC) (GLenum type, GLuint color);
typedef void (APIENTRYP PFNGLCOLORP4UIVPROC) (GLenum type, const GLuint *color);
typedef void (APIENTRYP PFNGLSECONDARYCOLORP3UIPROC) (GLenum type, GLuint color);
typedef void (APIENTRYP PFNGLSECONDARYCOLORP3UIVPROC) (GLenum type, const GLuint *color);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBindFragDataLocationIndexed (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
GLAPI GLint APIENTRY glGetFragDataIndex (GLuint program, const GLchar *name);
GLAPI void APIENTRY glGenSamplers (GLsizei count, GLuint *samplers);
GLAPI void APIENTRY glDeleteSamplers (GLsizei count, const GLuint *samplers);
GLAPI GLboolean APIENTRY glIsSampler (GLuint sampler);
GLAPI void APIENTRY glBindSampler (GLuint unit, GLuint sampler);
GLAPI void APIENTRY glSamplerParameteri (GLuint sampler, GLenum pname, GLint param);
GLAPI void APIENTRY glSamplerParameteriv (GLuint sampler, GLenum pname, const GLint *param);
GLAPI void APIENTRY glSamplerParameterf (GLuint sampler, GLenum pname, GLfloat param);
GLAPI void APIENTRY glSamplerParameterfv (GLuint sampler, GLenum pname, const GLfloat *param);
GLAPI void APIENTRY glSamplerParameterIiv (GLuint sampler, GLenum pname, const GLint *param);
GLAPI void APIENTRY glSamplerParameterIuiv (GLuint sampler, GLenum pname, const GLuint *param);
GLAPI void APIENTRY glGetSamplerParameteriv (GLuint sampler, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetSamplerParameterIiv (GLuint sampler, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetSamplerParameterfv (GLuint sampler, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetSamplerParameterIuiv (GLuint sampler, GLenum pname, GLuint *params);
GLAPI void APIENTRY glQueryCounter (GLuint id, GLenum target);
GLAPI void APIENTRY glGetQueryObjecti64v (GLuint id, GLenum pname, GLint64 *params);
GLAPI void APIENTRY glGetQueryObjectui64v (GLuint id, GLenum pname, GLuint64 *params);
GLAPI void APIENTRY glVertexAttribDivisor (GLuint index, GLuint divisor);
GLAPI void APIENTRY glVertexAttribP1ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void APIENTRY glVertexAttribP1uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLAPI void APIENTRY glVertexAttribP2ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void APIENTRY glVertexAttribP2uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLAPI void APIENTRY glVertexAttribP3ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void APIENTRY glVertexAttribP3uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLAPI void APIENTRY glVertexAttribP4ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLAPI void APIENTRY glVertexAttribP4uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLAPI void APIENTRY glVertexP2ui (GLenum type, GLuint value);
GLAPI void APIENTRY glVertexP2uiv (GLenum type, const GLuint *value);
GLAPI void APIENTRY glVertexP3ui (GLenum type, GLuint value);
GLAPI void APIENTRY glVertexP3uiv (GLenum type, const GLuint *value);
GLAPI void APIENTRY glVertexP4ui (GLenum type, GLuint value);
GLAPI void APIENTRY glVertexP4uiv (GLenum type, const GLuint *value);
GLAPI void APIENTRY glTexCoordP1ui (GLenum type, GLuint coords);
GLAPI void APIENTRY glTexCoordP1uiv (GLenum type, const GLuint *coords);
GLAPI void APIENTRY glTexCoordP2ui (GLenum type, GLuint coords);
GLAPI void APIENTRY glTexCoordP2uiv (GLenum type, const GLuint *coords);
GLAPI void APIENTRY glTexCoordP3ui (GLenum type, GLuint coords);
GLAPI void APIENTRY glTexCoordP3uiv (GLenum type, const GLuint *coords);
GLAPI void APIENTRY glTexCoordP4ui (GLenum type, GLuint coords);
GLAPI void APIENTRY glTexCoordP4uiv (GLenum type, const GLuint *coords);
GLAPI void APIENTRY glMultiTexCoordP1ui (GLenum texture, GLenum type, GLuint coords);
GLAPI void APIENTRY glMultiTexCoordP1uiv (GLenum texture, GLenum type, const GLuint *coords);
GLAPI void APIENTRY glMultiTexCoordP2ui (GLenum texture, GLenum type, GLuint coords);
GLAPI void APIENTRY glMultiTexCoordP2uiv (GLenum texture, GLenum type, const GLuint *coords);
GLAPI void APIENTRY glMultiTexCoordP3ui (GLenum texture, GLenum type, GLuint coords);
GLAPI void APIENTRY glMultiTexCoordP3uiv (GLenum texture, GLenum type, const GLuint *coords);
GLAPI void APIENTRY glMultiTexCoordP4ui (GLenum texture, GLenum type, GLuint coords);
GLAPI void APIENTRY glMultiTexCoordP4uiv (GLenum texture, GLenum type, const GLuint *coords);
GLAPI void APIENTRY glNormalP3ui (GLenum type, GLuint coords);
GLAPI void APIENTRY glNormalP3uiv (GLenum type, const GLuint *coords);
GLAPI void APIENTRY glColorP3ui (GLenum type, GLuint color);
GLAPI void APIENTRY glColorP3uiv (GLenum type, const GLuint *color);
GLAPI void APIENTRY glColorP4ui (GLenum type, GLuint color);
GLAPI void APIENTRY glColorP4uiv (GLenum type, const GLuint *color);
GLAPI void APIENTRY glSecondaryColorP3ui (GLenum type, GLuint color);
GLAPI void APIENTRY glSecondaryColorP3uiv (GLenum type, const GLuint *color);
#endif
#endif /* GL_VERSION_3_3 */

#ifndef GL_VERSION_4_0
#define GL_VERSION_4_0 1
#define GL_SAMPLE_SHADING                 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE       0x8C37
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
#define GL_TEXTURE_CUBE_MAP_ARRAY         0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY   0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY         0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW  0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY     0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F
#define GL_DRAW_INDIRECT_BUFFER           0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING   0x8F43
#define GL_GEOMETRY_SHADER_INVOCATIONS    0x887F
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
#define GL_MAX_VERTEX_STREAMS             0x8E71
#define GL_DOUBLE_VEC2                    0x8FFC
#define GL_DOUBLE_VEC3                    0x8FFD
#define GL_DOUBLE_VEC4                    0x8FFE
#define GL_DOUBLE_MAT2                    0x8F46
#define GL_DOUBLE_MAT3                    0x8F47
#define GL_DOUBLE_MAT4                    0x8F48
#define GL_DOUBLE_MAT2x3                  0x8F49
#define GL_DOUBLE_MAT2x4                  0x8F4A
#define GL_DOUBLE_MAT3x2                  0x8F4B
#define GL_DOUBLE_MAT3x4                  0x8F4C
#define GL_DOUBLE_MAT4x2                  0x8F4D
#define GL_DOUBLE_MAT4x3                  0x8F4E
#define GL_ACTIVE_SUBROUTINES             0x8DE5
#define GL_ACTIVE_SUBROUTINE_UNIFORMS     0x8DE6
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH   0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
#define GL_MAX_SUBROUTINES                0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
#define GL_NUM_COMPATIBLE_SUBROUTINES     0x8E4A
#define GL_COMPATIBLE_SUBROUTINES         0x8E4B
#define GL_PATCHES                        0x000E
#define GL_PATCH_VERTICES                 0x8E72
#define GL_PATCH_DEFAULT_INNER_LEVEL      0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL      0x8E74
#define GL_TESS_CONTROL_OUTPUT_VERTICES   0x8E75
#define GL_TESS_GEN_MODE                  0x8E76
#define GL_TESS_GEN_SPACING               0x8E77
#define GL_TESS_GEN_VERTEX_ORDER          0x8E78
#define GL_TESS_GEN_POINT_MODE            0x8E79
#define GL_ISOLINES                       0x8E7A
#define GL_FRACTIONAL_ODD                 0x8E7B
#define GL_FRACTIONAL_EVEN                0x8E7C
#define GL_MAX_PATCH_VERTICES             0x8E7D
#define GL_MAX_TESS_GEN_LEVEL             0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS      0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
#define GL_TESS_EVALUATION_SHADER         0x8E87
#define GL_TESS_CONTROL_SHADER            0x8E88
#define GL_TRANSFORM_FEEDBACK             0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING     0x8E25
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
typedef void (APIENTRYP PFNGLMINSAMPLESHADINGPROC) (GLfloat value);
typedef void (APIENTRYP PFNGLBLENDEQUATIONIPROC) (GLuint buf, GLenum mode);
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIPROC) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLBLENDFUNCIPROC) (GLuint buf, GLenum src, GLenum dst);
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIPROC) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
typedef void (APIENTRYP PFNGLDRAWARRAYSINDIRECTPROC) (GLenum mode, const void *indirect);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC) (GLenum mode, GLenum type, const void *indirect);
typedef void (APIENTRYP PFNGLUNIFORM1DPROC) (GLint location, GLdouble x);
typedef void (APIENTRYP PFNGLUNIFORM2DPROC) (GLint location, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLUNIFORM3DPROC) (GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLUNIFORM4DPROC) (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLUNIFORM1DVPROC) (GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORM2DVPROC) (GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORM3DVPROC) (GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORM4DVPROC) (GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLGETUNIFORMDVPROC) (GLuint program, GLint location, GLdouble *params);
typedef GLint (APIENTRYP PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC) (GLuint program, GLenum shadertype, const GLchar *name);
typedef GLuint (APIENTRYP PFNGLGETSUBROUTINEINDEXPROC) (GLuint program, GLenum shadertype, const GLchar *name);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC) (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINENAMEPROC) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
typedef void (APIENTRYP PFNGLUNIFORMSUBROUTINESUIVPROC) (GLenum shadertype, GLsizei count, const GLuint *indices);
typedef void (APIENTRYP PFNGLGETUNIFORMSUBROUTINEUIVPROC) (GLenum shadertype, GLint location, GLuint *params);
typedef void (APIENTRYP PFNGLGETPROGRAMSTAGEIVPROC) (GLuint program, GLenum shadertype, GLenum pname, GLint *values);
typedef void (APIENTRYP PFNGLPATCHPARAMETERIPROC) (GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLPATCHPARAMETERFVPROC) (GLenum pname, const GLfloat *values);
typedef void (APIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC) (GLenum target, GLuint id);
typedef void (APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC) (GLsizei n, const GLuint *ids);
typedef void (APIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC) (GLsizei n, GLuint *ids);
typedef GLboolean (APIENTRYP PFNGLISTRANSFORMFEEDBACKPROC) (GLuint id);
typedef void (APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC) (void);
typedef void (APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC) (void);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKPROC) (GLenum mode, GLuint id);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC) (GLenum mode, GLuint id, GLuint stream);
typedef void (APIENTRYP PFNGLBEGINQUERYINDEXEDPROC) (GLenum target, GLuint index, GLuint id);
typedef void (APIENTRYP PFNGLENDQUERYINDEXEDPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLGETQUERYINDEXEDIVPROC) (GLenum target, GLuint index, GLenum pname, GLint *params);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glMinSampleShading (GLfloat value);
GLAPI void APIENTRY glBlendEquationi (GLuint buf, GLenum mode);
GLAPI void APIENTRY glBlendEquationSeparatei (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLAPI void APIENTRY glBlendFunci (GLuint buf, GLenum src, GLenum dst);
GLAPI void APIENTRY glBlendFuncSeparatei (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
GLAPI void APIENTRY glDrawArraysIndirect (GLenum mode, const void *indirect);
GLAPI void APIENTRY glDrawElementsIndirect (GLenum mode, GLenum type, const void *indirect);
GLAPI void APIENTRY glUniform1d (GLint location, GLdouble x);
GLAPI void APIENTRY glUniform2d (GLint location, GLdouble x, GLdouble y);
GLAPI void APIENTRY glUniform3d (GLint location, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glUniform4d (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void APIENTRY glUniform1dv (GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glUniform2dv (GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glUniform3dv (GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glUniform4dv (GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix2dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix3dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix4dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix2x3dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix2x4dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix3x2dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix3x4dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix4x2dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glUniformMatrix4x3dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glGetUniformdv (GLuint program, GLint location, GLdouble *params);
GLAPI GLint APIENTRY glGetSubroutineUniformLocation (GLuint program, GLenum shadertype, const GLchar *name);
GLAPI GLuint APIENTRY glGetSubroutineIndex (GLuint program, GLenum shadertype, const GLchar *name);
GLAPI void APIENTRY glGetActiveSubroutineUniformiv (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
GLAPI void APIENTRY glGetActiveSubroutineUniformName (GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
GLAPI void APIENTRY glGetActiveSubroutineName (GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
GLAPI void APIENTRY glUniformSubroutinesuiv (GLenum shadertype, GLsizei count, const GLuint *indices);
GLAPI void APIENTRY glGetUniformSubroutineuiv (GLenum shadertype, GLint location, GLuint *params);
GLAPI void APIENTRY glGetProgramStageiv (GLuint program, GLenum shadertype, GLenum pname, GLint *values);
GLAPI void APIENTRY glPatchParameteri (GLenum pname, GLint value);
GLAPI void APIENTRY glPatchParameterfv (GLenum pname, const GLfloat *values);
GLAPI void APIENTRY glBindTransformFeedback (GLenum target, GLuint id);
GLAPI void APIENTRY glDeleteTransformFeedbacks (GLsizei n, const GLuint *ids);
GLAPI void APIENTRY glGenTransformFeedbacks (GLsizei n, GLuint *ids);
GLAPI GLboolean APIENTRY glIsTransformFeedback (GLuint id);
GLAPI void APIENTRY glPauseTransformFeedback (void);
GLAPI void APIENTRY glResumeTransformFeedback (void);
GLAPI void APIENTRY glDrawTransformFeedback (GLenum mode, GLuint id);
GLAPI void APIENTRY glDrawTransformFeedbackStream (GLenum mode, GLuint id, GLuint stream);
GLAPI void APIENTRY glBeginQueryIndexed (GLenum target, GLuint index, GLuint id);
GLAPI void APIENTRY glEndQueryIndexed (GLenum target, GLuint index);
GLAPI void APIENTRY glGetQueryIndexediv (GLenum target, GLuint index, GLenum pname, GLint *params);
#endif
#endif /* GL_VERSION_4_0 */

#ifndef GL_VERSION_4_1
#define GL_VERSION_4_1 1
#define GL_FIXED                          0x140C
#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#define GL_LOW_FLOAT                      0x8DF0
#define GL_MEDIUM_FLOAT                   0x8DF1
#define GL_HIGH_FLOAT                     0x8DF2
#define GL_LOW_INT                        0x8DF3
#define GL_MEDIUM_INT                     0x8DF4
#define GL_HIGH_INT                       0x8DF5
#define GL_SHADER_COMPILER                0x8DFA
#define GL_SHADER_BINARY_FORMATS          0x8DF8
#define GL_NUM_SHADER_BINARY_FORMATS      0x8DF9
#define GL_MAX_VERTEX_UNIFORM_VECTORS     0x8DFB
#define GL_MAX_VARYING_VECTORS            0x8DFC
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS   0x8DFD
#define GL_RGB565                         0x8D62
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
#define GL_PROGRAM_BINARY_LENGTH          0x8741
#define GL_NUM_PROGRAM_BINARY_FORMATS     0x87FE
#define GL_PROGRAM_BINARY_FORMATS         0x87FF
#define GL_VERTEX_SHADER_BIT              0x00000001
#define GL_FRAGMENT_SHADER_BIT            0x00000002
#define GL_GEOMETRY_SHADER_BIT            0x00000004
#define GL_TESS_CONTROL_SHADER_BIT        0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT     0x00000010
#define GL_ALL_SHADER_BITS                0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE              0x8258
#define GL_ACTIVE_PROGRAM                 0x8259
#define GL_PROGRAM_PIPELINE_BINDING       0x825A
#define GL_MAX_VIEWPORTS                  0x825B
#define GL_VIEWPORT_SUBPIXEL_BITS         0x825C
#define GL_VIEWPORT_BOUNDS_RANGE          0x825D
#define GL_LAYER_PROVOKING_VERTEX         0x825E
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX 0x825F
#define GL_UNDEFINED_VERTEX               0x8260
typedef void (APIENTRYP PFNGLRELEASESHADERCOMPILERPROC) (void);
typedef void (APIENTRYP PFNGLSHADERBINARYPROC) (GLsizei count, const GLuint *shaders, GLenum binaryFormat, const void *binary, GLsizei length);
typedef void (APIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC) (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
typedef void (APIENTRYP PFNGLDEPTHRANGEFPROC) (GLfloat n, GLfloat f);
typedef void (APIENTRYP PFNGLCLEARDEPTHFPROC) (GLfloat d);
typedef void (APIENTRYP PFNGLGETPROGRAMBINARYPROC) (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
typedef void (APIENTRYP PFNGLPROGRAMBINARYPROC) (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIPROC) (GLuint program, GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLUSEPROGRAMSTAGESPROC) (GLuint pipeline, GLbitfield stages, GLuint program);
typedef void (APIENTRYP PFNGLACTIVESHADERPROGRAMPROC) (GLuint pipeline, GLuint program);
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROGRAMVPROC) (GLenum type, GLsizei count, const GLchar *const*strings);
typedef void (APIENTRYP PFNGLBINDPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (APIENTRYP PFNGLDELETEPROGRAMPIPELINESPROC) (GLsizei n, const GLuint *pipelines);
typedef void (APIENTRYP PFNGLGENPROGRAMPIPELINESPROC) (GLsizei n, GLuint *pipelines);
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEIVPROC) (GLuint pipeline, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IPROC) (GLuint program, GLint location, GLint v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FPROC) (GLuint program, GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DPROC) (GLuint program, GLint location, GLdouble v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIPROC) (GLuint program, GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IPROC) (GLuint program, GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGPROC) (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DPROC) (GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DPROC) (GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DVPROC) (GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBLPOINTERPROC) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLDVPROC) (GLuint index, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLVIEWPORTARRAYVPROC) (GLuint first, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFVPROC) (GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLSCISSORARRAYVPROC) (GLuint first, GLsizei count, const GLint *v);
typedef void (APIENTRYP PFNGLSCISSORINDEXEDPROC) (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLSCISSORINDEXEDVPROC) (GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLDEPTHRANGEARRAYVPROC) (GLuint first, GLsizei count, const GLdouble *v);
typedef void (APIENTRYP PFNGLDEPTHRANGEINDEXEDPROC) (GLuint index, GLdouble n, GLdouble f);
typedef void (APIENTRYP PFNGLGETFLOATI_VPROC) (GLenum target, GLuint index, GLfloat *data);
typedef void (APIENTRYP PFNGLGETDOUBLEI_VPROC) (GLenum target, GLuint index, GLdouble *data);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glReleaseShaderCompiler (void);
GLAPI void APIENTRY glShaderBinary (GLsizei count, const GLuint *shaders, GLenum binaryFormat, const void *binary, GLsizei length);
GLAPI void APIENTRY glGetShaderPrecisionFormat (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
GLAPI void APIENTRY glDepthRangef (GLfloat n, GLfloat f);
GLAPI void APIENTRY glClearDepthf (GLfloat d);
GLAPI void APIENTRY glGetProgramBinary (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
GLAPI void APIENTRY glProgramBinary (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
GLAPI void APIENTRY glProgramParameteri (GLuint program, GLenum pname, GLint value);
GLAPI void APIENTRY glUseProgramStages (GLuint pipeline, GLbitfield stages, GLuint program);
GLAPI void APIENTRY glActiveShaderProgram (GLuint pipeline, GLuint program);
GLAPI GLuint APIENTRY glCreateShaderProgramv (GLenum type, GLsizei count, const GLchar *const*strings);
GLAPI void APIENTRY glBindProgramPipeline (GLuint pipeline);
GLAPI void APIENTRY glDeleteProgramPipelines (GLsizei n, const GLuint *pipelines);
GLAPI void APIENTRY glGenProgramPipelines (GLsizei n, GLuint *pipelines);
GLAPI GLboolean APIENTRY glIsProgramPipeline (GLuint pipeline);
GLAPI void APIENTRY glGetProgramPipelineiv (GLuint pipeline, GLenum pname, GLint *params);
GLAPI void APIENTRY glProgramUniform1i (GLuint program, GLint location, GLint v0);
GLAPI void APIENTRY glProgramUniform1iv (GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glProgramUniform1f (GLuint program, GLint location, GLfloat v0);
GLAPI void APIENTRY glProgramUniform1fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glProgramUniform1d (GLuint program, GLint location, GLdouble v0);
GLAPI void APIENTRY glProgramUniform1dv (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glProgramUniform1ui (GLuint program, GLint location, GLuint v0);
GLAPI void APIENTRY glProgramUniform1uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glProgramUniform2i (GLuint program, GLint location, GLint v0, GLint v1);
GLAPI void APIENTRY glProgramUniform2iv (GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glProgramUniform2f (GLuint program, GLint location, GLfloat v0, GLfloat v1);
GLAPI void APIENTRY glProgramUniform2fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glProgramUniform2d (GLuint program, GLint location, GLdouble v0, GLdouble v1);
GLAPI void APIENTRY glProgramUniform2dv (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glProgramUniform2ui (GLuint program, GLint location, GLuint v0, GLuint v1);
GLAPI void APIENTRY glProgramUniform2uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glProgramUniform3i (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
GLAPI void APIENTRY glProgramUniform3iv (GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glProgramUniform3f (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLAPI void APIENTRY glProgramUniform3fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glProgramUniform3d (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
GLAPI void APIENTRY glProgramUniform3dv (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glProgramUniform3ui (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
GLAPI void APIENTRY glProgramUniform3uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glProgramUniform4i (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLAPI void APIENTRY glProgramUniform4iv (GLuint program, GLint location, GLsizei count, const GLint *value);
GLAPI void APIENTRY glProgramUniform4f (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI void APIENTRY glProgramUniform4fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLAPI void APIENTRY glProgramUniform4d (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
GLAPI void APIENTRY glProgramUniform4dv (GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLAPI void APIENTRY glProgramUniform4ui (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLAPI void APIENTRY glProgramUniform4uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
GLAPI void APIENTRY glProgramUniformMatrix2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix2dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix3dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix4dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix2x3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix3x2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix2x4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix4x2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix3x4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix4x3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLAPI void APIENTRY glProgramUniformMatrix2x3dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix3x2dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix2x4dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix4x2dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix3x4dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glProgramUniformMatrix4x3dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLAPI void APIENTRY glValidateProgramPipeline (GLuint pipeline);
GLAPI void APIENTRY glGetProgramPipelineInfoLog (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLAPI void APIENTRY glVertexAttribL1d (GLuint index, GLdouble x);
GLAPI void APIENTRY glVertexAttribL2d (GLuint index, GLdouble x, GLdouble y);
GLAPI void APIENTRY glVertexAttribL3d (GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLAPI void APIENTRY glVertexAttribL4d (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void APIENTRY glVertexAttribL1dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttribL2dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttribL3dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttribL4dv (GLuint index, const GLdouble *v);
GLAPI void APIENTRY glVertexAttribLPointer (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLAPI void APIENTRY glGetVertexAttribLdv (GLuint index, GLenum pname, GLdouble *params);
GLAPI void APIENTRY glViewportArrayv (GLuint first, GLsizei count, const GLfloat *v);
GLAPI void APIENTRY glViewportIndexedf (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
GLAPI void APIENTRY glViewportIndexedfv (GLuint index, const GLfloat *v);
GLAPI void APIENTRY glScissorArrayv (GLuint first, GLsizei count, const GLint *v);
GLAPI void APIENTRY glScissorIndexed (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
GLAPI void APIENTRY glScissorIndexedv (GLuint index, const GLint *v);
GLAPI void APIENTRY glDepthRangeArrayv (GLuint first, GLsizei count, const GLdouble *v);
GLAPI void APIENTRY glDepthRangeIndexed (GLuint index, GLdouble n, GLdouble f);
GLAPI void APIENTRY glGetFloati_v (GLenum target, GLuint index, GLfloat *data);
GLAPI void APIENTRY glGetDoublei_v (GLenum target, GLuint index, GLdouble *data);
#endif
#endif /* GL_VERSION_4_1 */

#ifndef GL_VERSION_4_2
#define GL_VERSION_4_2 1
#define GL_COPY_READ_BUFFER_BINDING       0x8F36
#define GL_COPY_WRITE_BUFFER_BINDING      0x8F37
#define GL_TRANSFORM_FEEDBACK_ACTIVE      0x8E24
#define GL_TRANSFORM_FEEDBACK_PAUSED      0x8E23
#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH  0x9127
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT 0x9128
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH  0x9129
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE   0x912A
#define GL_PACK_COMPRESSED_BLOCK_WIDTH    0x912B
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT   0x912C
#define GL_PACK_COMPRESSED_BLOCK_DEPTH    0x912D
#define GL_PACK_COMPRESSED_BLOCK_SIZE     0x912E
#define GL_NUM_SAMPLE_COUNTS              0x9380
#define GL_MIN_MAP_BUFFER_ALIGNMENT       0x90BC
#define GL_ATOMIC_COUNTER_BUFFER          0x92C0
#define GL_ATOMIC_COUNTER_BUFFER_BINDING  0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_START    0x92C2
#define GL_ATOMIC_COUNTER_BUFFER_SIZE     0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
#define GL_MAX_VERTEX_ATOMIC_COUNTERS     0x92D2
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS   0x92D5
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS   0x92D6
#define GL_MAX_COMBINED_ATOMIC_COUNTERS   0x92D7
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS  0x92D9
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA
#define GL_UNSIGNED_INT_ATOMIC_COUNTER    0x92DB
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT      0x00000002
#define GL_UNIFORM_BARRIER_BIT            0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT      0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#define GL_COMMAND_BARRIER_BIT            0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT       0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT     0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT      0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT        0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT     0x00001000
#define GL_ALL_BARRIER_BITS               0xFFFFFFFF
#define GL_MAX_IMAGE_UNITS                0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#define GL_IMAGE_BINDING_NAME             0x8F3A
#define GL_IMAGE_BINDING_LEVEL            0x8F3B
#define GL_IMAGE_BINDING_LAYERED          0x8F3C
#define GL_IMAGE_BINDING_LAYER            0x8F3D
#define GL_IMAGE_BINDING_ACCESS           0x8F3E
#define GL_IMAGE_1D                       0x904C
#define GL_IMAGE_2D                       0x904D
#define GL_IMAGE_3D                       0x904E
#define GL_IMAGE_2D_RECT                  0x904F
#define GL_IMAGE_CUBE                     0x9050
#define GL_IMAGE_BUFFER                   0x9051
#define GL_IMAGE_1D_ARRAY                 0x9052
#define GL_IMAGE_2D_ARRAY                 0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY           0x9054
#define GL_IMAGE_2D_MULTISAMPLE           0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY     0x9056
#define GL_INT_IMAGE_1D                   0x9057
#define GL_INT_IMAGE_2D                   0x9058
#define GL_INT_IMAGE_3D                   0x9059
#define GL_INT_IMAGE_2D_RECT              0x905A
#define GL_INT_IMAGE_CUBE                 0x905B
#define GL_INT_IMAGE_BUFFER               0x905C
#define GL_INT_IMAGE_1D_ARRAY             0x905D
#define GL_INT_IMAGE_2D_ARRAY             0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY       0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE       0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
#define GL_UNSIGNED_INT_IMAGE_1D          0x9062
#define GL_UNSIGNED_INT_IMAGE_2D          0x9063
#define GL_UNSIGNED_INT_IMAGE_3D          0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT     0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE        0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER      0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY    0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY    0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
#define GL_MAX_IMAGE_SAMPLES              0x906D
#define GL_IMAGE_BINDING_FORMAT           0x906E
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#define GL_MAX_VERTEX_IMAGE_UNIFORMS      0x90CA
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS    0x90CD
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS    0x90CE
#define GL_MAX_COMBINED_IMAGE_UNIFORMS    0x90CF
#define GL_COMPRESSED_RGBA_BPTC_UNORM     0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT 0x8E8F
#define GL_TEXTURE_IMMUTABLE_FORMAT       0x912F
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
typedef void (APIENTRYP PFNGLGETINTERNALFORMATIVPROC) (GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint *params);
typedef void (APIENTRYP PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC) (GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLBINDIMAGETEXTUREPROC) (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
typedef void (APIENTRYP PFNGLMEMORYBARRIERPROC) (GLbitfield barriers);
typedef void (APIENTRYP PFNGLTEXSTORAGE1DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLTEXSTORAGE2DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXSTORAGE3DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC) (GLenum mode, GLuint id, GLsizei instancecount);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC) (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawArraysInstancedBaseInstance (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
GLAPI void APIENTRY glDrawElementsInstancedBaseInstance (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
GLAPI void APIENTRY glDrawElementsInstancedBaseVertexBaseInstance (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
GLAPI void APIENTRY glGetInternalformativ (GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint *params);
GLAPI void APIENTRY glGetActiveAtomicCounterBufferiv (GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
GLAPI void APIENTRY glBindImageTexture (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
GLAPI void APIENTRY glMemoryBarrier (GLbitfield barriers);
GLAPI void APIENTRY glTexStorage1D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
GLAPI void APIENTRY glTexStorage2D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTexStorage3D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void APIENTRY glDrawTransformFeedbackInstanced (GLenum mode, GLuint id, GLsizei instancecount);
GLAPI void APIENTRY glDrawTransformFeedbackStreamInstanced (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
#endif
#endif /* GL_VERSION_4_2 */

#ifndef GL_VERSION_4_3
#define GL_VERSION_4_3 1
typedef void (APIENTRY  *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
#define GL_NUM_SHADING_LANGUAGE_VERSIONS  0x82E9
#define GL_VERTEX_ATTRIB_ARRAY_LONG       0x874E
#define GL_COMPRESSED_RGB8_ETC2           0x9274
#define GL_COMPRESSED_SRGB8_ETC2          0x9275
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9276
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9277
#define GL_COMPRESSED_RGBA8_ETC2_EAC      0x9278
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC 0x9279
#define GL_COMPRESSED_R11_EAC             0x9270
#define GL_COMPRESSED_SIGNED_R11_EAC      0x9271
#define GL_COMPRESSED_RG11_EAC            0x9272
#define GL_COMPRESSED_SIGNED_RG11_EAC     0x9273
#define GL_PRIMITIVE_RESTART_FIXED_INDEX  0x8D69
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE 0x8D6A
#define GL_MAX_ELEMENT_INDEX              0x8D6B
#define GL_COMPUTE_SHADER                 0x91B9
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS     0x91BB
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS     0x91BD
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS    0x8265
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266
#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS 0x90EB
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT   0x91BE
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE    0x91BF
#define GL_COMPUTE_WORK_GROUP_SIZE        0x8267
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER 0x90EC
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
#define GL_DISPATCH_INDIRECT_BUFFER       0x90EE
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF
#define GL_COMPUTE_SHADER_BIT             0x00000020
#define GL_DEBUG_OUTPUT_SYNCHRONOUS       0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION        0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM      0x8245
#define GL_DEBUG_SOURCE_API               0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM     0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER   0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY       0x8249
#define GL_DEBUG_SOURCE_APPLICATION       0x824A
#define GL_DEBUG_SOURCE_OTHER             0x824B
#define GL_DEBUG_TYPE_ERROR               0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR  0x824E
#define GL_DEBUG_TYPE_PORTABILITY         0x824F
#define GL_DEBUG_TYPE_PERFORMANCE         0x8250
#define GL_DEBUG_TYPE_OTHER               0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH       0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES      0x9144
#define GL_DEBUG_LOGGED_MESSAGES          0x9145
#define GL_DEBUG_SEVERITY_HIGH            0x9146
#define GL_DEBUG_SEVERITY_MEDIUM          0x9147
#define GL_DEBUG_SEVERITY_LOW             0x9148
#define GL_DEBUG_TYPE_MARKER              0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP          0x8269
#define GL_DEBUG_TYPE_POP_GROUP           0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION    0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH    0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH        0x826D
#define GL_BUFFER                         0x82E0
#define GL_SHADER                         0x82E1
#define GL_PROGRAM                        0x82E2
#define GL_QUERY                          0x82E3
#define GL_PROGRAM_PIPELINE               0x82E4
#define GL_SAMPLER                        0x82E6
#define GL_MAX_LABEL_LENGTH               0x82E8
#define GL_DEBUG_OUTPUT                   0x92E0
#define GL_CONTEXT_FLAG_DEBUG_BIT         0x00000002
#define GL_MAX_UNIFORM_LOCATIONS          0x826E
#define GL_FRAMEBUFFER_DEFAULT_WIDTH      0x9310
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT     0x9311
#define GL_FRAMEBUFFER_DEFAULT_LAYERS     0x9312
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES    0x9313
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314
#define GL_MAX_FRAMEBUFFER_WIDTH          0x9315
#define GL_MAX_FRAMEBUFFER_HEIGHT         0x9316
#define GL_MAX_FRAMEBUFFER_LAYERS         0x9317
#define GL_MAX_FRAMEBUFFER_SAMPLES        0x9318
#define GL_INTERNALFORMAT_SUPPORTED       0x826F
#define GL_INTERNALFORMAT_PREFERRED       0x8270
#define GL_INTERNALFORMAT_RED_SIZE        0x8271
#define GL_INTERNALFORMAT_GREEN_SIZE      0x8272
#define GL_INTERNALFORMAT_BLUE_SIZE       0x8273
#define GL_INTERNALFORMAT_ALPHA_SIZE      0x8274
#define GL_INTERNALFORMAT_DEPTH_SIZE      0x8275
#define GL_INTERNALFORMAT_STENCIL_SIZE    0x8276
#define GL_INTERNALFORMAT_SHARED_SIZE     0x8277
#define GL_INTERNALFORMAT_RED_TYPE        0x8278
#define GL_INTERNALFORMAT_GREEN_TYPE      0x8279
#define GL_INTERNALFORMAT_BLUE_TYPE       0x827A
#define GL_INTERNALFORMAT_ALPHA_TYPE      0x827B
#define GL_INTERNALFORMAT_DEPTH_TYPE      0x827C
#define GL_INTERNALFORMAT_STENCIL_TYPE    0x827D
#define GL_MAX_WIDTH                      0x827E
#define GL_MAX_HEIGHT                     0x827F
#define GL_MAX_DEPTH                      0x8280
#define GL_MAX_LAYERS                     0x8281
#define GL_MAX_COMBINED_DIMENSIONS        0x8282
#define GL_COLOR_COMPONENTS               0x8283
#define GL_DEPTH_COMPONENTS               0x8284
#define GL_STENCIL_COMPONENTS             0x8285
#define GL_COLOR_RENDERABLE               0x8286
#define GL_DEPTH_RENDERABLE               0x8287
#define GL_STENCIL_RENDERABLE             0x8288
#define GL_FRAMEBUFFER_RENDERABLE         0x8289
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED 0x828A
#define GL_FRAMEBUFFER_BLEND              0x828B
#define GL_READ_PIXELS                    0x828C
#define GL_READ_PIXELS_FORMAT             0x828D
#define GL_READ_PIXELS_TYPE               0x828E
#define GL_TEXTURE_IMAGE_FORMAT           0x828F
#define GL_TEXTURE_IMAGE_TYPE             0x8290
#define GL_GET_TEXTURE_IMAGE_FORMAT       0x8291
#define GL_GET_TEXTURE_IMAGE_TYPE         0x8292
#define GL_MIPMAP                         0x8293
#define GL_MANUAL_GENERATE_MIPMAP         0x8294
#define GL_AUTO_GENERATE_MIPMAP           0x8295
#define GL_COLOR_ENCODING                 0x8296
#define GL_SRGB_READ                      0x8297
#define GL_SRGB_WRITE                     0x8298
#define GL_FILTER                         0x829A
#define GL_VERTEX_TEXTURE                 0x829B
#define GL_TESS_CONTROL_TEXTURE           0x829C
#define GL_TESS_EVALUATION_TEXTURE        0x829D
#define GL_GEOMETRY_TEXTURE               0x829E
#define GL_FRAGMENT_TEXTURE               0x829F
#define GL_COMPUTE_TEXTURE                0x82A0
#define GL_TEXTURE_SHADOW                 0x82A1
#define GL_TEXTURE_GATHER                 0x82A2
#define GL_TEXTURE_GATHER_SHADOW          0x82A3
#define GL_SHADER_IMAGE_LOAD              0x82A4
#define GL_SHADER_IMAGE_STORE             0x82A5
#define GL_SHADER_IMAGE_ATOMIC            0x82A6
#define GL_IMAGE_TEXEL_SIZE               0x82A7
#define GL_IMAGE_COMPATIBILITY_CLASS      0x82A8
#define GL_IMAGE_PIXEL_FORMAT             0x82A9
#define GL_IMAGE_PIXEL_TYPE               0x82AA
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST 0x82AC
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST 0x82AD
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE 0x82AE
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE 0x82AF
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH 0x82B1
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT 0x82B2
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE  0x82B3
#define GL_CLEAR_BUFFER                   0x82B4
#define GL_TEXTURE_VIEW                   0x82B5
#define GL_VIEW_COMPATIBILITY_CLASS       0x82B6
#define GL_FULL_SUPPORT                   0x82B7
#define GL_CAVEAT_SUPPORT                 0x82B8
#define GL_IMAGE_CLASS_4_X_32             0x82B9
#define GL_IMAGE_CLASS_2_X_32             0x82BA
#define GL_IMAGE_CLASS_1_X_32             0x82BB
#define GL_IMAGE_CLASS_4_X_16             0x82BC
#define GL_IMAGE_CLASS_2_X_16             0x82BD
#define GL_IMAGE_CLASS_1_X_16             0x82BE
#define GL_IMAGE_CLASS_4_X_8              0x82BF
#define GL_IMAGE_CLASS_2_X_8              0x82C0
#define GL_IMAGE_CLASS_1_X_8              0x82C1
#define GL_IMAGE_CLASS_11_11_10           0x82C2
#define GL_IMAGE_CLASS_10_10_10_2         0x82C3
#define GL_VIEW_CLASS_128_BITS            0x82C4
#define GL_VIEW_CLASS_96_BITS             0x82C5
#define GL_VIEW_CLASS_64_BITS             0x82C6
#define GL_VIEW_CLASS_48_BITS             0x82C7
#define GL_VIEW_CLASS_32_BITS             0x82C8
#define GL_VIEW_CLASS_24_BITS             0x82C9
#define GL_VIEW_CLASS_16_BITS             0x82CA
#define GL_VIEW_CLASS_8_BITS              0x82CB
#define GL_VIEW_CLASS_S3TC_DXT1_RGB       0x82CC
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA      0x82CD
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA      0x82CE
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA      0x82CF
#define GL_VIEW_CLASS_RGTC1_RED           0x82D0
#define GL_VIEW_CLASS_RGTC2_RG            0x82D1
#define GL_VIEW_CLASS_BPTC_UNORM          0x82D2
#define GL_VIEW_CLASS_BPTC_FLOAT          0x82D3
#define GL_UNIFORM                        0x92E1
#define GL_UNIFORM_BLOCK                  0x92E2
#define GL_PROGRAM_INPUT                  0x92E3
#define GL_PROGRAM_OUTPUT                 0x92E4
#define GL_BUFFER_VARIABLE                0x92E5
#define GL_SHADER_STORAGE_BLOCK           0x92E6
#define GL_VERTEX_SUBROUTINE              0x92E8
#define GL_TESS_CONTROL_SUBROUTINE        0x92E9
#define GL_TESS_EVALUATION_SUBROUTINE     0x92EA
#define GL_GEOMETRY_SUBROUTINE            0x92EB
#define GL_FRAGMENT_SUBROUTINE            0x92EC
#define GL_COMPUTE_SUBROUTINE             0x92ED
#define GL_VERTEX_SUBROUTINE_UNIFORM      0x92EE
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM 0x92EF
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM 0x92F0
#define GL_GEOMETRY_SUBROUTINE_UNIFORM    0x92F1
#define GL_FRAGMENT_SUBROUTINE_UNIFORM    0x92F2
#define GL_COMPUTE_SUBROUTINE_UNIFORM     0x92F3
#define GL_TRANSFORM_FEEDBACK_VARYING     0x92F4
#define GL_ACTIVE_RESOURCES               0x92F5
#define GL_MAX_NAME_LENGTH                0x92F6
#define GL_MAX_NUM_ACTIVE_VARIABLES       0x92F7
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES 0x92F8
#define GL_NAME_LENGTH                    0x92F9
#define GL_TYPE                           0x92FA
#define GL_ARRAY_SIZE                     0x92FB
#define GL_OFFSET                         0x92FC
#define GL_BLOCK_INDEX                    0x92FD
#define GL_ARRAY_STRIDE                   0x92FE
#define GL_MATRIX_STRIDE                  0x92FF
#define GL_IS_ROW_MAJOR                   0x9300
#define GL_ATOMIC_COUNTER_BUFFER_INDEX    0x9301
#define GL_BUFFER_BINDING                 0x9302
#define GL_BUFFER_DATA_SIZE               0x9303
#define GL_NUM_ACTIVE_VARIABLES           0x9304
#define GL_ACTIVE_VARIABLES               0x9305
#define GL_REFERENCED_BY_VERTEX_SHADER    0x9306
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER 0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER 0x9308
#define GL_REFERENCED_BY_GEOMETRY_SHADER  0x9309
#define GL_REFERENCED_BY_FRAGMENT_SHADER  0x930A
#define GL_REFERENCED_BY_COMPUTE_SHADER   0x930B
#define GL_TOP_LEVEL_ARRAY_SIZE           0x930C
#define GL_TOP_LEVEL_ARRAY_STRIDE         0x930D
#define GL_LOCATION                       0x930E
#define GL_LOCATION_INDEX                 0x930F
#define GL_IS_PER_PATCH                   0x92E7
#define GL_SHADER_STORAGE_BUFFER          0x90D2
#define GL_SHADER_STORAGE_BUFFER_BINDING  0x90D3
#define GL_SHADER_STORAGE_BUFFER_START    0x90D4
#define GL_SHADER_STORAGE_BUFFER_SIZE     0x90D5
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE  0x90DE
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF
#define GL_SHADER_STORAGE_BARRIER_BIT     0x00002000
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39
#define GL_DEPTH_STENCIL_TEXTURE_MODE     0x90EA
#define GL_TEXTURE_BUFFER_OFFSET          0x919D
#define GL_TEXTURE_BUFFER_SIZE            0x919E
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT 0x919F
#define GL_TEXTURE_VIEW_MIN_LEVEL         0x82DB
#define GL_TEXTURE_VIEW_NUM_LEVELS        0x82DC
#define GL_TEXTURE_VIEW_MIN_LAYER         0x82DD
#define GL_TEXTURE_VIEW_NUM_LAYERS        0x82DE
#define GL_TEXTURE_IMMUTABLE_LEVELS       0x82DF
#define GL_VERTEX_ATTRIB_BINDING          0x82D4
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET  0x82D5
#define GL_VERTEX_BINDING_DIVISOR         0x82D6
#define GL_VERTEX_BINDING_OFFSET          0x82D7
#define GL_VERTEX_BINDING_STRIDE          0x82D8
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D9
#define GL_MAX_VERTEX_ATTRIB_BINDINGS     0x82DA
#define GL_VERTEX_BINDING_BUFFER          0x8F4F
#define GL_DISPLAY_LIST                   0x82E7
typedef void (APIENTRYP PFNGLCLEARBUFFERDATAPROC) (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLCLEARBUFFERSUBDATAPROC) (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEPROC) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEINDIRECTPROC) (GLintptr indirect);
typedef void (APIENTRYP PFNGLCOPYIMAGESUBDATAPROC) (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
typedef void (APIENTRYP PFNGLFRAMEBUFFERPARAMETERIPROC) (GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETINTERNALFORMATI64VPROC) (GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 *params);
typedef void (APIENTRYP PFNGLINVALIDATETEXSUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLINVALIDATETEXIMAGEPROC) (GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERDATAPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLINVALIDATEFRAMEBUFFERPROC) (GLenum target, GLsizei numAttachments, const GLenum *attachments);
typedef void (APIENTRYP PFNGLINVALIDATESUBFRAMEBUFFERPROC) (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTPROC) (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTPROC) (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLGETPROGRAMINTERFACEIVPROC) (GLuint program, GLenum programInterface, GLenum pname, GLint *params);
typedef GLuint (APIENTRYP PFNGLGETPROGRAMRESOURCEINDEXPROC) (GLuint program, GLenum programInterface, const GLchar *name);
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCENAMEPROC) (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEIVPROC) (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei count, GLsizei *length, GLint *params);
typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONPROC) (GLuint program, GLenum programInterface, const GLchar *name);
typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC) (GLuint program, GLenum programInterface, const GLchar *name);
typedef void (APIENTRYP PFNGLSHADERSTORAGEBLOCKBINDINGPROC) (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
typedef void (APIENTRYP PFNGLTEXBUFFERRANGEPROC) (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTUREVIEWPROC) (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERPROC) (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBLFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBBINDINGPROC) (GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFNGLVERTEXBINDINGDIVISORPROC) (GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLPROC) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTPROC) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKPROC) (GLDEBUGPROC callback, const void *userParam);
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGPROC) (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
typedef void (APIENTRYP PFNGLPUSHDEBUGGROUPPROC) (GLenum source, GLuint id, GLsizei length, const GLchar *message);
typedef void (APIENTRYP PFNGLPOPDEBUGGROUPPROC) (void);
typedef void (APIENTRYP PFNGLOBJECTLABELPROC) (GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
typedef void (APIENTRYP PFNGLGETOBJECTLABELPROC) (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
typedef void (APIENTRYP PFNGLOBJECTPTRLABELPROC) (const void *ptr, GLsizei length, const GLchar *label);
typedef void (APIENTRYP PFNGLGETOBJECTPTRLABELPROC) (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glClearBufferData (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glClearBufferSubData (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glDispatchCompute (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
GLAPI void APIENTRY glDispatchComputeIndirect (GLintptr indirect);
GLAPI void APIENTRY glCopyImageSubData (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
GLAPI void APIENTRY glFramebufferParameteri (GLenum target, GLenum pname, GLint param);
GLAPI void APIENTRY glGetFramebufferParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetInternalformati64v (GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 *params);
GLAPI void APIENTRY glInvalidateTexSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void APIENTRY glInvalidateTexImage (GLuint texture, GLint level);
GLAPI void APIENTRY glInvalidateBufferSubData (GLuint buffer, GLintptr offset, GLsizeiptr length);
GLAPI void APIENTRY glInvalidateBufferData (GLuint buffer);
GLAPI void APIENTRY glInvalidateFramebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments);
GLAPI void APIENTRY glInvalidateSubFramebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glMultiDrawArraysIndirect (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
GLAPI void APIENTRY glMultiDrawElementsIndirect (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
GLAPI void APIENTRY glGetProgramInterfaceiv (GLuint program, GLenum programInterface, GLenum pname, GLint *params);
GLAPI GLuint APIENTRY glGetProgramResourceIndex (GLuint program, GLenum programInterface, const GLchar *name);
GLAPI void APIENTRY glGetProgramResourceName (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
GLAPI void APIENTRY glGetProgramResourceiv (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei count, GLsizei *length, GLint *params);
GLAPI GLint APIENTRY glGetProgramResourceLocation (GLuint program, GLenum programInterface, const GLchar *name);
GLAPI GLint APIENTRY glGetProgramResourceLocationIndex (GLuint program, GLenum programInterface, const GLchar *name);
GLAPI void APIENTRY glShaderStorageBlockBinding (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
GLAPI void APIENTRY glTexBufferRange (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void APIENTRY glTexStorage2DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTexStorage3DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTextureView (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
GLAPI void APIENTRY glBindVertexBuffer (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI void APIENTRY glVertexAttribFormat (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLAPI void APIENTRY glVertexAttribIFormat (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexAttribLFormat (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexAttribBinding (GLuint attribindex, GLuint bindingindex);
GLAPI void APIENTRY glVertexBindingDivisor (GLuint bindingindex, GLuint divisor);
GLAPI void APIENTRY glDebugMessageControl (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
GLAPI void APIENTRY glDebugMessageInsert (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
GLAPI void APIENTRY glDebugMessageCallback (GLDEBUGPROC callback, const void *userParam);
GLAPI GLuint APIENTRY glGetDebugMessageLog (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
GLAPI void APIENTRY glPushDebugGroup (GLenum source, GLuint id, GLsizei length, const GLchar *message);
GLAPI void APIENTRY glPopDebugGroup (void);
GLAPI void APIENTRY glObjectLabel (GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
GLAPI void APIENTRY glGetObjectLabel (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
GLAPI void APIENTRY glObjectPtrLabel (const void *ptr, GLsizei length, const GLchar *label);
GLAPI void APIENTRY glGetObjectPtrLabel (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
#endif
#endif /* GL_VERSION_4_3 */

#ifndef GL_VERSION_4_4
#define GL_VERSION_4_4 1
#define GL_MAX_VERTEX_ATTRIB_STRIDE       0x82E5
#define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED 0x8221
#define GL_TEXTURE_BUFFER_BINDING         0x8C2A
#define GL_MAP_PERSISTENT_BIT             0x0040
#define GL_MAP_COHERENT_BIT               0x0080
#define GL_DYNAMIC_STORAGE_BIT            0x0100
#define GL_CLIENT_STORAGE_BIT             0x0200
#define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT 0x00004000
#define GL_BUFFER_IMMUTABLE_STORAGE       0x821F
#define GL_BUFFER_STORAGE_FLAGS           0x8220
#define GL_CLEAR_TEXTURE                  0x9365
#define GL_LOCATION_COMPONENT             0x934A
#define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX 0x934B
#define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE 0x934C
#define GL_QUERY_BUFFER                   0x9192
#define GL_QUERY_BUFFER_BARRIER_BIT       0x00008000
#define GL_QUERY_BUFFER_BINDING           0x9193
#define GL_QUERY_RESULT_NO_WAIT           0x9194
#define GL_MIRROR_CLAMP_TO_EDGE           0x8743
typedef void (APIENTRYP PFNGLBUFFERSTORAGEPROC) (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
typedef void (APIENTRYP PFNGLCLEARTEXIMAGEPROC) (GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLCLEARTEXSUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLBINDBUFFERSBASEPROC) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
typedef void (APIENTRYP PFNGLBINDBUFFERSRANGEPROC) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
typedef void (APIENTRYP PFNGLBINDTEXTURESPROC) (GLuint first, GLsizei count, const GLuint *textures);
typedef void (APIENTRYP PFNGLBINDSAMPLERSPROC) (GLuint first, GLsizei count, const GLuint *samplers);
typedef void (APIENTRYP PFNGLBINDIMAGETEXTURESPROC) (GLuint first, GLsizei count, const GLuint *textures);
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERSPROC) (GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBufferStorage (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
GLAPI void APIENTRY glClearTexImage (GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glClearTexSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glBindBuffersBase (GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
GLAPI void APIENTRY glBindBuffersRange (GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
GLAPI void APIENTRY glBindTextures (GLuint first, GLsizei count, const GLuint *textures);
GLAPI void APIENTRY glBindSamplers (GLuint first, GLsizei count, const GLuint *samplers);
GLAPI void APIENTRY glBindImageTextures (GLuint first, GLsizei count, const GLuint *textures);
GLAPI void APIENTRY glBindVertexBuffers (GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
#endif
#endif /* GL_VERSION_4_4 */

#ifndef GL_VERSION_4_5
#define GL_VERSION_4_5 1
#define GL_CONTEXT_LOST                   0x0507
#define GL_NEGATIVE_ONE_TO_ONE            0x935E
#define GL_ZERO_TO_ONE                    0x935F
#define GL_CLIP_ORIGIN                    0x935C
#define GL_CLIP_DEPTH_MODE                0x935D
#define GL_QUERY_WAIT_INVERTED            0x8E17
#define GL_QUERY_NO_WAIT_INVERTED         0x8E18
#define GL_QUERY_BY_REGION_WAIT_INVERTED  0x8E19
#define GL_QUERY_BY_REGION_NO_WAIT_INVERTED 0x8E1A
#define GL_MAX_CULL_DISTANCES             0x82F9
#define GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES 0x82FA
#define GL_TEXTURE_TARGET                 0x1006
#define GL_QUERY_TARGET                   0x82EA
#define GL_GUILTY_CONTEXT_RESET           0x8253
#define GL_INNOCENT_CONTEXT_RESET         0x8254
#define GL_UNKNOWN_CONTEXT_RESET          0x8255
#define GL_RESET_NOTIFICATION_STRATEGY    0x8256
#define GL_LOSE_CONTEXT_ON_RESET          0x8252
#define GL_NO_RESET_NOTIFICATION          0x8261
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT 0x00000004
#define GL_COLOR_TABLE                    0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE   0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE  0x80D2
#define GL_PROXY_COLOR_TABLE              0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE 0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE 0x80D5
#define GL_CONVOLUTION_1D                 0x8010
#define GL_CONVOLUTION_2D                 0x8011
#define GL_SEPARABLE_2D                   0x8012
#define GL_HISTOGRAM                      0x8024
#define GL_PROXY_HISTOGRAM                0x8025
#define GL_MINMAX                         0x802E
#define GL_CONTEXT_RELEASE_BEHAVIOR       0x82FB
#define GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH 0x82FC
typedef void (APIENTRYP PFNGLCLIPCONTROLPROC) (GLenum origin, GLenum depth);
typedef void (APIENTRYP PFNGLCREATETRANSFORMFEEDBACKSPROC) (GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC) (GLuint xfb, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC) (GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKIVPROC) (GLuint xfb, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI_VPROC) (GLuint xfb, GLenum pname, GLuint index, GLint *param);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI64_VPROC) (GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
typedef void (APIENTRYP PFNGLCREATEBUFFERSPROC) (GLsizei n, GLuint *buffers);
typedef void (APIENTRYP PFNGLNAMEDBUFFERSTORAGEPROC) (GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
typedef void (APIENTRYP PFNGLNAMEDBUFFERDATAPROC) (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
typedef void (APIENTRYP PFNGLNAMEDBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
typedef void (APIENTRYP PFNGLCOPYNAMEDBUFFERSUBDATAPROC) (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERDATAPROC) (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAPROC) (GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
typedef void *(APIENTRYP PFNGLMAPNAMEDBUFFERPROC) (GLuint buffer, GLenum access);
typedef void *(APIENTRYP PFNGLMAPNAMEDBUFFERRANGEPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef GLboolean (APIENTRYP PFNGLUNMAPNAMEDBUFFERPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVPROC) (GLuint buffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERI64VPROC) (GLuint buffer, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVPROC) (GLuint buffer, GLenum pname, void **params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
typedef void (APIENTRYP PFNGLCREATEFRAMEBUFFERSPROC) (GLsizei n, GLuint *framebuffers);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC) (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC) (GLuint framebuffer, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC) (GLuint framebuffer, GLenum buf);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC) (GLuint framebuffer, GLsizei n, const GLenum *bufs);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC) (GLuint framebuffer, GLenum src);
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC) (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC) (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERIVPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFVPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFIPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef void (APIENTRYP PFNGLBLITNAMEDFRAMEBUFFERPROC) (GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef GLenum (APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC) (GLuint framebuffer, GLenum target);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC) (GLuint framebuffer, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC) (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLCREATERENDERBUFFERSPROC) (GLsizei n, GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEPROC) (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC) (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC) (GLuint renderbuffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLCREATETEXTURESPROC) (GLenum target, GLsizei n, GLuint *textures);
typedef void (APIENTRYP PFNGLTEXTUREBUFFERPROC) (GLuint texture, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLTEXTUREBUFFERRANGEPROC) (GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DPROC) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DPROC) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DPROC) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC) (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC) (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE1DPROC) (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE2DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE3DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC) (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DPROC) (GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFPROC) (GLuint texture, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFVPROC) (GLuint texture, GLenum pname, const GLfloat *param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIPROC) (GLuint texture, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIIVPROC) (GLuint texture, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIUIVPROC) (GLuint texture, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIVPROC) (GLuint texture, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFNGLGENERATETEXTUREMIPMAPPROC) (GLuint texture);
typedef void (APIENTRYP PFNGLBINDTEXTUREUNITPROC) (GLuint unit, GLuint texture);
typedef void (APIENTRYP PFNGLGETTEXTUREIMAGEPROC) (GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC) (GLuint texture, GLint level, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVPROC) (GLuint texture, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVPROC) (GLuint texture, GLint level, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERFVPROC) (GLuint texture, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIIVPROC) (GLuint texture, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVPROC) (GLuint texture, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIVPROC) (GLuint texture, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLCREATEVERTEXARRAYSPROC) (GLsizei n, GLuint *arrays);
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBPROC) (GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBPROC) (GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLVERTEXARRAYELEMENTBUFFERPROC) (GLuint vaobj, GLuint buffer);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERPROC) (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERSPROC) (GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBBINDINGPROC) (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBFORMATPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBIFORMATPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBLFORMATPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYBINDINGDIVISORPROC) (GLuint vaobj, GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYIVPROC) (GLuint vaobj, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXEDIVPROC) (GLuint vaobj, GLuint index, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXED64IVPROC) (GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
typedef void (APIENTRYP PFNGLCREATESAMPLERSPROC) (GLsizei n, GLuint *samplers);
typedef void (APIENTRYP PFNGLCREATEPROGRAMPIPELINESPROC) (GLsizei n, GLuint *pipelines);
typedef void (APIENTRYP PFNGLCREATEQUERIESPROC) (GLenum target, GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTI64VPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTIVPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUI64VPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUIVPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLMEMORYBARRIERBYREGIONPROC) (GLbitfield barriers);
typedef void (APIENTRYP PFNGLGETTEXTURESUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
typedef GLenum (APIENTRYP PFNGLGETGRAPHICSRESETSTATUSPROC) (void);
typedef void (APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEPROC) (GLenum target, GLint lod, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETNTEXIMAGEPROC) (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETNUNIFORMDVPROC) (GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMFVPROC) (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMIVPROC) (GLuint program, GLint location, GLsizei bufSize, GLint *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVPROC) (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
typedef void (APIENTRYP PFNGLREADNPIXELSPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
typedef void (APIENTRYP PFNGLGETNMAPDVPROC) (GLenum target, GLenum query, GLsizei bufSize, GLdouble *v);
typedef void (APIENTRYP PFNGLGETNMAPFVPROC) (GLenum target, GLenum query, GLsizei bufSize, GLfloat *v);
typedef void (APIENTRYP PFNGLGETNMAPIVPROC) (GLenum target, GLenum query, GLsizei bufSize, GLint *v);
typedef void (APIENTRYP PFNGLGETNPIXELMAPFVPROC) (GLenum map, GLsizei bufSize, GLfloat *values);
typedef void (APIENTRYP PFNGLGETNPIXELMAPUIVPROC) (GLenum map, GLsizei bufSize, GLuint *values);
typedef void (APIENTRYP PFNGLGETNPIXELMAPUSVPROC) (GLenum map, GLsizei bufSize, GLushort *values);
typedef void (APIENTRYP PFNGLGETNPOLYGONSTIPPLEPROC) (GLsizei bufSize, GLubyte *pattern);
typedef void (APIENTRYP PFNGLGETNCOLORTABLEPROC) (GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table);
typedef void (APIENTRYP PFNGLGETNCONVOLUTIONFILTERPROC) (GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image);
typedef void (APIENTRYP PFNGLGETNSEPARABLEFILTERPROC) (GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span);
typedef void (APIENTRYP PFNGLGETNHISTOGRAMPROC) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
typedef void (APIENTRYP PFNGLGETNMINMAXPROC) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
typedef void (APIENTRYP PFNGLTEXTUREBARRIERPROC) (void);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glClipControl (GLenum origin, GLenum depth);
GLAPI void APIENTRY glCreateTransformFeedbacks (GLsizei n, GLuint *ids);
GLAPI void APIENTRY glTransformFeedbackBufferBase (GLuint xfb, GLuint index, GLuint buffer);
GLAPI void APIENTRY glTransformFeedbackBufferRange (GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void APIENTRY glGetTransformFeedbackiv (GLuint xfb, GLenum pname, GLint *param);
GLAPI void APIENTRY glGetTransformFeedbacki_v (GLuint xfb, GLenum pname, GLuint index, GLint *param);
GLAPI void APIENTRY glGetTransformFeedbacki64_v (GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
GLAPI void APIENTRY glCreateBuffers (GLsizei n, GLuint *buffers);
GLAPI void APIENTRY glNamedBufferStorage (GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
GLAPI void APIENTRY glNamedBufferData (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
GLAPI void APIENTRY glNamedBufferSubData (GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
GLAPI void APIENTRY glCopyNamedBufferSubData (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLAPI void APIENTRY glClearNamedBufferData (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
GLAPI void APIENTRY glClearNamedBufferSubData (GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
GLAPI void *APIENTRY glMapNamedBuffer (GLuint buffer, GLenum access);
GLAPI void *APIENTRY glMapNamedBufferRange (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLAPI GLboolean APIENTRY glUnmapNamedBuffer (GLuint buffer);
GLAPI void APIENTRY glFlushMappedNamedBufferRange (GLuint buffer, GLintptr offset, GLsizeiptr length);
GLAPI void APIENTRY glGetNamedBufferParameteriv (GLuint buffer, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetNamedBufferParameteri64v (GLuint buffer, GLenum pname, GLint64 *params);
GLAPI void APIENTRY glGetNamedBufferPointerv (GLuint buffer, GLenum pname, void **params);
GLAPI void APIENTRY glGetNamedBufferSubData (GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
GLAPI void APIENTRY glCreateFramebuffers (GLsizei n, GLuint *framebuffers);
GLAPI void APIENTRY glNamedFramebufferRenderbuffer (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLAPI void APIENTRY glNamedFramebufferParameteri (GLuint framebuffer, GLenum pname, GLint param);
GLAPI void APIENTRY glNamedFramebufferTexture (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
GLAPI void APIENTRY glNamedFramebufferTextureLayer (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void APIENTRY glNamedFramebufferDrawBuffer (GLuint framebuffer, GLenum buf);
GLAPI void APIENTRY glNamedFramebufferDrawBuffers (GLuint framebuffer, GLsizei n, const GLenum *bufs);
GLAPI void APIENTRY glNamedFramebufferReadBuffer (GLuint framebuffer, GLenum src);
GLAPI void APIENTRY glInvalidateNamedFramebufferData (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
GLAPI void APIENTRY glInvalidateNamedFramebufferSubData (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glClearNamedFramebufferiv (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
GLAPI void APIENTRY glClearNamedFramebufferuiv (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
GLAPI void APIENTRY glClearNamedFramebufferfv (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
GLAPI void APIENTRY glClearNamedFramebufferfi (GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
GLAPI void APIENTRY glBlitNamedFramebuffer (GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLAPI GLenum APIENTRY glCheckNamedFramebufferStatus (GLuint framebuffer, GLenum target);
GLAPI void APIENTRY glGetNamedFramebufferParameteriv (GLuint framebuffer, GLenum pname, GLint *param);
GLAPI void APIENTRY glGetNamedFramebufferAttachmentParameteriv (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
GLAPI void APIENTRY glCreateRenderbuffers (GLsizei n, GLuint *renderbuffers);
GLAPI void APIENTRY glNamedRenderbufferStorage (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glNamedRenderbufferStorageMultisample (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glGetNamedRenderbufferParameteriv (GLuint renderbuffer, GLenum pname, GLint *params);
GLAPI void APIENTRY glCreateTextures (GLenum target, GLsizei n, GLuint *textures);
GLAPI void APIENTRY glTextureBuffer (GLuint texture, GLenum internalformat, GLuint buffer);
GLAPI void APIENTRY glTextureBufferRange (GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLAPI void APIENTRY glTextureStorage1D (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
GLAPI void APIENTRY glTextureStorage2D (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTextureStorage3D (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLAPI void APIENTRY glTextureStorage2DMultisample (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTextureStorage3DMultisample (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLAPI void APIENTRY glTextureSubImage1D (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTextureSubImage2D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTextureSubImage3D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glCompressedTextureSubImage1D (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTextureSubImage2D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCompressedTextureSubImage3D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
GLAPI void APIENTRY glCopyTextureSubImage1D (GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI void APIENTRY glCopyTextureSubImage2D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glCopyTextureSubImage3D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTextureParameterf (GLuint texture, GLenum pname, GLfloat param);
GLAPI void APIENTRY glTextureParameterfv (GLuint texture, GLenum pname, const GLfloat *param);
GLAPI void APIENTRY glTextureParameteri (GLuint texture, GLenum pname, GLint param);
GLAPI void APIENTRY glTextureParameterIiv (GLuint texture, GLenum pname, const GLint *params);
GLAPI void APIENTRY glTextureParameterIuiv (GLuint texture, GLenum pname, const GLuint *params);
GLAPI void APIENTRY glTextureParameteriv (GLuint texture, GLenum pname, const GLint *param);
GLAPI void APIENTRY glGenerateTextureMipmap (GLuint texture);
GLAPI void APIENTRY glBindTextureUnit (GLuint unit, GLuint texture);
GLAPI void APIENTRY glGetTextureImage (GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLAPI void APIENTRY glGetCompressedTextureImage (GLuint texture, GLint level, GLsizei bufSize, void *pixels);
GLAPI void APIENTRY glGetTextureLevelParameterfv (GLuint texture, GLint level, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTextureLevelParameteriv (GLuint texture, GLint level, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetTextureParameterfv (GLuint texture, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTextureParameterIiv (GLuint texture, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetTextureParameterIuiv (GLuint texture, GLenum pname, GLuint *params);
GLAPI void APIENTRY glGetTextureParameteriv (GLuint texture, GLenum pname, GLint *params);
GLAPI void APIENTRY glCreateVertexArrays (GLsizei n, GLuint *arrays);
GLAPI void APIENTRY glDisableVertexArrayAttrib (GLuint vaobj, GLuint index);
GLAPI void APIENTRY glEnableVertexArrayAttrib (GLuint vaobj, GLuint index);
GLAPI void APIENTRY glVertexArrayElementBuffer (GLuint vaobj, GLuint buffer);
GLAPI void APIENTRY glVertexArrayVertexBuffer (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLAPI void APIENTRY glVertexArrayVertexBuffers (GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
GLAPI void APIENTRY glVertexArrayAttribBinding (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
GLAPI void APIENTRY glVertexArrayAttribFormat (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLAPI void APIENTRY glVertexArrayAttribIFormat (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexArrayAttribLFormat (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLAPI void APIENTRY glVertexArrayBindingDivisor (GLuint vaobj, GLuint bindingindex, GLuint divisor);
GLAPI void APIENTRY glGetVertexArrayiv (GLuint vaobj, GLenum pname, GLint *param);
GLAPI void APIENTRY glGetVertexArrayIndexediv (GLuint vaobj, GLuint index, GLenum pname, GLint *param);
GLAPI void APIENTRY glGetVertexArrayIndexed64iv (GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
GLAPI void APIENTRY glCreateSamplers (GLsizei n, GLuint *samplers);
GLAPI void APIENTRY glCreateProgramPipelines (GLsizei n, GLuint *pipelines);
GLAPI void APIENTRY glCreateQueries (GLenum target, GLsizei n, GLuint *ids);
GLAPI void APIENTRY glGetQueryBufferObjecti64v (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void APIENTRY glGetQueryBufferObjectiv (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void APIENTRY glGetQueryBufferObjectui64v (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void APIENTRY glGetQueryBufferObjectuiv (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLAPI void APIENTRY glMemoryBarrierByRegion (GLbitfield barriers);
GLAPI void APIENTRY glGetTextureSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLAPI void APIENTRY glGetCompressedTextureSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
GLAPI GLenum APIENTRY glGetGraphicsResetStatus (void);
GLAPI void APIENTRY glGetnCompressedTexImage (GLenum target, GLint lod, GLsizei bufSize, void *pixels);
GLAPI void APIENTRY glGetnTexImage (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLAPI void APIENTRY glGetnUniformdv (GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
GLAPI void APIENTRY glGetnUniformfv (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
GLAPI void APIENTRY glGetnUniformiv (GLuint program, GLint location, GLsizei bufSize, GLint *params);
GLAPI void APIENTRY glGetnUniformuiv (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
GLAPI void APIENTRY glReadnPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
GLAPI void APIENTRY glGetnMapdv (GLenum target, GLenum query, GLsizei bufSize, GLdouble *v);
GLAPI void APIENTRY glGetnMapfv (GLenum target, GLenum query, GLsizei bufSize, GLfloat *v);
GLAPI void APIENTRY glGetnMapiv (GLenum target, GLenum query, GLsizei bufSize, GLint *v);
GLAPI void APIENTRY glGetnPixelMapfv (GLenum map, GLsizei bufSize, GLfloat *values);
GLAPI void APIENTRY glGetnPixelMapuiv (GLenum map, GLsizei bufSize, GLuint *values);
GLAPI void APIENTRY glGetnPixelMapusv (GLenum map, GLsizei bufSize, GLushort *values);
GLAPI void APIENTRY glGetnPolygonStipple (GLsizei bufSize, GLubyte *pattern);
GLAPI void APIENTRY glGetnColorTable (GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table);
GLAPI void APIENTRY glGetnConvolutionFilter (GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image);
GLAPI void APIENTRY glGetnSeparableFilter (GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span);
GLAPI void APIENTRY glGetnHistogram (GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
GLAPI void APIENTRY glGetnMinmax (GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
GLAPI void APIENTRY glTextureBarrier (void);
#endif
#endif /* GL_VERSION_4_5 */

#ifndef GL_VERSION_4_6
#define GL_VERSION_4_6 1
#define GL_SHADER_BINARY_FORMAT_SPIR_V    0x9551
#define GL_SPIR_V_BINARY                  0x9552
#define GL_PARAMETER_BUFFER               0x80EE
#define GL_PARAMETER_BUFFER_BINDING       0x80EF
#define GL_CONTEXT_FLAG_NO_ERROR_BIT      0x00000008
#define GL_VERTICES_SUBMITTED             0x82EE
#define GL_PRIMITIVES_SUBMITTED           0x82EF
#define GL_VERTEX_SHADER_INVOCATIONS      0x82F0
#define GL_TESS_CONTROL_SHADER_PATCHES    0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS 0x82F2
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED 0x82F3
#define GL_FRAGMENT_SHADER_INVOCATIONS    0x82F4
#define GL_COMPUTE_SHADER_INVOCATIONS     0x82F5
#define GL_CLIPPING_INPUT_PRIMITIVES      0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES     0x82F7
#define GL_POLYGON_OFFSET_CLAMP           0x8E1B
#define GL_SPIR_V_EXTENSIONS              0x9553
#define GL_NUM_SPIR_V_EXTENSIONS          0x9554
#define GL_TEXTURE_MAX_ANISOTROPY         0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY     0x84FF
#define GL_TRANSFORM_FEEDBACK_OVERFLOW    0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW 0x82ED
typedef void (APIENTRYP PFNGLSPECIALIZESHADERPROC) (GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC) (GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC) (GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLPOLYGONOFFSETCLAMPPROC) (GLfloat factor, GLfloat units, GLfloat clamp);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glSpecializeShader (GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue);
GLAPI void APIENTRY glMultiDrawArraysIndirectCount (GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
GLAPI void APIENTRY glMultiDrawElementsIndirectCount (GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
GLAPI void APIENTRY glPolygonOffsetClamp (GLfloat factor, GLfloat units, GLfloat clamp);
#endif
#endif /* GL_VERSION_4_6 */

#ifndef GL_ARB_ES2_compatibility
#define GL_ARB_ES2_compatibility 1
#endif /* GL_ARB_ES2_compatibility */

#ifndef GL_ARB_ES3_1_compatibility
#define GL_ARB_ES3_1_compatibility 1
#endif /* GL_ARB_ES3_1_compatibility */

#ifndef GL_ARB_ES3_2_compatibility
#define GL_ARB_ES3_2_compatibility 1
#define GL_PRIMITIVE_BOUNDING_BOX_ARB     0x92BE
#define GL_MULTISAMPLE_LINE_WIDTH_RANGE_ARB 0x9381
#define GL_MULTISAMPLE_LINE_WIDTH_GRANULARITY_ARB 0x9382
typedef void (APIENTRYP PFNGLPRIMITIVEBOUNDINGBOXARBPROC) (GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glPrimitiveBoundingBoxARB (GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
#endif
#endif /* GL_ARB_ES3_2_compatibility */

#ifndef GL_ARB_ES3_compatibility
#define GL_ARB_ES3_compatibility 1
#endif /* GL_ARB_ES3_compatibility */

#ifndef GL_ARB_arrays_of_arrays
#define GL_ARB_arrays_of_arrays 1
#endif /* GL_ARB_arrays_of_arrays */

#ifndef GL_ARB_base_instance
#define GL_ARB_base_instance 1
#endif /* GL_ARB_base_instance */

#ifndef GL_ARB_bindless_texture
#define GL_ARB_bindless_texture 1
typedef khronos_uint64_t GLuint64EXT;
#define GL_UNSIGNED_INT64_ARB             0x140F
typedef GLuint64 (APIENTRYP PFNGLGETTEXTUREHANDLEARBPROC) (GLuint texture);
typedef GLuint64 (APIENTRYP PFNGLGETTEXTURESAMPLERHANDLEARBPROC) (GLuint texture, GLuint sampler);
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLERESIDENTARBPROC) (GLuint64 handle);
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC) (GLuint64 handle);
typedef GLuint64 (APIENTRYP PFNGLGETIMAGEHANDLEARBPROC) (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLERESIDENTARBPROC) (GLuint64 handle, GLenum access);
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC) (GLuint64 handle);
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64ARBPROC) (GLint location, GLuint64 value);
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64VARBPROC) (GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC) (GLuint program, GLint location, GLuint64 value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLuint64 *values);
typedef GLboolean (APIENTRYP PFNGLISTEXTUREHANDLERESIDENTARBPROC) (GLuint64 handle);
typedef GLboolean (APIENTRYP PFNGLISIMAGEHANDLERESIDENTARBPROC) (GLuint64 handle);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64ARBPROC) (GLuint index, GLuint64EXT x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64VARBPROC) (GLuint index, const GLuint64EXT *v);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLUI64VARBPROC) (GLuint index, GLenum pname, GLuint64EXT *params);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLuint64 APIENTRY glGetTextureHandleARB (GLuint texture);
GLAPI GLuint64 APIENTRY glGetTextureSamplerHandleARB (GLuint texture, GLuint sampler);
GLAPI void APIENTRY glMakeTextureHandleResidentARB (GLuint64 handle);
GLAPI void APIENTRY glMakeTextureHandleNonResidentARB (GLuint64 handle);
GLAPI GLuint64 APIENTRY glGetImageHandleARB (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
GLAPI void APIENTRY glMakeImageHandleResidentARB (GLuint64 handle, GLenum access);
GLAPI void APIENTRY glMakeImageHandleNonResidentARB (GLuint64 handle);
GLAPI void APIENTRY glUniformHandleui64ARB (GLint location, GLuint64 value);
GLAPI void APIENTRY glUniformHandleui64vARB (GLint location, GLsizei count, const GLuint64 *value);
GLAPI void APIENTRY glProgramUniformHandleui64ARB (GLuint program, GLint location, GLuint64 value);
GLAPI void APIENTRY glProgramUniformHandleui64vARB (GLuint program, GLint location, GLsizei count, const GLuint64 *values);
GLAPI GLboolean APIENTRY glIsTextureHandleResidentARB (GLuint64 handle);
GLAPI GLboolean APIENTRY glIsImageHandleResidentARB (GLuint64 handle);
GLAPI void APIENTRY glVertexAttribL1ui64ARB (GLuint index, GLuint64EXT x);
GLAPI void APIENTRY glVertexAttribL1ui64vARB (GLuint index, const GLuint64EXT *v);
GLAPI void APIENTRY glGetVertexAttribLui64vARB (GLuint index, GLenum pname, GLuint64EXT *params);
#endif
#endif /* GL_ARB_bindless_texture */

#ifndef GL_ARB_blend_func_extended
#define GL_ARB_blend_func_extended 1
#endif /* GL_ARB_blend_func_extended */

#ifndef GL_ARB_buffer_storage
#define GL_ARB_buffer_storage 1
#endif /* GL_ARB_buffer_storage */

#ifndef GL_ARB_cl_event
#define GL_ARB_cl_event 1
struct _cl_context;
struct _cl_event;
#define GL_SYNC_CL_EVENT_ARB              0x8240
#define GL_SYNC_CL_EVENT_COMPLETE_ARB     0x8241
typedef GLsync (APIENTRYP PFNGLCREATESYNCFROMCLEVENTARBPROC) (struct _cl_context *context, struct _cl_event *event, GLbitfield flags);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI GLsync APIENTRY glCreateSyncFromCLeventARB (struct _cl_context *context, struct _cl_event *event, GLbitfield flags);
#endif
#endif /* GL_ARB_cl_event */

#ifndef GL_ARB_clear_buffer_object
#define GL_ARB_clear_buffer_object 1
#endif /* GL_ARB_clear_buffer_object */

#ifndef GL_ARB_clear_texture
#define GL_ARB_clear_texture 1
#endif /* GL_ARB_clear_texture */

#ifndef GL_ARB_clip_control
#define GL_ARB_clip_control 1
#endif /* GL_ARB_clip_control */

#ifndef GL_ARB_color_buffer_float
#define GL_ARB_color_buffer_float 1
#define GL_RGBA_FLOAT_MODE_ARB            0x8820
#define GL_CLAMP_VERTEX_COLOR_ARB         0x891A
#define GL_CLAMP_FRAGMENT_COLOR_ARB       0x891B
#define GL_CLAMP_READ_COLOR_ARB           0x891C
#define GL_FIXED_ONLY_ARB                 0x891D
typedef void (APIENTRYP PFNGLCLAMPCOLORARBPROC) (GLenum target, GLenum clamp);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glClampColorARB (GLenum target, GLenum clamp);
#endif
#endif /* GL_ARB_color_buffer_float */

#ifndef GL_ARB_compatibility
#define GL_ARB_compatibility 1
#endif /* GL_ARB_compatibility */

#ifndef GL_ARB_compressed_texture_pixel_storage
#define GL_ARB_compressed_texture_pixel_storage 1
#endif /* GL_ARB_compressed_texture_pixel_storage */

#ifndef GL_ARB_compute_shader
#define GL_ARB_compute_shader 1
#endif /* GL_ARB_compute_shader */

#ifndef GL_ARB_compute_variable_group_size
#define GL_ARB_compute_variable_group_size 1
#define GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB 0x9344
#define GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB 0x90EB
#define GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB 0x9345
#define GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB 0x91BF
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDispatchComputeGroupSizeARB (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
#endif
#endif /* GL_ARB_compute_variable_group_size */

#ifndef GL_ARB_conditional_render_inverted
#define GL_ARB_conditional_render_inverted 1
#endif /* GL_ARB_conditional_render_inverted */

#ifndef GL_ARB_conservative_depth
#define GL_ARB_conservative_depth 1
#endif /* GL_ARB_conservative_depth */

#ifndef GL_ARB_copy_buffer
#define GL_ARB_copy_buffer 1
#endif /* GL_ARB_copy_buffer */

#ifndef GL_ARB_copy_image
#define GL_ARB_copy_image 1
#endif /* GL_ARB_copy_image */

#ifndef GL_ARB_cull_distance
#define GL_ARB_cull_distance 1
#endif /* GL_ARB_cull_distance */

#ifndef GL_ARB_debug_output
#define GL_ARB_debug_output 1
typedef void (APIENTRY  *GLDEBUGPROCARB)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
#define GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB   0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION_ARB    0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_ARB  0x8245
#define GL_DEBUG_SOURCE_API_ARB           0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER_ARB 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_ARB   0x8249
#define GL_DEBUG_SOURCE_APPLICATION_ARB   0x824A
#define GL_DEBUG_SOURCE_OTHER_ARB         0x824B
#define GL_DEBUG_TYPE_ERROR_ARB           0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB 0x824E
#define GL_DEBUG_TYPE_PORTABILITY_ARB     0x824F
#define GL_DEBUG_TYPE_PERFORMANCE_ARB     0x8250
#define GL_DEBUG_TYPE_OTHER_ARB           0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH_ARB   0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_ARB  0x9144
#define GL_DEBUG_LOGGED_MESSAGES_ARB      0x9145
#define GL_DEBUG_SEVERITY_HIGH_ARB        0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_ARB      0x9147
#define GL_DEBUG_SEVERITY_LOW_ARB         0x9148
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLARBPROC) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTARBPROC) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKARBPROC) (GLDEBUGPROCARB callback, const void *userParam);
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGARBPROC) (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDebugMessageControlARB (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
GLAPI void APIENTRY glDebugMessageInsertARB (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
GLAPI void APIENTRY glDebugMessageCallbackARB (GLDEBUGPROCARB callback, const void *userParam);
GLAPI GLuint APIENTRY glGetDebugMessageLogARB (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
#endif
#endif /* GL_ARB_debug_output */

#ifndef GL_ARB_depth_buffer_float
#define GL_ARB_depth_buffer_float 1
#endif /* GL_ARB_depth_buffer_float */

#ifndef GL_ARB_depth_clamp
#define GL_ARB_depth_clamp 1
#endif /* GL_ARB_depth_clamp */

#ifndef GL_ARB_depth_texture
#define GL_ARB_depth_texture 1
#define GL_DEPTH_COMPONENT16_ARB          0x81A5
#define GL_DEPTH_COMPONENT24_ARB          0x81A6
#define GL_DEPTH_COMPONENT32_ARB          0x81A7
#define GL_TEXTURE_DEPTH_SIZE_ARB         0x884A
#define GL_DEPTH_TEXTURE_MODE_ARB         0x884B
#endif /* GL_ARB_depth_texture */

#ifndef GL_ARB_derivative_control
#define GL_ARB_derivative_control 1
#endif /* GL_ARB_derivative_control */

#ifndef GL_ARB_direct_state_access
#define GL_ARB_direct_state_access 1
#endif /* GL_ARB_direct_state_access */

#ifndef GL_ARB_draw_buffers
#define GL_ARB_draw_buffers 1
#define GL_MAX_DRAW_BUFFERS_ARB           0x8824
#define GL_DRAW_BUFFER0_ARB               0x8825
#define GL_DRAW_BUFFER1_ARB               0x8826
#define GL_DRAW_BUFFER2_ARB               0x8827
#define GL_DRAW_BUFFER3_ARB               0x8828
#define GL_DRAW_BUFFER4_ARB               0x8829
#define GL_DRAW_BUFFER5_ARB               0x882A
#define GL_DRAW_BUFFER6_ARB               0x882B
#define GL_DRAW_BUFFER7_ARB               0x882C
#define GL_DRAW_BUFFER8_ARB               0x882D
#define GL_DRAW_BUFFER9_ARB               0x882E
#define GL_DRAW_BUFFER10_ARB              0x882F
#define GL_DRAW_BUFFER11_ARB              0x8830
#define GL_DRAW_BUFFER12_ARB              0x8831
#define GL_DRAW_BUFFER13_ARB              0x8832
#define GL_DRAW_BUFFER14_ARB              0x8833
#define GL_DRAW_BUFFER15_ARB              0x8834
typedef void (APIENTRYP PFNGLDRAWBUFFERSARBPROC) (GLsizei n, const GLenum *bufs);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawBuffersARB (GLsizei n, const GLenum *bufs);
#endif
#endif /* GL_ARB_draw_buffers */

#ifndef GL_ARB_draw_buffers_blend
#define GL_ARB_draw_buffers_blend 1
typedef void (APIENTRYP PFNGLBLENDEQUATIONIARBPROC) (GLuint buf, GLenum mode);
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIARBPROC) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLBLENDFUNCIARBPROC) (GLuint buf, GLenum src, GLenum dst);
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIARBPROC) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBlendEquationiARB (GLuint buf, GLenum mode);
GLAPI void APIENTRY glBlendEquationSeparateiARB (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLAPI void APIENTRY glBlendFunciARB (GLuint buf, GLenum src, GLenum dst);
GLAPI void APIENTRY glBlendFuncSeparateiARB (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#endif
#endif /* GL_ARB_draw_buffers_blend */

#ifndef GL_ARB_draw_elements_base_vertex
#define GL_ARB_draw_elements_base_vertex 1
#endif /* GL_ARB_draw_elements_base_vertex */

#ifndef GL_ARB_draw_indirect
#define GL_ARB_draw_indirect 1
#endif /* GL_ARB_draw_indirect */

#ifndef GL_ARB_draw_instanced
#define GL_ARB_draw_instanced 1
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDARBPROC) (GLenum mode, GLint first, GLsizei count, GLsizei primcount);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDARBPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glDrawArraysInstancedARB (GLenum mode, GLint first, GLsizei count, GLsizei primcount);
GLAPI void APIENTRY glDrawElementsInstancedARB (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount);
#endif
#endif /* GL_ARB_draw_instanced */

#ifndef GL_ARB_enhanced_layouts
#define GL_ARB_enhanced_layouts 1
#endif /* GL_ARB_enhanced_layouts */

#ifndef GL_ARB_explicit_attrib_location
#define GL_ARB_explicit_attrib_location 1
#endif /* GL_ARB_explicit_attrib_location */

#ifndef GL_ARB_explicit_uniform_location
#define GL_ARB_explicit_uniform_location 1
#endif /* GL_ARB_explicit_uniform_location */

#ifndef GL_ARB_fragment_coord_conventions
#define GL_ARB_fragment_coord_conventions 1
#endif /* GL_ARB_fragment_coord_conventions */

#ifndef GL_ARB_fragment_layer_viewport
#define GL_ARB_fragment_layer_viewport 1
#endif /* GL_ARB_fragment_layer_viewport */

#ifndef GL_ARB_fragment_program
#define GL_ARB_fragment_program 1
#define GL_FRAGMENT_PROGRAM_ARB           0x8804
#define GL_PROGRAM_FORMAT_ASCII_ARB       0x8875
#define GL_PROGRAM_LENGTH_ARB             0x8627
#define GL_PROGRAM_FORMAT_ARB             0x8876
#define GL_PROGRAM_BINDING_ARB            0x8677
#define GL_PROGRAM_INSTRUCTIONS_ARB       0x88A0
#define GL_MAX_PROGRAM_INSTRUCTIONS_ARB   0x88A1
#define GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB 0x88A2
#define GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB 0x88A3
#define GL_PROGRAM_TEMPORARIES_ARB        0x88A4
#define GL_MAX_PROGRAM_TEMPORARIES_ARB    0x88A5
#define GL_PROGRAM_NATIVE_TEMPORARIES_ARB 0x88A6
#define GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB 0x88A7
#define GL_PROGRAM_PARAMETERS_ARB         0x88A8
#define GL_MAX_PROGRAM_PARAMETERS_ARB     0x88A9
#define GL_PROGRAM_NATIVE_PARAMETERS_ARB  0x88AA
#define GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB 0x88AB
#define GL_PROGRAM_ATTRIBS_ARB            0x88AC
#define GL_MAX_PROGRAM_ATTRIBS_ARB        0x88AD
#define GL_PROGRAM_NATIVE_ATTRIBS_ARB     0x88AE
#define GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB 0x88AF
#define GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB 0x88B4
#define GL_MAX_PROGRAM_ENV_PARAMETERS_ARB 0x88B5
#define GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB 0x88B6
#define GL_PROGRAM_ALU_INSTRUCTIONS_ARB   0x8805
#define GL_PROGRAM_TEX_INSTRUCTIONS_ARB   0x8806
#define GL_PROGRAM_TEX_INDIRECTIONS_ARB   0x8807
#define GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x8808
#define GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x8809
#define GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x880A
#define GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB 0x880B
#define GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB 0x880C
#define GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB 0x880D
#define GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x880E
#define GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x880F
#define GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x8810
#define GL_PROGRAM_STRING_ARB             0x8628
#define GL_PROGRAM_ERROR_POSITION_ARB     0x864B
#define GL_CURRENT_MATRIX_ARB             0x8641
#define GL_TRANSPOSE_CURRENT_MATRIX_ARB   0x88B7
#define GL_CURRENT_MATRIX_STACK_DEPTH_ARB 0x8640
#define GL_MAX_PROGRAM_MATRICES_ARB       0x862F
#define GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB 0x862E
#define GL_MAX_TEXTURE_COORDS_ARB         0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_ARB    0x8872
#define GL_PROGRAM_ERROR_STRING_ARB       0x8874
#define GL_MATRIX0_ARB                    0x88C0
#define GL_MATRIX1_ARB                    0x88C1
#define GL_MATRIX2_ARB                    0x88C2
#define GL_MATRIX3_ARB                    0x88C3
#define GL_MATRIX4_ARB                    0x88C4
#define GL_MATRIX5_ARB                    0x88C5
#define GL_MATRIX6_ARB                    0x88C6
#define GL_MATRIX7_ARB                    0x88C7
#define GL_MATRIX8_ARB                    0x88C8
#define GL_MATRIX9_ARB                    0x88C9
#define GL_MATRIX10_ARB                   0x88CA
#define GL_MATRIX11_ARB                   0x88CB
#define GL_MATRIX12_ARB                   0x88CC
#define GL_MATRIX13_ARB                   0x88CD
#define GL_MATRIX14_ARB                   0x88CE
#define GL_MATRIX15_ARB                   0x88CF
#define GL_MATRIX16_ARB                   0x88D0
#define GL_MATRIX17_ARB                   0x88D1
#define GL_MATRIX18_ARB                   0x88D2
#define GL_MATRIX19_ARB                   0x88D3
#define GL_MATRIX20_ARB                   0x88D4
#define GL_MATRIX21_ARB                   0x88D5
#define GL_MATRIX22_ARB                   0x88D6
#define GL_MATRIX23_ARB                   0x88D7
#define GL_MATRIX24_ARB                   0x88D8
#define GL_MATRIX25_ARB                   0x88D9
#define GL_MATRIX26_ARB                   0x88DA
#define GL_MATRIX27_ARB                   0x88DB
#define GL_MATRIX28_ARB                   0x88DC
#define GL_MATRIX29_ARB                   0x88DD
#define GL_MATRIX30_ARB                   0x88DE
#define GL_MATRIX31_ARB                   0x88DF
typedef void (APIENTRYP PFNGLPROGRAMSTRINGARBPROC) (GLenum target, GLenum format, GLsizei len, const void *string);
typedef void (APIENTRYP PFNGLBINDPROGRAMARBPROC) (GLenum target, GLuint program);
typedef void (APIENTRYP PFNGLDELETEPROGRAMSARBPROC) (GLsizei n, const GLuint *programs);
typedef void (APIENTRYP PFNGLGENPROGRAMSARBPROC) (GLsizei n, GLuint *programs);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETER4DARBPROC) (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETER4DVARBPROC) (GLenum target, GLuint index, const GLdouble *params);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETER4FARBPROC) (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETER4FVARBPROC) (GLenum target, GLuint index, const GLfloat *params);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETER4DARBPROC) (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETER4DVARBPROC) (GLenum target, GLuint index, const GLdouble *params);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETER4FARBPROC) (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETER4FVARBPROC) (GLenum target, GLuint index, const GLfloat *params);
typedef void (APIENTRYP PFNGLGETPROGRAMENVPARAMETERDVARBPROC) (GLenum target, GLuint index, GLdouble *params);
typedef void (APIENTRYP PFNGLGETPROGRAMENVPARAMETERFVARBPROC) (GLenum target, GLuint index, GLfloat *params);
typedef void (APIENTRYP PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC) (GLenum target, GLuint index, GLdouble *params);
typedef void (APIENTRYP PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC) (GLenum target, GLuint index, GLfloat *params);
typedef void (APIENTRYP PFNGLGETPROGRAMIVARBPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETPROGRAMSTRINGARBPROC) (GLenum target, GLenum pname, void *string);
typedef GLboolean (APIENTRYP PFNGLISPROGRAMARBPROC) (GLuint program);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glProgramStringARB (GLenum target, GLenum format, GLsizei len, const void *string);
GLAPI void APIENTRY glBindProgramARB (GLenum target, GLuint program);
GLAPI void APIENTRY glDeleteProgramsARB (GLsizei n, const GLuint *programs);
GLAPI void APIENTRY glGenProgramsARB (GLsizei n, GLuint *programs);
GLAPI void APIENTRY glProgramEnvParameter4dARB (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void APIENTRY glProgramEnvParameter4dvARB (GLenum target, GLuint index, const GLdouble *params);
GLAPI void APIENTRY glProgramEnvParameter4fARB (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void APIENTRY glProgramEnvParameter4fvARB (GLenum target, GLuint index, const GLfloat *params);
GLAPI void APIENTRY glProgramLocalParameter4dARB (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLAPI void APIENTRY glProgramLocalParameter4dvARB (GLenum target, GLuint index, const GLdouble *params);
GLAPI void APIENTRY glProgramLocalParameter4fARB (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLAPI void APIENTRY glProgramLocalParameter4fvARB (GLenum target, GLuint index, const GLfloat *params);
GLAPI void APIENTRY glGetProgramEnvParameterdvARB (GLenum target, GLuint index, GLdouble *params);
GLAPI void APIENTRY glGetProgramEnvParameterfvARB (GLenum target, GLuint index, GLfloat *params);
GLAPI void APIENTRY glGetProgramLocalParameterdvARB (GLenum target, GLuint index, GLdouble *params);
GLAPI void APIENTRY glGetProgramLocalParameterfvARB (GLenum target, GLuint index, GLfloat *params);
GLAPI void APIENTRY glGetProgramivARB (GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetProgramStringARB (GLenum target, GLenum pname, void *string);
GLAPI GLboolean APIENTRY glIsProgramARB (GLuint program);
#endif
#endif /* GL_ARB_fragment_program */

#ifndef GL_ARB_fragment_program_shadow
#define GL_ARB_fragment_program_shadow 1
#endif /* GL_ARB_fragment_program_shadow */

#ifndef GL_ARB_fragment_shader
#define GL_ARB_fragment_shader 1
#define GL_FRAGMENT_SHADER_ARB            0x8B30
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB 0x8B49
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB 0x8B8B
#endif /* GL_ARB_fragment_shader */

#ifndef GL_ARB_fragment_shader_interlock
#define GL_ARB_fragment_shader_interlock 1
#endif /* GL_ARB_fragment_shader_interlock */

#ifndef GL_ARB_framebuffer_no_attachments
#define GL_ARB_framebuffer_no_attachments 1
#endif /* GL_ARB_framebuffer_no_attachments */

#ifndef GL_ARB_framebuffer_object
#define GL_ARB_framebuffer_object 1
#endif /* GL_ARB_framebuffer_object */

#ifndef GL_ARB_framebuffer_sRGB
#define GL_ARB_framebuffer_sRGB 1
#endif /* GL_ARB_framebuffer_sRGB */

#ifndef GL_ARB_geometry_shader4
#define GL_ARB_geometry_shader4 1
#define GL_LINES_ADJACENCY_ARB            0x000A
#define GL_LINE_STRIP_ADJACENCY_ARB       0x000B
#define GL_TRIANGLES_ADJACENCY_ARB        0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_ARB   0x000D
#define GL_PROGRAM_POINT_SIZE_ARB         0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB 0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB 0x8DA9
#define GL_GEOMETRY_SHADER_ARB            0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_ARB      0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_ARB        0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_ARB       0x8DDC
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB 0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_ARB 0x8DDE
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB 0x8DE1
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIARBPROC) (GLuint program, GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREARBPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERARBPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREFACEARBPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glProgramParameteriARB (GLuint program, GLenum pname, GLint value);
GLAPI void APIENTRY glFramebufferTextureARB (GLenum target, GLenum attachment, GLuint texture, GLint level);
GLAPI void APIENTRY glFramebufferTextureLayerARB (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLAPI void APIENTRY glFramebufferTextureFaceARB (GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
#endif
#endif /* GL_ARB_geometry_shader4 */

#ifndef GL_ARB_get_program_binary
#define GL_ARB_get_program_binary 1
#endif /* GL_ARB_get_program_binary */

#ifndef GL_ARB_get_texture_sub_image
#define GL_ARB_get_texture_sub_image 1
#endif /* GL_ARB_get_texture_sub_image */

#ifndef GL_ARB_gl_spirv
#define GL_ARB_gl_spirv 1
#define GL_SHADER_BINARY_FORMAT_SPIR_V_ARB 0x9551
#define GL_SPIR_V_BINARY_ARB              0x9552
typedef void (APIENTRYP PFNGLSPECIALIZESHADERARBPROC) (GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glSpecializeShaderARB (GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue);
#endif
#endif /* GL_ARB_gl_spirv */

#ifndef GL_ARB_gpu_shader5
#define GL_ARB_gpu_shader5 1
#endif /* GL_ARB_gpu_shader5 */

#ifndef GL_ARB_gpu_shader_fp64
#define GL_ARB_gpu_shader_fp64 1
#endif /* GL_ARB_gpu_shader_fp64 */

#ifndef GL_ARB_gpu_shader_int64
#define GL_ARB_gpu_shader_int64 1
#define GL_INT64_ARB                      0x140E
#define GL_INT64_VEC2_ARB                 0x8FE9
#define GL_INT64_VEC3_ARB                 0x8FEA
#define GL_INT64_VEC4_ARB                 0x8FEB
#define GL_UNSIGNED_INT64_VEC2_ARB        0x8FF5
#define GL_UNSIGNED_INT64_VEC3_ARB        0x8FF6
#define GL_UNSIGNED_INT64_VEC4_ARB        0x8FF7
typedef void (APIENTRYP PFNGLUNIFORM1I64ARBPROC) (GLint location, GLint64 x);
typedef void (APIENTRYP PFNGLUNIFORM2I64ARBPROC) (GLint location, GLint64 x, GLint64 y);
typedef void (APIENTRYP PFNGLUNIFORM3I64ARBPROC) (GLint location, GLint64 x, GLint64 y, GLint64 z);
typedef void (APIENTRYP PFNGLUNIFORM4I64ARBPROC) (GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
typedef void (APIENTRYP PFNGLUNIFORM1I64VARBPROC) (GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLUNIFORM2I64VARBPROC) (GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLUNIFORM3I64VARBPROC) (GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLUNIFORM4I64VARBPROC) (GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLUNIFORM1UI64ARBPROC) (GLint location, GLuint64 x);
typedef void (APIENTRYP PFNGLUNIFORM2UI64ARBPROC) (GLint location, GLuint64 x, GLuint64 y);
typedef void (APIENTRYP PFNGLUNIFORM3UI64ARBPROC) (GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
typedef void (APIENTRYP PFNGLUNIFORM4UI64ARBPROC) (GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
typedef void (APIENTRYP PFNGLUNIFORM1UI64VARBPROC) (GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLUNIFORM2UI64VARBPROC) (GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLUNIFORM3UI64VARBPROC) (GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLUNIFORM4UI64VARBPROC) (GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLGETUNIFORMI64VARBPROC) (GLuint program, GLint location, GLint64 *params);
typedef void (APIENTRYP PFNGLGETUNIFORMUI64VARBPROC) (GLuint program, GLint location, GLuint64 *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMI64VARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLint64 *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMUI64VARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLuint64 *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64ARBPROC) (GLuint program, GLint location, GLint64 x);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64ARBPROC) (GLuint program, GLint location, GLint64 x, GLint64 y);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64ARBPROC) (GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64ARBPROC) (GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64ARBPROC) (GLuint program, GLint location, GLuint64 x);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64ARBPROC) (GLuint program, GLint location, GLuint64 x, GLuint64 y);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64ARBPROC) (GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64ARBPROC) (GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLuint64 *value);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glUniform1i64ARB (GLint location, GLint64 x);
GLAPI void APIENTRY glUniform2i64ARB (GLint location, GLint64 x, GLint64 y);
GLAPI void APIENTRY glUniform3i64ARB (GLint location, GLint64 x, GLint64 y, GLint64 z);
GLAPI void APIENTRY glUniform4i64ARB (GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
GLAPI void APIENTRY glUniform1i64vARB (GLint location, GLsizei count, const GLint64 *value);
GLAPI void APIENTRY glUniform2i64vARB (GLint location, GLsizei count, const GLint64 *value);
GLAPI void APIENTRY glUniform3i64vARB (GLint location, GLsizei count, const GLint64 *value);
GLAPI void APIENTRY glUniform4i64vARB (GLint location, GLsizei count, const GLint64 *value);
GLAPI void APIENTRY glUniform1ui64ARB (GLint location, GLuint64 x);
GLAPI void APIENTRY glUniform2ui64ARB (GLint location, GLuint64 x, GLuint64 y);
GLAPI void APIENTRY glUniform3ui64ARB (GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
GLAPI void APIENTRY glUniform4ui64ARB (GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
GLAPI void APIENTRY glUniform1ui64vARB (GLint location, GLsizei count, const GLuint64 *value);
GLAPI void APIENTRY glUniform2ui64vARB (GLint location, GLsizei count, const GLuint64 *value);
GLAPI void APIENTRY glUniform3ui64vARB (GLint location, GLsizei count, const GLuint64 *value);
GLAPI void APIENTRY glUniform4ui64vARB (GLint location, GLsizei count, const GLuint64 *value);
GLAPI void APIENTRY glGetUniformi64vARB (GLuint program, GLint location, GLint64 *params);
GLAPI void APIENTRY glGetUniformui64vARB (GLuint program, GLint location, GLuint64 *params);
GLAPI void APIENTRY glGetnUniformi64vARB (GLuint program, GLint location, GLsizei bufSize, GLint64 *params);
GLAPI void APIENTRY glGetnUniformui64vARB (GLuint program, GLint location, GLsizei bufSize, GLuint64 *params);
GLAPI void APIENTRY glProgramUniform1i64ARB (GLuint program, GLint location, GLint64 x);
GLAPI void APIENTRY glProgramUniform2i64ARB (GLuint program, GLint location, GLint64 x, GLint64 y);
GLAPI void APIENTRY glProgramUniform3i64ARB (GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z);
GLAPI void APIENTRY glProgramUniform4i64ARB (GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
GLAPI void APIENTRY glProgramUniform1i64vARB (GLuint program, GLint location, GLsizei count, const GLint64 *value);
GLAPI void APIENTRY glProgramUniform2i64vARB (GLuint program, GLint location, GLsizei count, const GLint64 *value);
GLAPI void APIENTRY glProgramUniform3i64vARB (GLuint program, GLint location, GLsizei count, const GLint64 *value);
GLAPI void APIENTRY glProgramUniform4i64vARB (GLuint program, GLint location, GLsizei count, const GLint64 *value);
GLAPI void APIENTRY glProgramUniform1ui64ARB (GLuint program, GLint location, GLuint64 x);
GLAPI void APIENTRY glProgramUniform2ui64ARB (GLuint program, GLint location, GLuint64 x, GLuint64 y);
GLAPI void APIENTRY glProgramUniform3ui64ARB (GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
GLAPI void APIENTRY glProgramUniform4ui64ARB (GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
GLAPI void APIENTRY glProgramUniform1ui64vARB (GLuint program, GLint location, GLsizei count, const GLuint64 *value);
GLAPI void APIENTRY glProgramUniform2ui64vARB (GLuint program, GLint location, GLsizei count, const GLuint64 *value);
GLAPI void APIENTRY glProgramUniform3ui64vARB (GLuint program, GLint location, GLsizei count, const GLuint64 *value);
GLAPI void APIENTRY glProgramUniform4ui64vARB (GLuint program, GLint location, GLsizei count, const GLuint64 *value);
#endif
#endif /* GL_ARB_gpu_shader_int64 */

#ifndef GL_ARB_half_float_pixel
#define GL_ARB_half_float_pixel 1
typedef khronos_uint16_t GLhalfARB;
#define GL_HALF_FLOAT_ARB                 0x140B
#endif /* GL_ARB_half_float_pixel */

#ifndef GL_ARB_half_float_vertex
#define GL_ARB_half_float_vertex 1
#endif /* GL_ARB_half_float_vertex */

#ifndef GL_ARB_imaging
#define GL_ARB_imaging 1
#define GL_CONVOLUTION_BORDER_MODE        0x8013
#define GL_CONVOLUTION_FILTER_SCALE       0x8014
#define GL_CONVOLUTION_FILTER_BIAS        0x8015
#define GL_REDUCE                         0x8016
#define GL_CONVOLUTION_FORMAT             0x8017
#define GL_CONVOLUTION_WIDTH              0x8018
#define GL_CONVOLUTION_HEIGHT             0x8019
#define GL_MAX_CONVOLUTION_WIDTH          0x801A
#define GL_MAX_CONVOLUTION_HEIGHT         0x801B
#define GL_POST_CONVOLUTION_RED_SCALE     0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE   0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE    0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE   0x801F
#define GL_POST_CONVOLUTION_RED_BIAS      0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS    0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS     0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS    0x8023
#define GL_HISTOGRAM_WIDTH                0x8026
#define GL_HISTOGRAM_FORMAT               0x8027
#define GL_HISTOGRAM_RED_SIZE             0x8028
#define GL_HISTOGRAM_GREEN_SIZE           0x8029
#define GL_HISTOGRAM_BLUE_SIZE            0x802A
#define GL_HISTOGRAM_ALPHA_SIZE           0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE       0x802C
#define GL_HISTOGRAM_SINK                 0x802D
#define GL_MINMAX_FORMAT                  0x802F
#define GL_MINMAX_SINK                    0x8030
#define GL_TABLE_TOO_LARGE                0x8031
#define GL_COLOR_MATRIX                   0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH       0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH   0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE    0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE  0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE   0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE  0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS     0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS   0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS    0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS   0x80BB
#define GL_COLOR_TABLE_SCALE              0x80D6
#define GL_COLOR_TABLE_BIAS               0x80D7
#define GL_COLOR_TABLE_FORMAT             0x80D8
#define GL_COLOR_TABLE_WIDTH              0x80D9
#define GL_COLOR_TABLE_RED_SIZE           0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE         0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE          0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE         0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE     0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE     0x80DF
#define GL_CONSTANT_BORDER                0x8151
#define GL_REPLICATE_BORDER               0x8153
#define GL_CONVOLUTION_BORDER_COLOR       0x8154
typedef void (APIENTRYP PFNGLCOLORTABLEPROC) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *table);
typedef void (APIENTRYP PFNGLCOLORTABLEPARAMETERFVPROC) (GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLCOLORTABLEPARAMETERIVPROC) (GLenum target, GLenum pname, 