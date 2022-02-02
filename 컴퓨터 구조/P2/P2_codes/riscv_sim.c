#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//clock cycles
long long cycles = 0;

// registers
long long int regs[32];

// program counter
unsigned long pc = 0;

// memory
#define INST_MEM_SIZE 32*1024
#define DATA_MEM_SIZE 32*1024
unsigned long inst_mem[INST_MEM_SIZE]; //instruction memory
unsigned long long data_mem[DATA_MEM_SIZE]; //data memory

//misc. function
int init(char* filename);
int array_to_num(int* num);
void print_cycles();
void print_reg();
void print_pc();

// declare for instruction fetch
unsigned int opcode[7] = {0,};
unsigned int rd[5], rs1[5], rs2[5], imm[11];
int _rd, _rs1, _rs2, _imm;
int type;
unsigned int binary_instruction[32] = {0,};

// Distinguish Instruction Type
/*
	0 : add / 1 : addi / 2 : jal / 3 : jalr / 4 : ld / 5 : sd / 6 : beq
*/
void find_type(int* op) {

	int opnum=0;

	opnum = array_to_num(op);

	// if add, return 0
	if (opnum == 0110011)
		type = 0;
	// if addi, return 1
	if (opnum == 0010011)
		type = 1;
	// if jal, return 2
	if (opnum == 1101111)
		type = 2;
	// if jalr, return 3
	if (opnum == 1100111)
		type = 3;
	// if ld, return 4
	if (opnum == 0000011)
		type = 4;
	// if sd, return 5
	if (opnum == 0100011)
		type = 5;
	// if beq, return 6
	if (opnum == 1100011)
		type = 6;
	
}

// make binary code
void to_binary(unsigned int num) {
	
	int position = 0;
	int decimal = num;

	while (1) {
		binary_instruction[position] = decimal % 2;
		decimal = decimal / 2;

		position++;

		if (decimal == 0)
			break;
	}
}


int array_to_num(int* num) {
	int number = 0;

	for (int i = 0; i < sizeof(num); i++) {
		number += pow(10,i) * num[i];
	}
	return number;
}

int to_decimal(int* num) {
	
	int n = array_to_num(num);
	int decimal = 0, i=0 , rem;
	while (n != 0) {
		rem = n % 10;
		n /= 10;
		decimal += rem * pow(2,i);
		++i;
	}
	return decimal;
}

//fetch an instruction from a instruction memory
void fetch() {
	
	to_binary(inst_mem[pc/4]);

}

//decode the instruction and read data from register file
void decode() {
		
	for (int i=0 ; i<7 ; i++) {
		opcode[i] = binary_instruction[pc * 8 + (6 - i)];
	}

	find_type(opcode);
	
	// save rd
	if (0 <= type <= 4) {
		for (int i=0 ; i<5 ; i++) {
			rd[i] = binary_instruction[pc * 8 + (11 - i)];
		}
	}

	// save rs1
	if (type != 2) {
		for (int i=0 ; i<5 ; i++) {
			rs1[i] = binary_instruction[pc * 8 + (11 - i)];
		}
	}

	// save rs2
	if (type ==0 | type == 5 | type == 6) {
		for (int i=0 ; i<5 ; i++) {
			rs2[i] = binary_instruction[pc * 8 + (24 - i)];
		}
	}

	//save imm
	if (type == 5 | type == 6) {
		for (int i=0 ; i<5 ; i++) {
			imm[i] = binary_instruction[pc * 8 + (11 - i)];
		}
	}

	if (type == 1 | type == 3 | type == 4) {
		for (int i=0 ; i<12 ; i++) {
			imm[i] = binary_instruction[pc * 8 + (31 - i)];
		}
	}  

	if (type == 2) {
		for (int i=0 ; i<20 ; i++) {
			imm[i] = binary_instruction[pc * 8 + (31 - i)];
		}
	} 

	pc +=4;

	// read data
	int _rs1 = to_decimal(rs1);
	int _rs2 = to_decimal(rs2);
	int _rd = to_decimal(rd);
	int _imm = to_decimal(imm);

	_rs1 = regs[_rs1];
	_rs2 = regs[_rs2];
}

//perform the appropriate operation 
void exe() {

	// add: type 0
	if (type==0) {
		regs[_rd] = regs[_rs1] + regs[_rs2];
	}

	// addi: type 1
	if (type==1) {
		regs[_rd] = regs[_rs1] + _imm;
	}

	// jal : type 2
	if (type==2) {
		regs[1] = pc + 4;
		pc = _imm/4;
	}

	// jalr : type 3
	if (type == 3) {
		regs[1] = pc +4;
		pc = (_imm + _rs1) /4;
	}

	//beq : type 6
	if (type==6) {
		if (_rs1 == _rs2)
			pc = pc + _imm;
	}

}

//access the data memory
void mem() {

	// ld : type 4
	if (type == 4) {
		regs[_rd] = data_mem[_rs1+_imm];
	}

	// sd : type 5
	if (type == 5) {
		data_mem[_rs2+_imm] = _rs1;
	}

}

//write result of arithmetic operation or data read from the data memory if required
void wb() {

}

int main(int ac, char* av[])
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


		cycles++;    //increase clock cycle

		//if debug mode, print clock cycle, pc, reg 
		if (*av[2] == '0') {
			print_cycles();  //print clock cycles
			print_pc();		 //print pc
			print_reg();	 //print registers
		}

		// check the exit condition, do not delete!! 
		if (regs[9] == 10)  //if value in $t1 is 10, finish the simulation
			done = 1;
	}

	if (*av[2] == '1')
	{
		print_cycles();  //print clock cycles
		print_pc();		 //print pc
		print_reg();	 //print registers
	}

	return 0;
}


/* initialize all datapat elements
//fill the instruction and data memory
//reset the registers
*/
int init(char* filename)
{
	FILE* fp = fopen(filename, "r");
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
	printf("PC	   = %ld\n\n", pc);
}

void print_reg()
{
	printf("x0   = %d\n", regs[0]);
	printf("x1   = %d\n", regs[1]);
	printf("x2   = %d\n", regs[2]);
	printf("x3   = %d\n", regs[3]);
	printf("x4   = %d\n", regs[4]);
	printf("x5   = %d\n", regs[5]);
	printf("x6   = %d\n", regs[6]);
	printf("x7   = %d\n", regs[7]);
	printf("x8   = %d\n", regs[8]);
	printf("x9   = %d\n", regs[9]);
	printf("x10  = %d\n", regs[10]);
	printf("x11  = %d\n", regs[11]);
	printf("x12  = %d\n", regs[12]);
	printf("x13  = %d\n", regs[13]);
	printf("x14  = %d\n", regs[14]);
	printf("x15  = %d\n", regs[15]);
	printf("x16  = %d\n", regs[16]);
	printf("x17  = %d\n", regs[17]);
	printf("x18  = %d\n", regs[18]);
	printf("x19  = %d\n", regs[19]);
	printf("x20  = %d\n", regs[20]);
	printf("x21  = %d\n", regs[21]);
	printf("x22  = %d\n", regs[22]);
	printf("x23  = %d\n", regs[23]);
	printf("x24  = %d\n", regs[24]);
	printf("x25  = %d\n", regs[25]);
	printf("x26  = %d\n", regs[26]);
	printf("x27  = %d\n", regs[27]);
	printf("x28  = %d\n", regs[28]);
	printf("x29  = %d\n", regs[29]);
	printf("x30  = %d\n", regs[30]);
	printf("x31  = %d\n", regs[31]);
	printf("\n");
}
