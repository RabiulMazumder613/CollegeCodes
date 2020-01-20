/*
Author: Rabiul Mazumder
Course: CSCI-136
Instructor: Alvin Lam
Assignment: Lab1A

User input two values then the program prints out the smallest of the tw
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
    if (x < y)//if less than y x is smaller
    {
        cout<<"The smaller of the two is " << x << endl;
    }
    
    else //if not than y is smaller than x
    {
        cout<<"The smaller of the two is " << y << endl;
    }
    return 0;
}
