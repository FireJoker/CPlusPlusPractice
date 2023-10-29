///////////////////////////////////////////////
//File: Calendar.cpp                         //
//host all the functions of this program     //
//Student name:                              //
//Student number:                            //
//Date: November 1, 2017                     //
///////////////////////////////////////////////

#include "Calendar.h"

//default constructor that initializes a date object to 01-01-1900
calendar::calendar()
{
	m = 1;
	d = 1;
	y = 1990;

}

//class constructor
calendar::calendar(int month, int day, int year)
{
	m = month;
	d = day;
	y = year;

	//set all array to fit Hercules
	dayOfMonth[0] = 0;
	dayOfMonth[1] = 31;
	dayOfMonth[2] = 28;
	dayOfMonth[3] = 31;
	dayOfMonth[4] = 30;
	dayOfMonth[5] = 31;
	dayOfMonth[6] = 30;
	dayOfMonth[7] = 31;
	dayOfMonth[8] = 31;
	dayOfMonth[9] = 30;
	dayOfMonth[10] = 31;
	dayOfMonth[11] = 30;
	dayOfMonth[12] = 31;

	monthName[0] = "0";
	monthName[1] = "January";
	monthName[2] = "February";
	monthName[3] = "March";
	monthName[4] = "April";
	monthName[5] = "May";
	monthName[6] = "Jun";
	monthName[7] = "July";
	monthName[8] = "August";
	monthName[9] = "September";
	monthName[10] = "October";
	monthName[11] = "November";
	monthName[12] = "December";
}

//to check if the entered date is vaild
bool calendar::checkDate(int m, int d, int y)
{
	vaild = true;

	//check for leap year
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
		dayOfMonth[2] = 29;
	else
		dayOfMonth[2] = 28;

	//check for day, month, year
	if (y < 1900 || m > 12 || m < 1 || d > dayOfMonth[m] || d < 1)
	{
		vaild = false;
		cout << "Incorrect day!" << endl;
	}

	return vaild;
}

//returns the string version of a date object
string calendar::toString()
{
	string dayName;
	stringstream s;

	switch (d)
	{
	case 1: case 21: case 31:
		dayName = "st";
		break;
	case 2: case 22:
		dayName = "nd";
		break;
	case 3: case 23:
		dayName = "rd";
		break;
	default:
		dayName = "th";
	}
	s << monthName[m] << " " << d << dayName << ", " << y << endl;
	return s.str();
}

//returns the new value of the date object
calendar calendar::nextDate()
{
	int nm, nd, ny;
	nm = m;
	nd = d;
	ny = y;

	//check for leap year
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
		dayOfMonth[2] = 29;
	else
		dayOfMonth[2] = 28;

	nd += 1;
	if (nd > dayOfMonth[nm])
	{
		nd = 1;
		nm += 1;
		if (nm > 12)
		{
			nm = 1;
			ny += 1;
		}
	}
	calendar nextdate(nm, nd, ny);
	return nextdate;
}

//checks if the date of interest is before, after or equal to the argument date
void calendar::compareDates(const calendar& D) const
{
	if (y > D.y)
		cout << "The first date comes after the second one." << endl;
	else if (y < D.y)
		cout << "The first date comes before the second one." << endl;
	else
	{
		if (m > D.m)
			cout << "The first date comes after the second one." << endl;
		else if (m < D.m)
			cout << "The first date comes before the second one." << endl;
		else
		{
			if (d > D.d)
				cout << "The first date comes after the second one." << endl;
			else if (d < D.d)
				cout << "The first date comes before the second one." << endl;
			else
				cout << "The first date and the second one are same day." << endl;
		}
	}
}
