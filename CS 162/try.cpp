#include <iostream>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

void blinker()
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


void toad()
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

		//toad
		one_array[10][8]='X';
		one_array[10][9]='X';
		one_array[10][10]='X';	
		one_array[9][7]='X';
		one_array[9][8]='X';
		one_array[9][9]='X';


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

void behive()
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

	//	beehive
		one_array[25][55]='X';
		one_array[26][55]='X';
		one_array[27][56]='X';
		one_array[26][57]='X';
		one_array[25][57]='X';
		one_array[24][56]='X';

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


void block()
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

		//block
		one_array[20][20]='X';
		one_array[20][21]='X';
		one_array[19][20]='X';
		one_array[19][21]='X';




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
	//		if (one_array[i][g] == 'X')
	//			neighbor++;
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


void clawk()
{
		const int col = 35;
		const int row = 90;
		const int a = 2;
		const int b = 2;
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

		//clock
		one_array[15][15]='X';
		one_array[16][16]='X';
		one_array[17][16]='X';
		one_array[14][17]='X';
		one_array[15][17]='X';
		one_array[16][18]='X';


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
		//	if (one_array[i][g] == 'X')
		//		neighbor++;
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

void aircraft_carrier()
{
		const int col = 35;
		const int row = 90;
		const int a = 2;
		const int b = 2;
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

		//aircraft carrier
		one_array[15][15]='X';
		one_array[15][16]='X';
		one_array[16][15]='X';
		one_array[16][18]='X';
		one_array[17][17]='X';
		one_array[17][18]='X';


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


void b_heptominos()
{
		const int col = 35;
		const int row = 90;
		const int a = 2;
		const int b = 2;
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

		//b-heptominos
		one_array[15][15]='X';
		one_array[16][15]='X';
		one_array[16][16]='X';
		one_array[17][16]='X';
		one_array[15][17]='X';
		one_array[16][17]='X';
		one_array[15][18]='X';

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





int main()
{
	int choice;
	cout << "************************************************************" << endl;
	cout << "Welcome to Minh Nguyen's version of Conway's game of life." << endl;
	cout << "Rules can be located on the internet." << endl;
	cout << "Without further adieu, let's begin." << endl;	
	cout << "Choose a configuration to see." << endl << endl << endl;
	cout << "************************************************************" << endl;
	cout << "#1 for the blinker.(oscillating)" << endl;
	cout << "#2 for the toad.(oscillating)" << endl;
	cout << "#3 for beehive(still)." << endl;
	cout << "#4 for the square block(still)." << endl;
	cout << "#5 for the clock.(oscillating)" << endl;
	cout << "#6 for the aircraft carrier. (still)" << endl;
	cout << "#7 for the B-heptominos. (oscillating)." << endl;
	cin  >> choice;


	switch (choice)
	{	
		case 1: {blinker(); break;}
		case 2: {toad(); break;}
		case 3: {behive(); break;}
		case 4: {block(); break;}
		case 5: {clawk(); break;}	
		case 6: {aircraft_carrier(); break;}
		case 7: {b_heptominos(); break;}


	}
return 0;
}
