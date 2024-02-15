#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class shopping
{
private:
	int pcode;
	float price;
	float dis;
	string pname;





public:


	void menu();
	void administrator();
	void buyer();
	void add();
	void edit();
	void rem();
	void list();
	void receipt();

};

void shopping::menu() {
	m:
	int choice =0;
	string email = "";
	string password = "";
	cout << "\t\t\t\t\t_____________________________________\n";
	cout << "\t\t\t\t\t                                     \n";
	cout << "\t\t\t\t\t        Supormarkot Main Menu        \n";
	cout << "\t\t\t\t\t                                     \n";
	cout << "\t\t\t\t\t_____________________________________\n";
	cout << "\t\t\t\t\t                                     \n";
	cout << "\t\t\t\t\t   1) Administrator                  \n";
	cout << "\t\t\t\t\t                                     \n";
	cout << "\t\t\t\t\t                                     \n";
	cout << "\t\t\t\t\t   2) Buyer                          \n";
	cout << "\t\t\t\t\t                                     \n";
	cout << "\t\t\t\t\t                                     \n";
	cout << "\t\t\t\t\t   3) Exit                           \n";
	cout << "\t\t\t\t\t                                     \n";

	cout << "\t\t\t\t\t Please select!";
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "\t\t\t Please login \n";
		cout << "\t\t\t Enter Email \n";
		cin >> email;
		cout << "\t\t\t Password      \n";
		cin >> password;
		if (email == "body" && password == "123456") {
			administrator();
		}
		else {
			cout << "Invalid Email/password" << endl;
		}
		break;
	case 2: 
	{
		buyer();
	}

	case 3:
	{
		exit(0);

	}
	default: {
		cout << "Please select from the Given optioons!" << endl;
	}

	}
	goto m;
}

void shopping::administrator() {
	m:
	int choice = 0 ;
	cout << "\n\n\n\t\t\t Administrator menu";
	cout << "\n\t\t\t|______1) Add the product ________|";
	cout << "\n\t\t\t|                                 |";
	cout << "\n\t\t\t|______2) Modify the product _____|";
	cout << "\n\t\t\t|                                 |";
	cout << "\n\t\t\t|______3) Delet the product ______|";
	cout << "\n\t\t\t|                                 |";
	cout << "\n\t\t\t|______4) Back to main meru ______|";
	 

	cout << "\n\n\t Please enter your choice ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		add();
		break;


	case 2:
		edit();

	case 3:
		rem();
		break;
	case 4:
		menu();
		break;
	default:
		cout << "Invalid choice!" << endl;
	}
	goto m;
}

void shopping::buyer()
{m:
int choice =0;
cout << "\t\t\t  Buyer  \n";
cout << "\t\t\t_____________  \n";
cout << "                       ";
cout << "\t\t\t1) Buy product \n";
cout << "                       ";
cout << "\t\t\t2 Go back      \n";
cout << "\t\t\t Enteor your choice : ";
cin >> choice;
switch (choice)
{
case 1:
	receipt();
	break;

case 2:
	menu();
	break;
default :
	cout << "invalid choice";

}
goto m;
}

void shopping::add()
{
	m:
	fstream data;
	int c = 0;
	int token = 0;
	float p;
	float d;
	string n;
	cout << "\n\n\t\t\t Add new product";
	cout << " \n\n\t Product code of the product ";
	cin >> pcode;
	cout << " \n\n\t Name of thr Product ";
	cin >> pname;
	cout << " \n\n\t Price of the product ";
	cin >> price;
	cout << " \n\n\t Discount on product ";
	cin >> dis;
	data.open("database.txt", ios::in);
	if (!data) {
		data.open("database.txt", ios::app | ios::out);

		data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		data.close();
	}
	else {
		data >> c >> n >> p >> d;

		while (!data.eof()) {
			if (c == pcode)
			{
				token++;
			}
			data >> c >> n >> p >> d;
		}
		data.close();
	}
	if (token == 1)
		goto m;
	else {
		data.open("database.txt", ios::app | ios::out);

		data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		data.close();
	}
	cout << "\n\n\t\t Record inserted !";
}

