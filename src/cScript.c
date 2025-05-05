#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "scriptCompile.h"
#include "utils.h"
#include "publics.h"
#include "repl.h"


int main(int argc, char** argv) 
{
	struct timespec start,end;
    const char *program = shift_args(&argc, &argv);
	const char **flagsArray;
	int flagCount;

	// Get start time
	clock_gettime(CLOCK_MONOTONIC, &start);

	// If the program is provided with no args
    if (argc == 0) {
        fprintf(stderr, "Usage: %s <input> <flags> \n", program);
		fprintf(stdout, "Hint: try --help to know how %s works\n", program);
        fprintf(stderr, "ERROR: no input file is provided\n");
        replLoop();
		return 1;
    }

	char firstArg[50];
	strcpy(firstArg, shift_args(&argc, &argv));

	// Checks if firstArg starts with --
	if (strncmp(firstArg, "--", 2) == 0) {
		// TODO: check the command
		return 0;
	}
	
	// Adds every flag to the flags string
	for (flagCount = 0; argc > 0; flagCount++) {
		char arg[20];
		strcpy(arg, shift_args(&argc, &argv));
		
		// Checks if arg starts with --
		if (strncmp(arg, "--", 2) == 0) {
			// TODO: check the command
			continue;
		}

		flagsArray[flagCount] = arg;
	}
	compileFile(firstArg, flagsArray, flagCount);
	executeAndDelete(executableName);

	// Print elapsed time
	clock_gettime(CLOCK_MONOTONIC, &end);
	printf("timeUsed: %lfms\n", ((end.tv_sec - start.tv_sec) *1000 + (end.tv_nsec - start.tv_nsec) /1.0e6));
	return 0;
}
