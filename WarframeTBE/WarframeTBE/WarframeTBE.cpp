// WarframeTBE.cpp : Defines the entry point for the console application.
// 

#include<iostream>
#include<string>
#include "stdafx.h"
#include "FrameT.h"
#include "AbilityT.h"
using namespace std;


//new day, new things to do
/*
	There is now a timeline! Have something user interactive by thanksgiving (5 working days left)
	here's what I want to get done today
		frame status printout 
		damage abilities able to target single enemy
			I think that this part may require splitting my main classes into seperate files
			lol idk how to do that
	here's what I've gotten done today
		
*/

//TODO
/*
	Baseline
		Startup "screen"
		Frame selection
		Enemy faction selection

	Gameplay
		Targeting System
		Turn System

	Frames
		Bleedout state / Death / Rez tokens
		Abilities
			All 
				Functionality 
				Targeting (if an ability targets all enemies, have it target each one instead of a seperate general target all ability funcition)
				Channel or Cast
				Turn Interaction
			Damage
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
				Perhaps just leave passives 'till later?
			Other
		Status Printout

	Enemies
		Target Prioritization
		Death
		Abilities
		Attacking

	Other
		Shield Regen
		Levels, XP, and scailing (save for later)
		Damage Types
			Need to know how multiple dmg + h/s/a types interact in game first
		Game Balance
		Split classes into other files to keep organized 

	Extras
		Frame Stats Page
*/

void calcDR(string * damageType, string * targetInfo) {
	//how to use the pointer?
	
	//Object health type is always a multiplier of 1

	//true damage type is a multiplier of 1 for all except armor, which is bypassed

	//maybe array this bitch?

	//how do health multipliers interact with armor multipliers 

}


class Ability {
protected:
	string abilityName;
	//int abilityLevel; //Leveled abilities will be done later
	string abilityType; 
	int energyCost;
	int energyCostTurn;
	//besides EV, how is energy going to be generated? Passive regen?
	
public:
	Ability() {}
	Ability(string name) {
		abilityName = name;
		abilityType = "passive";
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
	//having a bunch of getInfo() functions doesn't feel right, but i also don't want everything in my class to be public
	string getName() {
		return abilityName;
	}
	int getCost() {
		return energyCost;
	}
	int getTurnCost() {
		return energyCostTurn;
	}
	string getType() {
		return abilityType;
	}
	void cast() {
		cout << "Ability " << abilityName << " was cast" << endl;
	}
	
};

class damageAbility : public Ability {
protected:
	string damageType;
	//int damageStr[4];  //Leveled Abilities will be done later
	int damageStr;
public:
	damageAbility() {}
	damageAbility(Ability ability) {
		abilityName = ability.getName();
		energyCost = ability.getCost();
		energyCostTurn = ability.getTurnCost();
		abilityType = "dmg";
	}
	void setAbilityInfo(string type, int damage) {
		damageStr = damage;
		damageType = type;
	}
	

};
class CCAbility : public Ability {
protected:
public:
	CCAbility() {}
	CCAbility(Ability ability) {
		abilityName = ability.getName();
		energyCost = ability.getCost();
		energyCostTurn = ability.getTurnCost();
		abilityType = "CC";
	}
};
class buffAbility : public Ability {
protected:
public:
	buffAbility() {}
	buffAbility(Ability ability) {
		abilityName = ability.getName();
		energyCost = ability.getCost();
		energyCostTurn = ability.getTurnCost();
		abilityType = "Buff";
	}
};
class debuffAbility : public Ability {
protected:
public:
	debuffAbility() {}
	debuffAbility(Ability ability) {
		abilityName = ability.getName();
		energyCost = ability.getCost();
		energyCostTurn = ability.getTurnCost();
		abilityType = "Debuff";
	}
};
class otherAbility : public Ability {
protected:
public:
	otherAbility() {}
	otherAbility(Ability ability) {
		abilityName = ability.getName();
		energyCost = ability.getCost();
		energyCostTurn = ability.getTurnCost();
		abilityType = "Other";
	}
};
class passiveAbility : public Ability {
	//lol idk how to do this
protected:
public:
	passiveAbility(Ability ability) {
		abilityName = ability.getName();
		abilityType = "Passive";
	}
	passiveAbility() {}

};

//frame info
string frameName[] = { "Ash","Ember","Excalibur","Loki","Mag","Rhino","Trinity","Volt" };
int frameHealthMax[] = { 150,100,100,75,75,100,100,100 };
int frameShieldMax[] = { 100,100,100,75,150,150,100,150 };
int frameEnergyMax[] = { 100,150,100,150,125,100,150,100 };
float frameArmor[] = { 65,100,225,65,65,190,15,15 };
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
	float armor;
	string armorType = "Ferrite Armor";
	float sprintSpeed;

