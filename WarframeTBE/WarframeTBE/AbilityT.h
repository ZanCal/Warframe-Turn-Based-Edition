#include<iostream>
using namespace std;

class AbilityT {

protected:
	string abilityName;
	string abilityType;
	int energyCost;
	int energyCostTurn;

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