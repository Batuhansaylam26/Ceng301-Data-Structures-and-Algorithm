#include "Graph.h"
#include<iostream>

using namespace std;

int main() {
    // Define edges
    Edge edges_array[10] = {
        {0, 1, 3},
        {0, 3, 3},
        {0, 4, 1},
        {2, 1, 3},
        {2, 4, 1},
        {2, 3, 3},
        {1, 4, 1},
        {4, 3, 1},
        {5, 6, 12},
        {5, 7, 18}
    };
    int num_nodes = 8;
    int num_edges = 10;

    // Create graph
    Graph graph(edges_array, num_nodes, num_edges);

    for(int i = 0; i < num_nodes; i++)
    {
        int *distances = graph.dijkstra(i);
        for(int j =0; j < num_nodes; j++)
        {
            if(distances[j] == -1)
                cout<<"It is not possible to reach from node "<<i<<" to node "<<j<<"."<<endl; 
            else
                cout<<"Distance from node "<<i<<" to node "<<j<<" is "<<distances[j]<<"."<<endl;
        }
        delete distances;
    }
    
    int* centroids = graph.get_centroids();
    int num_centroids = centroids[0];
    cout<<"Number of connected components is: "<<num_centroids<<endl;
    
    for(int i = 1; i <= num_centroids; i++)
    {
        cout<<"Nodes in the connected component with centroid "<<centroids[i]<<" is:"<<endl;
        int *nodes = graph.nodes_in_connected_component_with_centroid(centroids[i]);
        for (int j = 1; j<= nodes[0];j++)
            cout<<nodes[j]<<" ";
        cout<<endl;
        delete nodes;
    }
    
    for(int i = 0; i < num_nodes; i++)
    {
        cout<<"Centroid node of the connected component containing the node "<<i<<" is: node "<<graph.get_centroid_of_connected_component_containing(i)<<endl;
    }
    return 0;
}