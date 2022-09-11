#pragma once
#include <list>
class Figure {
private:
	bool isPlayers;
	char representativeSymbol;
	std::list<int*> moves;
	std::list<int*> jumps;
public:
	char getSymbol();
	std::list<int*> getMoves()const;
	std::list<int*> getJumps()const;
	std::list<int*> getMovesAndJumps()const;
	bool isPlayersFigure()const;
	static bool isMove(int* coord);
	Figure(bool _isPlayers);
	~Figure();
};
