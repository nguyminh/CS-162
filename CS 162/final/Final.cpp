//Minh Nguyen
//Final assignment
//Creature fighting game. Create 4 creature subclass with different attributes and set them up to fight each other using 
//a random number generator to produce attack and defense rolls. 

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <list>
#include <iterator>
#include <utility>

using namespace std;


class Monsters //Base class of monsters, mainly just for initiliaziing variables
{
public: 
	Monsters()
	{
	}

	virtual int getAttack()
	{
		return 0;
	}
	
	virtual int getStrength()
	{
		return 0;	
	}

	virtual int getArmor()
	{
		return 0;	
	}

	virtual int getDefense()
	{
		return 0;	
	}

	virtual int damage(int attack, int defense)
	{	
		return 0;
	}

	virtual string name1()
	{
		return 0;
	}

	virtual string name2()
	{
		return 0;
	}

protected:
int strength;
int armor;
int dice1;
int dice2;
int dice3;
int damageTaken;
string oneName;
string twoName;
};

class Goblin : public Monsters   //Goblin class
{
public:
	Goblin()
	{
	}
	

	string name1()
	{
		oneName = "Player one's Goblin";
		return oneName;
	}	

	string name2()
	{
		twoName = "Player two's Goblin";
		return twoName;
	}	

	//Goblin changed in this version, has magic shield that reduces all damage by half
	int damage(int attack, int defense)
	{
		damageTaken = (attack - defense) - getArmor();
		return damageTaken;

	}

	int getAttack()  //returns the random number added togehter by the dies to produce an attack number
	{	
		srand(time(0)); //srand for a true random number generator
		dice1 = 1+(rand()%6);
		dice2 = 1+(rand()%6);
		return dice1 + dice2;
	}
	

	int getDefense() // returns the random number from the dies to produce a defense number
	{
		dice1 = 1+(rand()%6);
		return dice1;
	}
		
	
	int getArmor() //set armor value. different for each creature
	{	
		armor = 3;
		return armor;
	}

	int getStrength() //set strength value. Different for each creature
	{
		strength = 8;
		return strength;
	}

};


//Damage taken overriden, 20% chance to take half damage
class Barbarian : public Monsters
{
public:
	Barbarian()
	{	
	}
	

	string name1()
	{
		oneName = "Player one's Barbarian";
		return oneName;
	}	

	string name2()
	{
		twoName = "Player two's Barbarian";
		return twoName;	
	}

	int damage(int attack, int defense)
	{
		srand(time(0));
		damageTaken = (attack - defense) - getArmor();
		return damageTaken;

	}

	int getAttack()
	{	
		srand(time(0));
		dice1 = 1+(rand()%6);
		dice2 = 1+(rand()%6);
		return dice1 + dice2;
	}
	

	int getDefense()
	{
		srand(time(0));
		dice1 = 1+(rand()%6);
		dice2 = 1+(rand()%6);
		return dice1 + dice2;
	}
		
	
	int getArmor()
	{
		armor = 0;
		return armor;
	}

	int getStrength()
	{
		strength = 12;
		return strength;
	}
};

class ReptilePeople : public Monsters
{
public:
	ReptilePeople()
	{
	}


	string name1()
	{
		oneName = "Player one's Reptile Man";
		return oneName;
	}	

	string name2()
	{
		twoName = "Player two's Reptile Man";
		return twoName;
	}

	int damage(int attack, int defense)
	{
		damageTaken = (attack - defense) - getArmor();
		return damageTaken;

	}


	int getAttack()
	{	
		srand(time(0));
		dice1 = 1+(rand()%6);
		dice2 = 1+(rand()%6);
		dice3 = 1+(rand()%6);
		return dice1 + dice2 + dice3;
	}
	

	int getDefense()
	{
		dice1 = 1+(rand()%6);
		return dice1;
	}
		
	
	int getArmor()
	{	
		armor = 7;
		return armor;
	}
	int getStrength()
	{
		strength = 18;
		return strength;
	}

};

//Blue men has damage taken virtual damage overriden with 25% chance to take 150% damage
class BlueMen : public Monsters
{
public:
	BlueMen()
	{
	}


	string name1()
	{
		oneName = "Player one's Blue Man";
		return oneName;	
	}	

	string name2()
	{
		twoName = "Player two's  Blue Man ";
		return twoName;	
	}
	
	int damage(int attack, int defense)
	{
		srand(time(0));
		dice3 = 1+(rand()%4);
		damageTaken = (attack - defense) - getArmor();
		if (dice3 == 1)
		return (damageTaken + (damageTaken/2));
		else
		return damageTaken;

	}


