#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int asm_interp(int argc, char *argv[]) {

	const char *fname;

	fname = argv[1];
	char line[256];

	FILE *file;
	file = fopen(fname, "r+");
	FILE *output;
	output = fopen("a.asm", "r+");

	while(fgets(line, sizeof(line), file) != NULL) {
	
		printf("Test cinco de mayo 16:48 - %s", line);
		
		if(line == NULL) {
			break;
		}	

	}

	fclose(file);
	fclose(output);
	return 0;

}

void compile(int argc, char *argv[]) {

	char buf[0x100];
	char *arg = "-o";
	const char *OUTPUT_NAME;
	const char *EXEC_NAME;

	if(argv[2] == arg) {
		OUTPUT_NAME = argv[3];
		EXEC_NAME = argv[4];
		snprintf(buf, sizeof(buf), "nasm -f elf64 a.asm -o %s && ld %s -o %s && rm -f %s", OUTPUT_NAME, OUTPUT_NAME, EXEC_NAME, OUTPUT_NAME);
		system(buf);
		printf("%s Compiled successfully!\n", OUTPUT_NAME);
	} else {
		system("nasm -f elf64 a.asm -o a.o && ld a.o -o out");
		printf("Program Compiled successfully!\n");
	}

}

int main(int argc, char *argv[]) {

	if(argv[1] == NULL) {
		printf("\n:: Invalid file name, ex: wesm (.well file) -o (.o file) (executable name)\n > wesm test.well -o test.o test\n\n");
		return 0;
	}

	asm_interp(argc, argv);
	compile(argc, argv);
	return 0;	

}
