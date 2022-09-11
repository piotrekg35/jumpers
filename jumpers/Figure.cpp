#include "Figure.h"
Figure::Figure(bool _isPlayers) {
	isPlayers = _isPlayers;
	if (isPlayers)representativeSymbol = 'Y';
	else representativeSymbol = 'C';
	
	moves.push_back(new int[2]{ -1, 0 });
	moves.push_back(new int[2]{ 1, 0 });
	moves.push_back(new int[2]{ 0, -1 });
	moves.push_back(new int[2]{ 0, 1 });

	jumps.push_back(new int[2]{ -2, 0 });
	jumps.push_back(new int[2]{ -2, 2 });
	jumps.push_back(new int[2]{ -2, -2 });
	jumps.push_back(new int[2]{ 0, 2 });
	jumps.push_back(new int[2]{ 0, -2 });
	jumps.push_back(new int[2]{ 2, 0 });
	jumps.push_back(new int[2]{ 2, 2 });
	jumps.push_back(new int[2]{ 2, -2 });
	
}
Figure::~Figure(){
	for (auto &m : moves)delete m;
	moves.clear();
	for (auto& j : jumps)delete j;
	jumps.clear();
}
char Figure::getSymbol() {
	return representativeSymbol;
}
std::list<int*> Figure::getMoves()const{
	return moves;
}
std::list<int*> Figure::getJumps()const {
	return jumps;
}
std::list<int*> Figure::getMovesAndJumps()const {
	std::list<int*> jumpsAndMoves;
	for (auto iter = moves.begin(); iter != moves.end(); ++iter)jumpsAndMoves.push_back(*iter);
	for (auto iter = jumps.begin(); iter != jumps.end(); ++iter)jumpsAndMoves.push_back(*iter);
	return jumpsAndMoves;
}
bool Figure::isMove(int* coords) {
	if (coords[0] * coords[0] + coords[1] * coords[1] == 1)return true;
	return false;
}
bool Figure::isPlayersFigure()const {
	return isPlayers;
}
