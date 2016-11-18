#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;




class Point {
public:
	Point();
	Point(int);
	Point(int, int);
	Point(int, int, int, int);
	Point(const Fraction&);
	Point(const Fraction&, const Fraction&);
	Point(const Point&);
	~Point();
	

	static int getQuadrant(const Point&);
	int getQuadrant()const;
	void moveBy(Fraction&, Fraction&);
	void moveBy(Fraction&);
	void moveBy(int);
	void flipByXaxis();
	void flipByYaxis();
	void flipThroughOrigin();
	void print();


	Point operator=(const Point&);
	Point operator+(const Point&);
	Point operator-(const Point&);
	Point operator*(const Point&);
	Point operator/(const Point&);

	friend std::ostream& operator<<(std::ostream &out, const Point&);
//	friend std::ostream& operator>>(std::ostream &in, const Point &P);



private:
	Fraction frx;
	Fraction fry;
};



//std::ostream& operator>>(std::ostream &in, const Point &P) {
//	cout << "\n    X-coordinate : ";
//	cin >> P.frx;
//	return in;
//}


#endif


