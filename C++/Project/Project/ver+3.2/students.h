#ifndef STUDENTS_H
#define STUDENTS_H

#include "list.h"

class Students{
public:
	Students();
	~Students();

	bool AddStudent();
	void ShowAll();

	static void DeleteData(void* data);

private:
	List students;
	float TotalAve;
	int NumberOfStudent;
};

#endif