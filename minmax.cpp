/*
Author: Rabiul Mazumder
Course: CSCI-136
Instructor: Alvin Lam
Assignment: Lab1A
*/
#include <fstream>
#include <cstdlib>
#include <climits>
#include <iostream>

using namespace std;

int main(){
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    string junk;        // new string variable
    getline(fin, junk); // read one line from the file
    
    string date;
    double eastSt, eastEl,westSt,westEl;
    
    double max=0,min=1,number,sum=0;
    double count=0;
        
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 
        
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
            //ignorring the remaining columns 
            // for example, to print the date and East basin storage:
        if (eastSt > max)
        {
            max = eastSt;
        }
        if (eastSt < 59.89)
        {
            min = eastSt;
        }
    }
    cout <<"Minimum storage in East basin: " << min << " billion gallons" <<endl;
    cout <<"Maximum storage in East basin: " << max << " billion gallons" <<endl;
    fin.close();
}




