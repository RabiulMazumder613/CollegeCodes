/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*
Author: Rabiul Mazumder
Course: CSCI-136
Instructor: Alvin Lam
Assignment: Lab1A
*/
/*
Print all Fibonacci numbers from F(0) to F(59).
*/
#include <iostream>

using namespace std;

int main()  

{  

    int v1 = 0, v2 = 0;  

    cout << "Enter two integers to find numbers in their range (inclusive): " << endl;  

    cin >> v1 >> v2;  

    int current =  std::min(v1, v2);

    int max = std::max(v1, v2);

    while (current < max)  

    {  

        cout << current << endl;  

        ++ current;  

    }  

    return 0;  
}


