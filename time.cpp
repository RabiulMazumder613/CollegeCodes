/*
Author: Rabiul Mazumder
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 10
Fix program
*/
#include <iostream>
using namespace std;

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Time { 
public:
    int h;
    int m;
};

class Movie { 
public: 
    string title;
    Genre genre; // only one genre per movie
    int duration; // in minutes
};

class TimeSlot { 
public: 
    Movie movie; // what movie
    Time startTime; // when it starts
};

int minutesSinceMidnight(Time time)
{
  return time.h * 60 + time.m;
}

int minutesUntil(Time earlier, Time later)
{
  return minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
}

Time addMinutes(Time time0, int min)
{
  time0.m += min;
  //cout<<time0.m<<endl;
  if(time0.m >= 60)
  {
    time0.h += (time0.m/60);
    time0.m -= ((time0.m/60)*60);
    //cout<<time0.m<<endl;
    //cout<<time0.h<<endl;
  }
  return time0;
}

void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION : g = "ACTION"; break;
        case COMEDY : g = "COMEDY"; break;
        case DRAMA : g = "DRAMA"; break;
        case ROMANCE : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts)
{
 // string printTimeSlot="";
  Time timeEnd=addMinutes(ts.startTime, ts.movie.duration);
  printMovie(ts.movie);
  cout<<"[starts at "<<ts.startTime.h<<":"<<ts.startTime.m<<", ends by "<<timeEnd.h<<":"<<timeEnd.m<<"]";
  //cout<<printTimeSlot;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
  TimeSlot nextSlot={nextMovie,addMinutes(ts.startTime, ts.movie.duration)};
  return nextSlot;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
  int ts2Time=minutesSinceMidnight(ts2.startTime);
  //cout<<ts2Time<<endl;
  int ts1Time=minutesSinceMidnight(ts1.startTime);
  //cout<<ts1Time<<endl;
  if(ts1Time==ts2Time)
    return true;
  if(minutesUntil(ts1.startTime, ts2.startTime)<0)
  {
    //cout<<"t2"<<endl;
    //cout<<ts2Time+ts2.movie.duration<<endl;
    //cout<<minutesSinceMidnight(ts1.startTime)<<endl;
    if(ts2Time+ts2.movie.duration>minutesSinceMidnight(ts1.startTime))
      return true;
    else
      return false;
  }
  else
  {
    //cout<<"t1"<<endl;
    //cout<<ts1Time+ts1.movie.duration<<endl;
    //cout<<minutesSinceMidnight(ts2.startTime)<<endl;
    if(ts1Time+ts1.movie.duration>minutesSinceMidnight(ts2.startTime))
      return true;
    else
      return false;
  }
  return false;
}

int main() {
  //Time timeEnd=addMinutes({9,15}, 116);
  //cout<<endl<<timeEnd.h<<timeEnd.m;
  Movie future={"Back To The Future",COMEDY,180};
  Movie future2={"5cm",DRAMA,63};
  TimeSlot t1={future,{10,30}};
  TimeSlot t2={future2,{8,30}};
  cout<<timeOverlap(t1, t2);

}
