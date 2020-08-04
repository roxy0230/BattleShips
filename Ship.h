#ifndef SHIP_H_
#define SHIP_H_
#include<iostream>
using namespace std;

class Ship
{
private:
	bool direction;
	int lenght;
	int x, y;


public:
	Ship();
	Ship(bool direction,int lenght,int x,int y);
	Ship(const Ship&sh);
	bool getDirection()
	{
		return this->direction;
	}
	int getLenght()
	{
		return this->lenght;
	}
	int getX()
	{
		return this->x;
	}
	int getY()
	{
		return this->y;
	}
	void setDirection(bool dr);
	void setLenght(int lg);
	void setX(int i);
	void setY(int j);
	Ship& operator=(const Ship&dc);
	friend istream& operator>>(istream &is, Ship &f)
	{
		bool dr;
		cout << "Direction:  ";
		is >> dr;
		f.setDirection(dr);
		int lg;
		cout << "Lenght: ";
		is >> lg;
		f.setLenght(lg);
		int i, j;
		cout << "Coordonatele barcii: " << endl;
		cout << "Linia: ";
		is >> i;
		f.setX(i);
		cout << "Coloana: ";
		is >> j;
		f.setY(j);

		return is;
	}
	friend ostream& operator<<(ostream &os, Ship &f)
	{
		os << "Direction " << f.direction << "     Lenght " << f.lenght << "      X   " << f.x <<"      Y  "<<f.y<< endl;
		return os;
	}
	bool operator==(Ship &f)
	{
		return ( (this->direction == f.direction) && (this->lenght == f.lenght)&&(this->x==f.x)&&(this->y==f.y));
	}
};

#endif 
