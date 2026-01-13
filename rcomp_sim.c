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

Instruction read_program() {
	
}

int main() {

};

