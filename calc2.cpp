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
 int num, squared;
 char sign;
 bool truthValue = true; 
    int total;
   
    cin >> num; // first number
    total = num; // sets total equal to first number

    while(cin >> sign) // While the reading operation is a success
 { 
        if(sign == '^')
        {
   squared = num * num; //stores number squared
   if (truthValue == true) //if positive
   {
    total = total - num; //to account for the fact that num is automatically added to total
    total = total + squared; 
   }  
   else if (truthValue == false) //if negative
   { 
    total = total + num; // to account for the fact that num is automatically subtracted from total
    total = total - squared;
   }
  }
        else if (sign == '+')
        {
           truthValue = true; // positive
           cin >> num;
            total = total + num;
        }
        else if(sign == '-')
        {
           truthValue = false; // negative
           cin >> num;
            total = total - num;
        }
        else if(sign == ';')
        {
         cout << total << endl;
         cin >> num; //first number in each line 
         total = num;
         truthValue = true;
        }
 }
 return 0;   
}
