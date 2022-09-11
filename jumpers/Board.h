#pragma once
#include "Figure.h"
#include "Point.h"
#include <map>
#define WIN 1000;
#define LOOSE -1000;
#define MAX_HEIGHT_IDX 6
#define MAX_LENGTH_IDX 'd'	
class Board {
private:
	std::map<Point,Figure*> board;
protected:
	bool isPointOutOfBoard(Point p);
public:
	Board();
	Board(const Board& b);
	~Board();
	std::map<Point, Figure*> getBoard() const;
	int review();
	void move(Point p0,Point p1);
	void print();
	bool hasPlayerWin();
	bool hasComputerWin();
	bool isPlayersFigure(Point p);
	bool isPointTaken(Point p);
	bool isComputersFigure(Point p);
	bool isMoveOkWithRules(Point p0, Point p1);
	bool isMovePossible(Point p);
};