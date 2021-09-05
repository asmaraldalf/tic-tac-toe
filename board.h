#pragma once
class board
{
	private:
		char aBoard[3][3];

	public:
		board();
		bool isFull();
		bool isEmpty();
		char getValueAtIndex(int x, int y);
		void setValueAtIndex(int x, int y, char value);
		char checkSimilarValueVertically();
		char checkSimilarValueHorizontally();

};

