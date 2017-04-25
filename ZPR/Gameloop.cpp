#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hello

#include "Gameloop.h"
#include "Ship.h"
#include <iostream>
#include "Map.h"
#include <boost/test/included/unit_test.hpp>


int dodaj(int i, int j)
{
	return i + j;
}


BOOST_AUTO_TEST_CASE(testGameloop)
{
	Gameloop gameloop;
	BOOST_CHECK(gameloop.isRunning == true);
}

BOOST_AUTO_TEST_CASE(testShip)
{
	Ship ship(4);
	BOOST_CHECK(ship.getLenght() == 4);
}

BOOST_AUTO_TEST_CASE(testMap){
	Map mapa;
	BOOST_CHECK(mapa.displayMap() == 0);
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

	
	}




	


