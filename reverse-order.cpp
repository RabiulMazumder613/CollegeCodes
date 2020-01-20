/*
Author: Rabiul Mazumder
Course: CSCI-136
Instructor: Alvin Lam
Assignment: Lab1A
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
	
	string days[366];
	double feets[366];
    int counter = 0;
	
	while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) 
	{ 
	    fin.ignore(INT_MAX, '\n'); 
		
		if (date >= startDate && date <= endDate) //compares date
		{
		    days[counter] = date;
		    feets[counter] = westEl;
		    counter++;
		}
	}
	
/*	for (int i = 0; i < counter; i++)
	{
	    cout << days[i] << " " << feets[i] << endl;
	} */
	
	for (int i = counter - 1; i >= 0; i--)
	{
	    cout << days[i] << " " << feets[i] << endl;
	}
	
	return 0;
}

