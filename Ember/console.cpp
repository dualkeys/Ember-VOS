#include "console.hpp"
#include <stdio.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <array>
#include <cstdio>

using namespace std;
#define on ,

vector<char> hexChars = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
enum Colors {
	black,          //  0 text color - multiply by 16, for background colors
	dark_blue,      //  1
	dark_green,     //  2
	dark_cyan,      //  3
	dark_red,       //  4
	dark_magenta,   //  5
	dark_yellow,    //  6
	light_gray,     //  7
	dark_gray,      //  8
	light_blue,     //  9
	light_green,    // 10
	light_cyan,     // 11
	light_red,      // 12
	light_magenta,  // 13
	light_yellow,   // 14
	white           // 15
};

void color(int text_color = 7) { SetConsoleTextAttribute(hConsole, text_color); }

void cprint(string text, char data, bool newLine) {
	data = toupper(data);
	int clr = (data >= 'A') ? (data - 'A' + 10) : (data - '0');
	color(clr); printf(text.c_str()); color();
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

string exec(const char* cmd) {
	array<char, 128> buffer;
	string result;
	unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
	if (!pipe) {
		throw runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		result += buffer.data();
	}
	return result;
}