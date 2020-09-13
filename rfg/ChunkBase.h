#pragma once
#include "Containers.h"
#include "Vector.h"
#include "destruction/GeneralObjectBase.h"
#include "destruction/DestroyableBaseShape.h"
#include "destruction/RbbTree.h"
#include "destruction/DestructionMisc.h"
#include "render/Mesh.h"
#include "render/MaterialMap.h"
#include "render/Material.h"

struct __declspec(align(8)) c_chunk_base
{
    unsigned int signature;
    unsigned int version;
    unsigned int source_rfgchunkx_version;
    unsigned int render_data_checksum;
    unsigned int render_cpu_data_offset;
    unsigned int render_cpu_data_size;
    unsigned int collision_model_checksum;
    unsigned int collision_model_data_offset;
    unsigned int collision_model_data_size;
    unsigned int destruction_checksum;
    unsigned int destruction_offset;
    unsigned int destruction_datasize;
    char name[128];
    char filename[128];
    vector bmin;
    vector bmax;
    et_sized_native_pointer<rl_mesh> mesh_p;
    et_sized_native_pointer<rl_material_map> material_map_p;
    et_sized_native_pointer<et_sized_native_pointer<rl_material> > rl_materials;
    unsigned int num_rl_materials;
    int num_general_objects;
    et_sized_native_pointer<general_object_base> general_objects;
    int num_base_destroyables;
    et_sized_native_pointer<et_sized_native_pointer<rfg_base_destroyable_shape>> base_destroyables;
    et_sized_native_pointer<rbb_tree> rbb_parent_lods;
    et_sized_native_pointer<et_sized_native_pointer<c_chunk_base> > next;
    et_sized_native_pointer<et_sized_native_pointer<c_chunk_base> > prev;
    unsigned __int16 internal_uid;
    unsigned __int16 inst_ref_count;
    et_sized_native_pointer<unsigned char> stream_data;
    int data_size;
    int num_script_points;
    et_sized_native_pointer<c_script_point> script_points;
    et_sized_native_pointer<rbb_tree> rbb_shards;
    unsigned int num_object_identifiers;
    et_sized_native_pointer<c_object_identifier> object_identifiers;
    int num_object_skirts;
    et_sized_native_pointer<c_object_skirt> object_skirts;
    unsigned int mopp_handle;
    unsigned int texture_names_size;
    et_sized_native_pointer<char> texture_names;
    int num_light_clip_objects;
    et_sized_native_pointer<c_light_clip_object> light_clip_objects;
    unsigned int render_gpu_data_offset;
    unsigned int render_gpu_data_size;
    et_sized_native_pointer<et_sized_native_pointer<rl_fp_kdtree_base_data>> base_destroyable_kdtrees;
    et_sized_native_pointer<unsigned char> physics_data;
    bool physics_data_is_loaded;
    char future_use[115];
};

static const a = sizeof(c_chunk_base)