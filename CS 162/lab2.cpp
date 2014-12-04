

#include <iostream>
using std::cout;
using std::cin;
using std::endl;




int depth_function(int a);
class greater_than_10
{};

int main()
{
	int depth;
	try
	{
		cout << "Enter a depth number to throw exception. Remember, must be between 0 and 10: ";
		cin >> depth;
		
	

		if (depth <= 0)
		throw depth;
		
		if (depth > 10)
		throw greater_than_10();

                depth_function(depth);
		

    
	}

	catch(int e)
	{
		cout << "This catch is special for choosing " << e << " stacks." << endl;
	}

	catch(greater_than_10)
	{
		cout << "This catch is for integer inputs that are greater than 10." << endl;
	}


	
return 0;
}


int depth_function(int a) 
{	
	int temp;
	
	cout << "Recursing at stack #" << a << endl;
	

	try 
	{	
		if (a<=0)
		throw a;
		
		
		temp = depth_function(a-1);
		return temp;
		

	}
	catch(int e)
	{
		cout << "This catch is when the recursion has finished recursing the amount you've chosen. It's now at " << e << endl;
	
	}	
}




