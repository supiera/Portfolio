#ifndef STUDENTS_H
#define STUDENTS_H

#include "List.h"

class Students{
public:
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