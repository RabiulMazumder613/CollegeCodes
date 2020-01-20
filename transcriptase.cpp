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
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

char DNAbase_to_mRNAbase(char letter)
{
    if (letter == 'A')
        return 'U';
    else if (letter == 'T')
        return 'A';
    else if (letter == 'C')
        return 'G';
    else if (letter == 'G')
        return 'C';
}

string DNA_to_mRNA(string theDNA)
{
    string theRNA;
    char someLetter;
    
    for (int i = 0; i < theDNA.length(); i++)
    {
        theRNA += DNAbase_to_mRNAbase(toupper(theDNA[i]));
    }
    return theRNA;
}

int main()
{
    ifstream fin("dna.txt");
   
    string strand;
    
    while(getline(fin, strand)) 
    {
        cout << DNA_to_mRNA(strand) << endl;
    }
    return -1;
}

