/*
Author: Rabiul Mazumder
Course: CSCI-136
Instructor: Alvin Lam
Assignment: Lab1A
*/
//Helo//
//hi//
//ok//
#include <iostream>

using namespace std;
int main()
{
    int W;
    cout << "Input Width: ";
    cin>> W;
    int H;
    cout << "Input Height: ";
    cin>> H;
    cout << "\n";
	const size_t N = 9;
	
	const char c1 = '*', c2 = ' ';

	for ( size_t i = 0; i < H; i++ )
	{
		for ( size_t j = 0; j < W; j++ )
		{
			std::cout << ( ( i + j ) % 2 == 0 ? c1 : c2 );
		}
		std::cout << std::endl;
	}

	return 0;
}
