#pragma once
#ifndef BOAT_H
#define BOAT_H
#include ".h"
#include <iostream>
using namespace std;

class Boat1 {
public:
	virtual float area() {
		cout << "[Figure] : area " << endl;
		return 0.0;
	}
	virtual float perimeter() {
		cout << "[Figure] : perimeter " << endl;
		return 0.0;
	}
};
#endif
