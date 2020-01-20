/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
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
User input two values then the program prints out the smallest of the tw
*/
//hi//
//ki//

#include <iostream>
using namespace std;

int main()
{
    int myData[10];
    for (int i = 0; i < 10; i++)
    {
        myData[i] = 1;
    }

    int index = 0;
    int value;

    do 
    {
        for (int i = 0; i < 10; i++)
        {
            cout << myData[i] << " ";
        }
        cout << endl;
        
        cout << "Enter index: ";
        cin >> index;
        
        cout << "Enter value: ";
        cin >> value;
        
        if (index >= 0 && index < 10)
        {
            myData[index] = value;
        }
    
    } while (index >= 0 && index < 10); // if the index was good, repeat
    
    return 0;
}

