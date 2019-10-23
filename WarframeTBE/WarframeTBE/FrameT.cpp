#include <iostream>
#include <string> 
#include "FrameT.h"

using namespace std;

//frame stats
string frameName[] = { "Ash","Ember","Excalibur","Loki","Mag","Rhino","Trinity","Volt" };
int frameHealthMax[] = { 150,100,100,75,75,100,100,100 };
int frameShieldMax[] = { 100,100,100,75,150,150,100,150 };
int frameEnergyMax[] = { 100,150,100,150,125,100,150,100 };
float frameArmor[] = { 65,100,225,65,65,190,15,15 };
float frameSprintSpeed[] = { 1.15, 1.1, 1, 1.25, 1, 0.95, 1, 1 };

//ability stats
AbilityT frameAbility1[] = { { "Shruriken", 25 },{ "Fireball",25 },{ "Slash Dash",25 } ,{ "Decoy",25 },{ "Pull",25 },{ "Rhino Charge",25 },{ "Well of Life",25 },{ "Shock",25 } };
AbilityT frameAbility2[] = { { "Smoke Screen",35 },{ "Accelerant",50 },{ "Radial Blind",50 },{ "Invisibility",50 },{ "Magnitize",50 },{ "Iron Skin",50 },{ "Energy Vampire",50 },{ "Speed",25 } };
AbilityT frameAbility3[] = { { "Teleport",25 },{ "Fire Blast",75 },{ "Radial Javelin",75 },{ "Switch Teleport",25 },{ "Polarize",75 },{ "Roar",75 },{ "Link",75 },{ "Electric Shield",50, 1 } };
AbilityT frameAbility4[] = { { "Blade Storm",0,12 },{ "World on Fire",50,3 },{ "Exalted Blade",25,3 },{ "Radial Disarm",100 },{ "Crush",100 },{ "Rhino Stomp",100 },{ "Blessing",100 },{ "Discharge",100 } };
AbilityT frameAbilityP[] = { "Hemorrage", "Ignition", "Swordmanship", "Wall Grapple", "Magnetic Attraction", "Heavy Landing", "Triage", "Static Discharge" };

FrameT::FrameT(int frameID) {
	Name = frameName[frameID];
	healthMax = frameHealthMax[frameID];
	healthCur = healthMax;
	shieldMax = frameShieldMax[frameID];
	shieldCur = shieldMax;
	energyMax = frameEnergyMax[frameID];
	energyCur = energyMax;
	armor = frameArmor[frameID];
	sprintSpeed = frameSprintSpeed[frameID];
	switch (frameID) {
	case 0: //ash
		dmgAbilities[0] = damageAbilityT(frameAbility1[frameID]);
		abilities[0] = dmgAbilities[0];
		dmgAbilities[0].setAbilityInfo("slash", 200);
		buffAbilities[1] = buffAbilityT(frameAbility2[frameID]);
		abilities[1] = buffAbilities[1];
		CCAbilities[2] = CCAbilityT(frameAbility3[frameID]);
		abilities[2] = CCAbilities[2];
		dmgAbilities[3] = damageAbilityT(frameAbility4[frameID]);
		abilities[3] = dmgAbilities[3];
		dmgAbilities[3].setAbilityInfo("true", 2000);
		break;
	case 1: //ember (going to need to update for rework)
		dmgAbilities[0] = damageAbilityT(frameAbility1[frameID]);
		abilities[0] = dmgAbilities[0];
		dmgAbilities[0].setAbilityInfo("heat", 400);
		buffAbilities[1] = buffAbilityT(frameAbility2[frameID]);
		abilities[1] = buffAbilities[1];
		otherAbilities[2] = otherAbilityT(frameAbility3[frameID]);
		abilities[2] = otherAbilities[2];
		dmgAbilities[3] = damageAbilityT(frameAbility4[frameID]);
		abilities[3] = dmgAbilities[3];
		dmgAbilities[3].setAbilityInfo("heat", 400);
		break;
	case 2: //excal
		dmgAbilities[0] = damageAbilityT(frameAbility1[frameID]);
		abilities[0] = dmgAbilities[0];
		dmgAbilities[0].setAbilityInfo("IPS", 250);
		CCAbilities[1] = CCAbilityT(frameAbility2[frameID]);
		abilities[1] = CCAbilities[1];
		dmgAbilities[2] = damageAbilityT(frameAbility3[frameID]);
		abilities[2] = dmgAbilities[2];
		dmgAbilities[2].setAbilityInfo("IPS", 1000);
		dmgAbilities[3] = damageAbilityT(frameAbility4[frameID]);
		abilities[3] = dmgAbilities[3];
		dmgAbilities[3].setAbilityInfo("IPS", 250);
		break;
	case 3: //loki
		CCAbilities[0] = CCAbilityT(frameAbility1[frameID]);
		abilities[0] = CCAbilities[0];
		buffAbilities[1] = buffAbilityT(frameAbility2[frameID]);
		abilities[1] = buffAbilities[1];
		CCAbilities[2] = CCAbilityT(frameAbility3[frameID]);
		abilities[2] = CCAbilities[2];
		debuffAbilities[3] = debuffAbilityT(frameAbility4[frameID]);
		abilities[3] = debuffAbilities[3];
		break;
	case 4: //mag
		dmgAbilities[0] = damageAbilityT(frameAbility1[frameID]);
		abilities[0] = dmgAbilities[0];
		dmgAbilities[0].setAbilityInfo("magnetic", 300);
		debuffAbilities[1] = debuffAbilityT(frameAbility2[frameID]);
		abilities[1] = debuffAbilities[1];
		otherAbilities[2] = otherAbilityT(frameAbility3[frameID]);
		abilities[2] = otherAbilities[2];
		dmgAbilities[3] = damageAbilityT(frameAbility4[frameID]);
		abilities[3] = dmgAbilities[3];
		dmgAbilities[3].setAbilityInfo("magnetic", 1500);
		break;
	case 5: //rhino
		otherAbilities[0] = otherAbilityT(frameAbility1[frameID]);
		abilities[0] = otherAbilities[0];
		buffAbilities[1] = buffAbilityT(frameAbility2[frameID]);
		abilities[1] = buffAbilities[1];
		buffAbilities[2] = buffAbilityT(frameAbility3[frameID]);
		abilities[2] = buffAbilities[2];
		CCAbilities[3] = CCAbilityT(frameAbility4[frameID]);
		abilities[3] = CCAbilities[3];
		break;
	case 6: //trin
		debuffAbilities[0] = debuffAbilityT(frameAbility1[frameID]);
		abilities[0] = debuffAbilities[0];
		debuffAbilities[1] = debuffAbilityT(frameAbility2[frameID]);
		abilities[1] = debuffAbilities[1];
		buffAbilities[2] = buffAbilityT(frameAbility3[frameID]);
		abilities[2] = buffAbilities[2];
		buffAbilities[3] = buffAbilityT(frameAbility4[frameID]);
		abilities[3] = buffAbilities[3];
		break;
	case 7: //volt
		dmgAbilities[0] = damageAbilityT(frameAbility1[frameID]);
		abilities[0] = dmgAbilities[0];
		dmgAbilities[0].setAbilityInfo("electric", 200);
		buffAbilities[1] = buffAbilityT(frameAbility2[frameID]);
		abilities[1] = buffAbilities[1];
		otherAbilities[2] = otherAbilityT(frameAbility3[frameID]);
		abilities[2] = otherAbilities[2];
		CCAbilities[3] = CCAbilityT(frameAbility4[frameID]);
		abilities[3] = CCAbilities[3];
		break;
	}
}

