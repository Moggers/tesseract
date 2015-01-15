#ifndef IG_DEBUG
#define IG_DEBUG
#include <GL/gl.h>
void debug_check_gl_error( char * a );
void debug_check_glsl_error( char * a, GLuint shader );
void debug_check_sdl_error( char * a );
#ifdef DEBUG
#include <stdio.h>
#define debug_printf( ... ) fprintf( stdout, __VA_ARGS__ )
#else
#define debug_printf( ... )
#endif // DEBUG
#endif // IG_DEBUG
