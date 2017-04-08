#include <stdio.h>
#include <debug.hpp>

FILE* debugFile = fopen("debug.log", "w+");

void debug(std::string s) {
	fprintf(debugFile, "%s", s.c_str());
	fflush(debugFile);
}
