#pragma once
#include "Board.h"
class Game {
private:
	Board* board;
protected:
	void playersTurn();
	void computersTurn();
	void findTheBestMove(Board *b, Point *x0, Point *x1);
	bool isThereWinner();
public:
	Game();
	~Game();
	void start();
};