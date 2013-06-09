#include "VirtMachine.h"
#include "ErrorCodes.h"

#include <stdio.h>
namespace VM{

	VirtMachine::VirtMachine(const InstructionList &list)
	{
		this->instructionList = list;
		pc = 0;

		memset(operations, 0, sizeof(Operation) * 0xFF);
		operations[NOP] = &VirtMachine::op_nop;
		
		operations[BE] = &VirtMachine::op_be;
		operations[BNE] = &VirtMachine::op_bne;
		operations[BLT] = &VirtMachine::op_blt;
		operations[BLTE] = &VirtMachine::op_blte;
		operations[BGT] = &VirtMachine::op_bgt;
		operations[BGTE] = &VirtMachine::op_bgte;

		operations[LOADA] = &VirtMachine::op_loada;
		operations[LOADB] = &VirtMachine::op_loadb;
	
		operations[JUMP] = &VirtMachine::op_jump;
		operations[CALL] = &VirtMachine::op_call;
		operations[RETURN] = &VirtMachine::op_return;

		operations[ADDI] = &VirtMachine::op_addi;
		operations[SUBI] = &VirtMachine::op_subi;
		operations[MULI] = &VirtMachine::op_muli;
		operations[DIVI] = &VirtMachine::op_divi;
	}

	VirtMachine::~VirtMachine(void)
	{
		
	}

	int VirtMachine::Execute(void){

		while (true)
		{
			if (pc >= instructionList.size())
			{
				return MALFORMED_BYTE_CODE;
			}

			Instruction inst = instructionList.at(pc);
			printf("%04x:%02x\t", pc, inst.operation);

			Operation operationMethod = operations[inst.operation];

			if (inst.operation == END)
			{
				return 0;
			}

			if (operationMethod != nullptr)
			{
				(this->*operationMethod)(inst.arguments);
			}else
			{
				printf("UNDEFINED OP %02x\n", inst.operation);
				return MALFORMED_BYTE_CODE;
			}

			if (inst.operation & SequenceOpFlag)
			{
				++pc;
			}
		}

		return 0;
	}
	
	void VirtMachine::op_nop(const ArgumentList &args){
		printf("NOP\n");
	}

	void VirtMachine::op_be(const ArgumentList &args){
		if (reg_a == reg_b)
		{
			pc = args[0];
			printf("BN -> (%04x)\n", pc);
		}else
		{
			printf("BN (no jump)\n", pc);
			++pc;
		}
	}
	void VirtMachine::op_bne(const ArgumentList &args){
		if (reg_a != reg_b)
		{
			pc = args[0];
			printf("BNE -> (%04x)\n", pc);
		}else
		{
			printf("BNE (no jump)\n", pc);
			++pc;
		}
	}
	
	void VirtMachine::op_blt(const ArgumentList &args){
		if (reg_a < reg_b)
		{
			pc = args[0];
			printf("BLT -> (%04x)\n", pc);
		}else
		{
			printf("BLT (no jump)\n", pc);
			++pc;
		}
	}

	void VirtMachine::op_blte(const ArgumentList &args){
		if (reg_a <= reg_b)
		{
			pc = args[0];
			printf("BLTE -> (%04x)\n", pc);
		}else
		{
			printf("BLTE (no jump)\n", pc);
			++pc;
		}
	}
	void VirtMachine::op_bgt(const ArgumentList &args){
		if (reg_a < reg_b)
		{
			pc = args[0];
			printf("BGT -> (%04x)\n", pc);
		}else
		{
			printf("BGT (no jump)\n", pc);
			++pc;
		}
	}

	void VirtMachine::op_bgte(const ArgumentList &args){
		if (reg_a <= reg_b)
		{
			pc = args[0];
			printf("BGTE -> (%04x)\n", pc);
		}else
		{
			printf("BGTE (no jump)\n", pc);
			++pc;
		}
	}


	void VirtMachine::op_loada(const ArgumentList &args){
		reg_a = args[0];
		printf("LOADA (%04x)\n", reg_a);

	}

	void VirtMachine::op_loadb(const ArgumentList &args){
		reg_b = args[0];
		printf("LOADB (%04x)\n", reg_b);
	}

	void VirtMachine::op_jump(const ArgumentList &args){
		pc = args[0];
		printf("JUMP -> (%04x)\n", pc);
	}

	void VirtMachine::op_call(const ArgumentList &args){
		pc_stack.push(pc + 1);
		pc = args[0];
		printf("CALL -> (%04x)\n", pc);
	}

	void VirtMachine::op_return(const ArgumentList &args){
		pc = pc_stack.top();
		pc_stack.pop();
		printf("RETURN -> (%04x)\n", pc);
	}

	void VirtMachine::op_addi(const ArgumentList &args){
		accumuliator = reg_a + reg_b;
		printf("ADDI\n", pc);
	}
	
	void VirtMachine::op_subi(const ArgumentList &args){
		accumuliator = reg_a + reg_b;
		printf("SUBI\n", pc);
	}
	
	void VirtMachine::op_muli(const ArgumentList &args){
		accumuliator = reg_a + reg_b;
		printf("MULI\n", pc);
	}

	
	void VirtMachine::op_divi(const ArgumentList &args){
		accumuliator = reg_a / reg_b;
		printf("DIVI\n", pc);
	}
};