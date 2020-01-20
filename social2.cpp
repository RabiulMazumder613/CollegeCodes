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
#include <stdio.h> 
#include <stdlib.h> 

using namespace std;

class Profile 
{
    private:
        string username;
        string displayname;
    public:
        // Profile constructor for a user (initializing 
        // private variables username=usrn, displayname=dspn)
        Profile(string usrn, string dspn)
        {
            username = usrn;
            displayname = dspn;
        }
        // Default Profile constructor (username="", displayname="")
        Profile()
        {
            username = "";
            displayname = ""; 
        }
        // Return username
        string getUsername()
        {
            return username;
        }
        // Return name in the format: "displayname (@username)"
        string getFullName()
        {
            return displayname + " (@" + username + ")";
        }
        // Change display name
        void setDisplayName(string dspn)
        {
            displayname = dspn;
        }
};

class Network 
{
    private:
        static const int MAX_USERS = 20;    // max number of user profiles
        Profile profiles[MAX_USERS];        // user profiles array:
        int numUsers;                       // number of registered users
                                            // mapping integer ID -> Profile

        // Returns user ID (index in the 'profiles' array) by their username
        // (or -1 if username is not found)
        int findID (string usrn)
        {
            for (int i = 0; i < MAX_USERS; i++)
            {
                if (profiles[i].getUsername().compare(usrn) == 0)
                {
                    return 10;
                }
               
                for (int j = 0; j < usrn.length(); j++)
                {
                    if (!isalnum(usrn[j]))
                    {
			            return 20;
                    }
                } 
            }
            return -1;
        }
    public:
        // Constructor, makes an empty network (numUsers = 0)
        Network()
        {
            numUsers = 0;
        }
        // Attempts to sign up a new user with specified username and displayname
        // return true if the operation was successful, otherwise return false
        bool addUser(string usrn, string dspn)
        {
        //    cout << "The index is: " << findID(usrn) << " ";
            if (numUsers < MAX_USERS && findID(usrn) == -1)
            {
                profiles[numUsers] = Profile(usrn, dspn);
	        	numUsers++;
                return true;
            }
            return false;
        }
};

int main() 
{
	Network nw;
	cout << nw.addUser("mario", "Mario") << endl;     
	cout << nw.addUser("luigi", "Luigi") << endl;     
 
	cout << nw.addUser("mario", "Mario2") << endl;    
	cout << nw.addUser("mario 2", "Mario2") << endl;  
	cout << nw.addUser("mario-2", "Mario2") << endl;  

	for(int i = 2; i < 20; i++)
		cout << nw.addUser("mario" + to_string(i), "Mario" + to_string(i)) << endl;   

	cout << nw.addUser("yoshi", "Yoshi") << endl; 
}