void shopping::edit()
{
	fstream data, data1;
	int pkey = 0;
	int token = 0;
	int c = 0;
	float p = 0;
	float d = 0;
	string n;


	cout << "\n\t\t\t Modify the record ";
	cout << "\n\t\t\t Preoduct code : ";
	cin >> pkey;

	data.open("database.txt", ios::in);
	if (!data)
	{
		cout << "\n\nFile doesn't exist! ";
	}
	else
	{
		data1.open("database1.txt", ios::app | ios::out);
		data >> pcode >> pname >> price >> dis;
		while (data.eof()) {
			if (pkey == pcode)
			{
				cout << "\n\t\t Product new code :";
				cin >> c;
				cout << "\n\t\t Name of the product :";
				cin >> n;
				cout << "\n\t\t Price :";
				cin >> p;
				cout << "\n\n\t\t Discount : ";
				cin >> d;
				data1 << " " << c << "" << " " << p << " " << d << endl;
				cout << "\n\n\t\t Record edited ";
				token++;

			}
			else {
				data1 << " " << pcode << " " << pname << " " << price << " " << dis << endl;
			}
			data >> pcode >> pname >> price >> dis;

			data.close();
			data1.close();


			remove("database.txt");
			rename("database1.txt", "database.txt");

			if (token == 0)
			{
				cout << "\n\n Record not found sorry!";
			}
		}
	}
}

void shopping::rem() {
	fstream data, data1;
	int pkey = 0;
	int token = 0;
	cout << "\n\n\t Delete product";
	cout << "\n\n\t Product code  :";
	cin >> pkey;
	data.open("database.txt", ios::in);
	if (!data) {
		cout << "File doont exist";

	}
	else {
		data1.open("database1.txt", ios::app | ios::out);
		data >> pcode >> pname >> price >> dis;
		while (!data.eof()) {
			if (pcode == pkey) {
				cout << "\n\n\t Product deleted succesfully";
			}
			else {
				data << pcode << pname << price << dis <<endl;
			}
			data >> pcode >> pname >> price >> dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt", "database.txt");
		if (token == 0) {
			cout << "\n\nRecord not found";
		}
	}
}

void shopping::list() {
	fstream data;
	data.open("database.txt", ios::in);
		cout << "\n\n|________________________________________|\n";
		cout << "proNo\t\tName\t\tprice" << endl;
		cout << "\n\n|________________________________________|\n";
		data >> pcode >> pname >> price >> dis;
		while (!data.eof())
		{
			cout << pcode << "\t\t" << "\t\t" << price << endl;
			data >> pcode >> pname >> price >> dis;
		}
		data.close();

}

void shopping :: receipt(){
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c = 0;
	float amount = 0;
	float dis = 0;
	float total = 0;

	cout << "\n\n\t\t\t\t RECEIPT  ";
	data.open("database.txt", ios::in);
	if (!data) {
		cout << "\n\n Empty database ";

	}
	else {
		data.close();
		list();
		cout << "\n________________________________" << endl;
		cout << "                                  " << endl;
		cout << "        Please place the order    " << endl;
		cout << "                                  " << endl;
		cout << "\n________________________________" << endl;
		do
		{
		m:
			cout << "\n\nEnter Product code :";
			cin >> arrc[c];
			cout << "\n\nEnter the product quantity :";
			cin >> arrq[c];
			for (int i = 0; i < c; i++) {
				if (arrc[c] == arrc[i]) {
					cout << "\n\n Duplicate product code. please try again!";
					goto m;
				}
			}
			c++;
			cout << "\n\n Do you want to buy another product? if yes then press y else on";
			cin >> choice;

		} while (choice == 'y');

		cout << "\n\n\t\t\t_________________________________RECEIPT________________________";
		cout << "\nProduct NO\t Product Namer\t product quantity\tprice\tAmount\tAmount with discount\n";



		for (int i = 0; i < c; i++) {
			data.open("darabase.txt", ios::in);
			data >> pcode >> pname >> price >> dis;
			while (!data.eof()) {
				if (pcode == arrc[i]) {
					amount = price * arrq[i];
					dis = amount - (amount * dis / 100);
					total = total + dis;
					cout << "\n" << pcode << "\t\t" << pname << "\t\t" << price << "\t" << amount << "\t\t" << dis;

				}
				data >> pcode >> pname >> price >> dis;

			}

		}
		data.close();


	
	}
	cout << "\n\n___________________________________________________";
	cout << "\n Total Amount :" << total;
}