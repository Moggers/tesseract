#include "render.h"
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include "debug.h"

static SDL_Thread * render_thread;
static SDL_GLContext render_glcontext;
static GLuint render_program;
static char * render_vs_source[] = {
	"#version 330 core\n"
	"void main(void)\n"
	"{\n"
	"	gl_Position = vec4( 0.0, 0.0, 0.5, 1.0);\n"
	"}\n"
};
static char * render_fs_source[] = {
	"#version 330 core\n"
	"flat in vec4 vcolor;\n"
	"out vec4 color;\n"
	"void main(void)\n"
	"{\n"
	"	color = vcolor;\n"
	"}\n"
};


GLuint render_build_program( GLuint * in_program )
{
	GLuint vshader, fshader;

	vshader = glCreateShader( GL_VERTEX_SHADER );
	glShaderSource( vshader, 1, render_vs_source, NULL );
	glCompileShader( vshader );
	debug_check_glsl_error( "compiling vertex shader", vshader );

	fshader = glCreateShader( GL_FRAGMENT_SHADER );
	glShaderSource( fshader, 1, render_fs_source, NULL );
	glCompileShader( fshader );
	debug_check_glsl_error( "compiling fragment shader", fshader );

	*in_program = glCreateProgram();
	glAttachShader( *in_program, vshader );
	glAttachShader( *in_program, fshader );
	glLinkProgram( *in_program );
	debug_check_gl_error( "building GLSL program" );

	glDeleteShader( vshader );
	glDeleteShader( fshader );
	return 0;
}

int render_init_gl( SDL_GLContext * in_glcontext, SDL_Window * in_window )
{
	*in_glcontext = SDL_GL_CreateContext( in_window );
	debug_check_sdl_error( "creating GL context" );
	glClearColor( 1.f, 1.f, 1.f, 1.f );
	glClear( GL_COLOR_BUFFER_BIT );
	SDL_GL_SwapWindow( in_window );
	render_build_program( &render_program);
	debug_check_gl_error( "initializing GL" );
	debug_check_sdl_error( "initializing SDL" );
	return 0;
}

int render_destroy_gl( SDL_GLContext in_glcontext )
{
	SDL_GL_DeleteContext( in_glcontext );
	SDL_Quit();
}

int render_function( void * data )
{
	render_init_gl( &render_glcontext, (SDL_Window*)data );
	render_destroy_gl( render_glcontext );
}

int render_init( SDL_Window * in_window )
{
	render_thread = SDL_CreateThread( render_function, "render_thread", (void*)in_window );
	if( render_thread == NULL )
	{
		debug_printf( "Render thread creation failure: %s\n", SDL_GetError() );
		return 1;
	}
	return 0;
}
