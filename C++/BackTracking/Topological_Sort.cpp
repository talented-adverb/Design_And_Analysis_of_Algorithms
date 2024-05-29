#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
private:
    int numVertices; // Number of vertices
    list<int>* adj; // Adjacency lists
    vector<char> color; // Color of each vertex (WHITE, GRAY, BLACK)
    vector<int> parent; // Parent of each vertex
    vector<int> discoveryTime; // Discovery time of each vertex
    vector<int> finishTime; // Finish time of each vertex
    int time; // Global variable for time

    void DFSVisit(int u) {
        // Mark the current node as discovered and print it
        color[u] = 'G'; // GRAY
        discoveryTime[u] = ++time; // Set discovery time

        cout << "Visited " << u << endl;

        // Recur for all vertices adjacent to this vertex
        for (int v : adj[u]) {
            if (color[v] == 'W') { // WHITE
                parent[v] = u;
                DFSVisit(v);
            }
        }

        // Node is finished processing
        color[u] = 'B'; // BLACK
        finishTime[u] = ++time;
    }

public:
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adj = new list<int>[numVertices];
        color.assign(numVertices, 'W'); // WHITE
        parent.assign(numVertices, -1); // NIL
        discoveryTime.assign(numVertices, 0);
        finishTime.assign(numVertices, 0);
        time = 0;
    }

    ~Graph() {
        delete[] adj;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v); // Add v to u’s list.
    }

    void DFS() {
        // Initialize vertices
        for (int i = 0; i < numVertices; i++) {
            color[i] = 'W'; // WHITE
            parent[i] = -1; // NIL
        }

        time = 0; // Reset time

        // Call DFS-Visit for each vertex
        for (int i = 0; i < numVertices; i++) {
            if (color[i] == 'W') {
                DFSVisit(i);
            }
        }
    }
};

int main() {
    Graph g(4); // Creating a graph with 4 vertices

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal\n";
    g.DFS();
    return 0;
}