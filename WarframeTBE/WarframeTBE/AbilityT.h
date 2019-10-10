#include<iostream>
using namespace std;

class AbilityT {

protected:
	string abilityName;
	string abilityType;
	int energyCost;
	int energyCostTurn = 0;

public:
	AbilityT();
	AbilityT(string name);
	AbilityT(string name, int cost);
	AbilityT(string name, int cost, int turnCost);
	string getName();
	int getCost();
	int getTurnCost();
	string getType();
	virtual void cast();
};

class damageAbilityT : public AbilityT {
protected:
	string damageType;
	//int damageStr[4];  //Leveled Abilities will be done later
	int damageStr;
public:
	damageAbilityT();
	damageAbilityT(AbilityT ability);
	void setAbilityInfo(string type, int damage);
	void cast();
};

class CCAbilityT : public AbilityT {
protected:
public:
	CCAbilityT();
	CCAbilityT(AbilityT ability);
	void cast();
};

class buffAbilityT : public AbilityT {
protected:
public:
	buffAbilityT();
	buffAbilityT(AbilityT ability);
	void cast();
};

class debuffAbilityT : public AbilityT {
protected:
public:
	debuffAbilityT();
	debuffAbilityT(AbilityT ability);
	void cast();

};

class otherAbilityT : public AbilityT {
protected:
public:
	otherAbilityT();
	otherAbilityT(AbilityT ability);
	void cast();

};

class passiveAbilityT : public AbilityT {
protected:
public:
	passiveAbilityT();
	passiveAbilityT(AbilityT ability);
};