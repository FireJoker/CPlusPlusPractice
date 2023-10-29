#include "PlaneFigure.h"
//#include <>

int main()
{
	//greating user
	cout << "Wolcome to the progarm" << endl;
	cout << "It is design for calculating the perimeter and area of a figure" << endl;
	cout << "Assume all plane figures are measured in centimeters" << endl << endl;

	char shape, choose;
	float a, b, c, r;
	do
	{
		//select the shape
		cout << "Please select the plane figure: R)ectangle C)ircle S)quare T)riangle ";
		cin >> shape;
		shape = toupper(shape);

		if (shape == 'R')
		{
			cout << "Please enter the length and width of this rectangle: ";
			cin >> a >> b;
			if (a <= 0 || b <= 0 || isalnum(a) || isalnum(b))    //should enter digit and greater than zero
				cout << "Invilid input." << endl;
			else
			{
				Rectangle obj(a, b);
				cout << "The perimeter of this figure is " << obj.getPerim() << endl;
				cout << "The area of this figure is " << obj.getArea() << endl;
			}
		}
		else if (shape == 'C')
		{
			cout << "Please enter the radius of this circle: ";
			cin >> r;
			if (r <= 0 || isalnum(r))
				cout << "Invilid input." << endl;
			else
			{
				Circle obj(r);
				cout << "The perimeter of this figure is " << obj.getPerim() << endl;
				cout << "The area of this figure is " << obj.getArea() << endl;
			}
		}
		else if (shape == 'S')
		{
			cout << "Please enter the length of this rectangle: ";
			cin >> a;
			if (a <= 0 || isalnum(a))
				cout << "Invilid input." << endl;
			else
			{
				Square obj(a);
				cout << "The perimeter of this figure is " << obj.getPerim() << endl;
				cout << "The area of this figure is " << obj.getArea() << endl;
			}
		}
		else if (shape == 'T')
		{
			cout << "Please enter the length of edges of this triangle: ";
			cin >> a >> b >> c;
			if (a <= 0 || b <= 0 || c <= 0 || isalnum(a) || isalnum(b) || isalnum(c))
				cout << "Invilid input." << endl;
			else
			{
				Triangle obj(a, b, c);
				cout << "The perimeter of this figure is " << obj.getPerim() << endl;
				cout << "The area of this figure is " << obj.getArea() << endl;
			}
		}
		else
			cout << "Invilid input. " << endl;

		//ask user to continue
		do
		{
			cout << "Continue to find the perimeter and area of another figure: Y)es/N)o? ";
			cin >> choose;
		} while (choose != 'Y' && choose != 'y' && choose != 'N' && choose != 'n');

	} while (choose != 'N' && choose != 'n');

	return 0;
}