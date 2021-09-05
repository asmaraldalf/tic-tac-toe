#pragma once
#include <string>
using namespace std;

class player
{
	private:
		string aUsername;
		int winCount;
		int matchCount;

	public:
		player();
		player(string uname, int win, int match);
		void setUsername(string uname);
		string getUsername();
		void setWinCount(int win);
		int getWinCount();
		void setMatchCount(int match);
		int getMatchCount();
};

