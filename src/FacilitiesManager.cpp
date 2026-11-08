
#include "FacilitiesManager.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

// Remove whitespace 
static string trim(const string& value) {
    size_t first = value.find_first_not_of(" \t\r\n");

    if (first == string::npos) {
        return "";
    }

    size_t last = value.find_last_not_of(" \t\r\n");
    return value.substr(first, last - first + 1);
}

static string normalizeID(const string& id) {
    string result = trim(id);

    transform(result.begin(), result.end(), result.begin(),
        [](unsigned char c) {
            return static_cast<char>(toupper(c));
        });

    return result;
}

// Display one facility
static void displayFacility(const Facility& facility) {
    cout << "\nID: " << facility.facilityID << endl;
    cout << "Name: " << facility.facilityName << endl;
    cout << "Building: " << facility.buildingName << endl;
    cout << "Category: " << facility.category << endl;
}

// Load facilities from a file
bool FacilityManager::loadFacilities(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return false;
    }

    string line;
    int lineNumber = 0;
    int accepted = 0;
    int rejected = 0;

    while (getline(file, line)) {
        lineNumber++;

        line = trim(line);

        // Skip blank lines and comments
        if (line.empty() || line[0] == '#') {
            continue;
        }

        stringstream ss(line);

        string id;
        string name;
        string building;
        string category;
        string extra;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, building, '|');
        getline(ss, category, '|');

        // Reject records with missing or extra field
        if (id.empty() || name.empty() ||
            building.empty() || category.empty() ||
            getline(ss, extra, '|')) {

            cout << "Warning: " << filename
                 << " line " << lineNumber
                 << ": Invalid facility record." << endl;

            rejected++;
            continue;
        }

        id = normalizeID(id);
        name = trim(name);
        building = trim(building);
        category = trim(category);

        if (id.empty() || name.empty() ||
            building.empty() || category.empty()) {

            cout << "Warning: " << filename
                 << " line " << lineNumber
                 << ": Empty facility field." << endl;

            rejected++;
            continue;
        }

        // Reject duplicate IDs
        if (facilityTable.searchByID(id) != nullptr) {
            cout << "Warning: " << filename
                 << " line " << lineNumber
                 << ": Duplicate facility ID." << endl;

            rejected++;
            continue;
        }

        Facility facility(id, name, category, building);

        facilities.push_back(facility);
        facilityTable.insert(facility);

        accepted++;
    }

    file.close();

    cout << filename << ": " << accepted
         << " accepted, " << rejected << " rejected." << endl;

    return true;
}

// Search by facility ID using hash table
void FacilityManager::searchByID(const string& id) {
    string normalizedID = normalizeID(id);

    Facility* result = facilityTable.searchByID(normalizedID);

    if (result != nullptr) {
        cout << "\nFacility Found";
        displayFacility(*result);
    }
    else {
        cout << "Facility not found." << endl;
    }
}

// Search by facility name
void FacilityManager::searchByName(const string& name) {
    bool found = false;

    for (const Facility& facility : facilities) {
        if (facility.facilityName == trim(name)) {
            displayFacility(facility);
            found = true;
        }
    }

    if (!found) {
        cout << "No facility found." << endl;
    }
}

// Search by category
void FacilityManager::searchByCategory(const string& category) {
    bool found = false;

    for (const Facility& facility : facilities) {
        if (facility.category == trim(category)) {
            displayFacility(facility);
            found = true;
        }
    }

    if (!found) {
        cout << "No facilities found." << endl;
    }
}

// Display facilities in file order
void FacilityManager::displayAllFacilities() {
    if (facilities.empty()) {
        cout << "No facilities are loaded." << endl;
        return;
    }

    for (const Facility& facility : facilities) {
        displayFacility(facility);
    }

    cout << "\nTotal facilities: " << facilities.size() << endl;
}

// Display number of facilities in each category
void FacilityManager::categoryReport() {
    map<string, int> report;

    for (const Facility& facility : facilities) {
        report[facility.category]++;
    }

    cout << "\n===== CATEGORY REPORT =====\n";

    for (const auto& item : report) {
        cout << item.first << ": " << item.second << endl;
    }
}
