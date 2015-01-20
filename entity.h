#ifndef IG_ENTITY
#define IG_ENTITY

#include "vec4f.h"
#include "mesh.h"

typedef struct entity_s
{
	mesh_id_t mesh;
	vec4f_t pos;
	vec4f_t ang;
	vec4f_t sca;
} entity_t;

void entity_create( entity_t ** ent, mesh_id_t mesh );
void entity_set_pos( entity_t * ent, vec4f_t * pos );
void entity_set_ang( entity_t * ent, vec4f_t * ang );
void entity_set_sca( entity_t * ent, vec4f_t * sca );

#endif //IG_ENTITY
