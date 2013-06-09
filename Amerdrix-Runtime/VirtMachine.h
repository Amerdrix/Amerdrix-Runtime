#pragma once
#include "Instruction.h"
#include <vector>
#include <stack>



namespace VM
{
	class VirtMachine
	{
	private:
		typedef void(VirtMachine::*Operation)(const ArgumentList &args);
		InstructionList instructionList;

		Operation operations[MAX_OPCODE];

		int reg_a;
		int reg_b;
		int accumuliator;
		unsigned int pc;

		std::stack<unsigned int> pc_stack;


	public:
		VirtMachine(const InstructionList &list);
		~VirtMachine(void);	

		int Execute(void);

		void op_nop(const ArgumentList &);
		void op_be(const ArgumentList &);
		void op_bne(const ArgumentList &);
		void op_blt(const ArgumentList &);
		void op_blte(const ArgumentList &);
		void op_bgt(const ArgumentList &);
		void op_bgte(const ArgumentList &);
		
		void op_loada(const ArgumentList &);
		void op_loadb(const ArgumentList &);

		void op_mov_b_a(const ArgumentList &);
		void op_mov_a_b(const ArgumentList &);
		void op_mov_acca(const ArgumentList &);
		void op_mov_accb(const ArgumentList &);

		void op_jump(const ArgumentList &);

		void op_call(const ArgumentList &);
		void op_return(const ArgumentList &);

		void op_addi(const ArgumentList &);
		void op_subi(const ArgumentList &);
		void op_muli(const ArgumentList &);
		void op_divi(const ArgumentList &);

		void op_puta(const ArgumentList &);
		void op_putb(const ArgumentList &);


	};
};