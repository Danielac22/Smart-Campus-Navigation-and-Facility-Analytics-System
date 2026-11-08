
#include "../include/CampusGraph.h"
#include <iostream>

using namespace std;

int main() {
    CampusGraph graph;
    //Data.
    graph.loadBuildings("data/buildings.txt");
    graph.loadConnections("data/connections.txt");

    cout << "\n---- CAMPUS GRAPH ----\n";
    graph.displayGraph();

    cout << "\n---- GRAPH STATISTICS ----\n";
    graph.displayGraphStats();

    cout << "\n---- BFS ----\n";
    graph.bfsReachable("Library");

    cout << "\n---- ISOLATED BUILDING ----\n";
    graph.bfsReachable("Observatory");

    cout << "\n---- UNKNOWN BUILDING ----\n";
    graph.bfsReachable("Unknown Building");

    return 0;
}
