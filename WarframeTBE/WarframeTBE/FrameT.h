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

	//okay so i have an idea to fix this bug but oh my god do i hate it
	//example of first fit versus best fit? 

	AbilityT abilities[4];

	damageAbilityT dmgAbility1;
	damageAbilityT dmgAbility2;
	damageAbilityT dmgAbility3;
	damageAbilityT dmgAbility4;

	CCAbilityT CCAbility1;
	CCAbilityT CCAbility2;
	CCAbilityT CCAbility3;
	CCAbilityT CCAbility4;

	buffAbilityT buffAbility1;
	buffAbilityT buffAbility2;
	buffAbilityT buffAbility3;
	buffAbilityT buffAbility4;

	debuffAbilityT debuffAbility1;
	debuffAbilityT debuffAbility2;
	debuffAbilityT debuffAbility3;
	debuffAbilityT debuffAbility4;

	otherAbilityT otherAbility1;
	otherAbilityT otherAbility2;
	otherAbilityT otherAbility3;
	otherAbilityT otherAbility4;
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

	void printStatus();


};
