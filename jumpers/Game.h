#pragma once
#include "Board.h"
class Game {
private:
	Board* board;
	static Game* instance;
	Game();
protected:
	void playersTurn();
	void computersTurn();
	void findTheBestMove(Board *b, Point *x0, Point *x1);
	bool isThereWinner();
public:
	~Game();
	void start();
	static Game* getInstance();
};