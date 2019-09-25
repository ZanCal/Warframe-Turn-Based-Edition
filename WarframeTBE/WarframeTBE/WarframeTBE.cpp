// WarframeTBE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;


//TODO
/*
	Baseline
		Startup "screen"
		Frame selection
		Enemy faction selection

	Gameplay


	Frames
		Abilities
			All 
				Instance Creation
				Functionality 
				Targeting 
				Channel or Cast

			Damage
				Damage Type
				Special Effects
			CC
				Nature of CC
			
			Buff
				Nature of Buff

			Debuff
				Nature of Debuff

			Passive
				Adjustment for new context
				Interaction 

			Other

	Enemies
		Target Prioritization 
		


	Other
		Armor DR
		Shield Regen
		Levels, XP, and scailing 
		Damage Types

		Game Balance

	Extras
		Frame Stats Page


*/

//frame info
string frameName[] = {"Ash","Ember","Excalibur","Loki","Mag","Rhino","Trinity","Volt"};
int frameHealthMax[] = {150,100,100,75,75,100,100,100};
int frameShieldMax[] = {100,100,100,75,150,150,100,150};
int frameEnergyMax[] = {100,150,100,150,125,100,150,100};
int frameArmor[] = {65,100,225,65,65,190,15,15};
double frameSprintSpeed[] = {1.15, 1.1, 1, 1.25, 1, 0.95, 1, 1};

class Ability {
protected:
	string abilityName;
	//int abilityLevel; //Leveled abilities will be done later
	string abilityType; 
	int energyCost;
	
public:
	Ability(string name) {
		abilityName = name;
	}
	Ability() {}
};

class damageAbility : public Ability {
protected:
	string damageType;
	//int damageStr[4];  //Leveled Abilities will be done later
	int damageStr;
	bool singleTarget;
public:

	damageAbility(string name, bool sinTarg):Ability(){
		abilityName = name;
		singleTarget = sinTarg;
		abilityType = "dmg";
	}

};

class CCAbility : public Ability {
public:
	CCAbility(string name) :Ability() {
		abilityName = name;
		abilityType = "CC";
	}
};
class BuffAbility : public Ability {
public:
	BuffAbility(string name) :Ability() {
		abilityName = name;
		abilityType = "buff";
	}
};
class DebuffAbility : public Ability {
public:
	DebuffAbility(string name) :Ability() {
		abilityName = name;
		abilityType = "debuff";
	}
};
class OtherAbility : public Ability {
public:
	OtherAbility(string name) :Ability() {
		abilityName = name;
		abilityType = "other";
	}
};


Ability frameAbility1[] = {"Shruriken", "Fireball", "Slash Dash", "Decoy", "Pull", "Rhino Charge", "Well of Life", "Shock"};
Ability frameAbility2[] = {"Smoke Screen", "Accelerant", "Radial Blind", "Invisibility", "Magnitize", "Iron Skin", "Energy Vampire", "Speed"};
Ability frameAbility3[] = {"Teleport", "Fire Blast", "Radial Javelin", "Switch Teleport", "Polarize", "Roar", "Link", "Electric Shield"};
Ability frameAbility4[] = {"Blade Storm", "World on Fire", "Exalted Blade", "Radial Disarm", "Crush", "Rhino Stomp", "Blessing", "Discharge"};
Ability frameAbilityP[] = {"Hemorrage", "Ignition", "Swordmanship", "Wall Grapple", "Magnetic Attraction", "Heavy Landing", "Triage", "Static Discharge"};


class Frame {

protected:

public:

};

class Enemy {

};

int main(){

	

	cout << "Hello World!" << endl;

    return 0;
}

