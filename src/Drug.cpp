#include "../include/Drug.hpp"


int Drug::counter = 0;

int Drug::getDay()
{
    d.getDay();
}
int Drug::getMonth()
{
	d.getMonth();	
}
int Drug::getYear()
{	
    d.getYear();	
}
void Drug::showDate()
{
	d.showDate(); 
}

Drug::Drug()
{
	drug="NULL";
	type="NULL";
	number=0;
	id=0;
	price=0;
}

Drug::Drug(string name,string type, int number, int id, int price, int day, int month, int year)
{
	this->drug = name;
	this->type = type;
	this->number = number;
	this->id = id;
	this->price = price;
	d = Date(day,month,year);
	Drug::counter++;
}

void Drug::setNumber(int q)
{
	this->number = q;
}

void Drug::setPrice(int p)
{
	this->price = p;
}

string Drug::getDrug()
{
	return drug;
}

string Drug::getType()
{
	return type;
}

int Drug::getNumber()
{
	return number;
}

int Drug::getId()
{
	return id;
}

int Drug::getPrice()
{
	return price;
}



