#include "TextOutput.h"

TextOutput::TextOutput(STR filename){
	fout.open(filename.c_str());
}

TextOutput::~TextOutput(){ fout.close();}

ostream& TextOutput::StdOut(){return fout;}