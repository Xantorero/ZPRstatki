

#include "Gameloop.h"
#include "Ship.h"
#include <iostream>
#include <boost/test/unit_test.hpp>
#include "Map.h"

int dodaj(int i, int j);

int main()
	{
		Gameloop gameloop;
		Map mapa;
		mapa.displayMap();
		gameloop.isRunning = true;
		gameloop.isPlayerTurn = true;
		gameloop.placeShip(mapa);
		mapa.displayMap();
		
		while(gameloop.isRunning)
		{
			gameloop.shoot(mapa);
			mapa.displayMap();
			gameloop.isRunning = false;
		}
	
	
		return 0;
	}



	void Gameloop::shoot(Map& map)
	{
		char guessX;
		int guessY;
		std::cin >> guessX >> guessY;

		for(Ship* ship : map.fleet)
		{
			for(unsigned int i = 0; i < ship->coordinates.size(); ++i)
			{
				if (ship->coordinates.at(i)->getX() == guessX && ship->coordinates.at(i)->getY() == guessY)
				{
					ship->setLenght(ship->getLenght() -1);
					map.changeHit(guessX, guessY);
					cout << "Trafiony";
					break;
				}else
				{
					map.changeMiss(guessX, guessY);
					cout << "Pudlo";
					break;
				}
			}
		}
	
	}

	void Gameloop::placeShip(Map& map)
	{
			std::cout << "Czteromasztowiec";
			Ship* four = new Ship(4);
			map.addShip(*four);
			map.changeMap(*four);
		//	std::cout << "Trzymasztowiec";
			//std::cout << "Dwumasztowiec";
			//std::cout << "Jednoomasztowiec";
	
	}


	int dodaj(int i, int j)
	{
		return i + j;
	}


	


