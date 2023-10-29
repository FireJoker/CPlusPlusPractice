///////////////////////////////////////////////
//File: TestCalendar.cpp                     //
//main file of this program                  //
//Student name:                              //
//Student number:                            //
//Date: November 1, 2017                     //
///////////////////////////////////////////////

#include "Calendar.h"

int main()
{
	int month, day, year;
	char dash;
	bool valid;
	string date;

	calendar test;
	calendar date1;
	do
	{
		cout << "Enter the first date using format mm-dd-yyyy: ";
		cin >> month >> dash >> day >> dash >> year;
		valid = test.checkDate(month, day, year);
	} while (!valid);

	date1 = calendar(month, day, year);
	cout << "The string version of the date is: ";
	date = date1.toString();
	cout << date;

	test = date1.nextDate();
	cout << "The next date in string version is: ";
	date = test.toString();
	cout << date;

	//creat a object to get second date
	calendar date2;
	do
	{
		cout << "Enter the second date using format mm-dd-yyyy: ";
		cin >> month >> dash >> day >> dash >> year;
		valid = test.checkDate(month, day, year);
	} while (!valid);
	date2 = calendar(month, day, year);

	//to compare two dates
	date1.compareDates(date2);

	//system("pause");
	return 0;
}
