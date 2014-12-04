//Minh Nguyen
//Lab 6
//Create a derived Administrator class from the class SalariedEmployee from the book
//Allow input to administrators information such as salary and title
//Have a set function to change supervisor's name if needed


#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class Employee
{
public:
    Employee( ) : name("No name yet"), ssn("No number yet"), netPay(0)
    {
    }

    Employee(const string& theName, const string& theNumber)
       : name(theName), ssn(theNumber), netPay(0)
    {
    }

    string getName( ) const
    {
        return name;
    }

    string getSsn( ) const
    {
        return ssn;
    }

    double getNetPay( ) const
    {
        return netPay;
    }

   void setName(const string& newName)
    {
        name = newName;
    }

    void setSsn(const string& newSsn)
    {
        ssn = newSsn;
    }

    void setNetPay (double newNetPay)
    {
        netPay = newNetPay;
    }

    void printCheck( ) const
    {
        cout << "\nERROR: printCheck FUNCTION CALLED FOR AN \n"
             << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
             << "Check with the author of the program about this bug.\n";
        exit(1);
    }
protected:
string name;
string ssn;
double netPay;
};

class SalariedEmployee : public Employee
{
public:		
	SalariedEmployee() : Employee (), salary(0)
	{
	}

	SalariedEmployee (const string& theName, const string& theNumber,
				double theWeeklyPay)
				: Employee(theName, theNumber),
					 salary(theWeeklyPay)
	{


	}
	double getSalary()const
	{
		return salary;
	}
	
	void setSalary(double newSalary)
	{
		salary = newSalary;
	}



	void printcheck()
	{
		setNetPay(salary);
		cout << "Pay to the order of " << getName() << endl;
		cout << "The sum of " << getNetPay() << " Dollars" << endl;
		cout << "Check stub NOT NEGOTIABLE" << endl;
		cout << "Employee Number: " << getSsn() << endl;
		cout << "Salaried employee. Regular Pay: " << salary << endl;
	}


protected:
double salary;
};



class Administrator : public SalariedEmployee
{
public:
	Administrator () : SalariedEmployee()
	{
	}
	
		

	void setSupervisor(string superName)
	{
		supervisor = superName;
	}
	
	string getSupervisor()
	{
		return supervisor;
	}	

	string getArea()
	{
		return area;
	}

	string getTitle()
	{
		return title;
	}

		

	void input()
	{
		cout << "Please enter your name here : ";
		cin >> name;
		getName();	

		cout << "Enter title (VP or Director): ";
		cin >> title;
		getTitle();

		cout << "Enter in area of responsibility(Production, Accounting, or Personnel): ";
		cin >> area;
		getArea();
		
		cout << "Enter in your ssn: ";
		cin >> ssn;
		getSsn();
	
		cout << "Enter your Annual Salary: ";
		cin >> salary;
		getSalary();	

	}

	void print()
	{
		cout << "Name: " << getName() << endl;
		cout << "Title: " << getTitle() << endl;
		cout << "Area of responsibility: " << getArea() << endl;
	
	}
	 
	void printcheck()
	{
		cout << "_________________________________" << endl;
		cout << "Pay to the order of: " << getName() << endl;
		cout << "The sum of " << salary << " Dollars. " << endl;
		cout << "_________________________________" << endl;
		cout << "Check Stub: NOT NEGOTIABLE" << endl;
		cout << "Employee number: " << getSsn() << endl;
		cout << "Annual Salary Employee. " << endl; 	
	
	}
protected:
string title;
string area;
string supervisor;


};



int main()
{
	
	
	Administrator bob;
	bob.input();
	bob.print();	
	bob.printcheck();

return 0;
}
