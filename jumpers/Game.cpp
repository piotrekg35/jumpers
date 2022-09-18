#include "Game.h"
Game* Game::instance = nullptr;
Game::Game() {
	board = new Board();
}
Game::~Game() {
	delete board;
	instance = nullptr;
}
void Game::start() {
	while (true){
		board->print();
		playersTurn();
		if (isThereWinner())break;
		board->print();
		computersTurn();
		if (isThereWinner())break;
	}
}
void Game::playersTurn() {
	int x,x1;
	char y,y1;
	do {
		std::cout << "What move do you want to make?" << std::endl;
		std::cin >> x >> y >> x1 >> y1;
	} while (!board->isPlayersFigure(Point(x, y)) || !board->isMoveOkWithRules(Point(x, y), Point(x1, y1)));
	board->move(Point(x, y), Point(x1, y1));
}
void Game::computersTurn() {
	Point x0, x1;
	findTheBestMove(board, &x0,&x1);
	board->move(x0, x1);
}
void Game::findTheBestMove(Board *b, Point *x0, Point *x1) {
	Point tmp, tmp1;
	int maxScore = 10 * LOOSE;
	int score = b->review();
	
	for (auto &iterB : b->getBoard())
	{
		if (iterB.second == nullptr || iterB.second->isPlayersFigure())continue;
		for (auto &iterM : iterB.second->getMovesAndJumps())
		{
			if ( b->isMovePossible(Point(iterB.first.getX() + iterM[0], iterB.first.getY() + iterM[1])) &&
				( Figure::isMove(iterM) || b->isPointTaken(Point(iterB.first.getX() + iterM[0] / 2, iterB.first.getY() + iterM[1] / 2))))
			{
				tmp = iterB.first;
				tmp1 = Point(iterB.first.getX() + iterM[0], iterB.first.getY() + iterM[1]);
				if (!b->isMovePossible(tmp1))continue;
				b->move(tmp,tmp1);
				score = b->review();
				b->move(tmp1, tmp);
				if (score > maxScore)
				{
					maxScore = score;
					*x0 = tmp;
					*x1 = tmp1;
				}
			}
		}
	}
	
}
bool Game::isThereWinner() {
	if (board->hasComputerWin() || board->hasPlayerWin())
	{
		board->print();
		std::cout << "GAME OVER" << std::endl;
		return true;
	}
	return false;
}
Game* Game::getInstance(){
	if (instance == nullptr)
		instance = new Game();
	return instance;
}