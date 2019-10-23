#include<iostream>
#include"AbilityT.h"
using namespace std;

class FrameT {

protected:
	string Name;
	int healthMax;
	int healthCur;
	string healthType = "Flesh";
	int shieldMax;
	int shieldCur;
	int shieldRegen = 15 + shieldMax * 0.05;
	string shieldType = "Shield";
	bool shieldIsRegenerating;
	int energyMax;
	int energyCur;
	float armor;
	string armorType = "Ferrite Armor";
	float sprintSpeed;

	passiveAbilityT passive;

	AbilityT abilities[4];

	damageAbilityT dmgAbility1;
	damageAbilityT dmgAbility2;
	damageAbilityT dmgAbility3;
	damageAbilityT dmgAbility4;
	damageAbilityT dmgAbilities[4] = {dmgAbility1, dmgAbility2, dmgAbility3, dmgAbility4};

	CCAbilityT CCAbility1;
	CCAbilityT CCAbility2;
	CCAbilityT CCAbility3;
	CCAbilityT CCAbility4;
	CCAbilityT CCAbilities[4] = {CCAbility1, CCAbility2, CCAbility3, CCAbility4};

	buffAbilityT buffAbility1;
	buffAbilityT buffAbility2;
	buffAbilityT buffAbility3;
	buffAbilityT buffAbility4;
	buffAbilityT buffAbilities[4] = {buffAbility1, buffAbility2, buffAbility3, buffAbility4};

	debuffAbilityT debuffAbility1;
	debuffAbilityT debuffAbility2;
	debuffAbilityT debuffAbility3;
	debuffAbilityT debuffAbility4;
	debuffAbilityT debuffAbilities[4] = {debuffAbility1, debuffAbility2, debuffAbility3, debuffAbility4};

	otherAbilityT otherAbility1;
	otherAbilityT otherAbility2;
	otherAbilityT otherAbility3;
	otherAbilityT otherAbility4;
	otherAbilityT otherAbilities[4] = {otherAbility1, otherAbility2, otherAbility3, otherAbility4};
public:
	FrameT(int frameID);
	string getName();
	int getMaxHealth();
	string getHealthType();
	int getMaxShield();
	string getShieldType();
	int getMaxEnergy();
	int getArmor();
	string getArmorType();
	float getSpeed();
	AbilityT getAbility(int which);

	bool drainEnergy(int cost);
	void cast(int which);
	
	void getHit(float damage);
	string * getDRInfo();
	bool isDead();

	void printInfo();

	void printStatus();

};
