//Minh Nguyen
//Lab 5 Problem 1
//Takes 2 input files with 5 integers in each input files, one being odd numbers 1-10, and one being even numberse 1-10
//Puts them into a third file called output.txt sorted from 1-10

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	//eclaring temp integer for conversion with stringstream
	int integer;
	int integer2;

	//declaring I/O files to variable
	ifstream fin1;
	ifstream fin2;
	ofstream fout;

	//declaring temp strings for getline
	string input1;
	string input2;	

	//declaring stringstream variables to conert to integer
	stringstream ss;
	stringstream ss2;

	//vector to hold integers
	vector<int> v;


	//connecting input and output files to program
	fin1.open("input1.txt"); 
	fin2.open("input2.txt");
	fout.open("output.txt");


	//2 while loops to extract integers from each input files
	while (getline(fin1, input1))
	{
		ss << input1;
		while(ss >> integer)
		{
			v.push_back(integer); //adds integer to vector here
		}
	}

	while (getline(fin2, input2)) 
	{
		ss2 << input2;
		while(ss2 >> integer2)
		{
			v.push_back(integer2);
		}
	}
		
	//sort function to sort vector from lowest to highest
	sort(v.begin(), v.end()); 

	//outputting to output.txt file the vector
	for (int i=0; i < v.size(); i++)
	{
		fout << v[i] << " ";
	}
	
	//prints to screen during testing phase
	for (int i=0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	cout << endl;	


	//closing streams
	fin1.close();
	fin2.close();
	fout.close();


return 0;
}
