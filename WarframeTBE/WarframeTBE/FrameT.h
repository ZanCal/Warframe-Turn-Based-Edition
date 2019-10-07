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
	string shieldType = "Shield";
	int energyMax;
	int energyCur;
	float armor;
	string armorType = "Ferrite Armor";
	float sprintSpeed;

	passiveAbility passive;

	//okay so i have an idea to fix this bug but oh my god do i hate it
	//example of first fit versus best fit? 

	AbilityT abilities[4];

	damageAbilityT dmgAbility1;
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

};