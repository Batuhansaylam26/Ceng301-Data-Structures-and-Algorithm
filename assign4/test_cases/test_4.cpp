#include "Graph.h"
#include <iostream>

using namespace std;

int main() {
    // Define edges
    Edge edges_array[2] = {
        {0, 1, 2},
        {2, 3, 5}
    };
    int num_nodes = 5;
    int num_edges = 2;

    // Create graph
    Graph graph(edges_array, num_nodes, num_edges);

    for(int i = 0; i < num_nodes; i++)
    {
        int *distances = graph.dijkstra(i);
        for(int j = 0; j < num_nodes; j++)
        {
            if(distances[j] == -1)
                cout << "It is not possible to reach from node " << i << " to node " << j << "." << endl; 
            else
                cout << "Distance from node " << i << " to node " << j << " is " << distances[j] << "." << endl;
        }
        delete[] distances;
    }
    return 0;
}