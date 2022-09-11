#include "Point.h";
int Point::getX()const {
	return x;
}
int Point::getY()const {
	return y;
}
Point::Point(){
	x = 1;
	y = 'a';
}
Point::Point(int _x, char _y){
	x = _x;
	y = _y;
}
Point::Point(const Point& p) {
	x = p.x;
	y = p.y;
}
std::ostream& operator<<(std::ostream& os, const Point& p) {
	os << p.x << ", " << p.y;
	return os;
}
bool operator == (const Point & p, const Point& p1) {
	return p.x == p1.x && p.y == p1.y;
}
bool operator < (const Point& p, const Point& p1) {
	if (p.x < p1.x)return true;
	else if(p.x == p1.x && p.y<p1.y)return true;
	return false;
}