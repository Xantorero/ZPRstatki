#ifndef MAP_H
#define  MAP_H
#include <vector>
#include "Ship.h"
using namespace::std;

class Map
{


public:
	Map();
		enum state
		{
			miss,
			hit,
			unknown,
			ship
		};

		struct Point {
			Point(char x, int y)
			{
				this->x = x;
				this->y = y;
				this->stateField = unknown;
			}
			~Point()
			{
				
				//delete Point;
			}
			char x;
			int y;
			state stateField;

			char getX()
			{
				return x;
			}

			int getY()
			{
				return y;
			}
		};

		void createMap();
		int displayMap();
		void changeMap(Ship& ship);
		void changeHit(char x, int y);
		void changeMiss(char x, int y);
		void addShip(Ship& ship);
		vector<Ship*> fleet;

private:
	vector<Point*> map;
	vector<char> alphabet = { 'A','B','C','D','E','F','G','H','I','J' };
	
};



#endif