string FrameT::getName() {
	return Name;
}

int FrameT::getMaxHealth() {
	return healthMax;
}

string FrameT::getHealthType() {
	return healthType;
}

int FrameT::getMaxShield() {
	return shieldMax;
}

string FrameT::getShieldType() {
	return shieldType;
}

int FrameT::getMaxEnergy() {
	return energyMax;
}

int FrameT::getArmor() {
	return armor;
}

string FrameT::getArmorType() {
	return armorType;
}

float FrameT::getSpeed() {
	return sprintSpeed;
}

void FrameT::printStatus() {
	//this funciton will be reworked during refactoring
	//instead of printing out the frame status, it will 
	//put it all in a string it returns 

	cout << getName() << " Health:" << healthCur << " Shields:" << shieldCur << " Energy:" << energyCur << endl;
	

}

AbilityT FrameT::getAbility(int which) {
	return abilities[which];
}

bool FrameT::drainEnergy(int cost) {
	if (energyCur >= cost) {
		energyCur -= cost;
		
		return true;
	} else {
		
		return false;
	}
}

void FrameT::cast(int which){
	//could this function call unique cast functions for the distinct ability types?
	//i feel as if there should be a significantly easier way to do it
	if (drainEnergy(getAbility(which).getCost())) {
		//string switch would be so convient here
		if (getAbility(which).getType() == "dmg") {
			dmgAbilities[which].cast();
			return;
		}
		if (getAbility(which).getType() == "CC") {
			CCAbilities[which].cast();
			return;
		}
		if (getAbility(which).getType() == "buff") {
			buffAbilities[which].cast();
			return;
		}
		if (getAbility(which).getType() == "debuff") {
			debuffAbilities[which].cast();
			return;
		}
		if (getAbility(which).getType() == "other") {
			otherAbilities[which].cast();
			return;
		}

		abilities[which].cast();//debug func call, should never actually be called

	} else {
		//not enough energy error message	
		cout << "Not enough energy" << endl;
	}
}

void FrameT::printInfo() {
	cout << getName() << " Max Health:" << healthMax << " Max Shields:" << shieldMax << " Max Energy:" << energyMax << " Sprint Speed: " << sprintSpeed << endl;
	cout << abilities[0].getInfo() << endl;
	cout << abilities[1].getInfo() << endl;
	cout << abilities[2].getInfo() << endl;
	cout << abilities[3].getInfo() << endl;

}

void FrameT::getHit(float damage) {
	if (shieldCur > 0) {
		shieldCur -= damage;
		if (shieldCur < 0) {
			shieldCur = 0;
		}
	}
	else {
		float DR = (300 / (armor + 300));
		damage *= DR;
		healthCur -= damage;
	}
}