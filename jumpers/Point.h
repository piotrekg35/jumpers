#pragma once
#include <iostream>
class Point {
private:
	int x;
	char y;
public:
	int getX()const;
	int getY()const;
	Point();
	Point(int _x, char _y);
	Point(const Point& p);
	friend std::ostream& operator<<(std::ostream& os, const Point& p);
	friend bool operator==( const Point& p ,const Point& p1);
	friend bool operator<(const Point& p, const Point& p1);
};