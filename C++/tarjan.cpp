#include "tarjan.h"

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::DFS(int u) {
    discovery[u] = low[u] = ++timer;
    int children = 0;

    for (int v : adj[u]) {
        if (discovery[v] == 0) {
            parent[v] = u;
            children++;
            DFS(v);

            low[u] = min(low[u], low[v]);

            if (parent[u] != -1 && low[v] >= discovery[u])
                articulation[u] = true;

            if (low[v] > discovery[u])
                bridges.push_back({ u, v });

        }
        else if (v != parent[u]) {
            low[u] = min(low[u], discovery[v]);
        }
    }
    if (parent[u] == -1 && children > 1)
        articulation[u] = true;
}

void Graph::findArticulationPointsAndBridges() {
    for (int i = 0; i < V; i++) {
        if (discovery[i] == 0) {
            DFS(i);
        }
    }

    cout << "Articulation Points:\n";
    for (int i = 0; i < V; i++) {
        if (articulation[i]) cout << i << " ";
    }
    cout << "\nBridges:\n";
    for (auto& bridge : bridges) {
        cout << bridge.first << " - " << bridge.second << "\n";
    }
}