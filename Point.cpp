#include "Fraction.h"
#include "FractionUtility.h"
#include "Point.h"
#include "PointUtility.h"
using namespace std;




Point::Point() : frx(), fry() {
}
Point::Point(int nx) : frx(nx), fry(nx) {
}
Point::Point(int x, int y) : frx(x), fry(y) {
}
Point::Point(int nx, int dx, int ny, int dy) : frx(nx, dx), fry(ny, dy) {
}
Point::Point(const Fraction& f) : frx(f), fry(f){
}
Point::Point(const Fraction& fx, const Fraction& fy) : frx(fx), fry(fy) {
}
Point::Point(const Point& ref) : frx(ref.frx), fry(ref.fry) {
}
Point::~Point() {
	cout << "\nCaling ~Point";
}



Fraction Point::getFrx() {
	return frx;
}
Fraction Point::getFry() {
	return fry;
}



int Point::getQuadrant(const Point& p) {
	if (p.frx.getNum() > 0 && p.fry.getNum() > 0)
		return 1;
	else if (p.frx.getNum() < 0 && p.fry.getNum() > 0)
		return 2;
	else if (p.frx.getNum() < 0 && p.fry.getNum() < 0)
		return 3;
	else if (p.frx.getNum() > 0 && p.fry.getNum() < 0)
		return 4;
	else
		return 0;
}


int Point::getQuadrant()const {
	if (frx.getNum() > 0 && fry.getNum() > 0)
		return 1;
	else if (frx.getNum() < 0 && fry.getNum() > 0)
		return 2;
	else if (frx.getNum() < 0 && fry.getNum() < 0)
		return 3;
	else if (frx.getNum() > 0 && fry.getNum() < 0)
		return 4;
	else
		return 0;
}



void Point::moveBy(Fraction& delx, Fraction& dely) {
	frx += delx;
	fry += dely;
	frx.reduce();
	fry.reduce();
}

void Point::moveBy(Fraction& del) {
	frx += del;
	fry += del;
	frx.reduce();
	fry.reduce();
}

void Point::moveBy(int del) {
	frx.update(del);
	fry.update(del);
	frx.reduce();
	fry.reduce();
}




void Point::flipByXaxis() {
	fry *= -1;
}
void Point::flipByYaxis() {
	frx *= -1;
}
void Point::flipThroughOrigin() {
	frx *= -1;
	fry *= -1;
}

void Point::print() {
	cout << "(" << frx << "," << fry << ")";
}



double Point::distance(const Point& p2) {
	return  ((frx - p2.frx) * (frx - p2.frx)
		+ (fry - p2.fry) * (fry - p2.fry)).sqroot();
}





Point Point::operator=(const Point& p) {
	frx = p.frx;
	fry = p.fry;
	return p;
}

Point Point::operator+(const Point& p) {
	return (frx + p.frx, fry + p.fry);
}

Point Point::operator-(const Point& p) {
	return (frx - p.frx, fry - p.fry);
}

Point Point::operator*(const Point& p) {
	return (frx * p.frx, fry * p.fry);
}

Point Point::operator/(const Point& p) {
	return (frx * p.fry, fry * p.frx);
}


std::ostream& operator<<(std::ostream &out, const Point &P) {
	out << "(" << P.frx << "," << P.fry << ")";
	return out;
}