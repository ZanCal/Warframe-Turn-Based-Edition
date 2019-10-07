#include <iostream>
#include <string>
#include "AbilityT.h"
using namespace std;

class AbilityT {
protected:
	string abilityName;
	//int abilityLevel; //Leveled abilities will be done later
	string abilityType;
	int energyCost;
	int energyCostTurn;
	//besides EV, how is energy going to be generated? Passive regen?

public:
	AbilityT() {}
	AbilityT(string name) {
		abilityName = name;
		abilityType = "passive";
	}
	AbilityT(string name, int cost) {
		abilityName = name;
		energyCost = cost;
	}
	AbilityT(string name, int cost, int turnCost) {
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

class damageAbilityT : public AbilityT {
protected:
	string damageType;
	//int damageStr[4];  //Leveled Abilities will be done later
	int damageStr;
public:
	damageAbilityT() {}
	damageAbilityT(AbilityT ability) {
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

int main() {

}