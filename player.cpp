# include <iostream>
# include "player.h"
# include <conio.h>    // console input and output

using namespace std;

int player::input() 
{
	int playerKey{0};

	if (_getch() == 224) {
		int ch = _getch();
		switch (ch) {

		case 72:  //UP
			playerKey = 2;
			break;

		case 80: //DOWN
			playerKey = 4;
			break;

		case 77: //RIGHT
			playerKey = 3;
			break;

		case 75: //LEFT
			playerKey = 1;
			break;
		}
	}
	return playerKey;
}



