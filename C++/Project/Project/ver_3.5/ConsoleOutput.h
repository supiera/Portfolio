#ifndef CONSOLE_OUTPUT_H
#define CONSOLE_OUTPUT_H
#include "BaseOutput.h"

class ConsoleOutput : public BaseOutput{
public:
	ConsoleOutput();
	virtual ~ConsoleOutput();
	virtual void BeginTable(STR title);
	virtual void PutHeader(string headers[], int numbe);
	virtual void PutRecord(string record[]);
	virtual void EndTable();
	virtual void Write(STR text);

protected:
	virtual ostream& StdOut();

protected:
	int columns;
};

#endif