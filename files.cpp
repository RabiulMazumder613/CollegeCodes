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
#include <fstream>
using namespace std;
 
int main () 
{
    {
        ofstream myfile;
        myfile.open ("hello.txt");
        myfile << "Hello, World!\n";
        myfile.close();
    }
    ifstream myfile("hello.txt");
    std::string a;
    std::string b;
    if(myfile.is_open())
    {
        myfile >> a;
        myfile >> b;
        
        std::cout << a << " " << b << endl;
        
    }
    else
    {
        cout << "Error" << endl;
        
    }
    myfile.close();
    return 0;
}
