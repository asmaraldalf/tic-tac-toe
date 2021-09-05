#pragma once
#include "player.h"
#include "board.h"

class gameManager
{
	private:
		board b;
		player p1;
		player p2;
		char sym1;
		char sym2;

		//board index
		int row;
		int col;

	public:
		gameManager();
		gameManager(player player1, player player2, char symbol1, char symbol2);
		void init(); // add symbol, add matchCount
		void turn(char sym); // player's turn to fill the board with their symbol
		void play(); // manage the game (win condition checking and player's turn)
		char checkWin(); // check the winner
};

