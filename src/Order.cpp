#include "../include/Order.hpp"

int Order::order = 0;

void Order::takeOrder(Drug *dr[], Drug *order[])
{
	string sel;
	system("cls");
	cout << "1. Search by ID: " << endl;
	cout << "2. Search by Drug Name: " << endl;
	cout << "0. Back To Order Menu" << endl;
	cin >> sel;
				
	if(sel == "1" || sel == "2")
	{
		int found = -1;
		if(sel == "1")
		{
			system("cls");
			int id;
			cout << "\nEnter ID That You Want To Search: ";
			cin >> id;
			found = searchByID(id,dr);
		}
						
		else if(sel == "2")
		{
			system("cls");
			string name;
			cout << "\nEnter Drug Name That You Want To Search: ";
			cin.ignore();
			getline(cin,name);
			found = searchByName(name,dr);
		}
		
		
		if(found != -1)
		{
			int forder = check(dr[found]->getId(),order);
			
			if(forder == -1)
			{
				cout << endl;
				showOrderList(dr,found);
				int flag=0;
				do{
					string temp;
					do{
						cout << "Enter Number: ";
						cin >> temp;
					}while(!checkInt(temp));
					int number = castToInt(temp);

					positive(number);
					if(number != 0)
					{
						if(number <= dr[found]->getNumber())
						{
							dedicate(dr[found],order);
							order[Order::order-1]->setNumber(number);
							flag = 1;

							for(int i=0 ; i<Order::order ; i++)
							{
								int found,id;
								id = order[i]->getId();
								found = searchByID(id,dr);
								dr[found]->setNumber(dr[found]->getNumber()-order[i]->getNumber());
								order[i] == NULL;
								delete order[i];
							}
							Order::order = 0;
						}
							
						else
						{
							cout << "Not Enough Number, Retry.." << endl;
							Sleep(400);
						}
					}
					
					else
					{
						flag = 1;
					}
				}while(flag==0);
			}
		}
	}	

	else if(sel == "0"){}
						
	else
	{
		cout << "\nWrong Input, Back to Order Menu...";
		Sleep(600);
	}
}

void dedicate(Drug *dr, Drug *order[])
{
	string name = dr->getDrug();
	int number = dr->getNumber();
	int id = dr->getId();
	int price = dr->getPrice();
	int d = dr->getDay();
	int m = dr->getMonth();
	int y = dr->getYear();
	
	string type = dr->getType();
	
	int count = Order::order;
	order[count] = new Drug (name, type, number, id, price, d, m, y);

	Order::order++;
	Drug::counter--;
}


int check(int id, Drug *order[])
{
	for(int i=0 ; i<Order::order ; i++)
	{
		if(id == order[i]->getId())
		{
			return i;
		}
	}
	return -1;
}

