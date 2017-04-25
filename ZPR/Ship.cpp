
#include "Ship.h"
#include <iostream>
using namespace::std;

Ship::Ship()
{

	for (int i = 0; i < lenght; i++)
	{
		cout << "Podaj wspó³rzêdne" << endl;
		cin >> x >> y;
		coordinates.push_back( new Point(x, y));
	}
}

Ship::Ship(int lenght2)
{
	this->lenght = lenght2;

	
}


int Ship::getLenght()
{
	return lenght;
}

void Ship::setLenght(int lenght)
{
	this->lenght = lenght;
}

