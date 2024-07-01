#pragma once
# include <iostream>
# include <fstream>
# include <vector>

using namespace std;

class Map {

public:

	void readMap(const string &filename,int mapX,int mapY);
	void drawPacmanMap();
	void drawPlayer_drawEnemy();
	void updatePlayer(int playerInput);

	struct Coordinates
	{
		int newPlayerX;
		int newPlayerY;
		int enemyX;
		int enemyY;
	};

    Coordinates returnCoordination();

	void pathPlanning();
	
private:
	string filename;
	int mapX;
	int mapY;
	vector<vector<char>> drawMap;
};