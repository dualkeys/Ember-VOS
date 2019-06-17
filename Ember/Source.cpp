#include <windows.h>
#include <iostream>
#include <string>
#include <numeric>
#include <sstream>
#include <algorithm>
#include "console.hpp"
#include <iterator>

using namespace std;

string cwd = "";
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void readDirectory(const std::string& path, vector<string>& v) {
	std::string pattern(path);
	pattern.append("\\*");

	WIN32_FIND_DATA data;
	HANDLE hFind;

	if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
		do {
			v.push_back(data.cFileName);
		} while (FindNextFile(hFind, &data) != 0);
		FindClose(hFind);
	}
}

void commandParser(string comm) {
	vector<string> params = splitBySpace(comm);
	string command = params[0];
	params.erase(params.begin());
	// "Commands/"+command+" --cwd=\"" + cwd + "\" --params=\"" + passingParams + "\"";

	vector<string> files;
	readDirectory(".\\Commands", files);

	if (command == "exit" || command == "stop") exit(1);
	else if (command == "color") {
		string err = "Error: Please enter 1 hex - valid character(1 - 9, a - f)";
		if (params.size() > 1) { cprint(err, '4', true); return; }
		if (params[0].length() < 2, find(hexChars.begin(), hexChars.end(), params[0][0]) != hexChars.end()) {
			cprint("This is what that color looks like", params[0][0], true);
			return;
		}
		cprint(err, '4', true);
	} else if (command == "cd") {
		string passingParams;
		if (params.size() >= 2) copy(params.begin(), params.end() - 1, ostream_iterator<string>(cout, ","));
		if (params.size() >= 1) passingParams = params.back();
		string temp = "\"Commands\\cd.exe\" --cwd=\"" + cwd + "\" --params=\"" + passingParams + "\"";
		exec(temp.c_str());
	} else if (command == "list" || command == "ls") {
		string temp = "dir " + cwd;
		if (params.size() > 1) {
			replace(params[0].begin(), params[0].end(), '/', '\\');
			temp += params[0];
		}
		string test = exec(temp.c_str());
		cout << test << endl;
	} else {
		cprint(command + " is an unknown command/program", '4', true);
	}
}

void commandOperator() {
	string command;
	cprint("Ember", '6');
	cprint("~" + cwd, 'f');
	cprint("$ ", '9');
	getline(cin, command);
	if (!command.empty()) commandParser(command);
	else cprint("Please enter a command.", '4', true);
}

int main() {


	while (true) commandOperator();
	
	return 0;
}