#ifndef SHAP_H
#define SHAP_H
#include <iostream>
using namespace std;

class Rect;
class Circ;


class Shap {
public:
	virtual int overlapwith(const Shap&)const = 0;
	virtual int overlap(const Rect&)const = 0;
	virtual int overlap(const Circ&)const = 0;

};

#endif