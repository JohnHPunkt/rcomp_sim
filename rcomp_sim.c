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
  int akku = 0;
  regs = (int*) malloc(16 * sizeof(int));
	for (int i = 0; i < (sizeof(program)/sizeof(Instruction)); i++) {
    Instruction cmd = program[i];
    if (cmd.type == IT_NOP || cmd.type == IT_PAU) {
      continue;
    } else if (cmd.type == IT_HLT) {
      printf("%d", akku);
      return;
    } else if (cmd.type == IT_LDI) {
      akku = cmd.arg;
      continue;
    } else if (cmd.type == IT_LDA && cmd.arg < 16) {
      akku = regs[cmd.arg];
      continue;
    } else if (cmd.type == IT_STA) {
      regs[cmd.arg] = akku;
      continue;
    } else if (cmd.type == IT_ADI) {
      akku += cmd.arg;
      continue;
    } else if (cmd.type == IT_ADA) {
      akku += regs[cmd.arg];
    } else if (cmd.type == IT_SBA) {
      akku -= regs[cmd.arg];
      continue;
    } else if (cmd.type == IT_INC) {
      akku++;
      continue;
    } else if (cmd.type == IT_DEC) {
      akku--;
      continue;
    } else if (cmd.type == IT_JMP) {
      i = cmd.arg - 1;
      continue;
    } else if (cmd.type == IT_JPZ && akku == 0) {
      i = cmd.arg - 1;
      continue;
    } else if (cmd.type == IT_JPC && akku >= 16) {
      i = cmd.arg -1;
      continue;
    } else if (cmd.type == IT_E1) {     // freier Befehl, kann später implementiert werden
      continue;
    } else if (cmd.type == IT_E2) {     // freier Befehl, kann später implementiert werden
      continue;
    }
	}
}


int main(int argc, char** argv) {
	Instruction* program;
	read_Program(argv[1], program);
		
	return 0;
};

