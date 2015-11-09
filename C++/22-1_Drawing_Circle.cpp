#include <iostream>
using namespace std;

class  Shape
{
public:
	void Move(double x, double y);
	virtual void Draw() const;
	 

	Shape();
	Shape(double x, double y);

protected:
	double _x,_y;
};

Shape::Shape()
{
	_x = _y = 0.0;
	
}

Shape::Shape(double x, double y)
{
	
	_x = x;
	_y = y;
}
void Shape::Move(double x, double y)
{
	_x = x;
	_y = y;
}

void Shape::Draw() const
{
	cout <<"[Shape] position = ("<<_x<<","<<_y<<")\n";
}

class Rectangle: public Shape
{
public:
	void Draw() const;
	void Resize(double width, double height);

	Rectangle();
	Rectangle(double x, double y, double width, double height);
	
protected:
	double _width;
	double _height;
};

Rectangle::Rectangle()
{
	_width= _height =100.0f;
}

Rectangle::Rectangle(double x, double y, double width, double height)
	: Shape(x,y)
{
	Resize( width, height);
}

void Rectangle::Draw() const
{
	cout <<"[Rectangle]  position = ("<<_x<<","<<_y<<")" "Size =("<<_width <<","<<_height<<")\n";

}

void Rectangle::Resize( double width, double height)
{
	_width = width;
	_height = height;
}

class Circle : public Shape
{
public:
	void Draw() const;
	void SetRadius(double radius);
	Circle();
	Circle(double x, double y,double radius);

protected:
	double _radius;
};

Circle::Circle()
{
	_radius = 100.0f;
}
Circle::Circle(double x, double y, double radius)
	:Shape(x,y)
{
	SetRadius( radius);
}

void Circle::Draw() const
{
	cout<<"[Circle] Position = ("<< _x<<","<<_y<<")"" Radius = " <<_radius <<"\n";
}

void Circle::SetRadius(double radius)
{
	_radius = radius;
}


int main()
{

	Shape s;
	s.Move(100, 100);
	s.Draw();

	Rectangle r;
	r.Move(200, 100);
	r.Resize( 50, 50);
	r.Draw();

	Circle c;
	c.Move( 300, 100);
	c.SetRadius(30);
	c.Draw();

	return 0;
}



