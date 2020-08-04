#ifndef BOARD_H_
#define BOARD_H_
#include<iostream>
#include "Ship.h"
using namespace std;

class Board
{
private:
	int bd[100][100];
	int dim;

public:
	Board();
	Board(int bd[100][100],int dim);
	Board(const Board&bo);
	int getDim()
	{
		return this->dim;
	}
	int getBd()
	{
		return this->bd[getDim()][getDim()];
	}
	void setDim(int dim);
	void setBd(int bd[100][100]);
	Board& operator=(const Board&dc);
	bool validCoordonation1(Ship &sh);
	void placeShip(Ship &sh);
	void attack(int x, int y);
	bool ifLovit(int x, int y);
	void Lovit(int x, int y);
	bool ifScufundat(int x, int y);
	void copiere(int x, int y);
	bool ifCastig();


	friend ostream& operator<<(ostream &os, Board &f)
	{
		for (int i = 1;i <= f.dim;i++)
		{
			for (int j = 1;j <= f.dim;j++)
				os << f.bd[i][j]<<" ";
			os << endl;
		}
		return os;
	}
};

#endif 
