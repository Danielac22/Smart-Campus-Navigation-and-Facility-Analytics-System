
#include <iostream>
#include <string>
#include <stdexcept>

#include "CampusGraph.h"
#include "DepartmentTree.h"
#include "FacilitiesManager.h"

using namespace std;

// Get and validate the menu choice.
int getMenuChoice() {
    string input;

    cout << "\nEnter your choice: ";
    getline(cin, input);

    try {
        size_t position;
        int choice = stoi(input, &position);

        if (position != input.length()) {
            return -1;
        }

        return choice;
    }
    catch (const invalid_argument&) {
        return -1;
    }
    catch (const out_of_range&) {
        return -1;
    }
}

// Display main menu.
void displayMenu() {
    cout << "\n====================================\n";
    cout << " SMART CAMPUS NAVIGATION SYSTEM\n";
    cout << "====================================\n";

    cout << "\nFACILITIES\n";
    cout << "1. View all facilities\n";
    cout << "2. Search for a facility by ID\n";
    cout << "3. Search for a facility by name\n";
    cout << "4. Search for a facility by category\n";
    cout << "5. Display facility category report\n";

    cout << "\nCAMPUS GRAPH\n";
    cout << "6. Display campus graph\n";
    cout << "7. Display graph statistics\n";
    cout << "8. Find reachable buildings (BFS)\n";

    cout << "\nDEPARTMENT TREE\n";
    cout << "9. Display preorder traversal\n";
    cout << "10. Display postorder traversal\n";
    cout << "11. Display level-order traversal\n";
    cout << "12. Display department statistics\n";
    cout << "13. Add a department\n";

    cout << "\n0. Exit\n";
    cout << "====================================\n";
}

int main() {
    // Create system components.
    FacilityManager facilitiesManager;
    CampusGraph campusGraph;
    DepartmentTree departmentTree;

    cout << "Loading Smart Campus Navigation System...\n\n";

    // Load project data.
    campusGraph.loadBuildings("data/buildings.txt");
    campusGraph.loadConnections("data/connections.txt");
    facilitiesManager.loadFacilities("data/facilities.txt");
    departmentTree.loadDepartments("data/departments.txt");

    cout << "\nSmart Campus Navigation System loaded.\n";

    int choice;

    // Repeat menu until the user exits.
    do {
        displayMenu();
        choice = getMenuChoice();

        switch (choice) {

        case 1:
            facilitiesManager.displayAllFacilities();
            break;

        case 2: {
            string id;
            cout << "Enter facility ID: ";
            getline(cin, id);
            facilitiesManager.searchByID(id);
            break;
        }

        case 3: {
            string name;
            cout << "Enter facility name: ";
            getline(cin, name);
            facilitiesManager.searchByName(name);
            break;
        }

        case 4: {
            string category;
            cout << "Enter facility category: ";
            getline(cin, category);
            facilitiesManager.searchByCategory(category);
            break;
        }

        case 5:
            facilitiesManager.categoryReport();
            break;

        case 6:
            campusGraph.displayGraph();
            break;

        case 7:
            campusGraph.displayGraphStats();
            break;

        case 8: {
            string building;
            cout << "Enter building name: ";
            getline(cin, building);
            campusGraph.bfsReachable(building);
            break;
        }

        case 9:
            cout << "\nDepartment Preorder Traversal:\n";
            departmentTree.preorderTraversal(
                departmentTree.getRoot()
            );
            break;

        case 10:
            cout << "\nDepartment Postorder Traversal:\n";
            departmentTree.postorderTraversal(
                departmentTree.getRoot()
            );
            break;

        case 11:
            cout << "\nDepartment Level-Order Traversal:\n";
            departmentTree.levelOrderTraversal();
            break;

        case 12: {
            DepartmentNode* root = departmentTree.getRoot();

            if (root == nullptr) {
                cout << "No departments are loaded.\n";
            }
            else {
                cout << "Total departments: "
                     << departmentTree.countDepartments() << endl;

                cout << "Leaf departments: "
                     << departmentTree.countLeaves(root) << endl;

                cout << "Height of the department tree: "
                     << departmentTree.getHeight(root) << endl;
            }
            break;
        }

        case 13: {
            string name;
            string parent;

            cout << "Enter new department name: ";
            getline(cin, name);

            cout << "Enter parent department name: ";
            getline(cin, parent);

            if (name.empty() || parent.empty()) {
                cout << "Department name and parent cannot be blank.\n";
            }
            else {
                departmentTree.addDepartment(name, parent);
            }
            break;
        }

        case 0:
            cout << "Exiting Smart Campus System.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }

    } while (choice != 0);

    return 0;
}
