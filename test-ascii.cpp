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

using namespace std;

int main()
{
    string str;
    cout << "Input: \n";
    getline(cin, str);
    char ch;
    for(int i = 0 ; i < str.length() ; i++)
    {
        ch = str.at(i);
        cout << str[i] << " "<< (int) ch << "\n";
    }
    return 0;
 }
