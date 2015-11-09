#include <iostream>
#include <iomanip>
#include "ConsoleOutput.h"
using namespace std;

ConsoleOutput::ConsoleOutput(){ columns = 0; }
ConsoleOutput::~ConsoleOutput() {};

void ConsoleOutput::BeginTable(STR title){
	StdOut() << "\n\t\t\t" << title << "\n";
}

void ConsoleOutput::PutHeader(string headers[], int number){
	columns = number;
	for(int i = 0; i<number; ++i)
		StdOut() << setw(9) << headers[i];
	StdOut() << "\n";
}

void ConsoleOutput::PutRecord(string record[]){
	for (int i=0; i<columns; ++i)
		StdOut() << setw(9) << record[i];

	StdOut() << "\n";
}

void ConsoleOutput::EndTable(){
	StdOut() << "\n";
}

void ConsoleOutput::Write(STR text){
	StdOut() << text << "\n";
}

ostream& ConsoleOutput::StdOut(){
	return cout;
}