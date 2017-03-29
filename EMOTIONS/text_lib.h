#ifndef text_lib
#define text_lib
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include "emotional_lib.h"
char* read_file(const char[], bool&, bool);
void write_in_file(const char[], association*, int);
void tolow(char*);
void search_spaces(char*);
int search_word(char*, char*);
//void emotional_coloring(char*, map <char*, double > );
#endif