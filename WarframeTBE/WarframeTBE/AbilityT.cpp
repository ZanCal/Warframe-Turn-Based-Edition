#include <iostream>
#include <string>
#include "AbilityT.h"
using namespace std;


AbilityT::AbilityT() {}

AbilityT::AbilityT(string name) {
	abilityName = name;
	abilityType = "passive";
}

AbilityT::AbilityT(string name, int cost) {
	abilityName = name;
	energyCost = cost;
}

AbilityT::AbilityT(string name, int cost, int turnCost) {
	abilityName = name;
	energyCost = cost;
	energyCostTurn = turnCost;
}

void AbilityT::cast() {
	cout << abilityName << " was cast" << endl;
	cout << "This is the cast function for the generic ability superclass" << endl;
	cout << "This messages should not appear" << endl;
}

damageAbilityT::damageAbilityT() {}

damageAbilityT::damageAbilityT(AbilityT ability) {
	abilityName = ability.getName();
	energyCost = ability.getCost();
	energyCostTurn = ability.getTurnCost();
	abilityType = "dmg";
}

void damageAbilityT::setAbilityInfo(string type, int damage) {
	damageType = type;
	damageStr = damage;
}

void damageAbilityT::cast() {
	cout << abilityName << " was cast" << endl;
	cout << "this is the cast function for the damage ability ability subclass" << endl;
}

CCAbilityT::CCAbilityT() {}

CCAbilityT::CCAbilityT(AbilityT ability) {
	abilityName = ability.getName();
	energyCost = ability.getCost();
	energyCostTurn = ability.getTurnCost();
	abilityType = "CC";
}

void CCAbilityT::cast() {
	cout << abilityName << " was cast" << endl;
	cout << "this is the cast function for the CC ability ability subclass" << endl;
}

buffAbilityT::buffAbilityT() {}

buffAbilityT::buffAbilityT(AbilityT ability) {
	abilityName = ability.getName();
	energyCost = ability.getCost();
	energyCostTurn = ability.getTurnCost();
	abilityType = "buff";
}

void buffAbilityT::cast() {
	cout << abilityName << " was cast" << endl;
	cout << "this is the cast function for the buff ability ability subclass" << endl;
}

debuffAbilityT::debuffAbilityT() {}

debuffAbilityT::debuffAbilityT(AbilityT ability) {
	abilityName = ability.getName();
	energyCost = ability.getCost();
	energyCostTurn = ability.getTurnCost();
	abilityType = "debuff";
}

void debuffAbilityT::cast() {
	cout << abilityName << " was cast" << endl;
	cout << "this is the cast function for the debuff ability ability subclass" << endl;
}

otherAbilityT::otherAbilityT() {}

otherAbilityT::otherAbilityT(AbilityT ability) {
	abilityName = ability.getName();
	energyCost = ability.getCost();
	energyCostTurn = ability.getTurnCost();
	abilityType = "other";
}

void otherAbilityT::cast() {
	cout << abilityName << " was cast" << endl;
	cout << "this is the cast function for the other ability ability subclass" << endl;
}

passiveAbilityT::passiveAbilityT() {}

passiveAbilityT::passiveAbilityT(AbilityT ability) {
	abilityName = ability.getName();
	abilityType = "passive";
}

string AbilityT::getName() {
	return abilityName;
}

int AbilityT::getCost() {
	return energyCost;
}

int AbilityT::getTurnCost() {
	return energyCostTurn;
}

string AbilityT::getType() {
	return abilityType;
}

