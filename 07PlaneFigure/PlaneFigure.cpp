#include "PlaneFigure.h"

Rectangle::Rectangle(float length, float width)
{
	l = length;
	w = width;
}

float Rectangle::getPerim() const
{
	return 2 * (l + w);
}

float Rectangle::getArea() const
{
	return l * w;
}

Circle::Circle(float radius)
{
	r = radius;
}

float Circle::getPerim() const
{
	return 2 * PI * r;
}

float Circle::getArea() const
{
	return PI * r * r;
}

Square::Square(float length)
{
	l = length;
}

float Square::getPerim() const
{
	return 4 * l;
}

float Square::getArea() const
{
	return l * l;
}

Triangle::Triangle(float edgeA, float edgeB, float edgeC)
{
	a = edgeA;
	b = edgeB;
	c = edgeC;
}

float Triangle::getPerim() const
{
	return a + b + c;
}

float Triangle::getArea() const
{
	float area, temp;
	temp = (a + b + c)*(a + b - c)*(a - b + c)*(-a + b + c);
	area = sqrt(temp);
	area = area * 0.25;
	return area;
}