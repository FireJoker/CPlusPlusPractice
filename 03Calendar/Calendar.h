///////////////////////////////////////////////
//File: Calendar.h                           //
//The head file of this program              //
//Student name:                              //
//Student number:                            //
//Date: November 1, 2017                     //
///////////////////////////////////////////////

#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class calendar {
public:
	calendar();
	calendar(int month, int day, int year);
	bool checkDate(int m, int d, int y);
	string toString();
	calendar nextDate();
	void compareDates(const calendar& d) const;

private:
	int m;
	int d;
	int y;
	bool vaild;

	int  dayOfMonth[13];
	string monthName[13];
};

#endif

