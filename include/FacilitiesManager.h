#ifndef FACILITYMANAGER_H
#define FACILITYMANAGER_H

#include <vector>
#include <string>
#include "Facilities.h"
#include "HashTable.h"

using namespace std;

class FacilityManager {
    
private:

    vector<Facility> facilities;
    HashTable facilityTable;

public:

//setters and getters 
    bool loadFacilities(const string& filename);
    void searchByID(const string& id);
    void searchByName(const string& name);
    void searchByCategory(const string& category);


    void displayAllFacilities(); //display all facilities 
    void categoryReport(); //report by category 
};

#endif
