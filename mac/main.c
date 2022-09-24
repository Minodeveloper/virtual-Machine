#include <stdio.h>
#include <stdbool.h>
int sp = -1;
int stack[256];
typedef enum {
	PSH,
	ADD,
	POP,
	SET,
	HLT
} InstructionSet;

const int program[] = {
	PSH, 15,
	PSH, 100,
	ADD,
	POP,
	HLT
};

int ip = 0;

int fetch() {
	return program[ip];
}

bool running = true;

void eval(int instr)
{
	switch(instr)
	{
		case HLT:{
			running = false;
			break;
			 }
		case PSH:{
			sp++;
			stack[sp] = program[++ip];
			break;
			 }
		case POP:{
			int val_popped = stack[sp--];

			printf("popped %d\n", val_popped);
			break;
			 }
		case ADD:{
			int a = stack[sp--];
			int b = stack[sp--];
			int result = b + a;
			sp++;
			stack[sp] = result;
			break;
			 }
	
	}
}

//int sp = -1;
//int stack[256];

typedef enum {
	A, B, C, D, E, F, NUM_OF_REGISTERS
} Registers;

int registers[NUM_OF_REGISTERS];

int main(int argc, char *argv[])
{
	while(running)
	{
		eval( fetch() );
		ip++;
	}

	return 0;
}
