//Minh Nguyen
//Assignment 3
//Creature fighting game. Create 4 creature subclass with different attributes and set them up to fight each other using 
//a random number generator to produce attack and defense rolls. 

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;


class Monsters //Base class of monsters, mainly just for initiliaziing variables
{
public: 
	Monsters()
	{
	}

protected:
int strength;
int armor;
int dice1;
int dice2;
int dice3;

};

class Goblin : public Monsters   //Goblin class
{
public:
	Goblin()
	{
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

class Barbarian : public Monsters
{
public:
	Barbarian()
	{	
	}

	int getAttack()
	{	
		dice1 = 1+(rand()%6);
		dice2 = 1+(rand()%6);
		return dice1 + dice2;
	}
	

	int getDefense()
	{
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

class BlueMen : public Monsters
{
public:
	BlueMen()
	{
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

//functions with similar aloghrithm for different fight set up's. 
void gobVbarb();
void gobVrep();
void gobVblue();
void barbVrep();
void barbVblue();
void repVblue();


//the self fighting functions have an extra pause in between rolls for different random numbers to generate
void gobVgob();
void barbVbarb();
void repVrep();
void blueVblue();

int main()
{
	//choice to choose what 2 creatures to fight
	int choice;	
	char ans;
	

//do while loop to allow user to watch game again if they choose so
do	
{	cout << endl;
	cout << "***********************************************************" << endl << endl;
	cout << "Welcome to Minh's COLISEUM!" << endl;
	cout << "Please choose what two creature classes you'd like to see fight!" << endl;
	cout << "Enter 1 for Goblin vs. Barbarian" << endl;
	cout << "Enter 2 for Goblin vs. Reptile man" << endl;
	cout << "Enter 3 for Goblin vs. Blue man" << endl;
	cout << "Enter 4 for Barbarian vs. Reptile man" << endl;
	cout << "Enter 5 for Barbarian vs. Blue man" << endl;
	cout << "Enter 6 for Reptile man vs. Blue man" << endl;
	cout << "Enter 7 for a fight between 2 colorful Goblins" << endl;
	cout << "Enter 8 for a fight between 2 Barbarian's name Jim and Bob" << endl;
	cout << "Enter 9 for a fight between 2 Reptile People named Nasus and Renekton" << endl;
	cout << "Enter 0 for a fight between 2 Blue men named Sad and Lonely" << endl;
	cin >> choice;

	//switch statement to let user decide what battle they want to see
	switch (choice)
	{
		case 1:	{ gobVbarb(); break; }	
		case 2: { gobVrep(); break; }
		case 3: { gobVblue(); break; }	
		case 4: { barbVrep(); break; }
		case 5: { barbVblue(); break; }	
		case 6: { repVblue(); break; }
		case 7: { gobVgob(); break; }
		case 8: { barbVbarb(); break;}
		case 9: { repVrep(); break;}
		case 0: { blueVblue(); break;}
	}
	cout << endl << endl << endl << endl;
	cout << "Would you like to run the program again? Y/N: ";
	cin >> ans;
}
while (ans=='y' || ans=='Y');

return 0;

}

void repVblue()
{
	//All of my objects are named either Gob or Barb, because I was too lazy to change it
	//But Gob simply is the first attacker, and Barb is always the second
	ReptilePeople Gob;   //Creating first attacker object to cooresponding class, in this case ReptilePeople
	BlueMen Barb;   //Creating second attacker oobject to corresponding class, in this case Blue Men
	int attack1, attack2;   //Variable to declare the attack values of both creatures
	int defense1, defense2; //Variable to declare the defense values of both creature
	int damage1, damage2; //Variable to declare overall damage done after armor of both creatures
	int strength1, strength2;   //variable to hold remaining strength value of both creatures
	int round=1;  //Variable to see how many turns it has been

	strength1 = Gob.getStrength();  //Setting up each players starting strength points
	strength2 = Barb.getStrength();
		
	cout << "________________________________________________________________" << endl << endl;
	cout << "A fight between a Blue man and a Reptile Man is about to break out! " << endl << endl;

	cin.get(); //Needed or else it skips to Turn 2 for some reason
	
	cout << "The Reptile Man's starting strength point is: " << strength1 << endl;
	cout << "The Blue Man's starting strength point is: " << strength2 << endl << endl;

	cout << "The Reptile Man's armor value is: " << Gob.getArmor() << endl;
	cout << "The Blue's armor value is: " << Barb.getArmor() << endl << endl;

	cout << "The Reptile Man's lizardness allows him to attack first!" << endl << endl << endl << endl;

	while (strength1 > 0 || strength2 > 0)
{	
	//All the random numbers are rolled before any print statement, to assign values to variables
	Gob.getAttack();
	Gob.getDefense();
	Barb.getAttack();
	Barb.getDefense();
	attack1 = Gob.getAttack();
	defense1 = Gob.getDefense();
	attack2 = Barb.getAttack();
	defense2 = Barb.getDefense();
	
	cout << "**********TURN " << round << "****************" << endl;

	cout << "Reptile Man's attack rolls a:  " << attack1 << endl;
	cout << "Blue Man's defense rolls a:  " << defense2 << endl << endl;
		

	if (attack1 > defense2)
	{
		cout << "Reptile Man's damage before armor: " << attack1 - defense2<< endl;
		damage1 = (attack1 - defense2) - Barb.getArmor(); //Damage is the true damage after armor
		cout << "Reptile Man's damage after applying opponent's armor:  " << damage1 << endl << endl;
		if (damage1 > 0)
		strength2 = strength2 - damage1;
		if (strength2 <= 0)
		break;
		
	}
	else
	{
		cout << "Reptile Man's attack was not powerful enough! " << endl;
		cout << "Blue Man's turn to attack" << endl << endl;
	}

	cout << "Blue Man's attack rolls a:  " << attack2 << endl;
	cout << "Reptile Man's defense rolls a: " << defense1 << endl << endl;

	if (attack2 > defense1)
	{
		cout << "Blue Man's damage before armor: " << attack2 - defense1 << endl;
		damage2 = (attack2 - defense1) - Gob.getArmor();
		cout << "Blue Man's damage after applying opponent's armor: " << damage2 << endl << endl;
		if (damage2 > 0)
		strength1 = strength1 - damage2;
		if (strength1 <= 0)
		break;
	}
	else
	{
		cout << "Blue Man's attack was not powerful enough, Reptile Man's turn to attack!" << endl << endl;
	}

	cout << endl;

	cout << "Reptile Man's remaining Strength Point: " << strength1 << endl;
	cout << "Blue Man's remaining Strength Point: " << strength2 << endl << endl;	

	round = round++;

	cout << "Press enter for next attack turn" << endl;
	cout << "______________________________________________________________________________" << endl << endl;
	cin.get();
	
}

	if (strength1 <= 0)
	{	cout << "Reptile Man DIES!" << endl;
		cout << "Blue Man is the winner with " << strength2 << " Strength Points remaining" << endl;
	}
	
	if (strength2 <= 0)
	{
		cout << "Blue Man DIES!" << endl;
		cout << "Reptile Man is the winner with " << strength1 << " Strength Points remaining" << endl << endl;
	}



}

void blueVblue()
{
	BlueMen Gob;
	BlueMen Barb;
	int attack1, attack2;
	int defense1, defense2;
	int damage1, damage2;
	int strength1, strength2;
	int round=1;

	strength1 = Gob.getStrength();
	strength2 = Barb.getStrength();
		
	cout << "________________________________________________________________" << endl << endl;
	cout << "A fight between 2 Blue men named Sad and Lonely is about to break out! " << endl << endl;


	cin.get();
	
	cout << "Sad's starting strength point is: " << strength1 << endl;
	cout << "Lonely's starting strength point is: " << strength2 << endl << endl;

	cout << "Sad's armor value is: " << Gob.getArmor() << endl;
	cout << "Lonely's armor value is: " << Barb.getArmor() << endl << endl;

	cout << "Sad's uncontrollable mood swings allows him to attack first!" << endl << endl << endl << endl;

	while (strength1 > 0 || strength2 > 0)
{	
	Gob.getAttack();
	Gob.getDefense();
	Barb.getAttack();
	Barb.getDefense();
	attack1 = Gob.getAttack();
	defense1 = Gob.getDefense();

	cout << "Please wait at least 1 second before pressing Enter to continue: ";
	cin.get();

	attack2 = Barb.getAttack();
	defense2 = Barb.getDefense();
	
	cout << "**********TURN " << round << "****************" << endl;

	cout << "Sad's attack rolls a:  " << attack1 << endl;
	cout << "Lonely's defense rolls a:  " << defense2 << endl << endl;
		

	if (attack1 > defense2)
	{
		cout << "Sad's damage before armor: " << attack1 - defense2<< endl;
		damage1 = (attack1 - defense2) - Barb.getArmor();
		cout << "Sad's damage after applying opponent's armor:  " << damage1 << endl << endl;
		if (damage1 > 0)
		strength2 = strength2 - damage1;
		if (strength2 <= 0)
		break;
		
	}
	else
	{
		cout << "Sad's attack was not powerful enough! " << endl;
		cout << "Lonely's turn to attack" << endl << endl;
	}

	cout << "Lonely's attack rolls a:  " << attack2 << endl;
	cout << "Sad's defense rolls a: " << defense1 << endl << endl;

	if (attack2 > defense1)
	{
		cout << "Lonely's damage before armor: " << attack2 - defense1 << endl;
		damage2 = (attack2 - defense1) - Gob.getArmor();
		cout << "Lonely's damage after applying opponent's armor: " << damage2 << endl << endl;
		if (damage2 > 0)
		strength1 = strength1 - damage2;
		if (strength1 <= 0)
		break;
	}
	else
	{
		cout << "Lonely's attack was not powerful enough, Sad's turn to attack!" << endl << endl;
	}

	cout << endl;

	cout << "Sad's remaining Strength Point: " << strength1 << endl;
	cout << "Lonely's remaining Strength Point: " << strength2 << endl << endl;	

	round = round++;

	cout << "Press enter for next attack turn" << endl;
	cout << "______________________________________________________________________________" << endl << endl;
	cin.get();
	
}

	if (strength1 <= 0)
	{	cout << "Sad DIES!" << endl;
		cout << "Lonely is the winner with " << strength2 << " Strength Points remaining" << endl;
	}
	
	if (strength2 <= 0)
	{
		cout << "Lonely DIES!" << endl;
		cout << "Sad is the winner with " << strength1 << " Strength Points remaining" << endl << endl;
	}


}


void repVrep()
{
	ReptilePeople Gob;
	ReptilePeople Barb;
	int attack1, attack2;
	int defense1, defense2;
	int damage1, damage2;
	int strength1, strength2;
	int round=1;

	strength1 = Gob.getStrength();
	strength2 = Barb.getStrength();
		
	cout << "________________________________________________________________" << endl << endl;
	cout << "A fight between 2 Reptile People named Nasus and Renekton is about to break out! " << endl << endl;

	cin.get();
	
	cout << "Nasus' starting strength point is: " << strength1 << endl;
	cout << "Renekton's starting strength point is: " << strength2 << endl << endl;

	cout << "Nasus' armor value is: " << Gob.getArmor() << endl;
	cout << "Renekton's armor value is: " << Barb.getArmor() << endl << endl;

	cout << "Nasus' nimbleness allows him to strike first!" << endl << endl << endl << endl;

	while (strength1 > 0 || strength2 > 0)
{	
	Gob.getAttack();
	Gob.getDefense();
	Barb.getAttack();
	Barb.getDefense();
	attack1 = Gob.getAttack();
	defense1 = Gob.getDefense();

	cout << "Please at least 1 second before pressing Enter to continue: ";
	cin.get();

	attack2 = Barb.getAttack();
	defense2 = Barb.getDefense();
	
	cout << "**********TURN " << round << "****************" << endl;

	cout << "Nasus' attack rolls a:  " << attack1 << endl;
	cout << "Renekton's defense rolls a:  " << defense2 << endl << endl;
		

	if (attack1 > defense2)
	{
		cout << "Nasus' damage before armor: " << attack1 - defense2<< endl;
		damage1 = (attack1 - defense2) - Barb.getArmor();
		cout << "Nasus' damage after applying opponent's armor:  " << damage1 << endl << endl;
		if (damage1 > 0)
		strength2 = strength2 - damage1;
		if (strength2 <= 0)
		break;
		
	}
	else
	{
		cout << "Nasus' attack was not powerful enough! " << endl;
		cout << "Renekton's turn to attack" << endl << endl;
	}

	cout << "Renekton's attack rolls a:  " << attack2 << endl;
	cout << "Nasus' defense rolls a: " << defense1 << endl << endl;

	if (attack2 > defense1)
	{
		cout << "Renekton's damage before armor: " << attack2 - defense1 << endl;
		damage2 = (attack2 - defense1) - Gob.getArmor();
		cout << "Renekton's damage after applying opponent's armor: " << damage2 << endl << endl;
		if (damage2 > 0)
		strength1 = strength1 - damage2;
		if (strength1 <= 0)
		break;
	}
	else
	{
		cout << "Renekton's attack was not powerful enough, Nasus' turn to attack!" << endl << endl;
	}

	cout << endl;

	cout << "Nasus' remaining Strength Point: " << strength1 << endl;
	cout << "Renekton's remaining Strength Point: " << strength2 << endl << endl;	

	round = round++;

	cout << "Press enter for next attack turn" << endl;
	cout << "______________________________________________________________________________" << endl << endl;
	cin.get();
	
}

	if (strength1 <= 0)
	{	cout << "Nasus DIES!" << endl;
		cout << "Renekton is the winner with " << strength2 << " Strength Points remaining" << endl;
	}
	
	if (strength2 <= 0)
	{
		cout << "Renekton DIES!" << endl;
		cout << "Nasus is the winner with " << strength1 << " Strength Points remaining" << endl << endl;
	}


}


void barbVbarb()
{
	Barbarian Gob;
	Barbarian Barb;
	int attack1, attack2;
	int defense1, defense2;
	int damage1, damage2;
	int strength1, strength2;
	int round=1;

	strength1 = Gob.getStrength();
	strength2 = Barb.getStrength();
		
	cout << "________________________________________________________________" << endl << endl;
	cout << "A fight between Jim the barbarian, and Bob the Barbarian about to break out! " << endl << endl;

	cin.get();
	
	cout << "Jim's starting strength point is: " << strength1 << endl;
	cout << "Bob's starting strength point is: " << strength2 << endl << endl;

	cout << "Jim's armor value is: " << Gob.getArmor() << endl;
	cout << "Bob's armor value is: " << Barb.getArmor() << endl << endl;

	cout << "Jim's unique name allows him to attack first!" << endl << endl << endl << endl;

	while (strength1 > 0 || strength2 > 0)
{	
	Gob.getAttack();
	Gob.getDefense();
	Barb.getAttack();
	Barb.getDefense();
	attack1 = Gob.getAttack();
	defense1 = Gob.getDefense();

	cout << "Please wait at least 1 second before pressing Enter to continue: ";
	cin.get();

	attack2 = Barb.getAttack();
	defense2 = Barb.getDefense();
	
	cout << "**********TURN " << round << "****************" << endl;

	cout << "Jim's attack rolls a:  " << attack1 << endl;
	cout << "Bob's defense rolls a:  " << defense2 << endl << endl;
		

	if (attack1 > defense2)
	{
		cout << "Jim's damage before armor: " << attack1 - defense2<< endl;
		damage1 = (attack1 - defense2) - Barb.getArmor();
		cout << "Jim's damage after applying opponent's armor:  " << damage1 << endl << endl;
		if (damage1 > 0)
		strength2 = strength2 - damage1;
		if (strength2 <= 0)
		break;
		
	}
	else
	{
		cout << "Jim's attack was not powerful enough! " << endl;
		cout << "Bob's turn to attack" << endl << endl;
	}

	cout << "Bob's attack rolls a:  " << attack2 << endl;
	cout << "Jim's defense rolls a: " << defense1 << endl << endl;

	if (attack2 > defense1)
	{
		cout << "Bob's damage before armor: " << attack2 - defense1 << endl;
		damage2 = (attack2 - defense1) - Gob.getArmor();
		cout << "Bob's damage after applying opponent's armor: " << damage2 << endl << endl;
		if (damage2 > 0)
		strength1 = strength1 - damage2;
		if (strength1 <= 0)
		break;
	}
	else
	{
		cout << "Bob's attack was not powerful enough, Jim's turn to attack!" << endl << endl;
	}

	cout << endl;

	cout << "Jim's remaining Strength Point: " << strength1 << endl;
	cout << "Bob's remaining Strength Point: " << strength2 << endl << endl;	

	round = round++;

	cout << "Press enter for next attack turn" << endl;
	cout << "______________________________________________________________________________" << endl << endl;
	cin.get();
	
}

	if (strength1 <= 0)
	{	cout << "Jim DIES!" << endl;
		cout << "Bob is the winner with " << strength2 << " Strength Points remaining" << endl;
	}
	
	if (strength2 <= 0)
	{
		cout << "Bob DIES!" << endl;
		cout << "Jim is the winner with " << strength1 << " Strength Points remaining" << endl << endl;
	}


}





void gobVgob()
{
	Goblin Gob;
	Goblin Barb;
	int attack1, attack2;
	int defense1, defense2;
	int damage1, damage2;
	int strength1, strength2;
	int round=1;

	strength1 = Gob.getStrength();
	strength2 = Barb.getStrength();
		
	cout << "________________________________________________________________" << endl << endl;
	cout << "A fight between a red Goblin and an orange Goblin is about to break out! " << endl << endl;

	cin.get();
	
	cout << "The blue Goblin's starting strength point is: " << strength1 << endl;
	cout << "The orange Goblin's starting strength point is: " << strength2 << endl << endl;

	cout << "The blue Goblin's armor value is: " << Gob.getArmor() << endl;
	cout << "The orange Goblin's armor value is: " << Barb.getArmor() << endl << endl;

	cout << "The blue Goblin attacks first because blue is better than orange!!" << endl << endl << endl << endl;

	while (strength1 > 0 || strength2 > 0)
{	
	Gob.getAttack();
	Gob.getDefense();
	Barb.getAttack();
	Barb.getDefense();
	attack1 = Gob.getAttack();
	defense1 = Gob.getDefense();

	cout << "Please wait at least 1 second before pressing Enter to continue: ";
	cin.get();

	attack2 = Barb.getAttack();
	defense2 = Barb.getDefense();
	
	cout << "**********TURN " << round << "****************" << endl;

	cout << "blue Goblin's attack rolls a:  " << attack1 << endl;
	cout << "orange Goblin's defense rolls a:  " << defense2 << endl << endl;
		

	if (attack1 > defense2)
	{
		cout << "blue Goblins damage before armor: " << attack1 - defense2<< endl;
		damage1 = (attack1 - defense2) - Barb.getArmor();
		cout << "blue Goblin's damage after applying opponent's armor:  " << damage1 << endl << endl;
		if (damage1 > 0)
		strength2 = strength2 - damage1;
		if (strength2 <= 0)
		break;
		
	}
	else
	{
		cout << "blue Goblin's attack was not powerful enough! " << endl;
		cout << "orange Goblin's turn to attack" << endl << endl;
	}

	cout << "orange Goblin's attack rolls a:  " << attack2 << endl;
	cout << "blue Goblin's defense rolls a: " << defense1 << endl << endl;

	if (attack2 > defense1)
	{
		cout << "orange Goblin's damage before armor: " << attack2 - defense1 << endl;
		damage2 = (attack2 - defense1) - Gob.getArmor();
		cout << "orange Goblin's damage after applying opponent's armor: " << damage2 << endl << endl;
		if (damage2 > 0)
		strength1 = strength1 - damage2;
		if (strength1 <= 0)
		break;
	}
	else
	{
		cout << "orange Goblin's attack was not powerful enough, blue Goblin's turn to attack!" << endl << endl;
	}

	cout << endl;

	cout << "blue Goblin's remaining Strength Point: " << strength1 << endl;
	cout << "orange Goblin's remaining Strength Point: " << strength2 << endl << endl;	

	round = round++;

	cout << "Press enter for next attack turn" << endl;
	cout << "______________________________________________________________________________" << endl << endl;
	cin.get();
	
}

	if (strength1 <= 0)
	{	cout << "blue Goblin DIES!" << endl;
		cout << "orange Goblin is the winner with " << strength2 << " Strength Points remaining" << endl;
	}
	
	if (strength2 <= 0)
	{
		cout << "orange Goblin DIES!" << endl;
		cout << "blue Goblin is the winner with " << strength1 << " Strength Points remaining" << endl << endl;
	}


}




void barbVblue()
{
	Barbarian Gob;
	BlueMen Barb;
	int attack1, attack2;
	int defense1, defense2;
	int damage1, damage2;
	int strength1, strength2;
	int round=1;

	strength1 = Gob.getStrength();
	strength2 = Barb.getStrength();
		
	cout << "________________________________________________________________" << endl << endl;
	cout << "A fight between a Blue man and a Barbarian is about to break out! " << endl << endl;

	cin.get();
	
	cout << "The Barbarian's starting strength point is: " << strength1 << endl;
	cout << "The Blue Man's starting strength point is: " << strength2 << endl << endl;

	cout << "The Barbarian's armor value is: " << Gob.getArmor() << endl;
	cout << "The Blue's armor value is: " << Barb.getArmor() << endl << endl;

	cout << "The Barbarian's lesser armor weight allows him to attack first!" << endl << endl << endl << endl;

	while (strength1 > 0 || strength2 > 0)
{	
	Gob.getAttack();
	Gob.getDefense();
	Barb.getAttack();
	Barb.getDefense();
	attack1 = Gob.getAttack();
	defense1 = Gob.getDefense();
	attack2 = Barb.getAttack();
	defense2 = Barb.getDefense();
	
	cout << "**********TURN " << round << "****************" << endl;

	cout << "Barbarian's attack rolls a:  " << attack1 << endl;
	cout << "Blue Man's defense rolls a:  " << defense2 << endl << endl;
		

	if (attack1 > defense2)
	{
		cout << "Barbarian's damage before armor: " << attack1 - defense2<< endl;
		damage1 = (attack1 - defense2) - Barb.getArmor();
		cout << "Barbarian's damage after applying opponent's armor:  " << damage1 << endl << endl;
		if (damage1 > 0)
		strength2 = strength2 - damage1;
		if (strength2 <= 0)
		break;
		
	}
	else
	{
		cout << "Barbarian's attack was not powerful enough! " << endl;
		cout << "Blue Man's turn to attack" << endl << endl;
	}

	cout << "Blue Man's attack rolls a:  " << attack2 << endl;
	cout << "Barbarian's defense rolls a: " << defense1 << endl << endl;

	if (attack2 > defense1)
	{
		cout << "Blue Man's damage before armor: " << attack2 - defense1 << endl;
		damage2 = (attack2 - defense1) - Gob.getArmor();
		cout << "Blue Man's damage after applying opponent's armor: " << damage2 << endl << endl;
		if (damage2 > 0)
		strength1 = strength1 - damage2;
		if (strength1 <= 0)
		break;
	}
	else
	{
		cout << "Blue Man's attack was not powerful enough, Barbarian's turn to attack!" << endl << endl;
	}

	cout << endl;

	cout << "Barbarian's remaining Strength Point: " << strength1 << endl;
	cout << "Blue Man's remaining Strength Point: " << strength2 << endl << endl;	

	round = round++;

	cout << "Press enter for next attack turn" << endl;
	cout << "______________________________________________________________________________" << endl << endl;
	cin.get();
	
}

	if (strength1 <= 0)
	{	cout << "Barbarian DIES!" << endl;
		cout << "Blue Man is the winner with " << strength2 << " Strength Points remaining" << endl;
	}
	
	if (strength2 <= 0)
	{
		cout << "Blue Man DIES!" << endl;
		cout << "Barbarian is the winner with " << strength1 << " Strength Points remaining" << endl << endl;
	}


}

void barbVrep()
{

	Barbarian Gob;
	ReptilePeople Barb;
	int attack1, attack2;
	int defense1, defense2;
	int damage1, damage2;
	int strength1, strength2;
	int round=1;

	strength1 = Gob.getStrength();
	strength2 = Barb.getStrength();
		
	cout << "________________________________________________________________" << endl << endl;
	cout << "A fight between a Reptile man and a Barbarian is about to break out! " << endl << endl;

	cin.get();
	
	cout << "The Barbarian's starting strength point is: " << strength1 << endl;
	cout << "The Reptile Man's starting strength point is: " << strength2 << endl << endl;

	cout << "The Barbarian's armor value is: " << Gob.getArmor() << endl;
	cout << "The Reptileman's armor value is: " << Barb.getArmor() << endl << endl;

	cout << "The Barbarian's lesser armor weight allows him to attack first!" << endl << endl << endl << endl;

	while (strength1 > 0 || strength2 > 0)
{	
	Gob.getAttack();
	Gob.getDefense();
	Barb.getAttack();
	Barb.getDefense();
	attack1 = Gob.getAttack();
	defense1 = Gob.getDefense();
	attack2 = Barb.getAttack();
	defense2 = Barb.getDefense();
	
	cout << "**********TURN " << round << "****************" << endl;

	cout << "Barbarian's attack rolls a:  " << attack1 << endl;
	cout << "Reptile Man's defense rolls a:  " << defense2 << endl << endl;
		

	if (attack1 > defense2)
	{
		cout << "Barbarian's damage before armor: " << attack1 - defense2<< endl;
		damage1 = (attack1 - defense2) - Barb.getArmor();
		cout << "Barbarian's damage after applying opponent's armor:  " << damage1 << endl << endl;
		if (damage1 > 0)
		strength2 = strength2 - damage1;
		if (strength2 <= 0)
		break;
		
	}
	else
	{
		cout << "Barbarian's attack was not powerful enough! " << endl;
		cout << "Reptile Man's turn to attack" << endl << endl;
	}

	cout << "Reptile Man's attack rolls a:  " << attack2 << endl;
	cout << "Barbarian's defense rolls a: " << defense1 << endl << endl;

	if (attack2 > defense1)
	{
		cout << "Reptile Man's damage before armor: " << attack2 - defense1 << endl;
		damage2 = (attack2 - defense1) - Gob.getArmor();
		cout << "Reptile Man's damage after applying opponent's armor: " << damage2 << endl << endl;
		if (damage2 > 0)
		strength1 = strength1 - damage2;
		if (strength1 <= 0)
		break;
	}
	else
	{
		cout << "Reptile Man's attack was not powerful enough, Barbarian's turn to attack!" << endl << endl;
	}

	cout << endl;

	cout << "Barbarian's remaining Strength Point: " << strength1 << endl;
	cout << "Reptile Man's remaining Strength Point: " << strength2 << endl << endl;	

	round = round++;

	cout << "Press enter for next attack turn" << endl;
	cout << "______________________________________________________________________________" << endl << endl;
	cin.get();
	
}

	if (strength1 <= 0)
	{	cout << "Barbarian DIES!" << endl;
		cout << "Reptile Man is the winner with " << strength2 << " Strength Points remaining" << endl;
	}
	
	if (strength2 <= 0)
	{
		cout << "Reptile Man DIES!" << endl;
		cout << "Barbarian is the winner with " << strength1 << " Strength Points remaining" << endl << endl;
	}



}


void gobVblue()
{
	Goblin Gob;
	BlueMen Barb;
	int attack1, attack2;
	int defense1, defense2;
	int damage1, damage2;
	int strength1, strength2;
	int round=1;

	strength1 = Gob.getStrength();
	strength2 = Barb.getStrength();
		
	cout << "________________________________________________________________" << endl << endl;
	cout << "A fight between a Goblin and a Blue Man is about to break out! " << endl << endl;

	cin.get();
	
	cout << "The Goblin's starting strength point is: " << strength1 << endl;
	cout << "The Blue Man's starting strength point is: " << strength2 << endl << endl;

	cout << "The Goblin's armor value is: " << Gob.getArmor() << endl;
	cout << "The Blue Man's armor value is: " << Barb.getArmor() << endl << endl;

	cout << "The Goblin's swiftness allows him to attack first!" << endl << endl << endl << endl;

	while (strength1 > 0 || strength2 > 0)
{	
	Gob.getAttack();
	Gob.getDefense();
	Barb.getAttack();
	Barb.getDefense();
	attack1 = Gob.getAttack();
	defense1 = Gob.getDefense();
	attack2 = Barb.getAttack();
	defense2 = Barb.getDefense();
	
	cout << "**********TURN " << round << "****************" << endl;

	cout << "Goblin's attack rolls a:  " << attack1 << endl;
	cout << "Blue Man's defense rolls a:  " << defense2 << endl << endl;
		

	if (attack1 > defense2)
	{
		cout << "Goblins damage before armor: " << attack1 - defense2<< endl;
		damage1 = (attack1 - defense2) - Barb.getArmor();
		cout << "Goblin's damage after applying opponent's armor:  " << damage1 << endl << endl;
		if (damage1 > 0)
		strength2 = strength2 - damage1;
		if (strength2 <= 0)
		break;
		
	}
	else
	{
		cout << "Goblin's attack was not powerful enough! " << endl;
		cout << "Blue Man's turn to attack" << endl << endl;
	}

	cout << "Blue Man's attack rolls a:  " << attack2 << endl;
	cout << "Goblin's defense rolls a: " << defense1 << endl << endl;

	if (attack2 > defense1)
	{
		cout << "Blue Man's damage before armor: " << attack2 - defense1 << endl;
		damage2 = (attack2 - defense1) - Gob.getArmor();
		cout << "Blue Man's damage after applying opponent's armor: " << damage2 << endl << endl;
		if (damage2 > 0)
		strength1 = strength1 - damage2;
		if (strength1 <= 0)
		break;
	}
	else
	{
		cout << "Blue Man's attack was not powerful enough, Goblin's turn to attack!" << endl << endl;
	}

	cout << endl;

	cout << "Goblin's remaining Strength Point: " << strength1 << endl;
	cout << "Blue Man's remaining Strength Point: " << strength2 << endl << endl;	

	round = round++;

	cout << "Press enter for next attack turn" << endl;
	cout << "______________________________________________________________________________" << endl << endl;
	cin.get();
	
}

	if (strength1 <= 0)
	{	cout << "Goblin DIES!" << endl;
		cout << "Blue Man is the winner with " << strength2 << " Strength Points remaining" << endl;
	}
	
	if (strength2 <= 0)
	{
		cout << "Blue Man DIES!" << endl;
		cout << "Goblin is the winner with " << strength1 << " Strength Points remaining" << endl << endl;
	}


}


void gobVrep()
{
	Goblin Gob;
	ReptilePeople Barb;
	int attack1, attack2;
	int defense1, defense2;
	int damage1, damage2;
	int strength1, strength2;
	int round=1;

	strength1 = Gob.getStrength();
	strength2 = Barb.getStrength();
		
	cout << "________________________________________________________________" << endl << endl;
	cout << "A fight between a Goblin and a Reptile Man is about to break out! " << endl << endl;

	cin.get();
	
	cout << "The Goblin's starting strength point is: " << strength1 << endl;
	cout << "The Reptile Man's starting strength point is: " << strength2 << endl << endl;

	cout << "The Goblin's armor value is: " << Gob.getArmor() << endl;
	cout << "The Reptile Man's armor value is: " << Barb.getArmor() << endl << endl;

	cout << "The Goblin's swiftness allows him to attack first!" << endl << endl << endl << endl;

	while (strength1 > 0 || strength2 > 0)
{	
	Gob.getAttack();
	Gob.getDefense();
	Barb.getAttack();
	Barb.getDefense();
	attack1 = Gob.getAttack();
	defense1 = Gob.getDefense();
	attack2 = Barb.getAttack();
	defense2 = Barb.getDefense();
	
	cout << "**********TURN " << round << "****************" << endl;

	cout << "Goblin's attack rolls a:  " << attack1 << endl;
	cout << "Reptile Man's defense rolls a:  " << defense2 << endl << endl;
		

	if (attack1 > defense2)
	{
		cout << "Goblins damage before armor: " << attack1 - defense2<< endl;
		damage1 = (attack1 - defense2) - Barb.getArmor();
		cout << "Goblin's damage after applying opponent's armor:  " << damage1 << endl << endl;
		if (damage1 > 0)
		strength2 = strength2 - damage1;
		if (strength2 <= 0)
		break;
		
	}
	else
	{
		cout << "Goblin's attack was not powerful enough! " << endl;
		cout << "Reptile Man's turn to attack" << endl << endl;
	}

	cout << "Reptile Man's attack rolls a:  " << attack2 << endl;
	cout << "Goblin's defense rolls a: " << defense1 << endl << endl;

	if (attack2 > defense1)
	{
		cout << "Reptile Man's damage before armor: " << attack2 - defense1 << endl;
		damage2 = (attack2 - defense1) - Gob.getArmor();
		cout << "Reptile Man's damage after applying opponent's armor: " << damage2 << endl << endl;
		if (damage2 > 0)
		strength1 = strength1 - damage2;
		if (strength1 <= 0)
		break;
	}
	else
	{
		cout << "Reptile Man's attack was not powerful enough, Goblin's turn to attack!" << endl << endl;
	}

	cout << endl;

	cout << "Goblin's remaining Strength Point: " << strength1 << endl;
	cout << "Reptile Man's remaining Strength Point: " << strength2 << endl << endl;	

	round = round++;

	cout << "Press enter for next attack turn" << endl;
	cout << "______________________________________________________________________________" << endl << endl;
	cin.get();
	
}

	if (strength1 <= 0)
	{	cout << "Goblin DIES!" << endl;
		cout << "Reptile Man is the winner with " << strength2 << " Strength Points remaining" << endl;
	}
	
	if (strength2 <= 0)
	{
		cout << "Reptile Man DIES!" << endl;
		cout << "Goblin is the winner with " << strength1 << " Strength Points remaining" << endl << endl;
	}


}


void gobVbarb()
{
	Goblin Gob;
	Barbarian Barb;
	int attack1, attack2;
	int defense1, defense2;
	int damage1, damage2;
	int strength1, strength2;
	int round=1;
	
	strength1 = Gob.getStrength();
	strength2 = Barb.getStrength();
		
	cout << "________________________________________________________________" << endl << endl;
	cout << "A fight between a Goblin and a Barbarian is about to break out! " << endl << endl;

	cin.get();	
	
	cout << "The Goblin's starting strength point is: " << strength1 << endl;
	cout << "The Barbarian's starting strength point is: " << strength2 << endl << endl;

	cout << "The Goblin's armor value is: " << Gob.getArmor() << endl;
	cout << "The Barbarian's armor value is: " << Barb.getArmor() << endl << endl;

	cout << "The Goblin's swiftness allows him to attack first!" << endl << endl << endl << endl;

	while (strength1 > 0 || strength2 > 0)
{	
	Gob.getAttack();
	Gob.getDefense();
	Barb.getAttack();
	Barb.getDefense();
	attack1 = Gob.getAttack();
	defense1 = Gob.getDefense();
	attack2 = Barb.getAttack();
	defense2 = Barb.getDefense();
	
	cout << "**********TURN " << round << "****************" << endl;

	cout << "Goblin's attack rolls a:  " << attack1 << endl;
	cout << "Barbarian's defense rolls a:  " << defense2 << endl << endl;
		

	if (attack1 > defense2)
	{
		cout << "Goblins damage before armor: " << attack1 - defense2<< endl;
		damage1 = (attack1 - defense2) - Barb.getArmor();
		cout << "Goblin's damage after applying opponent's armor:  " << damage1 << endl << endl;
		if (damage1 > 0)
		strength2 = strength2 - damage1;
		if (strength2 <= 0)
		break;
		
	}
	else
	{
		cout << "Goblin's attack was not powerful enough, Barbarian's turn to attack" << endl << endl;
	}

	cout << "Barbarian's attack rolls a:  " << attack2 << endl;
	cout << "Goblin's defense rolls a: " << defense1 << endl << endl;

	if (attack2 > defense1)
	{
		cout << "Barbarian's damage before armor: " << attack2 - defense1 << endl;
		damage2 = (attack2 - defense1) - Gob.getArmor();
		cout << "Barbarian's damage after applying opponent's armor: " << damage2 << endl << endl;
		if (damage2 > 0)
		strength1 = strength1 - damage2;
		if (strength1 <= 0)
		break;
	}
	else
	{
		cout << "Barbarian's attack was not powerful enough, Goblin's turn to attack!" << endl << endl;
	}

	cout << endl;

	cout << "Goblin's remaining Strength Point: " << strength1 << endl;
	cout << "Barbarian's remaining Strength Point: " << strength2 << endl << endl;	

	round = round++;

	cout << "Press enter for next attack turn" << endl;
	cout << "______________________________________________________________________________" << endl << endl;
	cin.get();
	
}

	if (strength1 <= 0)
	{	cout << "Goblin DIES!" << endl;
		cout << "Barbarian is the winner with " << strength2 << " Strength Points remaining" << endl;
	}
	
	if (strength2 <= 0)
	{
		cout << "Barbarian DIES!" << endl;
		cout << "Goblin is the winner with " << strength1 << " Strength Points remaining" << endl << endl;
	}



}
