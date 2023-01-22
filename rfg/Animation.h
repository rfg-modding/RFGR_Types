#pragma once
#include "Vector.h"
#include "Matrix.h"

//TODO: Properly implement the templated version of this
struct et_ptr_offset_char_0
{
	int m_offset;

	void from_pointer(char* ptr)
	{
		m_offset = (int)ptr - (int)this;
	}

	char* to_pointer()
	{
		return (char*)((int)this + m_offset);
	}
};

struct anim_bone
{
	et_ptr_offset_char_0 name;
	vector inv_translation;
	vector rel_bone_translation;
	int parent_index;
	int vid;
};

struct anim_tag
{
	et_ptr_offset_char_0 name;
	matrix43 transformation;
	int parent_index;
	int vid;
};

struct anim_rig
{
	char name[32];
	unsigned int flags;
	int num_bones;
	int num_common_bones;
	int num_virtual_bones;
	int num_tags;
	unsigned int* bone_name_chksums;
	anim_bone* bones;
	anim_tag* tags;
	unsigned int data_size;
	char* original_buffer;
};

static_assert(sizeof(anim_rig) == 72, "anim_rig failed type size check.");