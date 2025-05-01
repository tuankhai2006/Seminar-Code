class Graph:
    def __init__(self, V):
        self.V = V
        self.timer = 0
        self.adj = [[] for _ in range(V)]
        self.discovery = [0] * V
        self.low = [0] * V
        self.parent = [-1] * V
        self.articulation = [False] * V
        self.bridges = []

    def add_edge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)  # Undirected graph

    def dfs(self, u):
        self.timer += 1
        self.discovery[u] = self.low[u] = self.timer
        children = 0

        for v in self.adj[u]:
            if self.discovery[v] == 0:  # Tree edge
                self.parent[v] = u
                children += 1
                self.dfs(v)

                self.low[u] = min(self.low[u], self.low[v])

                # Articulation point check
                if self.parent[u] == -1 and children > 1:
                    self.articulation[u] = True
                if self.parent[u] != -1 and self.low[v] >= self.discovery[u]:
                    self.articulation[u] = True

                # Bridge check
                if self.low[v] > self.discovery[u]:
                    self.bridges.append((u, v))

            elif v != self.parent[u]:  # Back edge
                self.low[u] = min(self.low[u], self.discovery[v])

    def find_articulation_points_and_bridges(self):
        for i in range(self.V):
            if self.discovery[i] == 0:
                self.dfs(i)

        print("Articulation Points:")
        for i in range(self.V):
            if self.articulation[i]:
                print(i, end=" ")
        print("\nBridges:")
        for u, v in self.bridges:
            print(f"{u} - {v}")