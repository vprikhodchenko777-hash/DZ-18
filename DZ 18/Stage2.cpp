#include "Stage2.h"
#include "Stage1.h"

bool levelUp(PartyList& party, const char* searchName)
{
    int index = findHeroIndex(party, searchName);
    if (index == -1) return false;

    party.heroes[index].level++;
    party.heroes[index].hp += 10;
    return true;
}

bool equipWeapon(PartyList& party, const char* searchName, Item newWeapon)
{
    int index = findHeroIndex(party, searchName);
    if (index == -1) return false;

    party.heroes[index].weapon = newWeapon;
    return true;
}

bool damageHero(PartyList& party, const char* searchName, int amount)
{
    int index = findHeroIndex(party, searchName);
    if (index == -1) return false;

    party.heroes[index].hp -= amount;
    if (party.heroes[index].hp < 0)
    {
        party.heroes[index].hp = 0;
    }
    return true;
}

bool healHero(PartyList& party, const char* searchName, int amount)
{
    int index = findHeroIndex(party, searchName);
    if (index == -1) return false;

    party.heroes[index].hp += amount;
    if (party.heroes[index].hp > 100)
    {
        party.heroes[index].hp = 100;
    }
    return true;
}