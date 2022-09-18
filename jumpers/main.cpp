// proba.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "main.h"

using namespace std;

int main()
{
	Game* g = Game::getInstance();
	g->start();
	delete g;
	return 0;
}
