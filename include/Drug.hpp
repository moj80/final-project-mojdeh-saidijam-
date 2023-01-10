#ifndef DRUG_H
#define DRUG_H
#include <iostream>
class Drug
{
	protected:
		string drug;
		string type;
		int number;
		int id;
		int price;
		Date d;		
	public:
		Drug();//constructor
		Drug(string drug, string type, int number, int id, int price, int day, int month, int year);//constructor
		void setNumber(int);//set number
		void setPrice(int);//set price of drug
		string getDrug();//set name of drug
		string getType();//set type of drug
		int getNumber();//get number
		int getId();//get id
		int getPrice();//get price
		//class Date
		int getDay();
		int getMonth();
		int getYear();
		void showDate();
		//static member
		static int counter;
};
#endif 
