#include "VirtMachine.h"
#include "Instruction.h"
#include <vector>
int main()
{
	VM::InstructionList list;

	VM::Instruction* inst;

	inst = new VM::Instruction();
	inst->operation = VM::BNE;
	inst->arguments.push_back(4);
	list.push_back(*inst);  // 0
	
	inst = new VM::Instruction();
	inst->operation = VM::LOADB;
	inst->arguments.push_back(1);
	list.push_back(*inst); // 1
	
	inst = new VM::Instruction();
	inst->operation = VM::NOP;
	list.push_back(*inst); // 2

	inst = new VM::Instruction();
	inst->operation = VM::JUMP;
	inst->arguments.push_back(0);

	list.push_back(*inst); // 3
	
	inst = new VM::Instruction();
	inst->operation = VM::CALL;
	inst->arguments.push_back(6);
	list.push_back(*inst);  // 4

	inst = new VM::Instruction();
	inst->operation = VM::END;
	list.push_back(*inst);  // 5


	inst = new VM::Instruction();
	inst->operation = VM::NOP;
	list.push_back(*inst);  // 6

	inst = new VM::Instruction();
	inst->operation = VM::RETURN;
	list.push_back(*inst);  // 7


	VM::VirtMachine* vm = new VM::VirtMachine(list);

	int result = vm->Execute();

	printf("\n\nExited with code (%04d)\n", result);
	return result;

}