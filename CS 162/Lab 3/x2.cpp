/* Minh Nguyen
 * Lab 3, question 2
 * Inputs: User inputs first name and room number into vector
 * User chooses to delete names they don't want on the list
 * output: List of occupants in building before and after deletion
 */


#include <vector>    // to use vector
#include <iostream>
#include <string>   // for strings in vectors
#include <cmath>
#include <iterator> //to iterate in vector
#include <algorithm>  

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::endl;

struct person //struct with name and room number to be used for vector
{
	string first_name;
	int room;
};

void erase(string name, vector<person> & a_person);  // function to erase names

int main()
{
	//initialize variables
	char choice; //for loop choices to continue or not
	vector<person> a_person; //creating vector using struct as the definition
	person names; //temporary variable for the vector
	string temp, del; //temporrary variable for vector usage, as well as deletion choice for later
	int number; //temporary int variable for the room number


	cout << endl << endl;
	cout << "***********************************************************" << endl;
	cout << "Do you wish to enter occupants name and room number now? Y/N: ";
	cin >> choice;
	while (choice =='y' || choice == 'Y') //loop to continue to fill vector or not
	{	
		for (size_t i=0; i < 1000; i++) //chose a large size but can be aborted with conditional statement below
		{
			cout << "Enter first name here: ";
			cin >> temp; //first name variable
			names.first_name = temp; //initializing the string in the struct to this temp string value
	
			cout << "Enter room number: ";
			cin >> number; //room number variable
			names.room = number; //initializing the integer of the room in the struct to this temporary int value called number

			a_person.push_back(names); //Push_back to move vector to next position
		

			cout << "Do you want to enter another name? Y/N: ";
			cin >> choice; //conditional choice to continue entering names or not
			
			if (choice !='Y' || choice !='y')
			break;	//if choice is not, while loop will break
			 
		}
	}	
	cout << endl << endl;
	cout << "**********Here is the list of occupants**********" << endl;
	for (auto it = a_person.begin(); it !=a_person.end(); it++) 	//for loop to print out list of occupants
	{
		cout << "Name: " << it->first_name << ", room #: " << it->room << endl; //Name and room number
	}

	cout << "Would you like to delete a name? Y/N: "; 
	cin >> choice;
	while (choice =='y' || choice =='Y') //while loop to delete names
	{
		cout << "Enter name to delete: ";
		cin >> del; //string variable to pass into erase function

		erase(del, a_person); //see function below for definition

		cout << endl;
		cout << "**** an updated list of occupants **** " << endl;
	
		for (auto it = a_person.begin(); it !=a_person.end(); it++) //for loop to print out updated list after deletion
		{	
			cout << "Name: " << it-> first_name << ", room #: " << it-> room << endl;
		}
		cout << "Delete another name? Y/N: ";	//conditional choice to continue with name deletion
		cin >> choice;
	}
	
		cout << "Thank you, have a nice day! Terminating program now.... " << endl;
		cout << "*************************************************************" << endl;
return 0;
}

void erase(string name, vector<person>& a_person) //erase function, pass in string of name chosen, vector with name of struct and name in main
{
	for (int i=0; i!=a_person.size(); i++) //for loop to iterate through entire vector 
	{
		if (a_person[i].first_name == name) //conditional statement to find a match for the name passed in to delete and name in vector
		{
			a_person.erase(a_person.begin()+i, a_person.begin()+1+i); //if match found, .erase will erase that name
			break;
		}
	
	}

}	
