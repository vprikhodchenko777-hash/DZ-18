#pragma once
#include "Hero.h"

bool dismissHero(PartyList& party, const char* searchName);
int totalPartyPower(const PartyList& party);
int findStrongestHeroIndex(const PartyList& party);
void sortByLevelDescending(PartyList& party);
