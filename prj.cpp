#include <iostream>
#include "./src/Date.cpp"
#include "./src/Drug.cpp"
#include "./src/Noskhe.cpp"
#include "./src/Func.cpp"
#include "./src/Order.cpp"


using namespace std;

int main()
{

		Drug *stock[200];
		Noskhe *noskh[100];
		string s1;
		readPharmacy(stock);
		readNoskhe(noskh);


		do{
		system("cls");
		cout << "Welcome To The Pharamacy Management System\n********************************************\n" ;
		cout << "1. Product List" << endl;
		cout << "2. Order Guide" << endl;
		cout << "0. Exit" << endl;
		cin >> s1;

		if(s1 == "1")
		{
			system("cls");
			showProductList(stock);
		}
		
		else if(s1 == "2")
		{
			string s2;
			Drug *order[200];
			Order odr;
			do
			{
				system("cls");
				cout << "\t ****Order Guide****\n******************************************"<<endl;
				cout << "1. Reading The Order From The Prescription" << endl;
				cout << "2. Add Order" << endl;
				cout << "0. Back to Main Menu" << endl;
				gotoxy(2,5);
				cin >> s2;

				if (s2 == "1")
				{
					system("cls");
					showNoskhe(noskh);
						
				}

				if(s2 == "2")
				{
					odr.takeOrder(stock,order);

				}

				else if(s2 == "0"){}
						
				else
				{
					cout << "\nWrong Input, Back to Order Menu...";
					Sleep(600);
				}	
			}while(s2 != "0");

		}
		
		else if(s1 == "0")
		{
			char ch;
			cout << "\nDo You Save The Changes In The File? (Y.yes/N.no): ";
			cin.ignore();
			cin >> ch;
			if(ch == 'Y' || ch == 'y')
			{
				save(stock);
			}
		}
		
		else
		{
			cout << "Wrong Input, Please Try Again";
			Sleep(600);
		}
	}while(s1 != "0");

	return 0;
}
