#include <windows.h>
#include <iostream>
#include <string>
#include "console.hpp"

using namespace std;

string cwd = "/";

void commandParser(string command) {
	vector<string> command = splitBySpace(command);
	if (command == "exit" || command == "stop") exit(1);
	else if (command == "testcolor" || command == "color") {
		cprint("", command[1].c_str);
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