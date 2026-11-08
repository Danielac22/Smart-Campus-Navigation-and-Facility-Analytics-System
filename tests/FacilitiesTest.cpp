#include "FacilitiesManager.h"
#include <iostream>

using namespace std;

int main()
{
    FacilityManager manager;

    cout << "===== LOADING FACILITIES =====" << endl;

    if (!manager.loadFacilities("data/facilities.txt"))
    {
        cout << "Failed to load facilities." << endl;
        return 1;
    }

    cout << "\n===== ALL FACILITIES =====" << endl;
    manager.displayAllFacilities();

    cout << "\n===== SEARCH BY ID =====" << endl;
    manager.searchByID("F001");

    cout << "\n===== SEARCH BY NAME =====" << endl;
    manager.searchByName("Room 101");

    cout << "\n===== SEARCH BY CATEGORY =====" << endl;
    manager.searchByCategory("Classroom");

    cout << "\n===== CATEGORY REPORT =====" << endl;
    manager.categoryReport();

    return 0;
}