#include <iostream>
using namespace std;

class Square{
public:

	void print() const; 
	
	void setWidth(double); 

	double calArea();
	Square();
	Square(double);
	
private:
	double width;
	double area;

};

void Square::print()const{
	cout << "Area: " << area << endl;
}

void Square::setWidth(double w)
{
	if (w >= 0)
		width = w;
	else
		width = 0.0;
}

double Square::calArea()
{
	return area = width * width;
}

Square::Square()
{
	width = 2.5;
	calArea();

}

Square::Square(double w)
{
	
	setWidth(w);
	calArea();
	
}






class Rod : public Square {
public:

	void print() const;

	void setLength(double);

	void calVolume();
	Rod();
	Rod(double, double);

private:
	double length;
	double volume;
};



void Rod::print() const
{
	Square::print();
	cout << "Volume: " << volume << endl;
}

void Rod::setLength(double l)
{
	if (l >= 0.0)
		length = l;
	else
		length = 0.0;
}

void Rod::calVolume()
{
	volume = calArea() * length;
}

Rod::Rod()
{
	length = 3.6;
	calVolume();
}

Rod::Rod(double w, double l):Square(w)
{
	setLength(l);
	calVolume();
}








