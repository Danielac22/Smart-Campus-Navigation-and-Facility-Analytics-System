
#ifndef CAMPUSGRAPH_H
#define CAMPUSGRAPH_H

#include <string>
#include <vector>

class CampusGraph {
private:
    std::vector<std::string> buildings;
    std::vector<std::vector<int>> adjacency;
    int connectionCount = 0;

    int findBuilding(const std::string& name) const;

public:
    //Load/validate campus data.
    void loadBuildings(const std::string& filename);
    void loadConnections(const std::string& filename);

    //Display graph info.
    void displayGraph() const;
    void displayGraphStats() const;

    //Operations.
    void bfsReachable(const std::string& start) const;
    void shortestPath(const std::string& start,
                      const std::string& destination) const;

    //Report.
    void connectivityReport() const;
};

#endif
