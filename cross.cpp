/*
Author: Rabiul Mazumder
Course: CSCI-136
Instructor: Alvin Lam
Assignment: Lab1A
*/
#include <iostream>

using namespace std;

int main()
{
    int size;
    cout<<"Input size: ";
    cin >> size;
    cout<<"\n";
    cout<<"Shape:\n";
    for (int rows=1;rows<=size;rows++){//rows//
        for(int cols=1;cols<=size;cols++){//columns//
            if(rows==cols || cols==(size+1)-rows) cout <<"*";
            else cout << " ";
            
        }
        cout << endl;
    }
    return 0;
    
}

