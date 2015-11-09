#ifndef STUDENTS_H
#define STUDENTS_H

#include "List.h"

class Students{
public:
	enum FORMAT {CONSOLE, TEXTFILE, HTMLFILE};

	Students();
	~Students();

	bool AddStudent(bool general);
	void ShowAll();

	static void DeleteData(void* data);

private:
	List students;
	float TotalAve;
	int NumberOfStudent;
};

#endif