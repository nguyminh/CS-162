//Minh Nguyen
//Lab 7: Polymorphism
//Overriding virtual function 'rolLDice' in base class Dice, with a 'rollDice' function in derive class LoadedDice
//Produces new outcomes that favors the maximum number with a 50% chance of being rolled


#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

class Dice
{
public:
	Dice()
	{
		numSides = 6;
		srand(time(0));
	}

	Dice(int numSides)
	{
		this-> numSides = numSides;
		srand(time(0));
	}			


	virtual int rollDice() 
	{
		return (rand()% numSides)+1;
	}

protected:
int numSides;
};

class LoadedDice : public Dice
{
public:
	LoadedDice()
	{
	}

	LoadedDice(int numSides)
	{
		this->numSides = numSides;
		srand(time(0));
	}

	
	int rollDice() 
	{
		srand(time(0));
		temp = (rand()%2)+1;
		if (temp==2)
		return numSides;
		else
		return (rand()%numSides)+1;
				
	}
protected:
int temp;
};



int rollTwoDice(Dice& die1,Dice& die2)
{
	return die1.rollDice() + die2.rollDice();
}

int main()
{
	LoadedDice dice1(10);
	LoadedDice dice2(10);


	for (int i=1; i < 11; i++)
	{
		cout << "roll " << i << ": " << rollTwoDice(dice1, dice2) << endl;
		cin.get();
	}

	

return 0;
}
