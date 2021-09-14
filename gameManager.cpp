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
	p1.setMatchCount(p1.getMatchCount() + 1);
	p2.setMatchCount(p2.getMatchCount() + 1);
};

void gameManager::turn(char sym) {
	// input value
	cout << "Insert position (x, y) : ";
	cin >> x >> y;

	if (x > 2 || y > 2) {
		cout << "Invalid square index. Try insert another position." << endl;
		turn(sym);
	}

	if (b.getValueAtIndex(x, y) == '0')
		b.setValueAtIndex(x, y, sym);
	else {
		cout << "Square is filled. Try insert another position." << endl;
		turn(sym);
	}
};

void gameManager::play() {
	// do game
	int step = 0;
	while (!b.isFull() && checkWin() == 'N')
	{
		step++;

		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++)
			{
				if (b.getValueAtIndex(x, y) != '0')
					cout << b.getValueAtIndex(x, y) << "\t";
				else
					cout << "-\t";
			}

			cout << endl << endl;
		}

		if (step % 2 == 1) // player 1 turn
		{
			cout << p1.getUsername() << "'s turn" << endl;
			turn(sym1);
		}
		else // player 2 turn
		{
			cout << p2.getUsername() << "'s turn" << endl;
			turn(sym2);
		}

		cout << endl;
	}

	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++)
		{
			if (b.getValueAtIndex(x, y) != '0')
				cout << b.getValueAtIndex(x, y) << "\t";
			else
				cout << "-\t";
		}

		cout << endl << endl;
	}

	if (checkWin() != 'N') {
		if (checkWin() == sym1)
		{
			cout << p1.getUsername();
			p1.setWinCount(p1.getWinCount() + 1);
		}
		if (checkWin() == sym2)
		{
			cout << p2.getUsername();
			p2.setWinCount(p2.getWinCount() + 1);
		}
		cout << " IS THE WINNER" << endl;
	}
	else
		cout << "MATCH DRAW" << endl;

	cout << "\nStat: " << endl;
	cout << "* PLAYER 1 * \n" << "Username: " << p1.getUsername() << "\n" << "Win: " << p1.getWinCount() << "\n" << "Match: " << p1.getMatchCount() << endl << endl;
	cout << "* PLAYER 2 * \n" << "Username: " << p2.getUsername() << "\n" << "Win: " << p2.getWinCount() << "\n" << "Match: " << p2.getMatchCount() << endl << endl;
	
};

char gameManager::checkWin() {
	if (b.checkSimilarValueHorizontally() != '0')
		return b.checkSimilarValueHorizontally();
	else if (b.checkSimilarValueVertically() != '0')
		return b.checkSimilarValueVertically();
	else
		return 'N';
};
