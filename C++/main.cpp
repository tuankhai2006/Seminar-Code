#include "tarjan.h"

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    Graph g(V);

    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter " << E << " edges (u v pairs, 0-based indexing):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.findArticulationPointsAndBridges();

    return 0;
}