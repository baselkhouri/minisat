#include "coloring.h"

// ***************************************************************************
// A main file that uses the Coloring and Graph classes.
// Note that you can create your own graphs and test their k-colorability for
// different values of k.
// ***************************************************************************
int main()
{
    printf("\n====================================================\n\n");
    printf("The k-coloring problem\n");
    printf("\n====================================================\n\n\n");

    int k = 5; // The number of colors

    // Create a graph with 3 nodes.
    Graph g(4);

    // Add edges to the graph - this is a simple triangle.
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);

    
    // Model the problem for k.
    Coloring c(g, k);

    // Now ask if it is colorable
    bool bResult = c.isColorable();

    if (bResult) {
        vector<vector<Minisat::lbool>> allColorings;
        c.givemeAllColoring(allColorings);
        printf("\tThe graph is %d-colorable. Additionally, there are %ld possible colorings.\n\n", k, allColorings.size());
    }
    else {
        printf("\tNo %d-coloring is found!\n\n", k);
    }
    return 0;
}
