#include "DocWriter.h"
#include "HTMLWriter.h"

int main(){
	HTMLWriter hw("test.html", "HTMLWriter content");
	DocWriter dw;

	dw = hw;
	dw.Write();
	return 0;
}