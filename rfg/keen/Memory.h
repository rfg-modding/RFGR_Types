#pragma once

namespace keen
{
	struct MemoryBlockDefinition
	{
		unsigned int size;
		unsigned int alignment;
		unsigned __int16 type;
		unsigned __int16 flags;
		unsigned int initialProtectionMask;
		const char* pDescription;
	};

	struct MemoryLayoutDefinition
	{
		keen::MemoryBlockDefinition* pBlockDefinitions;
		unsigned int blockCount;
	};
}