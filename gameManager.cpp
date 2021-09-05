#include "gameManager.h"
#include "player.h"
#include "board.h"
#include <iostream>
using namespace std;


gameManager::gameManager() {
	p1;
	sym1 = ' ';
	p2;
	sym2 = ' ';
};

gameManager::gameManager(player player1, player player2, char symbol1, char symbol2) {
	// player 1
	p1 = player1;
	sym1 = symbol1;

	// player 2
	p2 = player2;
	sym2 = symbol2;
};

void gameManager::init() {
	sym1 = 'X';
	sym2 = 'O';
	p1.setMatchCount(+1);
	p2.setMatchCount(+1);
};

void gameManager::turn(char sym) {
	// input value
	cout << "Insert row (space) column index: ";
	cin >> row, col;

	b.setValueAtIndex(row, col, sym);
};

void gameManager::play() {
	// do game
};

char gameManager::checkWin() {
	if (b.checkSimilarValueHorizontally() != '0')
		return b.checkSimilarValueHorizontally();
	else if (b.checkSimilarValueVertically() != '0')
		return b.checkSimilarValueVertically();
};
