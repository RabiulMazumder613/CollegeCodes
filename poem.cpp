/*
Author: Rabiul Mazumder
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 9D
Fix program
*/

#include <iostream>

using namespace std;

string * createAPoemDynamically()

{

string *p = new string;

  

*p = "Roses are red, violets are blue";
//comment
return p;

}

int main() {

while(true) {

string *p;

p = createAPoemDynamically();

if (!p)

{

cout << "Memory allocation failed\n";

}

cout<<*p<<"\n";

// assume that the poem p is not needed at this point

//delete allocated memory

delete p;
//comment
}

}
