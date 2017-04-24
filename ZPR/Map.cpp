
#include "Map.h"
#include "Ship.h"
#include <iostream>
using namespace::std;

Map::Map()
{
	createMap();
}

void Map::createMap()
{
	for(const char& a : alphabet)
	{
		for (int i = 1; i <= 10; ++i)
		{
			map.push_back(new Point(a, i));
		}
	}

}

void Map::displayMap()
{
	int counter = 0;
	for (Point* point : map)
	{
	
		if(point->stateField == unknown)
		{
			cout << "X ";
			++counter;
		}
		if (point->stateField == ship)
		{
			cout << "O ";
			++counter;
		}
		if (point->stateField == hit)
		{
			cout << "T ";
			++counter;
		}
		if (point->stateField == miss)
		{
			cout << "P ";
			++counter;
		}
		if(counter == 10)
		{
			cout << endl;
			counter = 0;
		}
	}

}


void Map::changeMap(Ship& shipek)
{
	for (unsigned int i = 0; i < shipek.coordinates.size(); ++i) {

		for (Point* point : map)
		{
			if (point->getX() == shipek.coordinates.at(i)->getX() && point->getY() == shipek.coordinates.at(i)->getY())
			{
				point->stateField = ship;
			}
		}
	}
}

void Map::changeHit(char x, int y)
{

		for (Point* point : map)
		{
			if (point->getX() == x && point->getY() == y)
			{
				point->stateField = hit;
			}
		}
}

void Map::changeMiss(char x, int y)
{

	for (Point* point : map)
	{
		if (point->getX() == x && point->getY() == y)
		{
			point->stateField = miss;
		}
	}
}


void Map::addShip(Ship& ship)
{
	fleet.push_back(&ship);

}

