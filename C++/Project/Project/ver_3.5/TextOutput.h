#ifndef TEXT_OUTPUT_H
#define TEXT_OUTPUT_H
#include "ConsoleOutput.h"
#include <fstream>
using namespace std;

class TextOutput:public ConsoleOutput{
public:
	TextOutput(STR filename);
	virtual ~TextOutput();

protected:
	virtual ostream& StdOut();

protected:
	ofstream fout;
};

#endif