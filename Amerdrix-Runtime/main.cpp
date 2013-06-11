#include "VirtMachine.h"
#include "Instruction.h"
#include <vector>
int main()
{
	VM::InstructionList list;

	VM::Instruction* inst;

	inst = new VM::Instruction();
	inst->operation = VM::STACK_ALLOC;
	inst->arguments.push_back(4);
	list.push_back(*inst);  // 0

	inst = new VM::Instruction();
	inst->operation = VM::STACK_ALLOC;
	inst->arguments.push_back(2);
	list.push_back(*inst);  // 0

	inst = new VM::Instruction();
	inst->operation = VM::END;
	list.push_back(*inst);  // E

	VM::VirtMachine* vm = new VM::VirtMachine(list);

	int result = vm->Execute();

	printf("\n\nExited with code (%04d)\n", result);
	return result;
}