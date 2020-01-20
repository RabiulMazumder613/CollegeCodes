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

string encryptCaesar(string plaintext, int rshift)
{
    string temp = plaintext;
    int length;

    length = (int)temp.length();

    for (int i = 0; i < length; i++)
    {
        if (isalpha(temp[i]))
        {
            for (int j = 0; j < rshift; j++)
            {
                if (temp[i] == 'z')
                {
                    temp[i] = 'a';
                }
                else if (temp[i] == 'Z')
                {
                    temp[i] = 'A';
                }
                else
                {
                    temp[i]++;
                }
            }
        }
    }

    return temp;
}


int main()
{
    string plaintext, encoded_string;
    int rshift;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "Enter shift: ";
    cin >> rshift;

    encoded_string = encryptCaesar(plaintext, rshift);

    cout << "Ciphertext: " << encoded_string << "\n\n";

    return 0;
}
