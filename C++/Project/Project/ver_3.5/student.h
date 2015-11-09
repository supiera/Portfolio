#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

class BaseOutput;
class Student{
public:
	Student(int sNo);
	virtual ~Student();
	virtual void Input();
	virtual void Show(BaseOutput& out) const;

	int GetStdNumber() const;
	string GetName() const;
	int GetKor() const;
	int GetEng() const;
	int GetMath() const;
	float GetAverage() const;

protected:
	int sNo;
	string name;
	int kor, eng, math;
	float ave;
};

class EngStudent : public Student{
public:
	EngStudent(int sNo);
	virtual void Input();
	virtual void Show(BaseOutput& out) const;

protected:
	int hi_eng;
};

#endif