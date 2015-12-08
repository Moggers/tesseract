#include "mesh.h"
#include "render.h"
#include "stdio.h"
#include "debug.h"


typedef struct mesh_s
{
	int meshid;
	int vertcount;
	vec4f_t * verts;

} mesh_t;
typedef mesh_t * mesh_set_t[128];

static mesh_set_t meshset;
static mesh_id_t mesh_count;

// Take an array of verts, throw them on the mesh stack, and return the unique ID.
mesh_id_t mesh_create( int vertcount, vec4f_t * in_verts )
{
	if( mesh_count >= 128 ) return -1;

	mesh_t * m = malloc( sizeof( mesh_t ) );
	m->vertcount = vertcount;
	m->verts = in_verts;
	meshset[mesh_count] = m;
	return mesh_count++;
}

// Build a mesh from the contents of a file.
mesh_id_t mesh_load( char * filename )
{
	FILE * file = fopen( filename, "r" );
	vec4f_t * verts;
	int tricount;
	if( file != 0 ) {
		debug_printf( "Found a file " );
		tricount = 0;
		fscanf( file, "%u\n", &tricount );
		debug_printf( "with %u tris\n", tricount );
		verts = calloc( tricount * 3, sizeof( vec4f_t ) );
		int ii, tt;
		for( ii = 0; ii < (tricount / 3); ii++ ) {
			fscanf( file, "\n", NULL );
			for( tt = 0; tt < 3; tt++ ) {
				int vid = ii * 3 + tt;
				fscanf( file, "%d %d %d\n", &verts[vid][0], &verts[vid][1], &verts[vid][2] );
			}
		}
		return mesh_create( tricount, verts );
	} else {
		debug_printf( "Failed to find mesh file\n" );
	}
}
