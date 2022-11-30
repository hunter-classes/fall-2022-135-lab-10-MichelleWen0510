#include <iostream>
#include "funcs.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"

int main()
{
	Time one = {12,00};
	Time two = {14,00};
	Time three = {17,30};

	std::cout << "Minutes from 12:00 to midnight (0:00): " << minutesSinceMidnight(one);
	std::cout << std::endl;

	std::cout << "Minutes between 14:00 and 17:30: " << minutesUntil(two,three);
	std::cout << std::endl;

	Time four = {10,45};
	Time five = {23,15};
	Time six = addMinutes(four,60);
	std::cout << "-------------------------------" << std::endl;
	printTime(four);
	std::cout << std::endl;
	std::cout << "Adding 60 minutes" << std::endl;
	printTime(six);
	std::cout << std::endl;
	Time seven = addMinutes(five, 120);
	std::cout << "-------------------------------" << std::endl;
	printTime(five);
	std::cout << std::endl;
	std::cout << "Adding 120 minutes" << std::endl;
	printTime(seven);
	std::cout << std::endl;
	std::cout << "-------------------------------" << std::endl;
	Time eight = addMinutes( {5,30} , 30);
	std::cout << "Adding 30 minutes to 5:30" << std::endl;
	printTime(eight);
	std::cout << std::endl;

	std::cout << "-------------------------------" << std::endl;
	Movie movie1 = {"Back to the Future", COMEDY, 116};
	Movie movie2 = {"Black Panther", ACTION, 134};
	TimeSlot morning = {movie1, {9,15}};
	TimeSlot daytime = {movie2, {12,15}};
	TimeSlot evening = {movie2, {16,45}};
	TimeSlot afternoon = {movie1, {19,00}};
	TimeSlot night = {movie2, {22,00}};
	std::cout << getTimeSlot(morning) << std::endl;
	std::cout << getTimeSlot(daytime) << std::endl;
	std::cout << getTimeSlot(evening) << std::endl;
	std::cout << getTimeSlot(afternoon) << std::endl;
	std::cout << getTimeSlot(night) << std::endl;

	std::cout << "-------------------------------" << std::endl;
	TimeSlot after = scheduleAfter(morning,movie1);
	std::cout << "Scheduling movie after:" << std::endl;
	std::cout << getTimeSlot(morning) << std::endl;
	std::cout << getTimeSlot(after) << std::endl;

	std::cout << "-------------------------------" << std::endl;
	std::cout << "Times and Overlapping:" << std::endl;
	std::cout << getTimeSlot(daytime) << std::endl;
	std::cout << getTimeSlot(after) << std::endl;
	std::cout << getTimeSlot(night) << std::endl;
	std::cout << "1 and 2: " << timeOverlap(daytime,after);
	std::cout << std::endl;
	std::cout << "1 and 3: " << timeOverlap(daytime,night);
	std::cout << std::endl;
}

