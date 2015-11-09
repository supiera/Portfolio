#include "HTMLOutput.h"
#include <iostream>
#include <iomanip>
using namespace std;

HTMLOutput::HTMLOutput(STR filename){
	columns = 0;
	fout.open(filename.c_str());
	fout << "<HTML><HEAD><TITLE> 성적 프로그램 </TITLE></HEAD><BODY><CENTER>";
}

HTMLOutput::~HTMLOutput(){
	fout << "</CENTER></BODY></HTML>";
	fout.close();
}

void HTMLOutput::BeginTable(STR title){
	fout << "<H3>" << title << "</H3>";
	fout << "<TABLE bgcolor='slategray' cellspacing = '1' cellpadding = '4' border = '0'>";
}

void HTMLOutput::PutHeader(string headers[], int number){
	columns = number;
	fout << "<TR bgcolor='#e0e0ff' align='center'>";
	for(int i =0; i<number; ++i)
		fout << "<TD>" << headers[i] << "</TD>";
	fout << "</TR>";
}

void HTMLOutput::PutRecord(string record[]){
	fout << "<TR bgcolor = 'white' align = 'right'>";
	for(int i = 0; i < columns; ++i)
		fout << "<TD>" << record[i] << "</TD>";
	fout << "</TR>";
}

void HTMLOutput::EndTable(){
	fout << "</TABLE>";
}

void HTMLOutput::Write(STR text){
	fout << "<P>" << text << "</P>";
}