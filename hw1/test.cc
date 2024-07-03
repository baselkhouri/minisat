#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "coloring.h"

using namespace std;

// Helper function to create a graph and add edges
Graph createGraph(int numNodes, const vector<pair<int, int>>& edges) {
    Graph g(numNodes);
    for (const auto& edge : edges) {
        if (edge.first <= edge.second) {
            g.addEdge(edge.first, edge.second);
        } else {
            g.addEdge(edge.second, edge.first);
        }
    }
    return g;
}

// Function to generate a random graph
vector<pair<int, int>> generateRandomEdges(int numNodes, int numEdges) {
    vector<pair<int, int>> edges;
    for (int i = 0; i < numEdges; ++i) {
        int from = rand() % numNodes;
        int to = rand() % numNodes;
        if (from <= to) {
            edges.push_back({from, to});
        } else {
            edges.push_back({to, from});
        }
    }
    return edges;
}

// Function to test the colorability of a graph
void testGraph(int testNumber, int k, int numNodes, const vector<pair<int, int>>& edges) {
    Graph g = createGraph(numNodes, edges);
    Coloring c(g, k);

    bool bResult = c.isColorable();
    cout << "Test " << testNumber << ": Graph with " << numNodes << " nodes, " << edges.size() << " edges, and k = " << k << endl;

    if (bResult) {
        vector<vector<Minisat::lbool>> allColorings;
        c.givemeAllColoring(allColorings);
        cout << "\tThe graph is " << k << "-colorable. Additionally, there are " << allColorings.size() << " possible colorings." << endl;
    } else {
        cout << "\tNo " << k << "-coloring is found!" << endl;
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    cout << "\n====================================================\n\n";
    cout << "The k-coloring problem\n";
    cout << "\n====================================================\n\n\n";

    int numTests = 1000;

    for (int i = 0; i < numTests; ++i) {
        int numNodes = rand() % 10 + 1; // Random number of nodes between 1 and 10
        int numEdges = rand() % (numNodes * (numNodes - 1) / 2); // Random number of edges
        int k = rand() % 10 + 1; // Random k between 1 and 10

        vector<pair<int, int>> edges = generateRandomEdges(numNodes, numEdges);
        testGraph(i + 1, k, numNodes, edges);
    }

    return 0;
}
