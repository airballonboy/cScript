#pragma once

#ifdef __cplusplus
extern "C" {  // Tells C++ to use C linkage
#endif

int compileFile(const char* file, const char** flags, int flagCount);
void executeAndDelete(const char* executableName);

#ifdef __cplusplus
}
#endif
