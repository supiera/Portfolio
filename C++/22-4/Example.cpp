#include "HTMLWriter.h"

int main(){
	HTMLWriter hw;
	hw.SetFileName("test.html");
	hw.SetContent("You must be a good programmer~!!");
	hw.SetFont("Arial", 16, "blue");
	hw.Write();

	return 0;
}