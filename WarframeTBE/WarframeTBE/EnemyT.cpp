#include <iostream>
#include <string>
#include "EnemyT.h"


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

void EnemyT::getHit(float damage) {
	if (shieldCur > 0) {
		shieldCur -= damage;
		if (shieldCur < 0) {
			shieldCur = 0;
		}
		cout << shieldCur << endl;
	}
	else {
		float DR = (200 / (armor + 200));
		damage *= DR;
		healthCur -= damage;
	}
}

bool EnemyT::isDead() {
	if (healthCur <= 0) {
		return true;
	}
	else {
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