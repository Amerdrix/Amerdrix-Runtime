#pragma once

#include "Operations.h"
#include <vector>

namespace VM
{
	typedef std::vector<int> ArgumentList;
	struct Instruction
	{
		VM::Operations operation;
		ArgumentList arguments;
	};

	typedef std::vector<Instruction> InstructionList;
}