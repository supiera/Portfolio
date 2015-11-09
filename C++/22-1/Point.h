#ifndef POINT_H
#define POINT_H

class Point{
public:
	void Print() const;
	void Offset(int x_delta, int y_delta);
	void Offset(const Point& pt);

	Point();
	Point(int initialX, int initialY);
	Point(const Point&pt);

	void SetX(int value);
	void SetY(int value);
	int GetX() const {return x;};
	int GetY() const {return y;};

private:
	int x, y;
};

inline void Point::SetX(int value){
	if (value < 0)	x = 0;
	else if (value > 100) x = 100;
	else	x = value;
}
inline void Point::SetY(int value){
	if (value < 0)	y = 0;
	else if (value > 100) y = 100;
	else	y = value;
}

#endif