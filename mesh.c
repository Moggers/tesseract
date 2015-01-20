#include "mesh.h"
#include "render.h"


typedef struct mesh_s
{
	int meshid;
	int vertcount;
	vec4f_t * verts;

} mesh_t;
typedef mesh_t * mesh_set_t[128];

static mesh_set_t meshset;
static mesh_id_t mesh_count;

mesh_id_t mesh_create( int vertcount, vec4f_t * in_verts )
{
	if( mesh_count >= 128 ) return -1;

	mesh_t * m = malloc( sizeof( mesh_t ) );
	m->vertcount = vertcount;
	m->verts = in_verts;
	meshset[mesh_count] = m;
	return mesh_count++;
}
