#pragma once

#include <string>
#include <vector>
#include <windows.h>
using namespace std;

extern string cwd;
extern vector<char> hexChars;
extern HANDLE hConsole;

void cprint(string text, char data, bool newLine=false);
void cprint(string text, string background, char data, bool newLine = false);
vector<string> splitBySpace(string input);
string exec(const char* cmd);