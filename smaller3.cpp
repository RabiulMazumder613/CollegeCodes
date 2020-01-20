/*
Author: Rabiul Mazumder
Course: CSCI-136
Instructor: Alvin Lam
Assignment: Lab1A

User input three values then the program prints out the smallest of the three
*/
#include <iostream>
using namespace std;

int main() 
{
    int x;
    cout << "Enter the first number: ";
    cin >> x;
    int y;
    cout << "Enter the second number: ";
    cin >> y;
    int z;
    cout << "Enter the third number: ";
    cin >> z;
    if (x < y && x < z)//if less than y x is smaller
    {
        cout<<"The smaller of the three is " << x << endl;
    }
    else if ( y < x && y < z)
    {
        cout<<"The smaller of the three is " << y << endl;
    }
    else //if not than y is smaller than x
    {
        cout<<"The smaller of the three is " << z << endl;
    }
    return 0;
}
