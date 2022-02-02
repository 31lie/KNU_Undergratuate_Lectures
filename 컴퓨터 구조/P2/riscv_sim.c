/*
	컴퓨터학부 심화컴퓨터전공 2020114658 이윤서
	컴퓨터구조_P2 과제
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// clock cycles
long long cycles = 0;

// registers
long long int regs[32];

// program counter
unsigned long pc = 0;

// memory
#define INST_MEM_SIZE 32 * 1024
#define DATA_MEM_SIZE 32 * 1024
unsigned long inst_mem[INST_MEM_SIZE];		// instruction memory
unsigned long long data_mem[DATA_MEM_SIZE]; // data memory

// misc. function
int init(char *filename);

void fetch();
void decode();
void exe();
void mem();
void wb();

void print_cycles();
void print_reg();
void print_pc();

// for saving each instruction
long instruction, opcode, rs1, rs2, rd;
int imm;

// fetch an instruction from a instruction memory
void fetch()
{
	instruction = inst_mem[pc]; // fetch an instruction
	if (instruction == 0)		// if there is no more instruction, exit
		exit(0);
	pc++; // increase Program Counter
}

// decode the instruction and read data from register file
void decode()
{
	imm = 0;							   // initialize immediate value
	opcode = instruction & 0x7f;		   // 0x7f = 1111111'b
	rd = (instruction & 0xf80) >> 7;	   // 0xf80 = 111110000000'b
	rs1 = (instruction & 0xf8000) >> 15;   // 0xf8000 = 11111000000000000000'b
	rs2 = (instruction & 0x1f00000) >> 20; // 0x1f00000 = 1111100000000000000000000'b

	unsigned int temp;

	switch (opcode)
	{

	// add (R-type)
	case 0x33:
		break;

	// addi (I-type)
	case 0x13:
		imm = (instruction & 0xfff00000) >> 20; // make immidiate value

		// if negative value, make 1111 ... (imm) by OR
		if (imm & 0x800)
			imm = imm | 0xfffff000;
		break;

	// jal (UJ-type)
	case 0x6f:

		temp = instruction >> 12;
		imm += (temp & 0x7fe00) >> 8; // [10:1]
		imm += (temp & 0x100) << 3;	  // [11]
		imm += (temp & 0xff) << 12;	  // [19:12]
		imm += (temp & 0x80000) << 1; // [20]

		// if negative value, make 1111 ... (imm) by OR
		if (imm & 0x100000)
			imm = imm | 0xffe00000;
		break;

	// jalr (I-type)
	case 0x67:
		imm = (instruction & 0xfff00000) >> 20;
		break;

	// beq (SB-type)
	case 0x63:

		imm = (instruction & 0xf00) >> 7;		 // [4:1]
		imm += (instruction & 0x7e000000) >> 20; // [10:5]
		imm += (instruction & 0x80) << 4;		 // [11]
		imm += (instruction & 0x80000000) >> 19; // [12]
		
		if (imm & 0x1000)
			imm = imm | 0xffffe000;
		break;

	// ld (I-type)
	case 0x03:
		imm = (instruction & 0xfff00000) >> 20;
		break;

	// sd (S-type)
	case 0x23:
		imm = (instruction & 0xf80) >> 7;
		imm += (instruction & 0xfe000000) >> 20;
		break;
	}

	regs[0] = 0;
}

// perform the appropriate operation
void exe()
{
	switch (opcode)
	{
	// add (R-type)
	case 0x33:
		regs[rd] = regs[rs1] + regs[rs2];
		break;

	// addi (I-type)
	case 0x13:
		regs[rd] = regs[rs1] + imm;
		break;

	// jal (UJ-type)
	case 0x6f:
		regs[rd] = pc * 4;
		pc = (pc - 1) + imm / sizeof(int);
		break;

	// jalr (I-type)
	case 0x67:
		regs[rd] = pc * 4;
		pc = (regs[rs1] + imm) / sizeof(int);
		break;

	// beq (SB-type)
	case 0x63:
		if (regs[rs1] == regs[rs2])
			pc = (pc - 1) + imm / sizeof(int);
		break;
	}
}

// access the data memory
void mem()
{
	// ld (I-type)
	if (opcode == 0x03)
		regs[rd] = data_mem[(regs[rs1] + imm) / sizeof(int)];
}

// write result of arithmetic operation or data read from the data memory if required
void wb()
{
	// sd (S-type)
	if (opcode == 0x23)
		data_mem[(regs[rs1] + imm) / sizeof(int)] = regs[rs2];
}

int main(int ac, char *av[])
{

	if (ac < 3)
	{
		printf("./riscv_sim filename mode\n");
		return -1;
	}

	char done = 0;
	if (init(av[1]) != 0)
		return -1;

	while (!done)
	{
		fetch();
		decode();
		exe();
		mem();
		wb();

		cycles++; // increase clock cycle

		// if debug mode, print clock cycle, pc, reg
		if (*av[2] == '0')
		{
			print_cycles(); // print clock cycles
			print_pc();		// print pc
			print_reg();	// print registers
		}

		// check the exit condition, do not delete!!
		if (regs[9] == 10) // if value in $t1 is 10, finish the simulation
			done = 1;
	}

	if (*av[2] == '1')
	{
		print_cycles(); // print clock cycles
		print_pc();		// print pc
		print_reg();	// print registers
	}

	return 0;
}

/* initialize all datapat elements
//fill the instruction and data memory
//reset the registers
*/
int init(char *filename)
{
	FILE *fp = fopen(filename, "r");
	int i;
	long inst;

	if (fp == NULL)
	{
		fprintf(stderr, "Error opening file.\n");
		return -1;
	}

	/* fill instruction memory */
	i = 0;
	while (fscanf(fp, "%lx", &inst) == 1)
	{
		inst_mem[i++] = inst;
	}

	/*reset the registers*/
	for (i = 0; i < 32; i++)
	{
		regs[i] = 0;
	}

	/*reset pc*/
	pc = 0;
	/*reset clock cycles*/
	cycles = 0;
	return 0;
}

