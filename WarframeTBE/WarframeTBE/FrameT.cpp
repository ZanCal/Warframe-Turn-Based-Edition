#include <iostream>
#include <string> 
#include "FrameT.h"
#include "AbilityT.h"
using namespace std;

string frameName[] = { "Ash","Ember","Excalibur","Loki","Mag","Rhino","Trinity","Volt" };
int frameHealthMax[] = { 150,100,100,75,75,100,100,100 };
int frameShieldMax[] = { 100,100,100,75,150,150,100,150 };
int frameEnergyMax[] = { 100,150,100,150,125,100,150,100 };
float frameArmor[] = { 65,100,225,65,65,190,15,15 };
float frameSprintSpeed[] = { 1.15, 1.1, 1, 1.25, 1, 0.95, 1, 1 };

AbilityT frameAbility1[] = { { "Shruriken", 25 },{ "Fireball",25 },{ "Slash Dash",25 } ,{ "Decoy",25 },{ "Pull",25 },{ "Rhino Charge",25 },{ "Well of Life",25 },{ "Shock",25 } };
AbilityT frameAbility2[] = { { "Smoke Screen",35 },{ "Accelerant",50 },{ "Radial Blind",50 },{ "Invisibility",50 },{ "Magnitize",50 },{ "Iron Skin",50 },{ "Energy Vampire",50 },{ "Speed",25 } };
AbilityT frameAbility3[] = { { "Teleport",25 },{ "Fire Blast",75 },{ "Radial Javelin",75 },{ "Switch Teleport",25 },{ "Polarize",75 },{ "Roar",75 },{ "Link",75 },{ "Electric Shield",50, 1 } };
AbilityT frameAbility4[] = { { "Blade Storm",0,12 },{ "World on Fire",50,3 },{ "Exalted Blade",25,3 },{ "Radial Disarm",100 },{ "Crush",100 },{ "Rhino Stomp",100 },{ "Blessing",100 },{ "Discharge",100 } };
AbilityT frameAbilityP[] = { "Hemorrage", "Ignition", "Swordmanship", "Wall Grapple", "Magnetic Attraction", "Heavy Landing", "Triage", "Static Discharge" };


int main() {

}
