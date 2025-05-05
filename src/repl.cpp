#include "repl.hpp"
#include "scriptCompile.h"
#include "publics.h"
#include "repl.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <readline/readline.h>
#include <readline/history.h>

void replLoop(){
	std::string user_code = "";
	std::string outputCPP = "cScriptOutput.cpp";
	std::ofstream outFile = std::ofstream(outputCPP);
	while(user_code != "exit") {
		user_code = getUserInput();
		for (const auto& [header, features] : header_features) {
			for (const auto& feature : features) {
				if (user_code.find(feature) != std::string::npos) {
					if(!needed_headers.contains(header)){
						needed_headers.insert(header);
						break;  // Check next header
					}
				}
			}
		}
		std::cout << user_code << '\n';
		if(!outFile.is_open())
			outFile.open(outputCPP);
		initFile(&outFile);
		outFile << user_code;
		if (user_code.back() != ';')
			outFile << ";\n";
		else
			outFile << "\n";
		outFile << "}";

		outFile.close();
		compileFile(outputCPP.c_str(), NULL, 0);
		executeAndDelete(executableName);
	}
}

void initFile(std::ofstream* outFile){
    if (!outFile) {
        std::cerr << "Error: cannot open output.txt\n";
		exit(-1);
    }

	for (const auto& hdr : needed_headers) {
		*outFile << "#include" << hdr <<"\n";
	}

	*outFile << mainFunc;
}

std::string getUserInput(){
	std::string input = readline("> ");
	add_history(input.c_str());
	return input;
}

