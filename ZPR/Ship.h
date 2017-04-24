#ifndef SHIP_H
#define  SHIP_H
#include <vector>


class Ship
{
public:
	Ship(int lenght);

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
			this->stateShip = ship;
		}
		char x;
		int y;
		state stateShip;

		char getX()
		{
			return x;
		}

		int getY()
		{
			return y;
		}
	};
		
	void detectHit();
	int getLenght();
	void setLenght(int leanght);
	state getState();
	std::vector<Point*> coordinates;
private:
	char x;
	int y;
	int lenght;


};

#endif