	int getAttack()
	{	
		srand(time(0));
		dice1 = 1+(rand()%10);
		dice2 = 1+(rand()%10);
		return dice1 + dice2;
	}
	

	int getDefense()
	{
		dice1 = 1+(rand()%6);
		dice2 = 1+(rand()%6);
		dice3 = 1+(rand()%6);
		return dice1 + dice2 + dice3;
	}
		
	
	int getArmor()
	{	
		armor = 3;
		return armor;
	}

	int getStrength()
	{
		strength = 12;
		return strength;
	}

};

//New sub class of blue men, defense is redefined for this sub class
class SadMen: public BlueMen
{
public:
	SadMen()
	{
	}

	
	string name1()
	{
		oneName = "Player one's Sad Man";
		return oneName;	
	}	

	string name2()
	{
		twoName = "Player two's Sad Man ";
		return twoName;	
	}

	int damage(int attack, int defense)
	{
		damageTaken = (attack - defense) - getArmor();
		return damageTaken;

	}


	int getAttack()
	{	
		srand(time(0));
		dice1 = 1+(rand()%10);
		dice2 = 1+(rand()%10);
		return dice1 + dice2;
	}
	

	int getDefense()
	{
		dice1 = 1+(rand()%6);
		dice2 = 1+(rand()%6);
		dice3 = 1+(rand()%6);
		return dice1 + dice2 + dice3;
	}
		
	
	int getArmor()
	{	
		armor = 3;
		return armor;
	}

	int getStrength()
	{
		strength = 12;
		return strength;
	}

};



