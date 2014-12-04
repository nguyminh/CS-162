//Minh Nguyen
//Lab 5 Question 2
//User prompted to enter in an integer, program will use getline to store input in a variable
//if an integer is available, sstream will grab it and store it and print out the input as an integer
//if no integer is inputted correctly, user is prompted to try again


// to use string stream
#include <sstream> 
//to use getline
#include <iostream>

using namespace std;

int main()
{

	//declaring stringstream variable to ss
	stringstream ss;
	
	//clearing ss variable
	ss.clear();
	ss.str("");

	//boolean variable for validation in while loop
	bool ok = false;

	//string and integer variable to pass into stringstream variable
	string input;
	int integer;

	//prompting user to enter string
	cout << "Please enter an integer: ";
	getline(cin,input);
	
	//loop runs when boolean variable ok == true
	while (!ok)
	{

	//initializing stringstream as input getline from user
	ss << input;

	//if stringstream extracts an integer, boolean set to true, exits program
		if (ss >> integer)	
		{	cout << "The integer in this string is: " <<  integer << endl;
			ok = true;
		}
	
	//if no integer found, input is cleared and user prompted to try again
		else
		{
			cout << "Not an integer, please try again: ";
			ss.clear();
			ss.str("");
			getline(cin, input);
		}
	}
return 0;
}
