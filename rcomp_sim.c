#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum InstructionType {
	IT_NOP,
	IT_LDI,
	IT_LDA,
	IT_STA,
	IT_ADI,
	IT_ADA,
	IT_SBA,
	IT_INC,
	IT_DEC,
	IT_JMP,
	IT_JPZ,
	IT_JPC,
	IT_E1,
	IT_E2,
	IT_PAU,
	IT_HLT,
} InstructionType;

typedef struct Instruction {
	InstructionType type;
	int arg;
} Instruction;

char* mnemonics[] = {
	"NOP",
	"LDI",
	"LDA",
	"STA",
	"ADI",
	"ADA",
	"SBA",
	"INC",
	"DEC",
	"JMP",
	"JPZ",
	"JPC",
	"E1",
	"E2",
	"PAU",
	"HLT",
};

Instruction* program;
int* regs;

Instruction read_Instruction() {
	Instruction a;
	a.type = IT_NOP;
	a.arg = 0;
	return a;
}

int getAndCompDigits(int numA, int numB) {
	if (numA == 0 && numB == 0) { 
		return 1;
	}
	int countA = 0;
	int countB = 0;
	while (numA != 0 || numB != 0) {
		if (numA != 0) countA++;
		if (numB != 0) countB++;
		numA /= 10;
		numB /= 10;
	}
	return (countA > countB) ? countA : countB;
}

void read_Program(char* file, Instruction* program) {
	
	int progLen;
	int regCount;
	int valLen;
	int progCount = 0;
	int lineLen;
	
	printf("Enter maximum programm length: ");
	scanf("%d", &progLen);
	printf("Enter Register Count: ");
	scanf("%d", &regCount);
	printf("Enter maximum Value: ");
	scanf("%d", &valLen);
	
	lineLen = getAndCompDigits(regCount, valLen);
	printf("%d\n", lineLen);

	program = (Instruction*) malloc(progLen * sizeof(Instruction));

	FILE* fptr;
	fptr = fopen(file, "r");
	if (fptr == NULL) {
		perror("fopen");
		exit(2);
		return;
	} else {
		
	}
	fclose(fptr);
}

void simProgram(Instruction* program){
	for (int i = 0; i < program.length(); i++) {
		
	}
}


int main(int argc, char** argv) {
	Instruction* program;
	read_Program(argv[1], program);
		
	return 0;
};

