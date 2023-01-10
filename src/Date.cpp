#include "../include/Date.hpp"

using namespace std;

Date::Date(){}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

int Date::getDay()
{
    return day;
}
int Date::getMonth()
{
    return month;
}
int Date::getYear()
{
    return year;
}

void Date::showDate()
{
	cout << day << "/" << month << "/" << year;
}

