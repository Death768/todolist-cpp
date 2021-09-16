#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void quit(map<char, string> arguments) {
	cout << "Quitting..." << endl;
	exit(0);
};

void commandManager(string command, map<char, string> arguments) {
	if(command == "quit") {
		quit(arguments);
	}
};

void seperateBySpaces(string s, vector<string> &ret) {
	int start = 0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == ' ') {
			ret.push_back(s.substr(start, i - start));
			start = i + 1;
		}
	}
	//check for edge cases
	if(start == s.length()) return;
	ret.push_back(s.substr(start, s.length()));
}

int main() {
	while(true) {
		string input;
		getline(cin, input);

		map<char, string> arguments;

		vector<string> spaceSeperated;
		seperateBySpaces(input, spaceSeperated);

		//check for options
		//make sure options are valid
	}
	return 0;
}
