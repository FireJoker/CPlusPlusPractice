#ifndef PLANEFIGURE_H
#define PLANEFIGURE_H
#include <iostream>
#include <cctype>
#define PI 3.1415926

using namespace std;

//base class
class PlaneFigure
{
public:
	virtual float getPerim() const = 0;    //return perimeter
	virtual float getArea() const = 0;    //return area
	virtual  ~PlaneFigure() {};

};

//inheritance and polymorphism 
class Rectangle : public PlaneFigure
{
public:
	Rectangle(float, float);
	float getPerim() const;
	float getArea() const;

private:
	float l;
	float w;

};

class Circle : public PlaneFigure
{
public:
	Circle(float);
	float getPerim() const;
	float getArea() const;

private:
	float r;

};

class Square : public PlaneFigure
{
public:
	Square(float);
	float getPerim() const;
	float getArea() const;

private:
	float l;

};

class Triangle : public PlaneFigure
{
public:
	Triangle(float, float, float);
	float getPerim() const;
	float getArea() const;

private:
	float a;
	float b;
	float c;

};

#endif