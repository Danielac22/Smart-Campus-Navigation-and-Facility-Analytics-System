#ifndef FACILITY_H
#define FACILITY_H

#include <string>

using namespace std;

struct Facility {

    string facilityID;
    string facilityName;
    string category;
    string buildingName;

    Facility() // default construct 
    {
        facilityID = "";
        facilityName = "";
        category = "";
        buildingName = "";
    }

    Facility(string id, string facility, string cat, string building) { // parameterized construct 
        
        facilityID = id;
        facilityName = facility;
        category = cat;
        buildingName = building;
    }
};

#endif
