#include "Stage3.h"
#include "Stage1.h"

bool dismissHero(PartyList& party, const char* searchName)
{
    int index = findHeroIndex(party, searchName);
    if (index == -1) return false;

    if (party.size == 1)
    {
        delete[] party.heroes;
        party.heroes = nullptr;
        party.size = 0;
        return true;
    }

    Character* temp = new Character[party.size - 1];
    int dest = 0;
    for (int i = 0; i < party.size; i++)
    {
        if (i == index) continue;
        temp[dest++] = party.heroes[i];
    }
    delete[] party.heroes;
    party.heroes = temp;
    party.size--;
    return true;
}

int totalPartyPower(const PartyList& party)
{
    int total = 0;
    for (int i = 0; i < party.size; i++)
    {
        total += (party.heroes[i].level * 10 + party.heroes[i].weapon.power);
    }
    return total;
}

int findStrongestHeroIndex(const PartyList& party)
{
    if (party.size == 0) return -1;

    int maxIndex = 0;
    int maxSum = party.heroes[0].stats.strength + party.heroes[0].stats.agility + party.heroes[0].stats.intelligence;

    for (int i = 1; i < party.size; i++)
    {
        int currentSum = party.heroes[i].stats.strength + party.heroes[i].stats.agility + party.heroes[i].stats.intelligence;
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            maxIndex = i;
        }
    }
    return maxIndex;
}

void sortByLevelDescending(PartyList& party)
{
    if (party.size <= 1) return;

    for (int i = 0; i < party.size - 1; i++)
    {
        for (int j = 0; j < party.size - i - 1; j++)
        {
            if (party.heroes[j].level < party.heroes[j + 1].level)
            {
                Character temp = party.heroes[j];
                party.heroes[j] = party.heroes[j + 1];
                party.heroes[j + 1] = temp;
            }
        }
    }
}