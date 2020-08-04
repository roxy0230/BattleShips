#ifndef REPOSITORY_H_
#define REPOSITORY_H_

#include <iostream>
#include <vector>
#include "Board.h"
#include "Ship.h"
#include <cstring>
#include <cstdlib>
#include "Exceptions.h"
using namespace std;



class Repo
{
protected:
	Board BTA1;  // tabla de atac a robotului
	Board BTA2; // tabla  de atac a jucatorului
	Board MB1;   // tabla cu barcile robotului
	Board MB2;  // tabla cu barcile jucatorului
public:
	Board getBTA1()
	{
		return BTA1;
	}
	Board getBTA2()
	{
		return BTA2;
	}
	Board getMB1()
	{
		return MB1;
	}
	Board getMB2()
	{
		return MB2;
	}
	void setAllDim()
	{
		BTA1.setDim(10);
		BTA2.setDim(10);
		MB1.setDim(10);
		MB2.setDim(10);
	}
	void place(Board &MB)
	{
		int i;
		Ship sh;
		for (i = 1;i <= 4;i++)
		{
			cin >> sh;
			MB.placeShip(sh);
			//cout << MB << endl;
		}
	}
	void randomPlace(Board &MB)
	{
		int i, x, y,leng;
		bool dir;
		Ship sh;
		
		for (i = 1;i <= 4;i++)
		{
			int gasit = 0;
			while (gasit == 0)
			{
				x = rand() % 10 + 1;
				y = rand() % 10 + 1;
				leng = i;
				dir = rand() % 2;
				sh = Ship(dir, leng, x, y);
				if (MB.validCoordonation1(sh) == 1)
					gasit = 1;
				//cout << gasit << endl;
			}
			cout << sh << endl;
			MB.placeShip(sh);
			//cout << MB << endl;
		}
		
	}
	
	void attackPlayer(Board &MB1,Board &MB2)
	{
		int x, y;
		cin >> x >> y;
		cout << MB1.getDim() << endl;
		if (x > MB1.getDim() || y > MB1.getDim() || x < 1 || y < 1)
			throw MyException("Coordonate invalide");
		MB1.attack(x, y);
		if (MB2.ifLovit(x, y) == 1)
		{
			MB1.Lovit(x, y);
			MB2.Lovit(x, y);
			if (MB2.ifScufundat(x, y) == 1)
			{
				cout << "Ai scufundat o barca" << endl;
				MB1.copiere(x, y);
			}
		}
		cout << MB1 <<endl<<MB2<< endl;
	}
	void attackRandom(Board &MB1,Board &MB2)
	{
		int x, y;
		x = rand() % 10 + 1;
		y = rand() % 10 + 1;
		if (x > MB1.getDim() || y > MB1.getDim() || x < 1 || y < 1)
			throw MyException("Coordonate invalide");
		MB1.attack(x, y);
		if (MB2.ifLovit(x, y) == 1)
		{
			MB1.Lovit(x, y);
			MB2.Lovit(x, y);
			if (MB2.ifScufundat(x, y) == 1)
			{
				cout << "Adversarul a scufundat o barca" << endl;
				MB1.copiere(x, y);
			}
		}
		cout << MB1<<endl<<MB2 << endl;
	}
	void printMB(Board MB)
	{
		cout << MB << endl;
	}
	


};

#endif /* REPO_H_ */