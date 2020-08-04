#include "stdafx.h"
#include<iostream>
#include<cstring>
#include "Board.h"
#include "Ship.h"
using namespace std;

Board::Board()
{
	this->dim = 0;
	for (int i = 1;i <= 100;i++)
		for (int j = 1;j <= 100;j++)
			this->bd[i][j] = 0;
	
}
Board::Board(int bd[100][100],int dim)
{
	this->dim = dim;
	for (int i = 1;i <= this->dim;i++)
		for (int j = 1;j <= this->dim;j++)
			this->bd[i][j] = bd[i][j];
}
Board::Board(const Board &bo)
{
	this->dim = bo.dim;
	for (int i = 1;i <= this->dim;i++)
		for (int j = 1;j <= this->dim;j++)
			this->bd[i][j] = bo.bd[i][j];
}

void Board::setDim(int dim)
{
	this->dim = dim;
}
void Board::setBd( int bd[100][100])
{
	for (int i = 1;i <= this->dim;i++)
		for (int j = 1;j <= this->dim;j++)
			this->bd[i][j] = bd[i][j];
}
Board& Board::operator=(const Board &rhs) 
{
	if (this != &rhs)
	{
		for (int i = 1; i <=this->dim ; i++) 
			for (int k = 1; k <= this->dim; k++)
			{
				this->bd[i][k]= rhs.bd[i][k];
			}
	}
	return *this;
}
bool Board::validCoordonation1(Ship &sh)
{
	int x, y, l, i;
	bool d;
	x = sh.getX();
	y = sh.getY();
	d = sh.getDirection();
	l = sh.getLenght();;
	if (d == 0)
	{
		if ( y + l - 1 > this->dim)
			return 0;
		else
		{
			for (i = y;i < y + l;i++)
				if (this->bd[x][i] == 1)
					return 0;
			return 1;
		}
	}
	if (d == 1)
	{
		if (x + l -1> this->dim)
			return 0;
		else
		{
			for (i = x;i < x + l;i++)
				if (this->bd[i][y] == 1)
					return 0;
			return 1;
		}
	}
}
virtual void Board::placeShip(Ship &sh)
{
	int x, y, l, i, j;
	bool d;
	y = sh.getY();
	x = sh.getX();
	d = sh.getDirection();
	l = sh.getLenght();
	//cout << sh << endl;
	if (d == 0)
	{
		for (i = y;i < y + l;i++)
			this->bd[x][i] = 1;
	}
	if (d == 1)
	{
		for (j = x;j < x + l;j++)
			this->bd[j][y] = 1;
	}
}
void Board::attack(int x, int y)
{
	this->bd[x][y] = 3;
}
bool Board::ifLovit(int x, int y)
{
	if (this->bd[x][y] == 1)
		return 1;
	else
		return 0;
}
void Board::Lovit(int x,int y)
{
	this->bd[x][y] = 4;
}
bool Board::ifScufundat(int x, int y)
{
	bool d;
	int i;
	if (this->bd[x + 1][y] == 0 && this->bd[x - 1][y] == 0 && this->bd[x][y + 1] == 0 && this->bd[x][y - 1] == 0)
	{
		this->bd[x][y] = 5;
		return 1;
	}
	else
	{
		
		
		if (this->bd[x + 1][y] != 0 || this->bd[x - 1][y] != 0)
		{
			d = 1;
			i = x;

			while (this->bd[i][y] != 0)
			{
				//cout << i << y << endl;
				if (this->bd[i][y] == 1)
					return 0;
				i++;
			}
			i = x;
			while (this->bd[i][y] != 0)
			{
				if (this->bd[i][y] == 1)
					return 0;
				i--;
			}

		}
		else
		{
			d = 0;
			i = y;
			//cout << this->bd[9][11] << endl;
			while (this->bd[x][i] != 0)
			{
				//cout << x << " una " << i << endl;
				if (this->bd[x][i] == 1)
					return 0;
				i++;
			}
			i = y;
			while (this->bd[x][i] != 0)
			{
				//cout << x << " doua " << i << endl;
				if (this->bd[x][i] == 1)
					return 0;
				i--;
			}
		}

		

		if (this->bd[x + 1][y] != 0 || this->bd[x - 1][y] != 0)
		{
			i = x;
			while (this->bd[i][y] != 0)
			{
				if (this->bd[i][y] == 4)
					this->bd[i][y]=5;
				i++;
			}
			i = x;
			while (this->bd[i][y] != 0)
			{
				if (this->bd[i][y] == 4)
					this->bd[i][y]=5;
				i--;
			}

		}
		else
		{
			i = y;
			while (this->bd[x][i] != 0)
			{
				if (this->bd[x][i] == 4)
					this->bd[x][i]=5;
				i++;
			}
			i = y;
			while (this->bd[x][i] != 0)
			{
				if (this->bd[x][i] == 4)
					this->bd[x][i]=5;
				i--;
			}
		}
		return 1;
	}
	return 0;
}
void Board::copiere(int x, int y)
{
	
	int i, j;
	if (this->bd[x + 1][y] == 0 && this->bd[x - 1][y] == 0 && this->bd[x][y + 1] == 0 && this->bd[x][y - 1] == 0)
		this->bd[x][y] = 5;
	else
	{
		
		if (this->bd[x + 1][y] != 0 || this->bd[x - 1][y] != 0)
		{
			i = x;
			while (this->bd[i][y] != 0)
			{
				if (this->bd[i][y] == 4)
					this->bd[i][y] = 5;
				i++;
			}
			i = x;
			while (this->bd[i][y] != 0)
			{
				if (this->bd[i][y] == 4)
					this->bd[i][y] = 5;
				i--;
			}

		}
		else
		{
			i = y;
			while (this->bd[x][i] != 0)
			{
				if (this->bd[x][i] == 4)
					this->bd[x][i] = 5;
				i++;
			}
			i = y;
			while (this->bd[x][i] != 0)
			{
				if (this->bd[x][i] == 4)
					this->bd[x][i] = 5;
				i--;
			}
		}


	}
}
bool Board::ifCastig()
{
	
	for (int i = 1;i <= this->dim;i++)
		for (int j = 1;j <= this->dim;j++)
			if (this->bd[i][j] != 0)
				if (this->bd[i][j] != 5)
					return 0;
	
        return 1;
}