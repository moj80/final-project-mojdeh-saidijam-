#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date
{
	private://data member
		int day;
		int month;
		int year;
		
	public:
		Date();//constructor
		Date(int day, int month, int year);//constructor
		
		int getDay();//get day
		int getMonth();//get month
		int getYear();//get year
		void showDate();//show date
};

#endif 
