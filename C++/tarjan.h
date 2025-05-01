#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Graph {
    int V, timer;
    vector<vector<int>> adj;
    vector<int> discovery, low, parent;
    vector<bool> articulation;
    vector<pair<int, int>> bridges;

    Graph(int V) : V(V), adj(V), discovery(V, 0), low(V, 0), parent(V, -1), articulation(V, false), timer(0) {}

    void addEdge(int u, int v);
    void DFS(int u);
    void findArticulationPointsAndBridges();
};
