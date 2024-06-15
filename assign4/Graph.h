//Graph.h
/*
    DON'T CHANGE THE EXISTING FUNCTION SIGNATURES AND VARIABLE NAMES
    IF YOU NEED, YOU CAN ADD NEW FUNCTIONS AND VARIABLES
*/
#ifndef GRAPH_H
#define GRAPH_H
#include "Edge.h"

class Graph
{
private:
    /*
    Since arrays are indeed pointers, you may use a double pointer as a matrix.
    You can allocate it using new or malloc (multiple new or malloc operations may be needed.).
    */
    int** adjMatrix;
    int num_nodes;
    int num_edges;
    /* ADD MORE PRIVATE VARIABLES/FUNCTIONS IF NEEDED */
    
public:
    Graph (Edge* edges_array, int num_nodes, int num_edges);
    ~Graph();
    /* 
    dijkstra function returns a dynamically allocated array of integers, corresponding to distances from source node to nodes.
    For example 0th element of the returned array is the distance from source node to node 0.
    If it is not possible to reach a node, you may add -1  to the array as an exceptional value.
    If the length of the returned array is not equal to number of nodes, you may get a segmentation fault.
    */
    int* dijkstra(int source);
    
    /*
    get_centroids function returns a dynamically allocated array of integers,
    0th element of the returned array will be number of connected components
    The other elements are centroid nodes sorted in ascending order.
    For example the 1st element of the returned array is the centroid node with the smallest value.
    Let's name the returned array as returned_array,
    If the length of the returned array is not equal to returned_array[0]+1, you may get a segmentation fault
    */
    int* get_centroids();
    
    
    int get_centroid_of_connected_component_containing(int node);
    
    /*
    nodes_in_connected_component_with_centroid function returns a dynamically allocated array of integers.
    If the given node is not a centroid print: Returned array will have only one element, this element will be 0.
    Else,
    0th element is the number of nodes in the connected component (including the centroid)
    The other elements are nodes in that connected component sorted in ascending order.
    For example the 1st element of the returned array is the node with the smallest value in that connected component.
    Let's name the returned array as returned_array,
    If the length of the returned array is not equal to returned_array[0]+1, you may get a segmentation fault
    */
    int* nodes_in_connected_component_with_centroid (int centroid_node);
    
    /* ADD MORE PUBLIC FUNCTIONS IF NEEDED */
};
#endif