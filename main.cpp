#include "gameManager.h"
#include <iostream>


int main(int argc, char** argv) {
	board Board;
	string name;
	int win, match;

	cout << "###***  WELCOME TO TICTACTOE GAME BY C++  ***###" << endl << endl;

	cout << "Player 1 [X] ( NAME  [space]  WIN  [space]  MATCH ): ";
	cin >> name >> win >> match;
	player player1(name, win, match);
	cout << "Player 2 [O] ( NAME  [space]  WIN  [space]  MATCH ): ";
	cin >> name >> win >> match;
	player player2(name, win, match);

	gameManager gm(player1, player2, 'X', 'O');

	cout << endl;

	gm.init();

	cout << endl;

	gm.play();

	cin.get();
	return 0;
}