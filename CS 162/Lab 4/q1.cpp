/*Minh Nguyen
 * Lab 4 Question 1
 * No input from user required
 * Output: After creating an overloaded product operator, A simple product is written in the main function to show 
 * how the dot product of two vector classes are added together and works.
 */

#include <iostream>

using std::cout;
using std::endl;


class Vector2D
{
public:

	
	int x;	
	int y;
	

	//default constructor
	Vector2D()
	{
		x = y = 0;
	}
	
	
	//Constructor to take in x and y values.
	Vector2D(int xValue, int yValue)
	{
		x = xValue;
		y = yValue;
	}	

	//overloading product operator
	Vector2D operator*(Vector2D& v)
	{
		Vector2D newNumb;
		newNumb.x = x * v.x;
		newNumb.y = y * v.y;
		return newNumb;
	}

	//destructor
	~Vector2D()
	{
	}	

	//accessor X
	int getX()const
	{
		return x;
	}

	//accessor Y
	int getY()const	
	{
		return y;
	}

	//mutator X
	void setX(int xValue)
	{
		x = xValue;
	}
	
	//mutator Y
	void setY(int yValue)
	{
		y = yValue;
	}

};



int main()
{
	cout << endl;
	cout << "*****************************************" << endl << endl;

	//variable d to hold addition of the 2 dot products 
	int d; 

	//Initializing x and y numbers for  Vectors A and B.
	Vector2D A(2,3);
	Vector2D B(4,5);
	
	//create object c to hold value of dot product of A and B
	Vector2D c; 

	cout << "A.x = " << A.x << ", B.x = " << B.x << endl;
	cout << "A.y = " << A.y << ", B.y = " << B.y << endl;
	


	//Using overloaded product operator 
	c = A * B;
	cout << endl;
	cout << "A.x * B.x = c.y " << endl;
	cout << A.x << " * " << B.x << " = " << c.x << endl;
	cout << "A.y * B.y = c.y " << endl;
	cout << A.y << " * " << B.y << " = " << c.y << endl;

	cout << endl << endl;
	//Adding A and B together, and storing it in a local variable d
	d = c.x + c.y;
	cout << "d =  (A.x * B.x) + (A.y * B.y)" << endl;
	cout << "d = " << c.x << " + " << c.y << " = " << d << endl;
	
	cout << endl << "*****************************************************" << endl << endl;

return 0;
}
