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
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int width, height;
    cout << "Input width: " << endl;
    cin >> width;
    cout << "Input height: " << endl;
    cin >> height;
    char rowStart = '*';
    char c = '*';
    for(int row = 1; row <= height; row++)
    {
        c = rowStart; //start with the character that the row should begin with
        for(int col = 1; col <= width; col++)
        {
            cout << c;
            if(col % 3 == 0)
            {
                if(c == '*')
                c = ' ';
                else
                c = '*';
            }
        }
        cout << endl;
        //check if we should toggle the row starting character, after every 3 lines, we need to toggle
        if(row % 3 == 0)
        {
            if(rowStart == '*')
            rowStart = ' ';
            else
            rowStart = '*';
        }
    }
}
