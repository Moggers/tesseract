#include "engine.h"
#include <SDL2/SDL.h>
#include "render.h"
#include "debug.h"

static SDL_Window * engine_window;

int engine_init_sdl( SDL_Window ** in_window )
{
	SDL_Init( SDL_INIT_EVERYTHING );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );
	*in_window = SDL_CreateWindow( "Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL );
	debug_check_sdl_error( "creating window" );
}

 int engine_start( void )
{
	engine_init_sdl( &engine_window );
	render_init( engine_window );
}
