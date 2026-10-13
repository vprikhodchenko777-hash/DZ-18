#pragma once
#include "Hero.h"

bool levelUp(PartyList& party, const char* searchName);
bool equipWeapon(PartyList& party, const char* searchName, Item newWeapon);
bool damageHero(PartyList& party, const char* searchName, int amount);
bool healHero(PartyList& party, const char* searchName, int amount);
