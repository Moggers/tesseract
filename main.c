#include <stdlib.h>
#include <stdio.h>
#include "debug.h"
#include "engine.h"

int main( int argc, char ** argv )
{
	debug_printf( "Hello world, this is main thread!\n" );
	engine_start();
	getchar();
	return 0;
}
