#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void msgUser(string msg, bool quit) {
	cout << msg << endl;
	if(quit) exit(0);
};

void commandManager(string command, map<char, string> arguments) {
	if(command == "quit") {
		msgUser("Quitting...", true);
	} else {
		msgUser("I did not understand that command, please try again.", false);
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

		if(spaceSeperated.size() % 2 != 1) {
			msgUser("You did not input your arguments correctly.", false);
			continue;
		}

		string command = spaceSeperated[0];
		for(int i = 1; i < spaceSeperated.size(); i += 2) {
			if(spaceSeperated[i][0] == '-') {
				arguments.insert(pair<char, string>(spaceSeperated[i][1], spaceSeperated[i + 1]));
			} else {
				msgUser("I did not understand one of your arguments, please try again.", false);
			}
		}
		commandManager(command, arguments);
	}
	return 0;
}
