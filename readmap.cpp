# include <iostream>
# include <fstream>
# include <string>
# include <vector>
# include <random>
# include <time.h>
# include "readmap.h"
# include <windows.h>
# include <conio.h>


using namespace std;

int XMax {1};
int YMax {1};

int playerX {0};
int playerY {0};

int newPlayerX {0};
int newPlayerY {0};

int enemyX {0};
int enemyY {0};


void Map::readMap(const string &filename,int mapX,int mapY) 
{
	ifstream file(filename);
	string content;
	int X = 0;
	int Y = 0;
	drawMap.resize(mapY, vector<char>(mapX));
	if (file.is_open())
	{
		while (getline(file, content))
		{
			for (auto cont : content)
			{
				drawMap[Y][X] = cont;
				cout << drawMap[Y][X];
				if (X >= XMax) {
					XMax = X;
				}
				X++;
				cout << " ";
			}
			cout << endl;
			Y++;
			if (Y >= YMax) {
				YMax = Y;
			}
			X = 0;
		}
	}
	else 
	{
		cout << "The file cannot be found...\n";
	}
}


void Map::drawPacmanMap() 
{
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	drawMap[playerY][playerX] = ' ';
	drawMap[newPlayerY][newPlayerX] = 'X';
	
	for (int j = 0; j <= YMax; j++)
	{
		for (int i = 0; i <= XMax; i++)
		{
			cout <<drawMap[j][i]<<" ";
		}
		cout << endl;
	}
	
}


void Map::drawPlayer_drawEnemy()
{
	srand(time(0));              // seeds random number generator at current time
	playerX = rand() % XMax;
	playerY = rand() % YMax;
	newPlayerX = playerX;        // initialization     
	newPlayerY = playerY;

	enemyX = rand() % XMax;
	enemyY = rand() % YMax;

	while (drawMap[playerY][playerX] == '*' || (playerX == enemyX && playerY == enemyY))
	{
		playerX = rand() % XMax;
		playerY = rand() % YMax;

		newPlayerX = playerX;     // initialization        
		newPlayerY = playerY;
	}

	while (drawMap[enemyY][enemyX] == '*') 
	{
		enemyX = rand() % XMax;
		enemyY = rand() % YMax;
	}

	drawMap[playerY][playerX] = 'X';
	drawMap[enemyY][enemyX] = 'O';
}
	

void Map::updatePlayer(int playerInput) 
{
	playerX = newPlayerX;
	playerY = newPlayerY;
	
	switch (playerInput)
	{

	case 1:
		newPlayerX -= 1;
		if (drawMap[newPlayerY][newPlayerX] == '*')
		{
			newPlayerX += 1;
		}
		break;

	case 2:
		newPlayerY -= 1;
		if (drawMap[newPlayerY][newPlayerX] == '*')
		{
			newPlayerY += 1;
		}
		break;

	case 3:
		newPlayerX += 1;
		if (drawMap[newPlayerY][newPlayerX] == '*')
		{
			newPlayerX -= 1;
		}
		break;

	case 4:
		newPlayerY += 1;
		if (drawMap[newPlayerY][newPlayerX] == '*')
		{
			newPlayerY -= 1;
		}
		break;
	}

	// Prevent the player go beyond the borderline
	if (newPlayerX < 0) 
	{
		newPlayerX = 0;
	}

	if (newPlayerX > XMax) 
	{
		newPlayerX = XMax;
	}

	if (newPlayerY < 0) 
	{
		newPlayerY = 0;
	}

	if (newPlayerY > (YMax-1))
	{
		newPlayerY = YMax-1;
	}

	//prevent the player hit the tiles
	if (drawMap[newPlayerY][newPlayerX] == '*')
	{
		drawMap[newPlayerY][newPlayerX] = '*';
		drawMap[playerY][playerX] = 'X';
	}

}


struct Coordinates
{
	int newPlayerX;
	int newPlayerY;
	int enemyX;
	int enemyY;
};

Map::Coordinates Map::returnCoordination() 
{
	Coordinates coords;
	coords.enemyX = enemyX;
	coords.enemyY = enemyY;
	coords.newPlayerX = newPlayerX;
	coords.newPlayerY = newPlayerY;

	return coords;
}


struct search 
{
public:
	int x;
	int y;
	int id;         // set ID for each node 
	search* parent;
	float C;        // cumlatitive distance from the start node to the current node
	float H;        // Heuristic distance (estimated distance to the goal)

    search() :parent(0) {}
	search(int X, int Y, search* _parent = 0) :x(X), y(Y), parent(_parent), id(X * 20 + X), C(0), H(0) {}

};


void Map::pathPlanning()
{
	

	
	


}