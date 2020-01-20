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
#include <cctype>

using namespace std; 


char shiftCaesarChar(char c, int rshift)
{
	if (isalpha(c))
	{	
		if ((int)c >= 97) //if lowercase
			return (((c - 'a') + rshift) % 26) + 'a';
		else		//if uppercase
			return (((c - 'A') + rshift) % 26) + 'A';
	}	
	return c;
}

string encryptCaesar(string plaintext, int rshift)
{
	string cipher;	
	for (int i = 0; i < plaintext.length(); i++)
	{
		cipher += shiftCaesarChar(plaintext[i], rshift);
	}	
	plaintext = cipher;
	return plaintext;
}


char shiftVigChar(char c, int rshift)
{
	char theletter;
	if (isalpha(c))
	{	
		//if lowercase
		if ((int)c >= 97) 
		    theletter = (c + (rshift - 'a') - 'a') % 26 + 'a';
	    //if uppercase
	    else    
		    theletter = (c + (rshift - 'a') - 'A') % 26 + 'A';
	    return theletter;
	}	
	return c;
}

string encryptVigenere(string plaintext, string keyword)
{
	string cipher;	
	int counter = 0;
	for (int i = 0; i < plaintext.length(); i++)
	{
		//wraps around the keyword
		int rshift = (int)(keyword[counter % keyword.length()]); 
		
		//adds the letters into a string
		cipher += shiftVigChar(plaintext[i], rshift);                 
		if (isalpha(plaintext[i]))
		    counter++;
	}	
	return cipher;
}

char deshiftChar(char c, int rshift){
    if(isalpha(c))
    {
        if((int)c >= 97) //lowercase
            return (((c - 97) + (26 + rshift)) % 26) + 97;
    
        else  //uppercase
            return (((c - 65) + (26 + rshift)) % 26) + 65;
    }  
  return c;
}

string decryptCaesar(string ciphertext, int rshift)
{
    string newtext;
    for(int i = 0; i < ciphertext.length(); i++)
    {
        newtext += deshiftChar(ciphertext[i],-1*rshift);
    }
    return newtext;
}

string decryptVigenere(string ciphertext, string keyword)
{
    string decrypted;
    int c = 0;
    for (int i = 0;i < ciphertext.length(); i++)
    {
        char letter = ciphertext[i];
    //  cout << letter << endl;
    if (isalpha(letter))
    {
        int shift =- (int)keyword[c%keyword.length()] + 97;
        c += 1;
        //cout << shift << endl;
        decrypted += deshiftChar(letter, shift);
    }
    else
        decrypted += letter;
    
  }
  return decrypted;
}


int main()
{
    //  string input="ab cde fg";
    //  cout << decryptCaesar("Rovvy, Gybvn!",10) << endl;
    //  cout << decryptVigenere("Jevpq, Wyvnd!","cake") << endl;
    //  getline(std::cin, input);
    
    string someInput;

    cout << "Enter plaintext: ";
    getline(cin, someInput);
    
    cout << endl << "= Caesar =" << endl;
    
    int rightShift;
    cout << "Enter shift: ";
    cin >> rightShift;
    
    string caesarInput = encryptCaesar (someInput, rightShift);
    cout << "Cipher text: " << caesarInput << endl;
    cout << "Decrypted: " << decryptCaesar(caesarInput, rightShift) << endl;
    
    cout << endl << "= Vigenere =" << endl;
    string key;
    cout << "Enter keyword: ";
    cin >> key;
    
    string vigenereInput = encryptVigenere (someInput, key);
    cout << "Cipher text: " << vigenereInput << endl;
    cout << "Decrypted: " << decryptVigenere(vigenereInput, key) << endl;
    
    return 0; 
}

