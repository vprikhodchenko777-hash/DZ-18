#include "Stage1.h"
#include <iostream>
#include <cstring>

using namespace std;

void recruitHero(PartyList& party, Character newHero)
{
    Character* temp = new Character[party.size + 1];
    for (int i = 0; i < party.size; i++)
    {
        temp[i] = party.heroes[i];
    }
    temp[party.size] = newHero;
    delete[] party.heroes;
    party.heroes = temp;
    party.size++;
}

int findHeroIndex(const PartyList& party, const char* searchName)
{
    for (int i = 0; i < party.size; i++)
    {
        if (strcmp(party.heroes[i].name, searchName) == 0)
        {
            return i;
        }
    }
    return -1;
}

Character getHeroByName(const PartyList& party, const char* searchName)
{
    int index = findHeroIndex(party, searchName);
    if (index != -1)
    {
        return party.heroes[index];
    }
    Character emptyHero{};
    emptyHero.level = -1;
    return emptyHero;
}

void printParty(const PartyList& party)
{
    if (party.size == 0)
    {
        cout << "Табір порожній!" << endl;
        return;
    }
    for (int i = 0; i < party.size; i++)
    {
        cout << "\n=====================" << endl;
        cout << "Ім'я: " << party.heroes[i].name << endl;
        cout << "Клас: " << party.heroes[i].classType << endl;
        cout << "Рівень: " << party.heroes[i].level << endl;
        cout << "HP: " << party.heroes[i].hp << endl;
        cout << "Сила: " << party.heroes[i].stats.strength << endl;
        cout << "Спритність: " << party.heroes[i].stats.agility << endl;
        cout << "Інтелект: " << party.heroes[i].stats.intelligence << endl;
        cout << "Зброя: " << party.heroes[i].weapon.name << endl;
        cout << "Сила зброї: " << party.heroes[i].weapon.power << endl;
    }
}