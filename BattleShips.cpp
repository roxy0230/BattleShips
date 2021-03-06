// BattleShips.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Board.h"
#include "Ship.h"
#include "4Boards.h"
#include "Exceptions.h"
using namespace std;
int tb[100][100];
int main()
{
	int op;
	cout << "Apasa 1 pt start" << endl;
	cin >> op;
	while (op == 1)
	{
		Repo re;
		re.setAllDim();
		Board M1 = re.getBTA1();
		Board M2 = re.getBTA2();
		Board M3 = re.getMB1();
		Board M4 = re.getMB2();
		cout << "Poti alege 4 barcute de dimensiune 1,2,3,4:"<<endl;
		re.place(M4);
		cout << "Calculatorul va genera cele 4 barcute ale adversarului" << endl;
		re.randomPlace(M3);
		re.printMB(M3);
		int g = 0;
		while (g==0)
		{
			cout << "Alegeti coordonatele pozitiei pe care vreti sa o atacati" << endl;
			try
			{
				re.attackPlayer(M1, M3);
			}
			catch (MyException& exc) {
				cout << exc.getMessage();
			}
			if (M3.ifCastig() == 1)
			{
				g = 1;
				cout << "Ai castigat!" << endl;
			}
			else
			{
				cout << "Acum va ataca adversarul" << endl;
				try
				{
					re.attackRandom(M2, M4);
				}
				catch (MyException& exc) {
					cout << exc.getMessage();
				}
				
				if (M4.ifCastig() == 1)
				{
					g = 1;
					cout << "Ai pierdut" << endl;
				}
			}

		}
		
		cout << "Pentru a juca din nou apasa 1. Daca nu apasa alt numar" << endl;
		cin >> op;
	}

    return 0;
}

