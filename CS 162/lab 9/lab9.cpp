//Minh Nguyen
//Lab 9

#include <iostream>
using namespace std;

struct node
{
int number;
node *next;
};

bool empty(node *head)
{
	if (head == NULL)
	return true;
	else
	return false;
}

void first(node *&head, node *&last, int number)
{
	node *temp = new node;
	temp->number = number;
	temp->next = NULL;
	head = temp;
	last = temp;
}

void insert(node *&head, node *&last, int number)
{
	if(empty(head))
		first(head,last, number);
	
	else
	{
		node *temp = new node;
		temp->number = number;
		temp->next = NULL;
		last->next = temp;
		last = temp;	
	}
}

void remove(node *&head, node *&last)
{
	if(empty(head))
	cout << "empty" << endl;

	else if(head == last)
	{
		delete head;
		head == NULL;
		last == NULL;
	}
	else 
	{
		node *temp = head;
		head = head->next;
		delete temp;
	}

}


void print_out(node *print)
{	
	while (print != NULL)
	{
		cout << print->number << endl;
		print = print->next;
	}
}



int main()
{
	int choice, run;
	node *head = NULL;
	node *last = NULL;


	run = 1;
	cout << "Enter number of suitors: ";
	cin >> choice;

	while (run >= 0) 	
	{	
		if (run == 1)
		first(head, last, run);
		else
		insert(head, last, run);
	
		run++;
		if (run > choice)
		break;
	}
	
	for (int i = 1; i < choice; i++)
	remove(head,last);

	print_out(head);

	
return 0;
}
