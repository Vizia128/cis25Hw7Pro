#include <iostream>
#include "Circ.h"
#include "Rect.h"
#include "Shap.h"
using namespace std;

//class Rectangle;
//class Circle;
//
//class Shape {
//public:
//	virtual double overlapwith(const Shape&)const = 0;
//	virtual double overlap(const Rectangle&)const = 0;
//	virtual double overlap(const Circle&)const = 0;
//
//};
//
//
//class Circle : public Shape {
//public:
//	Circle() : x(0), y(0), r(0) {
//	}
//	Circle(int X, int Y, int R) : x(X), y(Y), r(R) {
//	}
//
//	double overlapwith(const Shape &with)const {
//		cout << "\nCirc::overlapwith(const Shap&)const";
//		return with.overlap(*this);
//	}
//	double overlap(const Rectangle &w)const {
//		cout << "\nCirc::overlap(const Rect&)const";
//		return 12;
//	}
//	double overlap(const Circle &w)const {
//		cout << "\nCirc::overlap(const Circ&)const";
//		return 11;
//	}
//
//private:
//	int x, y, r;
//
//};
//
//class Rectangle : public Shape {
//public:
//	Rectangle() : x(0), y(0), l(0), w(0) {
//	}
//	Rectangle(int X, int Y, int L, int W) : x(X), y(Y), l(L), w(W) {
//	}
//
//	double overlapwith(const Shape &with)const {
//		cout << "\nRect::overlapwith(const Shap&)const";
//		return with.overlap(*this);
//	}
//	double overlap(const Rectangle &w)const {
//		cout << "\nRect::overlap(const Rect&)const";
//		return 22;
//	}
//	double overlap(const Circle &w)const {
//		cout << "\nRect::overlap(const Circ&)const";
//		return 21;
//	}
//
//private:
//	int x, y, l, w;
//
//};
//




int main() {

	Shap* F1 = new Rect(0,0,1,1);
	Shap* F2 = new Rect(1,1,2,2);
	Shap* C1 = new Circ(0,0,1);
	Shap* C2 = new Circ(1,1,2);


	double ff, fc, cf, cc;
	ff = F1->overlapwith(*F2);
	fc = F1->overlapwith(*C2);
	cf = C1->overlapwith(*F2);
	cc = C1->overlapwith(*C2);

	cout << "\n\n\tff : " << ff
		<< "\n\tfc : " << fc
		<< "\n\tcf : " << cf
		<< "\n\tcc : " << cc;

	int pb; cin >> pb;
	return 0;
}

