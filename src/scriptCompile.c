#include "scriptCompile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "publics.h"
#include "utils.h"

int compileFile(const char *file, const char **flagsArray, int flagCount)
{
	char command[400];
	// Checks if file is C or Cpp 
	if (strstr(file, ".cpp") != NULL){
		// Adds the file name to the command
		sprintf(command, "g++ %s -o %s ", file, executableName);
	}else if (strstr(file, ".c") != NULL){
		// Adds the file name to the command
		sprintf(command, "gcc %s -o %s ", file, executableName);
	}
	char flags[300];
	resetString(flags);


	// Adds every flag to the flags string
	for (int i = 0;flagCount > 0; flagCount--)
		strcat(flags, flagsArray[i++]);


	// Adds the flags and the opening and deleting file to the command
	strcat(command, flags);

	// Compile File
	system(command);

	return 0;
}

void executeAndDelete(const char* executableName)
{
	char executeCommend[50];
	sprintf(executeCommend, "./%s && rm ./%s", executableName, executableName);

	// Open And Delete
	system(executeCommend);
}
