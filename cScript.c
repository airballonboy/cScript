#include <bits/time.h>
#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

char *shift_args(int *argc, char ***argv) {
	if (!(*argc > 0)) exit(-1);
    char *result = (**argv);
    (*argv) += 1;
    (*argc) -= 1;
    return result;
}

int main(int argc, char** argv) 
{
	struct timespec start,end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	char command[400];
	char flags[300];
    const char *program = shift_args(&argc, &argv);

	// If the program is provided with no args
    if (argc == 0) {
        fprintf(stderr, "Usage: %s <input> <flags> \n", program);
		fprintf(stdout, "Hint: try --help to know how %s works\n", program);
        fprintf(stderr, "ERROR: no input file is provided\n");
        return 1;
    }

	char firstArg[50];
	strcpy(firstArg, shift_args(&argc, &argv));

	// Checks if firstArg starts with --
	if (strncmp(firstArg, "--", 2) == 0){
		// TODO: check the command
		return 0;
	}

	// Checks if file is C or Cpp 
	if (strstr(firstArg, ".cpp") != NULL){
		// Adds the file name to the command
		sprintf(command, "g++ %s -o out ", firstArg);
	}else if (strstr(firstArg, ".c") != NULL){
		// Adds the file name to the command
		sprintf(command, "gcc %s -o out ", firstArg);
	}

	// Adds every flag to the flags string
	for (;argc > 0;) {
		char arg[20];
		strcpy(arg, shift_args(&argc, &argv));
		
		// Checks if arg starts with --
		if (strncmp(arg, "--", 2) == 0) {
			// TODO: check the command
			continue;
		}

		strcat(flags, arg);
	}

	// Adds the flags and the opening and deleting file to the command
	strcat(command, flags);
	strcat(command, " && ./out && rm ./out");

	//execute the finale command
	system(command);

	clock_gettime(CLOCK_MONOTONIC, &end);
	printf("timeUsed: %lfms\n", ((end.tv_sec - start.tv_sec) *1000 + (end.tv_nsec - start.tv_nsec) /1.0e6));
	return 0;
}
