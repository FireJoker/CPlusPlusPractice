# Calendar

Develop in C++ a class date to represent a calendar. The class should provide the following operations:


- A default constructor that initializes a date object to **01-01-1900**.
- A class constructor that initializes a date object to a correct value using three integer
- The function **`toString()`** that returns the string version of a date object. For example,
applying **`toString()`** to the date **12-01-2000** produces **"December 1st, 2000"**.
- The function **nextDate()** that returns the successive date i.e. the new value of the
date object. For example, applying **`nextDate()`** to the date **12-31-2000** produces a
new date: **`01-01-2001`**. You should take into account if the year is a leap year or not.
A leap year is: (1) divisible by 400 or (2) divisible by 4 and not divisible by 100.
- The function **`compareDates()`** that checks if the date of interest is before, after or
equal to the argument date.