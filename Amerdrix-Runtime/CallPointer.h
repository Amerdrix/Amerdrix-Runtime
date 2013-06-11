#pragma once
namespace VM
{
	typedef unsigned int InstructionPointer;
	typedef unsigned int StackPointer;
	struct CallPointer
	{
		InstructionPointer instruction_pointer;
		StackPointer stack_head;
	};
}