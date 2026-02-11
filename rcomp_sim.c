#include <stdio.h>
#include <stdlib.h>


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

char *mnemonics[] = {
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

Instruction read_Instruction() {
	Instruction a;
	a.type = IT_NOP;
	a.arg = 1;
	return a;
}

Instruction read_Program() {
	Instruction a;
	a.type = IT_NOP;
	a.arg = 1;
	return a;
}

int main(int argc, char** argv) {
	for (int i = 0; i < argc; i++) {
		printf("argv[%d]: %s\n", i, argv[i]);
	}
	 FILE *fptr;

	fptr = fopen(argv[1], "r");

	char myString[100];

	fgets(myString, 100, fptr);

	printf("%s", myString);

	fclose(fptr);
	return 1;

};

