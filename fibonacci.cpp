/*
Author: Rabiul Mazumder
Course: CSCI-136
Instructor: Alvin Lam
Assignment: Lab1A
*/
/*
Print all Fibonacci numbers from F(0) to F(59).
*/
//By 47 it starts to have negative values//
#include <iostream>
using namespace std;

int main()
{
    int n, t1 = 0, t2 = 1, nextTerm = 0;

    cout << "Fibonacci Series: ";

    for (int i = 1; i <= 60; ++i)
    {
        // Prints the first two terms.
        if(i == 1)
        {
            cout << t1 << " ";
            continue;
        }
        if(i == 2)
        {
            cout << t2 << " ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        
        cout << nextTerm << " ";
    }
    return 0;
}
