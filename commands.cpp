#include <iostream>
#include <string>
using namespace std;

void msgUser(string msg, bool quit) {
	cout << msg << endl;
	if(quit) exit(0);
}
