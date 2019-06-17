#include <windows.h>
#include <iostream>
#include <string>
#include <algorithm>
#include "console.hpp"

using namespace std;

string cwd = "/";
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void commandParser(string comm) {
	vector<string> params = splitBySpace(comm);
	string command = params[0];
	params.erase(params.begin());
	if (command == "exit" || command == "stop") exit(1);
	else if (command == "testcolor" || command == "color") {
		string err = "Error: Please enter 1 hex - valid character(1 - 9, a - f)";
		if (params.size() > 1) { cprint(err, 'c', true); return; }
		if(params[0].length() < 2, find(hexChars.begin(), hexChars.end(), params[0][0]) != hexChars.end()) {
			cprint("This is what that color looks like", params[0][0], true);
			return;
		}
		cprint(err, 'c', true);
	}
}

void commandOperator() {
	string command;
	cprint("Ember", '6', false);
	cprint(cwd, 'f', false);
	cprint("~ ", '9', false);
	getline(cin, command);
	if (!command.empty()) commandParser(command);
	else cprint("Please enter a command.", 'c', true);
}

int main() {


	while (true) commandOperator();
	
	return 0;
}