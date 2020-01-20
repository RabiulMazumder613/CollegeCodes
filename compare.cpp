/*
Author: Your name
Course: CSCI-136
Instructor: Your instructor 
Assignment: Lab 3C
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main()
{
	ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) 
	{
		cerr << "File cannot be opened for reading." << endl;
	   	exit(1); // exit if failed to open the file
	}

	string junk;        // new string variable
	getline(fin, junk); // read one line from the file 

	string date;	
	double eastSt, eastEl, westSt, westEl;

	string startDate;
	cout << "Enter a start date: ";
	cin >> startDate;
	string endDate;
	cout << "Enter an end date: ";
	cin >> endDate;

	while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) 
	{ 
	    	fin.ignore(INT_MAX, '\n'); 
		
		if (date >= startDate && date <= endDate) //compares date
		{
			if (eastEl > westEl) //East
			{
				cout << date << " " << "East" << endl;
			}
			if (westEl > eastEl) //West
			{
				cout << date << " " << "West" << endl;
			}
			if (westEl == eastEl) //Equal
			{
				cout << date << " " << "Equal" << endl;
			}
		}
	}

	return 0;
}
