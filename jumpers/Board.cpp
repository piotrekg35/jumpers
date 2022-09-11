#include "Board.h"
Board::Board()
{
	for (char c = 'a'; c <= MAX_LENGTH_IDX; ++c){
		board[Point(1, c)] = new Figure(0);
		board[Point(2, c)] = new Figure(0);
		for (int i = 3; i < 5; ++i)
			board[Point(i, c)] = nullptr;
		board[Point(5, c)] = new Figure(1);
		board[Point(6, c)] = new Figure(1);
	}
}
Board::~Board()
{
	for (auto iter = board.begin(); iter != board.end(); ++iter)
		delete iter->second;
	board.clear();
}
Board::Board(const Board& b)
{
	for (auto iter = board.begin(); iter != board.end(); ++iter)
		board[iter->first] = iter->second==nullptr ? nullptr : new Figure(iter->second->isPlayersFigure());
}
std::map<Point, Figure*> Board::getBoard() const
{
	return board;
}
void Board::print()
{
	std::cout << "  ";
	for (char c = 'a'; c <= MAX_LENGTH_IDX; ++c)std::cout << c<<" ";
	std::cout << std::endl;
	for (int i = 1; i <= MAX_HEIGHT_IDX; ++i)
	{
		std::cout << i<<" ";
		for (char c = 'a'; c <= MAX_LENGTH_IDX; ++c)
		{
			if (board[Point(i, c)] != nullptr) std::cout << board[Point(i, c)]->getSymbol() << " ";
			else std::cout << "* ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
int Board::review()
{

	int score = 0;
	for (auto iter = board.begin(); iter != board.end(); ++iter)
	{
		if (iter->second == nullptr)continue;

		if (iter->second->isPlayersFigure() && iter->first.getX()==1)score -= 5;
		else if (iter->second->isPlayersFigure() && iter->first.getX() == 2)score -= 4;
		else if (iter->second->isPlayersFigure() && iter->first.getX() == 3)score -= 3;
		else if (iter->second->isPlayersFigure() && iter->first.getX() == 4)score -= 2;
		else if (iter->second->isPlayersFigure() && iter->first.getX() == 5)score -= 1;

		else if (!iter->second->isPlayersFigure() && iter->first.getX() == 2)score += 1;
		else if (!iter->second->isPlayersFigure() && iter->first.getX() == 3)score += 2;
		else if (!iter->second->isPlayersFigure() && iter->first.getX() == 4)score += 3;
		else if (!iter->second->isPlayersFigure() && iter->first.getX() == 5)score += 4;
		else if (!iter->second->isPlayersFigure() && iter->first.getX() == 6)score += 5;
	}
	return score;
}
bool Board::hasPlayerWin()
{
	bool isRowComplete;
	for (int i = 1; i < 3; ++i)
	{
		for (char c = 'a'; c <= MAX_LENGTH_IDX; ++c)
		{
			isRowComplete = true;
			if (board[Point(i, c)] != nullptr && board[Point(i, c)]->isPlayersFigure()) continue;
			else {
				isRowComplete = false;
				break;
			}
		}
		if (!isRowComplete)break;
	}
	if (!isRowComplete)return false;
	return true;
}
bool Board::hasComputerWin()
{
	bool isRowComplete;
	for (int i = MAX_HEIGHT_IDX-1; i <=MAX_HEIGHT_IDX; ++i)
	{
		for (char c = 'a'; c <= MAX_LENGTH_IDX; ++c)
		{
			isRowComplete = true;
			if (board[Point(i, c)] != nullptr && !board[Point(i, c)]->isPlayersFigure()) continue;
			else {
				isRowComplete = false;
				break;
			}
		}
		if (!isRowComplete)break;
	}
	if (!isRowComplete)return false;
	return true;
}
bool Board::isPointOutOfBoard(Point p)
{
	if (p.getX() > MAX_HEIGHT_IDX || p.getX() < 1 || p.getY() > MAX_LENGTH_IDX || p.getY() < 'a') return true;
	return false;
}
bool Board::isPointTaken(Point p)
{
	if (board[p]==nullptr) return false;
	return true;
}
bool Board::isMovePossible(Point p)
{
	if (isPointOutOfBoard(p) || isPointTaken(p)) return false;
	return true;
}
bool Board::isPlayersFigure(Point p)
{
	if (isPointOutOfBoard(p) || board[p] == nullptr || !board[p]->isPlayersFigure()) return false;
	return true;
}
bool Board::isComputersFigure(Point p)
{
	if (isPointOutOfBoard(p) || board[p] == nullptr || board[p]->isPlayersFigure()) return false;
	return true;
}
bool Board::isMoveOkWithRules(Point p0, Point p1) {
	if (!isMovePossible(p1))return false;
	for (auto it : board[p0]->getMoves())
	{
		if (p1.getX() - p0.getX() == it[0] && p1.getY() - p0.getY() == it[1])return true;
	}
	for (auto it : board[p0]->getJumps())
	{
		if (p1.getX() - p0.getX() == it[0] && p1.getY() - p0.getY() == it[1] &&
			isPointTaken(Point(p0.getX() + it[0]/2, p0.getY() + it[1]/2)))return true;
	}
	return false;
	
}

void Board::move(Point p0,Point p1)
{
	board[p1] = board[p0];
	board[p0] = nullptr;
}