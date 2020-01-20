/*
Author: Rabiul Mazumder
Course: CSCI-136
Instructor: Alvin Lam
Assignment: Lab1A
*/
//hi//
//bye//
//Hi//
//Another Comment//
#include <iostream>

#include <string>

using namespace std;

//comment

 

string removeLeadingSpaces(string line);

 

int main() {

   string line;

   while(getline(cin, line)) {

       cout << removeLeadingSpaces(line) << endl;

   }

   return 0;

}

 

string removeLeadingSpaces(string line) {

   string result = "";

   bool check = true;

   for(int i = 0; i < line.size(); ++i) {

       if(!(check && isspace(line[i]))) {

           result += line[i];

           check = false;

       }

   }

//comment

   return result;

}
