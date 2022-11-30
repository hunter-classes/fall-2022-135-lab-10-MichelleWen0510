#include <iostream>
#include <string> 
#include "funcs.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"

void printTime(Time time)
{
	std::cout << time.h << ":" << time.m;
}

int minutesSinceMidnight(Time time)
{
	int hours = time.h;
	int minutes = time.m;
	int total = (hours*60)+minutes;
	return total;
}

int minutesUntil(Time earlier, Time later)
{
	int totalL=(later.h*60)+later.m;
	int totalE=(earlier.h*60)+earlier.m;
	return totalL-totalE;	
}

Time addMinutes(Time time, int min)
{
	int cur = (time.h*60)+time.m;
	int total = cur+min;
	int minutes = total%60;
	int hours = ((total-minutes)/60)%24;
	Time now = {hours,minutes};
	return now;
}

void printMovie(Movie mv)
{
	std::string g;
	switch(mv.genre) {
		case ACTION : g = "ACTION"; break;
		case COMEDY : g = "COMEDY"; break;
		case DRAMA : g = "DRAMA"; break;
		case ROMANCE : g = "ROMANCE"; break;
		case THRILLER : g = "THRILLER"; break;
	}
	std::cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

std::string getTimeSlot(TimeSlot ts)
{
	std::string mt;
	Movie holder = ts.movie;
	Time staTime = ts.startTime;
	std::string sTime = std::to_string(staTime.h) + ":" + std::to_string(staTime.m);
	Time endTime = addMinutes(ts.startTime,holder.duration);
	std::string eTime = std::to_string(endTime.h) + ":" + std::to_string(endTime.m);

	std::string g;
	switch(holder.genre) {
		case ACTION : g = "ACTION"; break;
		case COMEDY : g = "COMEDY"; break;
                case DRAMA : g = "DRAMA"; break;
		case ROMANCE : g = "ROMANCE"; break;
		case THRILLER : g = "THRILLER"; break;	
	}
	mt = holder.title + " " + g + " (" + std::to_string(holder.duration) + " min) [starts at " + sTime + ", ends by " + eTime + "]";
	return mt;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
	Movie holder = ts.movie;
	Time endTime = addMinutes(ts.startTime, holder.duration);
	TimeSlot after = {nextMovie, endTime};
	return after;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
	Movie one = ts1.movie;
	Time endTime = addMinutes(ts1.startTime, one.duration);
	if(minutesUntil(ts1.startTime, endTime) > minutesUntil(ts1.startTime, ts2.startTime))
	{
		return true;
	}
	return false;
}



