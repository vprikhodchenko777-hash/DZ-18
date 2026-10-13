#include <iostream>
#include <windows.h>
#include "Hero.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "FileIO.h"

using namespace std;

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    PartyList party;

    cout << "=== 1. Набір героїв у табір ===" << endl;
    recruitHero(party, { "Артур", "Воїн", 1, 90, {15, 8, 5}, {"Меч", 25} });
    recruitHero(party, { "Мерлін", "Маг", 3, 70, {4, 6, 25}, {"Жезл", 30} });
    recruitHero(party, { "Леголас", "Лучник", 2, 80, {8, 18, 7}, {"Лук", 20} });

    cout << "\n=== 2. Початковий вивід табору ===" << endl;
    printParty(party);

    cout << "\n=== 3. Читання героя за іменем (Мерлін) ===" << endl;
    Character merlin = getHeroByName(party, "Мерлін");
    if (merlin.level != -1)
    {
        cout << "Знайдено: " << merlin.name << " (" << merlin.classType << "), Рівень: " << merlin.level << endl;
    }

    cout << "\n=== 4 & 5. Підвищення рівня та зміна зброї ===" << endl;
    levelUp(party, "Артур");
    equipWeapon(party, "Леголас", { "Ельфійський лук", 45 });

    cout << "\n=== 6. Бій (шкода та лікування) ===" << endl;
    damageHero(party, "Мерлін", 40);
    healHero(party, "Мерлін", 15);

    cout << "\n=== 7. Загальна сила табору ===" << endl;
    cout << "Загальна сила: " << totalPartyPower(party) << endl;

    cout << "\n=== 8. Найсильніший герой за характеристиками ===" << endl;
    int strongestIdx = findStrongestHeroIndex(party);
    if (strongestIdx != -1)
    {
        cout << "Найсильніший: " << party.heroes[strongestIdx].name << endl;
    }

    cout << "\n=== 9. Видалення героя ('Артур загинув в бою') ===" << endl;
    dismissHero(party, "Артур");

    cout << "\n=== Сортування табору за спаданням рівня ===" << endl;
    sortByLevelDescending(party);

    cout << "\n=== 10. Вивід табору після всіх операцій ===" << endl;
    printParty(party);

    cout << "\n=== Збереження та завантаження з файлу ===" << endl;
    savePartyToFile(party, "party_save.bin");

    delete[] party.heroes;
    party.heroes = nullptr;
    party.size = 0;

    loadPartyFromFile(party, "party_save.bin");
    cout << "\nТабір успішно завантажено з файлу:" << endl;
    printParty(party);

    // 11. Звільнення пам'яті
    delete[] party.heroes;

    return 0;
}