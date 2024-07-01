# include <iostream>
# include "enemy.h"

using namespace std;


void enemy::AstarAlgorithm(int playerX, int playerY, int enemyX, int enemyY)
{

	float eucledianDistance = sqrt(static_cast<float>(pow(enemyY - playerY, 2)) + static_cast<float>(pow(enemyX - playerX, 2)));
	//cout << playerX << "-" << playerY << " " << enemyX << "-" << enemyY << endl;
	//cout << eucledianDistance;
}