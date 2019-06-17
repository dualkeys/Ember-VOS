#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

vector<string> splitBySpace(string input) {
 	vector<string> result;
	istringstream iss(input);
	for (string s; iss >> s;) {
		result.push_back(s);
	}
	return result;
}

int main(int varc, char** var) {
	if (varc < 3) return 0;
	string cwd;
	vector<string> params;
	vector<string> vars;
	for (int i = 0; i < sizeof(var); i++) {
		vars.push_back(string(var[i]));
	}
	for (int i = 0; i < vars.size(); i++) {
		if (vars[i].find("--cwd=")) {
			vars[i].erase(0, 6);
			vars[i].erase(sizeof(vars[i]) - 1);
			cwd = vars[i];
			printf(cwd.c_str());
		} else if (vars[i].find("--params=")) {
			vars[i].erase(0, 9);
			vars[i].erase(sizeof(vars[i]) - 1);
			replace(vars[i].begin(), vars[i].end(), ',', ' ');
			params = splitBySpace(vars[i]);
			printf(params[0].c_str());
		}
	}

	if (params[0] == "../" && cwd != "") {
		replace(cwd.begin(), cwd.end(), '/', ' ');
		vector<string> tempCwd = splitBySpace(cwd);
		stringstream ss;
		for (size_t i = 0; i < tempCwd.size(); i++) {
			if (i != 0) ss << "/";
			if (i != tempCwd.size() - 1) ss << tempCwd[i];
		}
		cwd = ss.str();
	} else {
		if (cwd != "" && cwd[cwd.size() - 1] == '/') cwd = cwd + params[0];
		else if (cwd != "") cwd = cwd + "/" + params[0];
		else cwd = params[0];
	}
}