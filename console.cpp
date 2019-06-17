#include "console.hpp"
#include <stdio.h>
#include <vector>
#include <sstream>

using namespace std;

vector<char> hexChars = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

void cprint(string text, char data, bool newLine) {
	switch (data) {
	case '0':
		printf("\033[38;5;0m%s\033[0m", text.c_str());
		break;
	case '1':
		printf("\033[38;5;12m%s\033[0m", text.c_str());
		break;
	case '2':
		printf("\033[38;5;2m%s\033[0m", text.c_str());
		break;
	case '3':
		printf("\033[38;5;6m%s\033[0m", text.c_str());
		break;
	case '4':
		printf("\033[38;5;1m%s\033[0m", text.c_str());
		break;
	case '5':
		printf("\033[38;5;5m%s\033[0m", text.c_str());
		break;
	case '6':
		printf("\033[38;5;214m%s\033[0m", text.c_str());
		break;
	case '7':
		printf("\033[38;5;7m%s\033[0m", text.c_str());
		break;
	case '8':
		printf("\033[38;5;8m%s\033[0m", text.c_str());
		break;
	case '9':
		printf("\033[38;5;33m%s\033[0m", text.c_str());
		break;
	case 'a':
		printf("\033[38;5;10m%s\033[0m", text.c_str());
		break;
	case 'b':
		printf("\033[38;5;14m%s\033[0m", text.c_str());
		break;
	case 'c':
		printf("\033[38;5;196m%s\033[0m", text.c_str());
		break;
	case 'd':
		printf("\033[38;5;13m%s\033[0m", text.c_str());
		break;
	case 'e':
		printf("\033[38;5;11m%s\033[0m", text.c_str());
		break;
	case 'f':
		printf("\033[38;5;15m%s\033[0m", text.c_str());
		break;
	}
	if (newLine) printf("\n");
}


vector<string> splitBySpace(string input) {
	vector<string> result;
	istringstream iss(input);
	for (string s; iss >> s;) {
		result.push_back(s);
	}
	return result;
}

