/*
Author: Rabiul Mazumder
Course: CSCI-136
Instructor: Alvin Lam
Assignment: Lab1A
*/
//Helo//
//hi//
//ok//
//hi//
//hi//
#include<iostream>
using namespace std;

int main() 
{
    int width,height;
    cout<<"Enter width : " << endl;
    cin>>width;
    cout<<"Enter height : " << endl;
    cin>>height;
    int i,j;
    if(2*height>width+1)
    {
        cout<<"Impossible Shape!"; // impossible shape
    }
    else
    {
        for(i=0;i<height;i++)
        {
            for(j=0;j<i;j++)
            cout<<" ";
            for(j=0;j<width;j++)
            {
                cout<<"*";
            }
            width-=2;
            cout<<endl;
        }
    }
}
