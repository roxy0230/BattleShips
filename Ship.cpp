#include "stdafx.h"
#include<iostream>
#include<cstring>
#include "Ship.h"
using namespace std;
Ship::Ship()
{
	this->direction = 0;
	this->lenght = 0;
	this->x= 0;
	this->y = 0;
}
Ship::Ship(bool direction, int lenght, int x,int y)
{
	this->direction = direction;
	this->lenght = lenght;
	this->x = x;
	this->y = y;
}
Ship::Ship(const Ship &s)
{
	this->direction = s.direction;
	this->lenght = s.lenght;
	this->x = s.x;
	this->y = y;

}

void Ship::setDirection(bool dr)
{
	this->direction = dr;;
}
void Ship::setLenght(int lg)
{
	this->lenght = lg;
}
void Ship::setX(int i)
{
	this->x = i;
}
void Ship::setY(int j)
{
	this->y = j;
}
Ship& Ship::operator=(const Ship&dc)
{
	if (this != &dc)
	{
		this->setDirection(dc.direction);
		this->setLenght(dc.lenght);
		this->setX(dc.x);
		this->setY(dc.y);
	}
	return *this;
}