#include <iostream>
#include <string>
#include "EnemyT.h"

//enemy stats
string enemyName[] = {"Butcher", "Lancer","Bombard","Roller","Manic Bombard"};
int enemyBaseHealth[] = {50,100,300,40,1500};
string enemyHealthType[] = {"Cloned Flesh","Cloned Flesh","Cloned Flesh","Machinery","Cloned Flesh"};
int enemyBaseArmor[] = {5,100,500,100,500};
string enemyArmorType[] = {"Ferrite Armor","Ferrite Armor","Alloy Armor","Ferrite Armor","Alloy Armor"};
int enemyBaseShield[] = {0, 0, 0, 0, 0};
string enemyShieldType[] = {"None", "None", "None", "None", "None" };
string enemyFaction[] = {"Grinner","Grinner","Grinner","Grinner","Grinner"};

EnemyT::EnemyT(){

}

EnemyT::EnemyT(bool isTest) {
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

EnemyT::EnemyT(int enemyID) {
	Name = enemyName[enemyID];
	healthBase = enemyBaseHealth[enemyID];
	shieldBase = enemyBaseShield[enemyID];
	armorBase = enemyBaseArmor[enemyID];
	healthType = enemyHealthType[enemyID];
	shieldType = enemyShieldType[enemyID];
	armorType = enemyArmorType[enemyID];
	faction = enemyFaction[enemyID];
	Level = 1;

}

void EnemyT::getHit(float damage) {
	if (shieldCur > 0) {
		shieldCur -= damage;
		if (shieldCur < 0) {
			shieldCur = 0;
		}
	} else {
		float DR = (200 / (armor + 200));
		damage *= DR;
		healthCur -= damage;
	}
}

bool EnemyT::isDead() {
	if (healthCur <= 0) {
		return true;
	} else {
		return false;
	}
}

string * EnemyT::getDRInfo() {
	string DRInfo[] = { healthType, armorType, shieldType };
	return DRInfo;
}

string EnemyT::getName() {
	return Name;
}