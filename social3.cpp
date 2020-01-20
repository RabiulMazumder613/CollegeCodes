/*
Author: Rabiul Mazumder
Course: CSCI-136
Instructor: Alvin Lam
Assignment: Lab1A
*/
//Helo//
//hi//
//ok//
//hi//
//k//
#include <iostream>
#include <string>
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
        static const int MAX_USERS = 20;        
        Profile profiles[MAX_USERS];            
        int numUsers;                           
        bool following[MAX_USERS][MAX_USERS];  
        
        int findID (string usrn)
        {
            for (int i = 0; i < MAX_USERS; i++)
            {
                if (profiles[i].getUsername().compare(usrn) == 0)
                {
                    return i;
                }
               
                for (int j = 0; j < usrn.length(); j++)
                {
                    if (!isalnum(usrn[j]))
                    {
			            return -2;
                    }
                } 
            }
            return -1;
        }
        
    public:
        Network()
        {
            numUsers = 0;
            for (int i = 0; i < MAX_USERS; i++)
            {
                for (int j = 0; j < MAX_USERS; j++)
                {
                    following[i][j] = false;    
                }
            }
        }
        
        bool addUser(string usrn, string dspn)
        {
            if (numUsers < MAX_USERS && findID(usrn) == -1)
            {
                profiles[numUsers] = Profile(usrn, dspn);
	        	numUsers++;
                return true;
            }
            return false;
        }
        
        // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
        // return true if success (if both usernames exist), otherwise return false
        bool follow(string usrn1, string usrn2)
        {
            int x = findID(usrn1);
            int y = findID(usrn2);
            if (x > -1 && y > -1)
            {
                following[x][y] = true;
                return true;
            }
            return false;
        }
        
        // Print Dot file (graphical representation of the network)
        void printDot()
        {
            cout << "digraph { " << endl;
            for (int i = 0; i < MAX_USERS; i++)
            {
                if (profiles[i].getUsername() != "")
                { 
                    cout << "   \"@" << profiles[i].getUsername() << "\"" << endl;
                }
            }
            
            for (int i = 0; i < MAX_USERS; i++)
            {
                for (int j = 0; j < MAX_USERS; j++)
                {
                    if (profiles[i].getUsername() != "" && profiles[j].getUsername() != "" && following[i][j] == true)
                        cout << "   \"@" << profiles[i].getUsername() << "\" -> \"@" << profiles[j].getUsername() << "\"" << endl;
                }
            }
            cout << "}";
        } 

}; 

int main() {
    Network nw;
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    nw.addUser("wario", "Wario");
    
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    nw.follow("mario2", "luigi");

    nw.printDot();
}

