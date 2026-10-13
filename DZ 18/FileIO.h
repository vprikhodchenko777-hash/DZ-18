#pragma once
#include "Hero.h"

void savePartyToFile(const PartyList& party, const char* filename);
void loadPartyFromFile(PartyList& party, const char* filename);
