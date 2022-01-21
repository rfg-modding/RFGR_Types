#include "common/Typedefs.h"
#include "rfg/Vector.h"
#include "rfg/Matrix.h"
#include "rfg/Containers.h"
#include "rfg/render_lib/Mesh.h"
#include "rfg/physics/RfgDestroyableShape.h"

struct rl_fp_aabb
{
	__int16 min_x;
	__int16 min_y;
	__int16 min_z;
	__int16 max_x;
	__int16 max_y;
	__int16 max_z;
};

struct rl_fp_kdtree_node
{
	__int16 plane_offset;
	unsigned __int16 plane_axis;
	unsigned __int16 left_offset;
	unsigned __int16 right_offset;
	unsigned __int16 leaf_offset;
	unsigned __int16 num_leaves;
	unsigned int pad;
};

struct rl_fp_kdtree_leaf
{
	rl_fp_aabb aabb;
	unsigned int data;
};

struct rl_fp_kdtree_base_data
{
	int num_nodes;
	et_ptr_offset<rl_fp_kdtree_node, 0> nodes;
	int num_leaves;
	et_ptr_offset<rl_fp_kdtree_leaf, 0> leaves;
	et_ptr_offset<unsigned short, 0> leaf_map;
};

struct c_object_skirt_edge
{
	vector point[2];
	vector norm[2];
};

struct c_object_skirt
{
	unsigned __int16 rl_submesh_idx;
	int num_weld_edges;
	et_sized_native_pointer<c_object_skirt_edge> weld_edges;
};

struct c_script_point
{
	matrix43 transform;
	char name[32];
	char sub_piece_name[32];
	unsigned int destroyable_idx;
};

struct c_object_identifier
{
	unsigned int unique_id;
	char name[24];
	int object_index;
	unsigned int is_destroyable;
	unsigned int num_snap_points;
	matrix43 snap_points[10];
};

struct rbb_tree_node
{
	int num_objects;
	vector mn;
	vector mx;
	char* node_data;
};

struct rbb_tree
{
	int obj_size;
	void(__cdecl* leaf_cb)(void*);
	rbb_tree_node* nodes;
};

struct __declspec(align(8)) c_light_clip_object
{
	et_sized_native_pointer<char> name;
	vector bmin;
	vector bmax;
	vector pos;
	matrix orient;
	unsigned __int16 submesh_idx;
	unsigned __int16 object_identifier_index;
};

struct __declspec(align(8)) general_object_base
{
	et_sized_native_pointer<char> name;
	vector bmin;
	vector bmax;
	vector initial_pos;
	matrix initial_orient;
	unsigned __int16 collision_models[2];
	unsigned __int16 flags;
	__int16 mesh_subpieces[2];
	char padding[2];
};

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
	et_sized_native_pointer<et_sized_native_pointer<rfg_base_destroyable_shape> > base_destroyables;
	et_sized_native_pointer<rbb_tree> rbb_parent_lods;
	et_sized_native_pointer<et_sized_native_pointer<c_chunk_base>> next;
	et_sized_native_pointer<et_sized_native_pointer<c_chunk_base>> prev;
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