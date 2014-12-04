#include <iostream>
#include <climits>
#include <cstdlib>
#include <cmath>
#include "f.h"
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

namespace gol
{
	void makeBoard()
	{
		const int col = 35;
		const int row = 90;
		const int j = 2;
		const int k = 2;
		int generations =0;
		int neighbor;
		char one_array[col][row];
		char two_array[col][row];
		
		for (int i=0; i < col; i++)
		{
			for (int g=0; g<row;g++)
			{
				one_array[i][g] = '-';
				two_array[i][g] = '-';
			}
		}

		//blinker
		one_array[10][19] = 'X';
		one_array[11][19] = 'X';
		one_array[12][19] = 'X';

		//toad
		one_array[10][8]='X';
		one_array[10][9]='X';
		one_array[10][10]='X';	
		one_array[9][7]='X';
		one_array[9][8]='X';
		one_array[9][9]='X';

		//behive
		one_array[25][55]='X';
		one_array[26][55]='X';
		one_array[27][56]='X';
		one_array[26][57]='X';
		one_array[25][57]='X';
		one_array[24][56]='X';


		//glider	
		one_array[25][50]='X';
		one_array[26][51]='X';
		one_array[27][49]='X';
		one_array[27][50]='X';
		one_array[27][51]='X';




	for (int i=2; i <(col-1); i++)
		{
			for (int g=2; g< row-1; g++)
			{
				cout << one_array[i][g];
			}
			cout << endl;
		}
	
	cout << endl << endl;
	cout << "Enter in generation amount: ";
	cin >> generations;


	for (int m=0; m <= generations; m++)
	{
		for (int i=2; i < (col-1);i++)
		{
		 	for (int g=2;g<(row-1);g++)
			{
				neighbor=0;

			if (one_array[i-1][g+1] == 'X')
				neighbor++;
			if (one_array[i][g+1] == 'X')
				neighbor++;
			if (one_array[i+1][g+1] == 'X')
				neighbor++;
			if (one_array[i-1][g] == 'X')
				neighbor++;
			if (one_array[i][g] == 'X')
				neighbor++;
			if (one_array[i+1][g] == 'X')
				neighbor++;
			if (one_array[i-1][g-1] == 'X')
				neighbor++;
			if (one_array[i][g-1] == 'X')
				neighbor++;
			if (one_array[i+1][g-1] == 'X')
				neighbor++;
	
			if (neighbor==3)
			two_array[i][g] = 'X';
			if (neighbor > 3 || neighbor < 2)
			two_array[i][g] = '-';
	
			cout << endl;
			}
		
		}
	
		for (int a=2;a<(col-1);a++)
		{
			for (int b=2;b < (row-1); b++)
			{
				one_array[a][b] = two_array[a][b];
				cout << two_array[a][b];
				two_array[a][b]='-';
			}
			cout << endl;
		}
	
		cout << "generation number: " << m << endl;
		cout << "Press enter key for the next generation.";
		std::cin.get();
	}	

	}	
}
