#include "../include/Func.hpp"

void gotoxy(int x, int y) 
{ 
    COORD coord;
    coord.X = x; 
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void showOrderList(Drug *dr[], int found)
{
	gotoxy(10,3);
	std::cout << "Name Of Drug";
	gotoxy(40,3);
	std::cout << "ID";
	gotoxy(50,3);
	std::cout << "Price";
	gotoxy(65,3);
	std::cout << "Number";
	gotoxy(80,3);
	std::cout << "Type";
	gotoxy(95,3);
	std::cout << "Expiration Date";
	
	gotoxy(10,5);
	std::cout << dr[found]->getDrug();
	gotoxy(40,5);
	std::cout << dr[found]->getId();
	gotoxy(50,5);
	std::cout << "Rs." << dr[found]->getPrice();
	gotoxy(65,5);
	std::cout << dr[found]->getNumber();
	gotoxy(80,5);
	std::cout << dr[found]->getType();
	gotoxy(95,5);
	dr[found]->showDate();
	
	std::cout << std::endl << std::endl;
}

void showProductList(Drug *dr[])
{
	if(Drug::counter!=0)
	{
		gotoxy(10,0);
		std::cout << "Medcine Name";
		gotoxy(10,0);
		gotoxy(40,0);
		std::cout << "ID";
		gotoxy(50,0);
		std::cout << "Price";
		gotoxy(65,0);
		std::cout << "Number";
		gotoxy(80,0);
		std::cout << "Type";
		gotoxy(95,0);
		std::cout << "Expiration Date";
		for(int i=0 ; i < Drug::counter ; i++)
		{
			gotoxy(10,i+2);
			std::cout << dr[i]->getDrug();
			gotoxy(40,i+2);
			std::cout << dr[i]->getId();
			gotoxy(50,i+2);
			std::cout << "Rs." << dr[i]->getPrice();
			gotoxy(65,i+2);
			std::cout << dr[i]->getNumber();
			gotoxy(80,i+2);
			std::cout << dr[i]->getType();
			gotoxy(95,i+2);
			dr[i]->showDate();
		}
	}
	else
	{
		std::cout << "No Entry Found";
	}
	std::cout << std::endl << std::endl;
	system("pause");
}

void save(Drug *dr[])
{
	ofstream myfile;
	myfile.open("pharm.txt", ios::out);
	
	for(int i=0 ; i<Drug::counter ; i++)
	{
		myfile << dr[i]->getDrug() << std::endl;
		myfile << dr[i]->getId() << std::endl;
		myfile << dr[i]->getNumber() << std::endl;
		myfile << dr[i]->getPrice() << std::endl;
		myfile << dr[i]->getType() << std::endl;
		myfile << dr[i]->getDay() << std::endl;
		myfile << dr[i]->getMonth() << std::endl;
		myfile << dr[i]->getYear() << std::endl;
	}
	myfile.close();
}

void readPharmacy(Drug *dr[])
{
	ifstream myfile;
	myfile.open("pharm.txt", ios::in);

	string name,type;
	int number,id,price;
	
	int day,month,year;
	
	int count = 0;
	if(!myfile.fail())
	{
		while(myfile>>name)
		{
			myfile>>id;
			myfile>>number;
			myfile>>price;
			myfile>>type;
			myfile>>day;
			myfile>>month;
			myfile>>year;
			count = Drug::counter;
			dr[count] = new Drug(name, type, number, id, price, day, month, year);
			count++;
		}
	}
	myfile.close();
}


int searchByID(int id, Drug *dr[])
{
	for(int i=0 ; i<Drug::counter ; i++)
	{
		if(id == dr[i]->getId())
		{
			return i;
		}
	}
	
	std::cout << "\nDrug With Given ID Was Not Found...." << std::endl << std::endl;
	Sleep(600);
	return -1;
}


int searchByName(string name, Drug *dr[])
{
	for(int i=0 ; i<Drug::counter ; i++)
	{
		string name1 = dr[i]->getDrug();
		if(name.compare(name1)==0)
		{
			return i;
		}
	}
	
	std::cout << "\nDrug With Given Name Was Not Found....." << std::endl << std::endl;
	Sleep(600);
	return -1;
}



void positive(int &input)
{
	if(input<0)
	{
		input *= -1;
	}
}

int castToInt(string x)
{
	stringstream ss;
	ss << x;
	int casted;
	ss >> casted;
	return casted;
}

bool checkInt(string x)
{
	if(x[0] == '-' || (x[0] >= 48 && x[0] <= 57))
	{
		for(int i=1 ; i < x.length() ; i++)
		{
			if((x[i] >= 48 && x[i] <= 57));
			else
			{
				std::cout << "Not Valid Input, Retry..." << std::endl;
				Sleep(600);
				return false;
			}
		}
	}
	
	else
	{
		std::cout << "Not Valid Input, Retry..." << std::endl;
		Sleep(600);
		return false;
	}
	return true;
}

void readNoskhe(Noskhe *no[])
{
	ifstream mf;
	mf.open("noskhebimar.txt", ios::in);

	string name;
	int id;
	
	int count = 0;
	if(!mf.fail())
	{
		while(mf>>name)
		{
			mf>>id;
			count = Noskhe::cnos;
			no[count] = new Noskhe(name, id);
			count++;
		}
	}
	mf.close();

}


void showNoskhe(Noskhe *no[])
{
	if(Noskhe::cnos!=0)
	{
		gotoxy(10,0);
		std::cout << "Medcine Name";
		gotoxy(40,0);
		std::cout << "ID";
		

		for(int i=0 ; i < Noskhe::cnos ; i++)
		{
			gotoxy(10,i+2);
			std::cout << no[i]->getDrug();
			gotoxy(40,i+2);
			std::cout << no[i]->getId();
			
		}
	}
	else
	{
		std::cout << "No Entry Found";
	}
	std::cout << std::endl << std::endl;
	system("pause");
}
