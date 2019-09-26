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
		Targeting System

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
		Split classes into other files to keep organized 

	Extras
		Frame Stats Page


*/

void calcDR(string damageType, string healthType, string armorType, string shieldType) {

	
}


class Ability {
protected:
	string abilityName;
	//int abilityLevel; //Leveled abilities will be done later
	string abilityType; 
	int energyCost;
	int energyCostTurn;
	
public:
	Ability(string name) {
		abilityName = name;
	}
	Ability(string name, int cost) {
		abilityName = name;
		energyCost = cost;
	}
	Ability(string name, int cost, int turnCost) {
		abilityName = name;
		energyCost = cost;
		energyCostTurn = turnCost;
	}

	Ability() {}

	void cast() {
	
	}
	
};

class damageAbility : public Ability {
protected:
	string damageType;
	//int damageStr[4];  //Leveled Abilities will be done later
	int damageStr;
	bool singleTarget;
public:
	//create a constructor that takes an instance of Ability as argument
	damageAbility(string name, bool sinTarg):Ability(){
		abilityName = name;
		singleTarget = sinTarg;
		abilityType = "dmg";
	}

	damageAbility(Ability ability) {
		
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

//frame info
string frameName[] = { "Ash","Ember","Excalibur","Loki","Mag","Rhino","Trinity","Volt" };
int frameHealthMax[] = { 150,100,100,75,75,100,100,100 };
int frameShieldMax[] = { 100,100,100,75,150,150,100,150 };
int frameEnergyMax[] = { 100,150,100,150,125,100,150,100 };
int frameArmor[] = { 65,100,225,65,65,190,15,15 };
float frameSprintSpeed[] = { 1.15, 1.1, 1, 1.25, 1, 0.95, 1, 1 };

Ability frameAbility1[] = { {"Shruriken", 25}, {"Fireball",25}, {"Slash Dash",25} ,{"Decoy",25}, {"Pull",25}, {"Rhino Charge",25}, {"Well of Life",25}, {"Shock",25} };
Ability frameAbility2[] = { {"Smoke Screen",35}, {"Accelerant",50}, {"Radial Blind",50}, {"Invisibility",50}, {"Magnitize",50}, {"Iron Skin",50}, {"Energy Vampire",50}, {"Speed",25} };
Ability frameAbility3[] = { {"Teleport",25}, {"Fire Blast",75}, {"Radial Javelin",75}, {"Switch Teleport",25}, {"Polarize",75}, {"Roar",75}, {"Link",75}, {"Electric Shield",50, 1} };
Ability frameAbility4[] = { {"Blade Storm",0,12}, {"World on Fire",50,3}, {"Exalted Blade",25,3}, {"Radial Disarm",100}, {"Crush",100}, {"Rhino Stomp",100}, {"Blessing",100}, {"Discharge",100} };
Ability frameAbilityP[] = {"Hemorrage", "Ignition", "Swordmanship", "Wall Grapple", "Magnetic Attraction", "Heavy Landing", "Triage", "Static Discharge"};


class Frame {

protected:
	string Name;
	int healthMax;
	int healthCur;
	string healthType = "Flesh";
	int shieldMax;
	int shieldCur;
	string shieldType = "Shield";
	int energyMax;
	int energyCur;
	int armor;
	string armorType = "Ferrite Armor";
	float sprintSpeed;

	/*
	Ability ability1;
	Ability ability2;
	Ability ability3;
	Ability ability4;
	Ability abilityP;
	*/

public:
	Frame(int frameID) {
		Name = frameName[frameID];
		healthMax = frameHealthMax[frameID];
		shieldMax = frameShieldMax[frameID];
		energyMax = frameEnergyMax[frameID];
		armor = frameArmor[frameID];
		sprintSpeed	 = frameSprintSpeed[frameID];

	}
};

class Enemy {
protected:
	string Name;
	int healthMax;
	int healthCur;
	int shieldMax;
	int shieldCur;
	int armor;

public:
};

int main(){
	Ability test =  damageAbility("test", false);
	
	test.cast();
	cout << "Welcome to Warframe: Turn Based Edition" << endl;

    return 0;
}