	passiveAbility passive;

	//okay so i have an idea to fix this bug but oh my god do i hate it
	//example of first fit versus best fit? 

	Ability abilities[4];

	damageAbility dmgAbility1;
	damageAbility dmgAbility2;
	damageAbility dmgAbility3;
	damageAbility dmgAbility4;
	
	CCAbility CCAbility1;
	CCAbility CCAbility2;
	CCAbility CCAbility3;
	CCAbility CCAbility4;

	buffAbility buffAbility1;
	buffAbility buffAbility2;
	buffAbility buffAbility3;
	buffAbility buffAbility4;

	debuffAbility debuffAbility1;
	debuffAbility debuffAbility2;
	debuffAbility debuffAbility3;
	debuffAbility debuffAbility4;

	otherAbility otherAbility1;
	otherAbility otherAbility2;
	otherAbility otherAbility3;
	otherAbility otherAbility4;


public:
	Frame(int frameID) {
		Name = frameName[frameID];
		healthMax = frameHealthMax[frameID];
		healthCur = healthMax;
		shieldMax = frameShieldMax[frameID];
		shieldCur = shieldMax;
		energyMax = frameEnergyMax[frameID];
		energyCur = energyMax;
		armor = frameArmor[frameID];
		sprintSpeed	 = frameSprintSpeed[frameID];
		passive = passiveAbility(frameAbilityP[frameID]);
		
		//I still don't like this, but it seems a lot better than the if statements i had before
		//I wonder if there's still a better way to do it
		switch (frameID) {
		case 0: //ash
			dmgAbility1 = damageAbility(frameAbility1[frameID]);
			abilities[0] = dmgAbility1;
			dmgAbility1.setAbilityInfo("slash", 200);
			buffAbility2 = buffAbility(frameAbility2[frameID]);
			abilities[1] = buffAbility2;
			CCAbility3 = CCAbility(frameAbility3[frameID]);
			abilities[2] = CCAbility3;
			dmgAbility4 = damageAbility(frameAbility4[frameID]);
			abilities[3] = dmgAbility4;
			dmgAbility4.setAbilityInfo("true", 2000);
			break;
		case 1: //ember
			dmgAbility1 = damageAbility(frameAbility1[frameID]);
			abilities[0] = dmgAbility1;
			dmgAbility1.setAbilityInfo("heat", 400);
			buffAbility2 = buffAbility(frameAbility2[frameID]);
			abilities[1] = buffAbility2;
			otherAbility3 = otherAbility(frameAbility3[frameID]);
			abilities[2] = otherAbility3;
			dmgAbility4 = damageAbility(frameAbility4[frameID]);
			abilities[3] = dmgAbility4;
			dmgAbility4.setAbilityInfo("heat", 400);
			break;
		case 2: //excal
			dmgAbility1 = damageAbility(frameAbility1[frameID]);
			abilities[0] = dmgAbility1;
			dmgAbility1.setAbilityInfo("IPS", 250);
			CCAbility2 = CCAbility(frameAbility2[frameID]);
			abilities[1] = CCAbility2;
			dmgAbility3 = damageAbility(frameAbility3[frameID]);
			abilities[2] = dmgAbility3;
			dmgAbility3.setAbilityInfo("IPS", 1000);
			dmgAbility4 = damageAbility(frameAbility4[frameID]);
			abilities[3] = dmgAbility4;
			dmgAbility4.setAbilityInfo("IPS",250);
			break;
		case 3: //loki
			CCAbility1 = CCAbility(frameAbility1[frameID]);
			abilities[0] = CCAbility1;
			buffAbility2 = buffAbility(frameAbility2[frameID]);
			abilities[1] = buffAbility2;
			CCAbility3 = CCAbility(frameAbility3[frameID]);
			abilities[2] = CCAbility3;
			debuffAbility4 = debuffAbility(frameAbility4[frameID]);
			abilities[3] = debuffAbility4;
			break;
		case 4: //mag
			dmgAbility1 = damageAbility(frameAbility1[frameID]);
			abilities[0] = dmgAbility1;
			dmgAbility1.setAbilityInfo("magnetic", 300);
			debuffAbility2 = debuffAbility(frameAbility2[frameID]);
			abilities[1] = debuffAbility2;
			otherAbility3 = otherAbility(frameAbility3[frameID]);
			abilities[2] = otherAbility3;
			dmgAbility4 = damageAbility(frameAbility4[frameID]);
			abilities[3] = dmgAbility4;
			dmgAbility4.setAbilityInfo("magnetic", 1500);
			break;
		case 5: //rhino
			otherAbility1 = otherAbility(frameAbility1[frameID]);
			abilities[0] = otherAbility1;
			buffAbility2 = buffAbility(frameAbility2[frameID]);
			abilities[1] = buffAbility2;
			buffAbility3 = buffAbility(frameAbility3[frameID]);
			abilities[2] = buffAbility3;
			CCAbility4 = CCAbility(frameAbility4[frameID]);
			abilities[3] = CCAbility4;
			break;
		case 6: //trin
			debuffAbility1 = debuffAbility(frameAbility1[frameID]);
			abilities[0] = debuffAbility1;
			debuffAbility2 = debuffAbility(frameAbility2[frameID]);
			abilities[1] = debuffAbility2;
			buffAbility3 = buffAbility(frameAbility3[frameID]);
			abilities[2] = buffAbility3;
			buffAbility4 = buffAbility(frameAbility4[frameID]);
			abilities[3] = buffAbility4;
			break;
		case 7: //volt
			dmgAbility1 = damageAbility(frameAbility1[frameID]);
			abilities[0] = dmgAbility1;
			dmgAbility1.setAbilityInfo("electric", 200);
			buffAbility2 = buffAbility(frameAbility2[frameID]);
			abilities[1] = buffAbility2;
			otherAbility3 = otherAbility(frameAbility3[frameID]);
			abilities[2] = otherAbility3;
			CCAbility4 = CCAbility(frameAbility4[frameID]);
			abilities[3] = CCAbility4;
			break;
		}

	}


