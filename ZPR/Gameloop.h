#ifndef GAMELOOP_H
#define GAMELOOP_H
#include "Map.h"

class Gameloop
{
private:
	
public:
	bool isRunning = true;
	bool isPlayerTurn = true;
	void placeShip(Map& map);
	void shoot(Map& map);


};



#endif