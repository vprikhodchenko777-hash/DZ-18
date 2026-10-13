#include "FileIO.h"
#include <fstream>

void savePartyToFile(const PartyList& party, const char* filename)
{
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) return;

    outFile.write(reinterpret_cast<const char*>(&party.size), sizeof(int));
    if (party.size > 0)
    {
        outFile.write(reinterpret_cast<const char*>(party.heroes), party.size * sizeof(Character));
    }
    outFile.close();
}

void loadPartyFromFile(PartyList& party, const char* filename)
{
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) return;

    delete[] party.heroes;
    party.heroes = nullptr;
    party.size = 0;

    inFile.read(reinterpret_cast<char*>(&party.size), sizeof(int));
    if (party.size > 0)
    {
        party.heroes = new Character[party.size];
        inFile.read(reinterpret_cast<char*>(party.heroes), party.size * sizeof(Character));
    }
    inFile.close();
}