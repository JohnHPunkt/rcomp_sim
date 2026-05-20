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
	"EM1",
	"EM2",
	"PAU",
	"HLT",
};

Instruction* program;
int* regs;

Instruction read_instruction() {
	Instruction a;
	a.type = IT_NOP;
	a.arg = 0;
	return a;
}

void read_program(char* file, Instruction* program) {
	
	int prog_len = 16;
	
	printf("%d\n", lineLen);

	program = (Instruction*) malloc(prog_len * sizeof(Instruction));

	FILE* fptr;
	fptr = fopen(file, "r");
	if (fptr == NULL) {
		perror("fopen");
		exit(2);
		return;
	} else {
		
	}
	fclose(fptr);
	sim_program(program);
}

void sim_program(Instruction* program){
  int accu = 0;
  int[16] regs;
	for (int i = 0; i < (sizeof(program)/sizeof(Instruction)); i++) {
    Instruction cmd = program[i];
    if (cmd.type == IT_NOP || cmd.type == IT_PAU) {
      continue;
    } else if (cmd.type == IT_HLT) {
      printf("%d", akku);
      free(regs);
      return;
    } else if (cmd.type == IT_LDI) {
      akku = cmd.arg;
    } else if (cmd.type == IT_LDA && cmd.arg < 16) {
      akku = regs[cmd.arg];
    } else if (cmd.type == IT_STA) {
      regs[cmd.arg] = akku;
    } else if (cmd.type == IT_ADI) {
      accu += cmd.arg;
    } else if (cmd.type == IT_ADA) {
      accu += regs[cmd.arg];
    } else if (cmd.type == IT_SBA) {
      accu -= regs[cmd.arg];
    } else if (cmd.type == IT_INC) {
      accu++;
    } else if (cmd.type == IT_DEC) {
      accu--;
    } else if (cmd.type == IT_JMP) {
      i = cmd.arg - 1;
    } else if (cmd.type == IT_JPZ && akku == 0) {
      i = cmd.arg - 1;
    } else if (cmd.type == IT_JPC && akku >= 16) {
      i = cmd.arg -1;
    } else if (cmd.type == IT_E1) {     // freier Befehl, kann später implementiert werden

    } else if (cmd.type == IT_E2) {     // freier Befehl, kann später implementiert werden

    }
	}
	printf("%d", accu);
	free(regs);
}


int main(int argc, char** argv) {
	Instruction* program;
	read_program(argv[1], program);
		
	return 0;
};

