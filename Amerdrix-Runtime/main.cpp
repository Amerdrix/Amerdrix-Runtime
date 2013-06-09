#include "VirtMachine.h"
#include "Instruction.h"
#include <vector>
int main()
{
	VM::InstructionList list;

	VM::Instruction* inst;

	inst = new VM::Instruction();
	inst->operation = VM::PUTA;
	list.push_back(*inst);  // 0

	inst = new VM::Instruction();
	inst->operation = VM::PUTB;
	list.push_back(*inst);  // 1


	inst = new VM::Instruction();
	inst->operation = VM::BNE;
	inst->arguments.push_back(6);
	list.push_back(*inst);  // 2
	
	inst = new VM::Instruction();
	inst->operation = VM::LOADB;
	inst->arguments.push_back(1);
	list.push_back(*inst); // 3
	
	inst = new VM::Instruction();
	inst->operation = VM::NOP;
	list.push_back(*inst); // 4

	inst = new VM::Instruction();
	inst->operation = VM::JUMP;
	inst->arguments.push_back(0);
	list.push_back(*inst); // 5
	
	inst = new VM::Instruction();
	inst->operation = VM::MOV_B_A;
	list.push_back(*inst);  // 6

	inst = new VM::Instruction();
	inst->operation = VM::PUTB;
	list.push_back(*inst);  // 7

	inst = new VM::Instruction();
	inst->operation = VM::ADDI;
	list.push_back(*inst);  // 8

	inst = new VM::Instruction();
	inst->operation = VM::MOV_ACC_A;
	list.push_back(*inst);  // 9

	inst = new VM::Instruction();
	inst->operation = VM::MOV_A_B;
	list.push_back(*inst);  // A

	inst = new VM::Instruction();
	inst->operation = VM::MULI;
	list.push_back(*inst);  // B

	inst = new VM::Instruction();
	inst->operation = VM::MOV_ACC_A;
	list.push_back(*inst);  // C

	inst = new VM::Instruction();
	inst->operation = VM::PUTA;
	list.push_back(*inst);  // D

	inst = new VM::Instruction();
	inst->operation = VM::LOADB;
	inst->arguments.push_back(32);
	list.push_back(*inst);  // E

	inst = new VM::Instruction();
	inst->operation = VM::BLTE;
	inst->arguments.push_back(0x0A);
	list.push_back(*inst);  // F

	inst = new VM::Instruction();
	inst->operation = VM::END;
	list.push_back(*inst);  // 5

	VM::VirtMachine* vm = new VM::VirtMachine(list);

	int result = vm->Execute();

	printf("\n\nExited with code (%04d)\n", result);
	return result;
}