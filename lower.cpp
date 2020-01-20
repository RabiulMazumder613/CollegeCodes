/*
Author: Rabiul Mazumder
Course: CSCI-136
Instructor: Alvin Lam
Assignment: Lab1A
*/
#include <iostream>
using namespace std;

// Function to demonstrate printing pattern

// Driver Function
int main()
{
    int num;
    cout<<"Input side length: ";
    cin>> num;
    cout<<"\n";
    cout<<"Shape:\n";
    void pypart(int n);
    {
        // outer loop to handle number of rows
        //  n in this case
        for (int i=0; i<n; i++)
            {
                //  inner loop to handle number of columns
                //  values changing acc. to outer loop
                for(int j=10; j>i; j-- )
                {
                    // printing stars
                    cout << "*";
                    }
                    // ending line after each row
                    cout << endl;
                    }
    }
    pypart(n);
    return 0;
}
