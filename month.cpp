/*
Author: Rabiul Mazumder
Course: CSCI-136
Instructor: Alvin Lam
Assignment: Lab1A
*/
/*
Asks the user to input an integer representing a year number and enter the month (1-12).
It will print the days in that month (taking into account leap years).
*/
/*
 2012, 2016, 2020, and 2040 are all leap years.
*/
/*
However, the century years 1800, 1900, 2100, 2200, 2300 and 2500 are NOT.
*/
/*
Yet, 2000, 2400, 2800 are still leap years.
*/
#include <iostream>
using namespace std;

int main() 
{
    int year;
    cout << "Enter year: ";
    cin >> year;
    int month;
    cout << "Enter month: ";
    cin >> month;
    if (year % 4 && month == 2)
    {
        cout<<"28 days" << endl;
    }
    else if (year % 100 && month == 2)
    {
       cout<<"29 days " << endl; 
    }
    else if (year % 400 && month == 2)
    {
       cout<<"28 days " << endl; 
    }
    else if (year == 2000 && month == 2)
    {
       cout<<"29 days " << endl; 
    }
    else if (year == 2400 && month == 2)
    {
       cout<<"29 days " << endl; 
    }
    else if (year == 2800 && month == 2)
    {
       cout<<"29 days " << endl; 
    }
    else if (year % 400 && month <= 7 && month % 2) 
    {
        cout<<"31 days " << endl;
    }
    else if (year % 4 && month == 11) 
    {
        cout<<"30 days " << endl;
    }
    else if (year % 4 && month == 12) 
    {
        cout<<"31 days " << endl;
    }
    else if (year % 4 && month >= 8 && month % 3) 
    {
        cout<<"31 days " << endl;
    }
    else 
    {
        cout<<"30 days" << endl;
    }
    return 0;
}

