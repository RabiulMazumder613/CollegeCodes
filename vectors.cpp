/*
Author: Rabiul Mazumder
Course: CSCI-135
Instructor: Alvin Lam
Assignment: Lab 12 A

Here, briefly, at least in one or a few sentences
describe what the program does.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> makeVector(int n)
{
    vector<int> a;
    for(int i = 0; i<n; i++)
    {
        a.push_back(i);
    }
    return a;
}
