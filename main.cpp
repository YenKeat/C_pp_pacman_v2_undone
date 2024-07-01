# include <iostream>
# include <vector>
# include "player.h"
# include "readmap.h"
# include "enemy.h"

const int rows{ 20 };
const int columns{ 20 };

int X_coord;
int Y_coord;

using namespace std;

// intialize the variables
bool Quit{ false };
bool gameOver{ false };


int main()
{
	system("cls");
	Map map1;
	map1.readMap("map1.txt", columns, rows);
	map1.drawPlayer_drawEnemy();

	while (gameOver != true)
	{
		map1.drawPacmanMap();
		Map::Coordinates coords = map1.returnCoordination();
		map1.pathPlanning();
        // call enemy class
		enemy e;
		


		//call player class
		player p;
		map1.updatePlayer(p.input());
	    
	}
	return 0;

}

