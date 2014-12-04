/*Minh Nguyen
 * Question 1, lab 3
 * User inputs inventory list with 5 detailed aspects
 * Output will display in a list name, color, age, price paid, and asking price of item
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>


using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;


class Inventory
{

public:
		//initialize variables for the class
	string ItemName;
	string ItemColor;
	int ItemAge;
	double AskingPrice;
	double PricePaid;


	Inventory()
	{
	}


	

private:

};


int main()
{	//initialize temporary variables to transfer to class
	string tempname;
	double tempask;
	string tempcolor;
	double temppaid;
	int tempage;
	vector<Inventory> list; //vector to add to inventory list
	Inventory names;
	int choice;
	char ans;
	
	cout << "Do you wish to enter in an inventory item? Y/N";
	cin >> ans;   //conditional statement to keep program looped

	while (ans=='y' || ans=='Y')
	{
		for (size_t i=0; i < 1000; i++) //loop to run entering in inventory. quit upon conditional statement at the end
		{	cout << "Enter name: ";
			cin >> tempname;
			names.ItemName = tempname;  //sets item name to the variable in the class
	
			cout << "Enter price: ";
			cin >> tempask; 
			names.AskingPrice = tempask; //sets asking price to the variable in the class

	
			cout << "Do you know the item color? Y/N "; 
			cin >> ans;

			if (ans =='y' || ans=='Y')  //conditional statement if knowledge of color is known
			{	
				cout << "Enter color here: ";
				cin >> tempcolor;
				names.ItemColor = tempcolor;
			}
	
			cout << "Do you know price paid? Y/N ";
			cin >> ans;
	
			if (ans =='y' || ans=='Y') //conditional statement if knowledge of price paid is known
			{
				cout << "Enter price paid: ";
				cin >> temppaid;
				names.PricePaid = temppaid;
			}
	
			cout << "Do you know the Item age? Y/N";
			cin >> ans;
			if (ans =='y' || ans=='Y')  //conditional statement if knowledge of age is known
			{
				cout << "Enter item age: ";
				cin >> tempage;
				names.ItemAge = tempage;
			}
		
			list.push_back(names); //adds to the vector
		
			cout << "DO you want to enter another inventory item? Y/N: ";
			cin >> ans;
			if (choice !='y' || choice !='Y') //conditional statement to add more items
			break;
		}
	}
		cout << endl << endl;
		cout << "Here is the inventory list" << endl << endl;
		cout << "______________________________________________________" << endl;
	for (auto it = list.begin(); it!=list.end(); it++) //displays items punched in
	{	
		cout << "Name of item: (" << it->ItemName << ") " << endl;
		cout << "Asking price: ($" << it->AskingPrice << ") " << endl;
		cout << "Item color: (" << it->ItemColor << ") " << endl;
		cout << "Price paid for item: ($" << it->PricePaid << ") " << endl;
		cout << "Item age: (" << it->ItemAge << " days old) " << endl;
		cout << "____________________________________________________" << endl;	
		cout << endl;
	}


return 0;
}
