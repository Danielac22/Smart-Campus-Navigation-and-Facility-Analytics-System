# Smart-Campus-Navigation-and-Facility-Analytics-System
# Smart Campus Navigation and Facility Analytics System
**Project 2 – Milestone 1**

## Project Overview

This project is a C++ application designed to organize and manage campus information using different data structures. The system allows users to search for campus facilities, explore building connections, identify reachable buildings, and view academic department information.

## Data Structures Used

**1. Custom Hash Table**

Stores campus facility information and allows users to search for facilities using their unique IDs.

**2. Campus Graph**

Uses an undirected graph represented by an adjacency list. Each building is a vertex, and each connection between buildings is an edge. Breadth-First Search (BFS) is used to identify reachable buildings and calculate their distances.

**3. Department Tree**

Uses a general tree to represent the academic department hierarchy. Each department can have multiple child departments. The system supports adding, searching, and displaying departments using preorder traversal.

## Milestone 1 Features

- Load campus information from text files.
- Display all campus facilities.
- Search for facilities by ID.
- Display campus buildings and their connections.
- Show total buildings, connections, and building degrees.
- Use BFS to find reachable buildings.
- Add and search academic departments.
- Display the department hierarchy.
- Perform preorder traversal.

## Project File Structure


Smart-Campus-Navigation-and-Facility-Analytics-System/
│
├── data/
│   ├── buildings.txt
│   ├── connections.txt
│   ├── facilities.txt
│   └── departments.txt
│
├── include/
│   ├── CampusGraph.h
│   └── DepartmentTree.h
│
├── src/
│   ├── CampusGraph.cpp
│   ├── DepartmentTree.cpp
│   └── main.cpp
│
├── tests/
│   ├── CampusGraphTest.cpp
│   └── DepartmentTreeTest.cpp
│
├── testdata/
├── README.txt
├── CONTRIBUTIONS.txt
├── design_document.txt
├── test_results.txt
└── .gitignore


Additional facility and hash-table source files will be included as the team completes integration.

## Compilation and Execution

The project is written in C++ and can be compiled using g++.

To compile and run the Campus Graph module independently, from the project root directory:


g++ -std=c++17 src/CampusGraph.cpp tests/CampusGraphTest.cpp -o campus_graph_test
./campus_graph_test


The complete application will use a shared `main.cpp` that integrates the facility, graph, and department modules. The final Milestone 1 build command will be added after integration.

The complete application must also support an optional data-directory argument. Without an argument, it will load files from `data/`.

## Team Contributions

**Member A - Lucy Naggayi:** Facility database, custom hash table, and facility ID search.

**Member B – Catarina Antonio:** Campus graph, adjacency list, graph statistics, BFS reachability, and graph testing.

**Member C - Daniela Cortez:** Department tree, department operations, and preorder traversal.

## Additional Information

The program reads campus data from external text files rather than hard-coded records. It includes validation for invalid records and is designed to handle missing files, duplicate entries, and unknown references without crashing.

The project is developed collaboratively using GitHub, with each team member responsible for implementing and testing their assigned module.
