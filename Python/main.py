from tarjan import Graph

if __name__ == "__main__":
    V = int(input("Enter the number of vertices: "))
    g = Graph(V)
    
    E = int(input("Enter the number of edges: "))
    print(f"Enter {E} edges (u v pairs, 0-based indexing):")
    for _ in range(E):
        u, v = map(int, input().split())
        g.add_edge(u, v)

    g.find_articulation_points_and_bridges()