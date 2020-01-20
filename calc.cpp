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
#include <string>
using namespace std;

int main()
{
 char sign;
 int num, total;//assign variables
 cin >> total; //set total to the first input

 while(cin >> sign >> num)//cheeky double input
 {
  if(sign =='+')
  {
   total += num;
  }
  else if(sign =='-')
  {
   total -= num;
  }
  else if(sign ==';')
  {
   cout << total << endl;
   total = num;
  }
 }
 cout << total;
}
