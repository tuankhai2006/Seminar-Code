# CS163 Seminar Project: Graph Analysis

A project implementing graph analysis algorithms in **C++** and **Python** to identify **articulation points** and **bridges** in undirected graphs.

---

## 📑 Overview

This repository contains two implementations for finding articulation points (vertices whose removal increases the number of connected components) and bridges (edges whose removal increases the number of connected components) in a graph:

- **C++ Implementation**: A fast, compiled solution using adjacency lists and DFS.
- **Python Implementation**: A clean, interpretive solution for ease of understanding and modification.

Both programs take a graph as input (vertices and edges) and output the articulation points and bridges.

---

## 📂 Folder Structure

```
CS163-Seminar-Project/
├── C++/                # C++ implementation
│   ├── main.cpp        # Main C++ program
│   └── tarjan.h        # Header file for Tarjan's algorithm
├── Python/             # Python implementation
│   ├── main.py         # Main Python program
│   └── tarjan.py       # Tarjan's algorithm implementation
└── README.md           # Project documentation
```

---

## 🚀 Getting Started

### Prerequisites

- **C++**:
  - A C++ compiler (e.g., `g++`)
  - Tested with C++11 or later
- **Python**:
  - Python 3.x
  - No external libraries required
- A terminal or command prompt for running the programs

---

### 🛠️ Running the C++ Version

1. **Navigate** to the `/C++/` directory.
2. **Ensure** both `main.cpp` and `tarjan.h` are in the directory.
3. **Compile** the code:
   ```bash
   g++ main.cpp -o graph
   ```
4. **Run** the executable:
   - Linux/Mac: `./graph`
   - Windows: `graph.exe`
5. **Input**:
   - Enter the number of vertices (`V`) and edges (`E`).
   - For each edge, provide two integers `u` and `v` (space-separated) to denote an edge between vertices `u` and `v`.
   - Use **0-based indexing** (vertices in range `[0, V-1]`).
6. **Output**:
   - The program lists all articulation points and bridges in the graph.

**Example**:
```bash
Enter number of vertices and edges: 5 5
Enter edges (u v):
0 1
1 2
2 0
1 3
3 4
Output:
Articulation Points: 1, 3
Bridges: (1, 3), (3, 4)
```

---

### 🐍 Running the Python Version

1. **Navigate** to the `/Python/` directory.
2. **Ensure** both `main.py` and `tarjan.py` are in the directory.
3. **Run** the script:
   ```bash
   python3 main.py
   ```
   (Use `python main.py` if `python3` is not configured.)
4. **Input**:
   - Enter the number of vertices (`V`) and edges (`E`).
   - For each edge, provide two integers `u` and `v` (space-separated) to denote an edge between vertices `u` and `v`.
   - Use **0-based indexing** (vertices in range `[0, V-1]`).
5. **Output**:
   - The program lists all articulation points and bridges in the graph.

**Example**:
```bash
Enter number of vertices and edges: 5 5
Enter edges (u v):
0 1
1 2
2 0
1 3
3 4
Output:
Articulation Points: 1, 3
Bridges: (1, 3), (3, 4)
```

---

## 📝 Notes

- **Input Validation**: Ensure vertex indices are valid (in range `[0, V-1]`) and edges are undirected (the programs handle bidirectional edges internally).
- **Graph Constraints**: The graph should be undirected and may be disconnected. Self-loops and multiple edges are not supported.
- **Performance**:
  - The C++ version is optimized for speed using compiled code.
  - The Python version prioritizes readability and is slower for large graphs.

---

## 🧠 Algorithm Details

Both implementations use a **Depth-First Search (DFS)** approach to find articulation points and bridges:

- **Articulation Points**: A vertex is an articulation point if:
  - It is the root of the DFS tree and has at least two children.
  - It is not the root, and its removal disconnects a subtree (detected using low-link values).
- **Bridges**: An edge `(u, v)` is a bridge if its removal increases the number of connected components (detected when the low-link value of `v` exceeds the discovery time of `u`).

Time Complexity: **O(V + E)** for both implementations, where `V` is the number of vertices and `E` is the number of edges.

---

## 🤝 Contributing

Feel free to fork this repository, submit issues, or create pull requests to improve the code or documentation!

---

## 📬 Contact

For questions or feedback, reach out to the project maintainers or open an issue in the repository.

---

*Built for CS163 Seminar, 2025*