/*
Author: Rabiul Mazumder
Course: CSCI-136
Instructor: Alvin Lam
Assignment: Lab1A
*/
/*
Asks the user to input an integer representing a year number (1999, 2016, etc.). If the input year is a leap year according to the modern Gregorian calendar, it should print Leap year, otherwise, print Common year.
*/
#include <iostream>

#include <fstream>

using namespace std;

int main() 
{
    int x = 0;
    int sum = 0;
    ifstream inFile;
    inFile.open("numbers.txt");
    if (!inFile) {
    cerr << "Unable to open file";
    exit(1); // terminate with error
}
    while (inFile >> x) {
        sum = sum + x;
    }
    
    inFile.close();
    cout << "Sum = " << sum << endl; 
    return 0;
}
