#include <iostream>
using namespace std;












//#include <iostream>
//using namespace std;
//
//
//class B {
//public:
//	int x;
//	B(int a) {
//		x = a;
//	}
//	virtual void vF() {
//		void vF() {
//		cout << "Using base function -- display x: " << x << endl;
//		return;
//	}
//};
//class D1 : public B {
//public:
//	D1(int b) : B(b) {
//		x = b;
//	}
//	void vF() {
//		cout << "\nUsing D1 function -- display x + 10: " << (x + 10) << endl;
//		return;
//	}
//};
//class D2 : public B {
//public:
//	D2(int c) : B(c) {
//		x = c;
//	}
//	void vF() {
//		cout << "\nUsing D2 function -- display x - 10: "
//			<< (x - 10) << endl;
//		return;
//	}
//};
//int main() {
//	B bObj(50);
//	B* bPtr;
//	D1 d1Obj(100);
//	D2 d2Obj(150);
//	bPtr = &bObj; // Pointing to base B object
//	bPtr->vF();
//	bPtr = &d1Obj; // Pointing to derived D1 object
//	bPtr->vF();
//	bPtr = &d2Obj; // Pointing to derived D2 object
//	bPtr->vF();
//	bPtr = new D1(360);
//	bPtr->vF();
//	
//	return 0;
//}