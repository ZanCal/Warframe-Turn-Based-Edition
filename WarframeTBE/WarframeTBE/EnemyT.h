#include<iostream>
using namespace std;

class EnemyT {
protected:
	string Name;
	int Level;
	int healthBase;
	int healthMax;
	int healthCur;
	string healthType;
	int shieldBase;
	int shieldMax;
	int shieldCur;
	string shieldType;
	int armorBase;
	float armor;
	string armorType;
	string faction;

public:
	EnemyT();
	EnemyT(bool isTest);
	EnemyT(int enemyID);
	EnemyT(int enemyID, int level);
	void getHit(float damage);
	bool isDead();
	string * getDRInfo();
	string getName();

};