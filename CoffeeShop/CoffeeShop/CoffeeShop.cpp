/*
Number Guessing Game
Alex Starr
2 / 14 / 19
Chapter: 6
*/

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void SellCof(int smcup, int mdcup, int lgcup, int SmOz, int MdOz, int LgOz, double SmCof,
	double MdCof, double LgCof, int& CupCount, int& TotOun, double& Sales);
void TotalCup(int& s, int& m, int& l, int& CupCount);
void TotalOz(int& s, int& m, int& l, int SmOz, int MdOz, int LgOz, int& TotOun);
void TotalSale(double& Sales);
void Help();

int main()
{
	cout << fixed << showpoint << setprecision(2);
	const int SmOz = 9;
	const int MdOz = 12;
	const int LgOz = 15;
	const double SmCof = 1.75;
	const double MdCof = 1.90;
	const double LgCof = 2.00;
	int choice = 0;
	int s, m, l;
	int CupCount = 0;
	int TotOun;
	double Sales = 0.00;

	while (choice != 6)
	{
		cout << "Welcome to Jason's Coffee Shop!" << endl;
		cout << "Choose from the following Menu options:" << endl;
		cout << "1. Sell Coffee" << endl;
		cout << "2. Total Cups Sold" << endl;
		cout << "3. Total Ounces Sold" << endl;
		cout << "4. Total Sales" << endl;
		cout << "5. Help" << endl;
		cout << "6. Exit" << endl;
		cin >> choice;
		cout << endl;

		switch (choice)
		{
			case 1:
				cout << "Please enter coffee orders starting with Small cups:" << endl;
				cout << "(Enter 0 if no Small or Medium Cups ordered)" << endl;
				cout << "Sm: ";
				cin >> s;
				cout << "Md: ";
				cin >> m;
				cout << "Lg: ";
				cin >> l;
				SellCof(s, m, l, SmOz, MdOz, LgOz, SmCof, MdCof, LgCof, CupCount, TotOun, Sales);
				break;
			case 2:
				TotalCup(s, m, l, CupCount);
				break;
			case 3:
				TotalOz(s, m, l, SmOz, MdOz, LgOz, TotOun);
				break;
			case 4:
				TotalSale(Sales);
				break;
			case 5:
				Help();
				break;
			case 6:
				break;
			default:
				cout << "Invalid input, please try again." << endl;
		}	
	}

	cout << "Thank you, have a nice day.";
	
	return 0;
}

void SellCof(int smcup, int mdcup, int lgcup, int SmOz, int MdOz, int LgOz, double SmCof,
	double MdCof, double LgCof, int& CupCount, int& TotOun, double& Sales)
{
	cout << fixed << showpoint << setprecision(2);
	double SmSale, MdSale, LgSale, CTotal;
	
	SmSale = smcup * SmCof;
	MdSale = mdcup * MdCof;
	LgSale = lgcup * LgCof;
	CTotal = SmSale + MdSale + LgSale;
	
	cout << endl;
	cout << "Your total is " << CTotal << endl;
	cout << endl;

	Sales += CTotal;
}
void TotalCup(int& s, int& m, int& l, int& CupCount)
{
	
	CupCount = s + m + l;

	cout << endl;
	cout << "Total cups sold: " << CupCount << endl;
	cout << endl;
}
void TotalOz(int& s, int& m, int& l, int SmOz, int MdOz, int LgOz, int& TotOun)
{
	int ounS, ounM, ounL;
	
	ounS = s * SmOz;
	ounM = m * MdOz;
	ounL = l * LgOz;

	TotOun = ounS + ounM + ounL;
	
	cout << endl;
	cout << "Total Ounces sold: " << TotOun << endl;
	cout << endl;
}
void TotalSale(double& Sales)
{
	cout << fixed << showpoint << setprecision(2);
	cout << endl;
	cout << "Total Sales today: " << Sales << endl;
	cout << endl;
}
void Help()
{
	cout << "-This program is set to aid in coffee sales." << endl;
	cout << "-Do not choose any option but Sell Coffee until after " << endl;
	cout << "  it has been through one transaction." << endl;
	cout << "-Sell Coffee is for point of sale for coffee, " << endl;
	cout << "  with only number of cups ordered needed to be input." << endl;
	cout << "  The input needs to be in order of size, Small to Large." << endl;
	cout << "  If no cups ordered for that size, enter 0." << endl;
	cout << "-Total Cups Sold will display total cups sold overall" << endl;
	cout << "  for gauging sales trends." << endl;
	cout << "-Total Ounces Sold will display how many ounces sold" << endl;
	cout << "  overall for inventory management." << endl;
	cout << "-Total Sales will display total sales overall this shift." << endl;
	cout << "-Please speak to supervisor for other questions or help." << endl;
	cout << endl;
}
