#ifndef IG_MESH
#define IG_MESH

#include "vec4f.h"

typedef int mesh_id_t;

mesh_id_t mesh_create( int vertcount, vec4f_t * in_verts );

#endif //IG_MESH
