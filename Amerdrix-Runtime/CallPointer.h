#pragma once
namespace VM
{
	typedef unsigned int PcPointer;
	typedef unsigned int StackPointer;
	struct CallPointer
	{
		PcPointer pc;
		StackPointer stack_head;
	};
}