/*
Rabiul Mazumder 
Alvin Lam
Lab 13A
*/

#include <iostream>
#include <array>

using namespace std;

//that prints all numbers in range left ≤   x   ≤ right, 
//separated by spaces. 
//(Don’t use loops, global or static variables.)

void printRange(int left, int right)
{
	if (left > right)
	{
		cout << "";
	}
    else
    {
        cout << left << " ";  
        printRange(left + 1, right);
    }
}

//that prints the sum of all numbers in range left ≤   x   ≤ right, 
//separated by spaces. 
//(Don’t use loops, global or static variables.)

int sumRange(int left, int right)
{
	if (left > right)
	{
		return 0;
	}
    else
    {
        return left + sumRange(left + 1, right);
    }
} 

//receives an array (as a pointer to its first element) and the size of the array, and should return the sum of its elements. 
//The function itself should not do any new dynamic memory allocations.

int sumArray(int *arr, int size)
{
	if (size <= 0)
	{
		return 0;
	}
	else 
	{
		return arr[size - 1] + sumArray(arr, size - 1);
	}
}

void isAlphanumeric_helper(string s, bool& value)
{
	if(s.length()==0)
	{
		return;
	}
	if(!isalnum( s[0]))
	{
		value = false;
		return;
	}
	isAlphanumeric_helper(s.substr(1, s.length()-1), value);
	return;
}

bool isAlphanumeric(string s)
{
    bool val = true;
    isAlphanumeric_helper(s, val); // calls helper
    return val;

}

bool nestedParens(string s){
	if(s.length() ==0) 
		return true;
	//if(s.substr(0,1)=="(" && s.substr(s.length()-1,1)==")" ){
	if(s[0] == '(' && s[s.length()-1] == ')'){	
		if(nestedParens(s.substr(1, s.length()-2))){
			return true;
		}
	}
	return false;
}	

int sumArray(int *arr, int size) 
{
	return (size != 0) ? (*arr + sumArray(arr+1, size-1)) : 0;
}

bool helper(int *p, int l, int n) 
{
	return !n || ((n >= 0 && l) && (helper(p+1, l-1, n) || helper(p+1, l-1, n - *p)));
}

bool divisible(int *p, int n) 
{
	return !(sumArray(p, n) % 2) && helper(p, n, sumArray(p, n) / 2);
}

int main()
{
	cout << nestedParens("((()))") << endl;      // true (1)
	cout << nestedParens("()") << endl;          // true (1)
	cout << nestedParens("") << endl;            // true (1)

	cout << nestedParens("(((") << endl;         // false (0)
	cout << nestedParens("(()") << endl;         // false (0)
	cout << nestedParens(")(") << endl;          // false (0)
	cout << nestedParens("a(b)c") << endl;       // false (0)
	return 0;
}
