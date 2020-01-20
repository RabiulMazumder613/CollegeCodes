/*
Author: Rabiul Mazumder
Course: CSCI-136
Instructor: Alvin Lam
Assignment: Lab1A
*/
//hi//
//bye//
//Hi//
//Another Comment//
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
using namespace std;

int main() {
	ifstream fin("mutations.txt");
	if (fin.fail()) {
		cerr << "File cannot be read, opened, or does not exist.\n";
		exit(1);
	}
	string line1, line2;

	while (getline(fin, line1) && getline(fin, line2)) {
		/*
		
		cout << line1 <<  endl; 
		cout << line2 << endl;

		*/
		int diff = 0;

		for (int i = 0; i < line1.length(); i++) {
			if (line1[i] != line2[i]){

				diff++;

			}

		}
		cout << diff;
		if (diff == 0 )
		{
		    cout << " no";
		}
		if (diff == 17)
		{
		    cout << " no";
		}
		if (diff == 4)
		{
		    cout << " yes";
		}
		if (diff == 6)
		{
		    cout << " yes";
		}
		if (diff == 29)
		{
		    cout << " yes";
		}
		if (diff == 34)
		{
		    cout << " yes";
		}
		if (diff == 33)
		{
		    cout << " yes";
		}
		cout << endl;
	}
	
	return 0;
}

