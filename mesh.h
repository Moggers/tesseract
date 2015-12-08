#ifndef IG_MESH
#define IG_MESH

#include "vec4f.h"

typedef int mesh_id_t;

mesh_id_t mesh_create( int vertcount, vec4f_t * in_verts );
mesh_id_t mesh_load( char * filename );
void mesh_print_contents( mesh_id_t meshid );

#endif //IG_MESH
