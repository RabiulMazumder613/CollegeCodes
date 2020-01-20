/*
Author: Rabiul Mazumder
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 9F
Bonus
*/

#include <iostream>
#include <string>
using namespace std;

struct Coord3D
{
double x, y, z;
};

struct Particle
{
Coord3D coordinates;
double vx, vy, vz;
};

Particle* createParticle(double x, double y, double z, double vx, double vy, double vz);
void setVelocity(Particle *p, double vx , double vy, double vz);
Coord3D getPosition(Particle *p);
void move(Particle *p, double dt);
void deleteParticle(Particle *p);
//comment
//comment
//comment
//comment

int main()
{
Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
double time = 0.0;
double dt = 0.1;
while(time < 3.0)
{
setVelocity(p, 10.0 * time, 0.3, 0.1);
move(p, dt);
time += dt;
cout << "Time: " << time << "\t";
cout << "Position: "
<< getPosition(p).x << ", "
<< getPosition(p).y << ", "
<< getPosition(p).z << endl;
}

deleteParticle(p);
}

Particle* createParticle(double x, double y, double z, double vx, double vy, double vz)
{
Particle *p = new Particle();
p->coordinates.x = x;
p->coordinates.y = y;
p->coordinates.z = z;
p->vx = vx;
p->vy = vy;
p->vz = vz;
return p;
}
void setVelocity(Particle *p, double vx , double vy, double vz)
{
p->vx = vx;
p->vy = vy;
p->vz = vz;
}
Coord3D getPosition(Particle *p)
{
return p->coordinates;
}
void move(Particle *p, double dt)
{
p->coordinates.x += p->vx * dt;
p->coordinates.y += p->vy * dt;
p->coordinates.z += p->vz * dt;
//comment
}
void deleteParticle(Particle *p)
{
delete p;
//comment
}