int main()
{
	//choice to choose what 2 creatures to fight
	int choice11, choice12, choice13, choice21, choice22, choice23;	
	char ans;
	int attack1, attack2;
	int defense1, defense2;
	int strength1, strength2;
	int round = 0;

	vector<Monsters*> Player1;
	vector<Monsters*> Player2;
	vector<Monsters*> Losers;

	cout << "list of creatures to choose from: " << endl;
	cout << "1 = Goblin" << endl;
	cout << "2 = Barbarian" << endl;
	cout << "3 = Reptile person" << endl;
	cout << "4 = Blue person" << endl;
	cout << "5 = Sad man" << endl;


	cout << "Player 1, Choose your three creatures: ";
	cin >> choice11 >> choice12 >> choice13; 

	cout << "player 2, Chooase your three creatures: ";
	cin >> choice21 >> choice22 >> choice23;

	if (choice11 == 1)
	Player1.push_back(new Goblin());
	if (choice11 == 2) 
	Player1.push_back(new Barbarian());
	if (choice11 == 3) 
	Player1.push_back(new ReptilePeople());
	if (choice11 == 4) 
	Player1.push_back(new BlueMen());
	if (choice11 == 5) 
	Player1.push_back(new SadMen());
	if (choice12 == 1)
	Player1.push_back(new Goblin());
	if (choice12 == 2) 
	Player1.push_back(new Barbarian());
	if (choice12 == 3) 
	Player1.push_back(new ReptilePeople());
	if (choice12 == 4) 
	Player1.push_back(new BlueMen());
	if (choice12 == 5) 
	Player1.push_back(new SadMen());
	if (choice13 == 1)
	Player1.push_back(new Goblin());
	if (choice13 == 2) 
	Player1.push_back(new Barbarian());
	if (choice13 == 3) 
	Player1.push_back(new ReptilePeople());
	if (choice13 == 4) 
	Player1.push_back(new BlueMen());
	if (choice13 == 5) 
	Player1.push_back(new SadMen());

	if (choice21 == 1)
	Player2.push_back(new Goblin());
	if (choice21 == 2) 
	Player2.push_back(new Barbarian());
	if (choice21 == 3) 
	Player2.push_back(new ReptilePeople());
	if (choice21 == 4) 
	Player2.push_back(new BlueMen());
	if (choice21 == 5) 
	Player2.push_back(new SadMen());
	if (choice22 == 1)
	Player2.push_back(new Goblin());
	if (choice22 == 2) 
	Player2.push_back(new Barbarian());
	if (choice22 == 3) 
	Player2.push_back(new ReptilePeople());
	if (choice22 == 4) 
	Player2.push_back(new BlueMen());
	if (choice22 == 5) 
	Player2.push_back(new SadMen());
	if (choice23 == 1)
	Player2.push_back(new Goblin());
	if (choice23 == 2) 
	Player2.push_back(new Barbarian());
	if (choice23 == 3) 
	Player2.push_back(new ReptilePeople());
	if (choice23 == 4) 
	Player2.push_back(new BlueMen());
	if (choice23 == 5) 
	Player2.push_back(new SadMen());

{
	int attack1, attack2;   //Variable to declare the attack values of both creatures
	int defense1, defense2; //Variable to declare the defense values of both creature
	int strength1, strength2;   //variable to hold remaining strength value of both creatures
	int round=1;  //Variable to see how many turns it has been
	int damageTaken;

	strength1 = Player1[0]->getStrength();  //Setting up each players starting strength points
	strength2 = Player2[0]->getStrength();
		
	cout << "________________________________________________________________" << endl << endl;
	cout << "A fight between " << Player1[0]->name1() << " and " << Player2[0]->name2() << " is about to break out! " << endl << endl;

	cin.get(); //Needed or else it skips to Turn 2 for some reason
	
	cout << Player1[0]->name1() <<"'s starting strength point is: " << strength1 << endl;
	cout << Player2[0]->name2() <<"'s starting strength point is: " << strength2 << endl << endl;

	cout << Player1[0]->name1() << "'s armor value is: " << Player1[0]->getArmor() << endl;
	cout << Player2[0]->name2() << "'s armor value is: " << Player2[0]->getArmor() << endl << endl;

	cout << Player1[0]->name1() << " attacks first!" << endl << endl << endl << endl;

	while (strength1 > 0 || strength2 > 0)
{	
	//All the random numbers are rolled before any print statement, to assign values to variables
	Player1[0]->getAttack();
	Player1[0]->getDefense();
	Player2[0]->getAttack();
	Player2[0]->getDefense();
	attack1 = Player1[0]->getAttack();
	defense1 = Player2[0]->getDefense();

	cin.get();
	attack2 = Player2[0]->getAttack();
	defense2 = Player2[0]->getDefense();
	
	cout << "**********TURN " << round << "****************" << endl;

	cout << Player1[0]->name1() << "'s attack rolls a:  " << attack1 << endl;
	cout << Player2[0]->name2() << "'s defense rolls a:  " << defense2 << endl << endl;
		

	if (attack1 > defense2)
	{
		damageTaken = Player2[0]->damage(attack1, defense2);
		if (damageTaken > 0)
		{
			cout << Player1[0]->name1() << " does a total of:  " << damageTaken << " damage! " << endl; 
			cout << "********************" << endl << endl;
			strength2 = strength2 - damageTaken;
			if (strength2 <= 0)
			break;	
		}
		else
		{
			cout << Player1[0]->name1() << " Did not do enough damage to penetrate " << Player2[0]->name2() << "'s armor! " << endl;
		}
	}
	else
	{
		cout << Player1[0]->name1() << "'s attack was not powerful enough to get pass " << Player2[0]->name2() << "'s defense!" << endl;
		cout << Player2[0]->name2() << "'s turn to attack" << endl << endl;
	}

	cout << Player2[0]->name1() << "'s attack rolls a:  " << attack2 << endl;
	cout << Player1[0]->name2() <<"'s defense rolls a: " << defense1 << endl << endl;

	if (attack2 > defense1)
	{
		damageTaken = Player1[0]->damage(attack2, defense1);
		if (damageTaken > 0)
		{
			cout << Player2[0]->name2() << " does a total of: " << damageTaken << " damage! " << endl; 
			cout << "******************" << endl << endl;
			strength1 = strength1 - damageTaken;
			if (strength1 <= 0)
			break;	
		}
		else
		{
			cout << Player2[0]->name2() << " Did not do enough damage to penetrate " << Player1[0]->name1() << "'s armor! " << endl;
		}
	}
	else
	{
		cout << Player2[0]->name2() << "'s attack was not powerful enough to get pass " << Player1[0]->name1() << "'s defense!" << endl;
		cout << Player1[0]->name1() << "'s turn to attack" << endl << endl;
	}
	



	cout << endl;

	cout << Player1[0]->name1() << "'s remaining Strength Point: " << strength1 << endl;
	cout << Player2[0]->name2() << "'s remaining Strength Point: " << strength2 << endl << endl;	

	round = round++;

	cout << "Press enter for next attack turn" << endl;
	cout << "______________________________________________________________________________" << endl << endl;
	cin.get();
	
}

	if (strength1 <= 0)
	{	cout << Player1[0]->name1() << " DIES!" << endl;
		cout << Player2[0]->name2() << " is the winner with " << strength2 << " Strength Points remaining" << endl;
		Losers.push_back(Player1[0]);
	}
	
	if (strength2 <= 0)
	{
		cout << Player2[0]->name2() << " DIES!" << endl;
		cout << Player1[0]->name1() << " is the winner with " << strength1 << " Strength Points remaining" << endl << endl;
		Losers.push_back(Player2[0]);
	}



}
{
	 round=1;  //Variable to see how many turns it has been
	int damageTaken;

	strength1 = Player1[1]->getStrength();  //Setting up each players starting strength points
	strength2 = Player2[1]->getStrength();
		
	cout << "________________________________________________________________" << endl << endl;
	cout << "A fight between " << Player1[1]->name1() << " and " << Player2[1]->name2() << " is about to break out! " << endl << endl;

	cin.get(); //Needed or else it skips to Turn 2 for some reason
	
	cout << Player1[1]->name1() <<"'s starting strength point is: " << strength1 << endl;
	cout << Player2[1]->name2() <<"'s starting strength point is: " << strength2 << endl << endl;

	cout << Player1[1]->name1() << "'s armor value is: " << Player1[1]->getArmor() << endl;
	cout << Player2[1]->name2() << "'s armor value is: " << Player2[1]->getArmor() << endl << endl;

	cout << Player1[1]->name1() << " attacks first!" << endl << endl << endl << endl;

	while (strength1 > 0 || strength2 > 0)
{	
	//All the random numbers are rolled before any print statement, to assign values to variables
	Player1[1]->getAttack();
	Player1[1]->getDefense();
	Player2[1]->getAttack();
	Player2[1]->getDefense();
	attack1 = Player1[1]->getAttack();
	defense1 = Player2[1]->getDefense();

	cin.get();
	attack2 = Player2[1]->getAttack();
	defense2 = Player2[1]->getDefense();
	
	cout << "**********TURN " << round << "****************" << endl;

	cout << Player1[1]->name1() << "'s attack rolls a:  " << attack1 << endl;
	cout << Player2[1]->name2() << "'s defense rolls a:  " << defense2 << endl << endl;
		

	if (attack1 > defense2)
	{
		damageTaken = Player2[1]->damage(attack1, defense2);
		if (damageTaken > 0)
		{
			cout << Player1[1]->name1() << " does a total of:  " << damageTaken << " damage! " << endl; 
			cout << "********************" << endl << endl;
			strength2 = strength2 - damageTaken;
			if (strength2 <= 0)
			break;	
		}
		else
		{
			cout << Player1[1]->name1() << " Did not do enough damage to penetrate " << Player2[1]->name2() << "'s armor! " << endl;
		}
	}
	else
	{
		cout << Player1[1]->name1() << "'s attack was not powerful enough to get pass " << Player2[1]->name2() << "'s defense!" << endl;
		cout << Player2[1]->name2() << "'s turn to attack" << endl << endl;
	}

	cout << Player2[1]->name1() << "'s attack rolls a:  " << attack2 << endl;
	cout << Player1[1]->name2() <<"'s defense rolls a: " << defense1 << endl << endl;

	if (attack2 > defense1)
	{
		damageTaken = Player1[1]->damage(attack2, defense1);
		if (damageTaken > 0)
		{
			cout << Player2[1]->name2() << " does a total of: " << damageTaken << " damage! " << endl; 
			cout << "******************" << endl << endl;
			strength1 = strength1 - damageTaken;
			if (strength1 <= 0)
			break;	
		}
		else
		{
			cout << Player2[1]->name2() << " Did not do enough damage to penetrate " << Player1[1]->name1() << "'s armor! " << endl;
		}
	}
	else
	{
		cout << Player2[1]->name2() << "'s attack was not powerful enough to get pass " << Player1[1]->name1() << "'s defense!" << endl;
		cout << Player1[1]->name1() << "'s turn to attack" << endl << endl;
	}
	



	cout << endl;

	cout << Player1[1]->name1() << "'s remaining Strength Point: " << strength1 << endl;
	cout << Player2[1]->name2() << "'s remaining Strength Point: " << strength2 << endl << endl;	

	round = round++;

	cout << "Press enter for next attack turn" << endl;
	cout << "______________________________________________________________________________" << endl << endl;
	cin.get();
	
}

	if (strength1 <= 0)
	{	cout << Player1[1]->name1() << " DIES!" << endl;
		cout << Player2[1]->name2() << " is the winner with " << strength2 << " Strength Points remaining" << endl;
		Losers.push_back(Player1[1]);
	}
	
	if (strength2 <= 0)
	{
		cout << Player2[1]->name2() << " DIES!" << endl;
		cout << Player1[1]->name1() << " is the winner with " << strength1 << " Strength Points remaining" << endl << endl;
		Losers.push_back(Player2[1]);
	}



}
	cout << Player1[2]->name1() << endl;


{
	int damageTaken;

	strength1 = Player1[2]->getStrength();  //Setting up each players starting strength points
	strength2 = Player2[2]->getStrength();
		
	cout << "________________________________________________________________" << endl << endl;
	cout << "A fight between " << Player1[2]->name1() << " and " << Player2[2]->name2() << " is about to break out! " << endl << endl;

	cin.get(); //Needed or else it skips to Turn 2 for some reason
	
	cout << Player1[2]->name1() <<"'s starting strength point is: " << strength1 << endl;
	cout << Player2[2]->name2() <<"'s starting strength point is: " << strength2 << endl << endl;

	cout << Player1[2]->name1() << "'s armor value is: " << Player1[2]->getArmor() << endl;
	cout << Player2[2]->name2() << "'s armor value is: " << Player2[2]->getArmor() << endl << endl;

	cout << Player1[2]->name1() << " attacks first!" << endl << endl << endl << endl;

	while (strength1 > 0 || strength2 > 0)
{	
	//All the random numbers are rolled before any print statement, to assign values to variables
	Player1[2]->getAttack();
	Player1[2]->getDefense();
	Player2[2]->getAttack();
	Player2[2]->getDefense();
	attack1 = Player1[2]->getAttack();
	defense1 = Player2[2]->getDefense();

	cin.get();
	attack2 = Player2[2]->getAttack();
	defense2 = Player2[2]->getDefense();
	
	cout << "**********TURN " << round << "****************" << endl;

	cout << Player1[2]->name1() << "'s attack rolls a:  " << attack1 << endl;
	cout << Player2[2]->name2() << "'s defense rolls a:  " << defense2 << endl << endl;
		

	if (attack1 > defense2)
	{
		damageTaken = Player2[2]->damage(attack1, defense2);
		if (damageTaken > 0)
		{
			cout << Player1[2]->name1() << " does a total of:  " << damageTaken << " damage! " << endl; 
			cout << "********************" << endl << endl;
			strength2 = strength2 - damageTaken;
			if (strength2 <= 0)
			break;	
		}
		else
		{
			cout << Player1[2]->name1() << " Did not do enough damage to penetrate " << Player2[2]->name2() << "'s armor! " << endl;
		}
	}
	else
	{
		cout << Player1[2]->name1() << "'s attack was not powerful enough to get pass " << Player2[2]->name2() << "'s defense!" << endl;
		cout << Player2[2]->name2() << "'s turn to attack" << endl << endl;
	}

	cout << Player2[2]->name1() << "'s attack rolls a:  " << attack2 << endl;
	cout << Player1[2]->name2() <<"'s defense rolls a: " << defense1 << endl << endl;

	if (attack2 > defense1)
	{
		damageTaken = Player1[2]->damage(attack2, defense1);
		if (damageTaken > 0)
		{
			cout << Player2[2]->name2() << " does a total of: " << damageTaken << " damage! " << endl; 
			cout << "******************" << endl << endl;
			strength1 = strength1 - damageTaken;
			if (strength1 <= 0)
			break;	
		}
		else
		{
			cout << Player2[2]->name2() << " Did not do enough damage to penetrate " << Player1[2]->name1() << "'s armor! " << endl;
		}
	}
	else
	{
		cout << Player2[2]->name2() << "'s attack was not powerful enough to get pass " << Player1[2]->name1() << "'s defense!" << endl;
		cout << Player1[2]->name1() << "'s turn to attack" << endl << endl;
	}
	



	cout << endl;

	cout << Player1[2]->name1() << "'s remaining Strength Point: " << strength1 << endl;
	cout << Player2[2]->name2() << "'s remaining Strength Point: " << strength2 << endl << endl;	

	round = round++;

	cout << "Press enter for next attack turn" << endl;
	cout << "______________________________________________________________________________" << endl << endl;
	cin.get();
	
}

	if (strength1 <= 0)
	{	cout << Player1[2]->name1() << " DIES!" << endl;
		cout << Player2[2]->name2() << " is the winner with " << strength2 << " Strength Points remaining" << endl;
		Losers.push_back(Player1[2]);
	}
	
	if (strength2 <= 0)
	{
		cout << Player2[2]->name2() << " DIES!" << endl;
		cout << Player1[2]->name1() << " is the winner with " << strength1 << " Strength Points remaining" << endl << endl;
		Losers.push_back(Player2[2]);
	}



}

cout << endl  << endl << endl;
cout << "***********************************************************************************************" << endl;
cout << "In 6th place we have " << Losers[0]->name1() << endl;
cout << "In 5th place we have " << Losers[1]->name1() << endl;
cout << "In 4th place we have " << Losers[2]->name1() << endl;
cout << endl;
return 0;

}


