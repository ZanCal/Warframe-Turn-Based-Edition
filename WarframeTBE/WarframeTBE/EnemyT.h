#include<iostream>
using namespace std;

class EnemyT {
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
	EnemyT();
	EnemyT(bool isTest);
	void getHit(float damage);
	bool isDead();
	string * getDRInfo();
	string getName();

};