	//all my get functions for frames
	//once again, this doesn't feel too right. Maybe i'm just rusty?
	string getName() {
		return Name;
	}
	int getMaxHealth() {
		return healthMax;
	}
	string getHealthType() {
		return healthType;
	}
	int getMaxShield() {
		return shieldMax;
	}
	string getShieldType() {
		return shieldType;
	}
	int getEnergyMax(){
		return energyMax;
	}
	int getArmor() {
		return armor;
	}
	string getArmorType() {
		return armorType;
	}
	float getSpeed() {
		return sprintSpeed;
	}
	//I wonder if i can do a getAbility(ability number) thing instead of 4 get fuctions for each ability
	//turns out i can, but only because of how i decided to fix a bug (which isn't a way i'm satisfied with)
	Ability getAbility(int which) {
		return abilities[which];
	}
	


	//ability functions 
	bool drainEnergy(int cost) {
		if (energyCur >= cost) {
			energyCur -= cost;
			return true;
		} else {
			return false;
		}
	}
	void cast(int which) {
		if (drainEnergy(getAbility(which).getCost())) {
			getAbility(which).cast();
		} else {
			//not enough energy error message	
			cout << "Not enough energy" << endl;
		}
	}


	void getHit(float damage) {
		//holdup 
		//armor DR doesn't apply to shields 
		//whoops
		if (shieldCur > 0) {
			shieldCur -= damage;
			if (shieldCur < 0) {
				shieldCur = 0;
			}
		} else {
			float DR = (300 / (armor + 300));
			damage *= DR;
			healthCur -= damage;
		}
		cout << "Frame " << Name << " has " << shieldCur << " shields and " << healthCur <<  " health" << endl;
	}

};

class Enemy {
protected:
	string Name;
	int healthMax;
	int healthCur;
	string healthType;
	int shieldMax;
	int shieldCur;
	string shieldType;
	float armor;
	string armorType;

public:

	Enemy() {}

	Enemy(bool isTest) {
		Name = "Test Butcher";
		healthMax = 50;
		healthCur = healthMax;
		healthType = "Cloned Flesh";
		shieldMax = 0;
		shieldCur = 0;
		shieldType = "None";
		armor = 5;
		armorType = "Ferrite Armor";
	}

	void getHit(float damage) {
		//armor DR doesn't apply to shields 
		
		if (shieldCur > 0) {
			shieldCur -= damage;
			if (shieldCur < 0) {
				shieldCur = 0;
			}
			cout << shieldCur << endl;
		} else {
			float DR = (200 / (armor + 200));
			damage *= DR;
			healthCur -= damage;
			cout << healthCur << endl;
		}
	}

	bool isDead() {
		if (healthCur <= 0) {
			return true;
		} else {
			return false;
		}
	}

	//function that returns an array of strings needed for the calcDR function

	string * getDRInfo() {
		string DRInfo[] = { healthType, armorType, shieldType };
		return DRInfo;
	}
};

class cell {
protected:
	Frame frame1;
	Frame frame2;
	Frame frame3;
	Frame frame4;


public:


};

class enemyCell {};

int main(){

	Enemy testE = Enemy(true);

	Frame testF = Frame(1);

	

	cout << "Welcome to Warframe: Turn Based Edition" << endl;

    return 0;
}

