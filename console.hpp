#pragma once

#include <string>
#include <vector>
using namespace std;

extern string cwd;
extern vector<char> hexChars;

void cprint(string text, char data, bool newLine=false);
vector<string> splitBySpace(string input);