/*
Author: Rabiul Mazumder
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 9D
Fix program
*/

#include<iostream>

using namespace std;

//Define structure

struct Coord3D

{

double x;

double y;

double z;

};

//Create function to allocate memory and initialize

Coord3D* createCoord3D(double x, double y, double z)

{

cout <<"dynamically allocated memory for structure"<<endl;

Coord3D* ppos = new Coord3D;

ppos->x = x;

ppos->y = y;

ppos->z = z;

return ppos;

}

//Function to free memory

void deleteCoord3D(Coord3D *p)

{

cout <<"Deleting the structure"<<endl;

delete p;

}

void move(Coord3D *pp, Coord3D *pv, double t)

{

pp->x = (pv->x*t)+pp->x;

pp->y = (pv->y*t)+pp->y;

pp->z = (pv->z*t)+pp->z;

}

int main()

{

double x, y, z;

cout <<"Enter position: ";

cin>>x>>y>>z;

Coord3D *ppos = createCoord3D(x, y, z);

cout <<"Enter Velocity: ";

cin>>x>>y>>z;

Coord3D *pvel = createCoord3D(x, y, z);

move(ppos, pvel, 10.0);

cout <<"Coordinates after 10 seconds: "<<(*ppos).x<<" "<<(*ppos).y<<" "<<(*ppos).z<< endl;

deleteCoord3D(ppos);

deleteCoord3D(pvel);

return 0;

}
