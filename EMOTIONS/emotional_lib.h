#ifndef emotion_lib
#define emotion_lib
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
struct association
{
	char*key;
	double value;
};
//vector <association>;
vector <association> form_map(char*);
void map_sort(association*, int);
double map_search(char*, vector<association>);
#endif  
#pragma once
