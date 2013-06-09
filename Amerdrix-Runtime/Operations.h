#pragma once
namespace VM
{
	enum OperationsFlags : unsigned short
	{
		SequenceOpFlag = 0x80,
	};

	enum Operations : unsigned short
	{
		END = 0xFF,
		NOP = 0x80,

		// Branching
		BE = 0x01,
		BNE = 0x02,
		BLT = 0x03,
		BLTE = 0x04,
		BGT = 0x05,
		BGTE = 0x06,

		// Jumping
		JUMP = 0x0A,
		CALL = 0x0B,
		RETURN = 0x0C,

		// Stack Ops
		PUSHA = 0x81,
		PUSHB = 0x82,
		POPA =  0x83,
		POPB =  0x84,
		PEEKA = 0x85,
		PEEKB = 0x86,

		LOADA = 0x90,
		LOADB = 0x91,

		// Arithmatic
		ADDI = 0xA0,
		SUBI = 0xA1,
		MULI = 0xA2,
		DIVI = 0xA3,
	}; 
};