void print_cycles()
{
	printf("---------------------------------------------------\n");

	printf("Clock cycles = %lld\n", cycles);
}

void print_pc()
{
	printf("PC	   = %ld\n\n", pc * 4);
}

void print_reg()
{
	printf("x0   = %lld\n", regs[0]);
	printf("x1   = %lld\n", regs[1]);
	printf("x2   = %lld\n", regs[2]);
	printf("x3   = %lld\n", regs[3]);
	printf("x4   = %lld\n", regs[4]);
	printf("x5   = %lld\n", regs[5]);
	printf("x6   = %lld\n", regs[6]);
	printf("x7   = %lld\n", regs[7]);
	printf("x8   = %lld\n", regs[8]);
	printf("x9   = %lld\n", regs[9]);
	printf("x10  = %lld\n", regs[10]);
	printf("x11  = %lld\n", regs[11]);
	printf("x12  = %lld\n", regs[12]);
	printf("x13  = %lld\n", regs[13]);
	printf("x14  = %lld\n", regs[14]);
	printf("x15  = %lld\n", regs[15]);
	printf("x16  = %lld\n", regs[16]);
	printf("x17  = %lld\n", regs[17]);
	printf("x18  = %lld\n", regs[18]);
	printf("x19  = %lld\n", regs[19]);
	printf("x20  = %lld\n", regs[20]);
	printf("x21  = %lld\n", regs[21]);
	printf("x22  = %lld\n", regs[22]);
	printf("x23  = %lld\n", regs[23]);
	printf("x24  = %lld\n", regs[24]);
	printf("x25  = %lld\n", regs[25]);
	printf("x26  = %lld\n", regs[26]);
	printf("x27  = %lld\n", regs[27]);
	printf("x28  = %lld\n", regs[28]);
	printf("x29  = %lld\n", regs[29]);
	printf("x30  = %lld\n", regs[30]);
	printf("x31  = %lld\n", regs[31]);
	printf("\n");
}
