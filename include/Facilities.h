#ifndef FACILITY_H
#define FACILITY_H

#include <string>

using namespace std;

struct Facility {

    string facilityID;
    string facilityName;
    string category;
    string buildingName;

 // default construct 
    Facility() 
    {
        facilityID = "";
        facilityName = "";
        category = "";
        buildingName = "";
    }
// parameterized construct
    Facility(string id, string facility, string cat, string building) {  
        
        facilityID = id;
        facilityName = facility;
        category = cat;
        buildingName = building;
    }
};

#endif
