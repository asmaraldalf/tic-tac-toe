#include "player.h"
#include <string>
#include <iostream>
using namespace std;

player::player() {
	aUsername = ' ';
	winCount = 0;
	matchCount = 0;
}

player::player(string uname, int win, int match) {
	aUsername = uname;
	winCount = win;
	matchCount = match;
}

void player::setUsername(string uname) {
	aUsername = uname;
}

string player::getUsername() {
	return aUsername;
}

void player::setWinCount(int win) {
	winCount = win;
}

int player::getWinCount() {
	return winCount;
}

void player::setMatchCount(int match) {
	matchCount = match;
}

int player::getMatchCount() {
	return matchCount;
};