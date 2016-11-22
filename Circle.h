#ifndef CIRCLE_H
#define CIRCLE_H
using namespace std;

class Circle{
public:
	Circle();
	Circle(int, int, int);
	Circle(const Point&, const Fraction&);
	Circle(const Fraction&, const Fraction&, const Fraction&);
	Circle(const Circle&);

	void moveBy();
	
	Point getLocation()const;
	Fraction getRadius()const;
	int overlap(const Circle&)const;
	double overlappingArea(const Circle&)const;
	
	void combine(const Circle&)const;

	Circle operator=(const Circle&);
	Circle operator+(const Point&);
	Circle operator-(const Point&);
	Circle operator*(const Fraction&);
	Circle operator/(const Fraction&);
	

	friend std::ostream& operator<<(std::ostream &out, const Circle &C);

private:
	Point *cPtr;
	Fraction *rPtr;

};
#endif