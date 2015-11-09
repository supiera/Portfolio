#include "Point.h"

int main(){
	Point pt(50, 50);
	Point delta(100, 100);
	
	pt.Offset(10, -10);
	pt.Print();

	pt.Offset(delta);
	pt.Print();

	return 0;
}