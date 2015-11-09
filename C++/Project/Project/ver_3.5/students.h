#ifndef STUDENTS_H
#define STUDENTS_H

#include "list.h"

class Students{
public:
	enum FORMAT {CONSOLE, TEXTFILE, HTMLFILE};

public:
	Students();
	~Students();

	bool AddStudent(bool general);
	void ShowAll(FORMAT fmt);

	static void DeleteData(void* data);

private:
	List students;
	float TotalAve;
	int NumberOfStudent;
};

#endif