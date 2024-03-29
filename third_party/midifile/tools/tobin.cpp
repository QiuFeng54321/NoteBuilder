//
// Programmer:    Craig Stuart Sapp <craig@ccrma.stanford.edu>
// Creation Date: Wed Jan 28 00:22:15 GMT-0800 1998
// Last Modified: Wed Jan 28 00:22:20 GMT-0800 1998
// Filename:      ...sig/doc/examples/improv/improv/tobin/tobin.cpp
// Syntax:        C++; improv
// $Smake:        cc -o %b %f -lg++ && strip %b
// $Smake-linux:  g++ -o %b %f && strip %b
//

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

int atohd(const char *aNumber);

void exitUsage(const char *command);


int main(int argc, char *argv[]) {
	if (argc != 2) exitUsage(argv[0]);

	int aValue;
	aValue = atohd(argv[1]);

	for (int i = 0; i < 32; i++) {
		if ((aValue >> (31 - i)) & 0x01) {
			cout << "1";
		} else {
			cout << "0";
		}
		if (i % 4 == 3) cout << " ";
	}
	cout << endl;

	return 0;
}


int atohd(const char *aNumber) {
	if (strchr(aNumber, 'x') != NULL) {
		return (int) strtol(aNumber, (char **) NULL, 16);
	} else {
		return atoi(aNumber);
	}
}


void exitUsage(const char *command) {
	cout << endl;
	cout << "Converts an integer into binary form.\n";
	cout << endl;
	cout << "Usage: " << command << " integer" << endl;
	cout << endl;
	cout << "   integer = [-2147483648..2147483647] \n";
	cout << "             [-0x80000000..0x7fffffff] \n";
	cout << endl;
	exit(1);
}



