 /*
    Implement the Graph class functions declared in Graph.h in this file.
    Don't define global functions.
    Don't define global variables.
 */


#include "Graph.h"
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

Graph::Graph(Edge* edges_array, int num_nodes, int num_edges) {
    this->num_nodes = num_nodes;
    this->num_edges = num_edges;
    adjMatrix = new int*[num_nodes];
    for (int i = 0; i < num_nodes; ++i) {
        adjMatrix[i] = new int[num_nodes];
    }
    for (int i = 0; i < num_nodes; ++i){
        for (int j = 0; j < num_nodes; ++j){
            adjMatrix[i][j] = numeric_limits<int>::max(); 
        }
    }

    for (int i = 0; i < num_edges; ++i) {
        int src = edges_array[i].node1;
        int dest = edges_array[i].node2;
        int weight = edges_array[i].length;
        adjMatrix[src][dest] = weight;
        adjMatrix[dest][src] = weight;
    }

}

Graph::~Graph() {
    for (int i = 0; i < num_nodes; ++i) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

int* Graph::dijkstra(int source) {
    int* distances = new int[num_nodes];
    bool* visited = new bool[num_nodes];

    for (int i = 0; i < num_nodes; ++i) {
        distances[i] = numeric_limits<int>::max(); 
        visited[i] = false;
    }
    distances[source] = 0;
    for(int count = 0; count < num_nodes - 1; count++) {
        int min = numeric_limits<int>::max(); 
        int min_index;
        for(int j = 0; j < num_nodes; j++) {
            if (!visited[j] && distances[j] <= min) {
                min = distances[j];
                min_index = j;
            }
        }

        visited[min_index] = true;
        for(int v = 0; v < num_nodes; v++) {
            if (!visited[v] && adjMatrix[min_index][v] != numeric_limits<int>::max() && distances[min_index] != numeric_limits<int>::max() && distances[min_index] + adjMatrix[min_index][v] < distances[v]) {
                distances[v] = distances[min_index] + adjMatrix[min_index][v];
            }
        }
    }

    for(int i = 0; i < num_nodes; i++) {
        if (distances[i] == numeric_limits<int>::max()) { 
            distances[i] = -1;
        }
    }
    delete[] visited;
    return distances;

}


int* Graph::get_centroids(){
    int* centroid=new int[num_nodes];
    int* dist;
    int sizeOfDist;
    int sizeOfadj;
    int newSize;
    newSize=1;
    int* newCentroid;
    int index;
    for(int i=0;i<num_nodes;i++){
        centroid[i]=0;
    }
    for(int i=0;i<num_nodes;i++){
        dist=dijkstra(i);
        sizeOfDist=0;
        sizeOfadj=1;
        for(int j=0;j<num_nodes;j++){
            if(adjMatrix[i][j]!=numeric_limits<int>::max()){
                sizeOfadj++;
            }
        }
        for(int k=0;k<num_nodes;k++){
            if(dist[k]!=-1){
                sizeOfDist++;
            }
        }
        if(sizeOfDist==sizeOfadj){
            centroid[i]=1;
            newSize++;
        }
        

        
    }

    
    if(newSize-1==num_nodes){
        int* dist;
        int min;
        min=numeric_limits<int>::max();
        int min_index;
        min_index=0;
        newSize=2;
        newCentroid=new int[newSize];
        newCentroid[0]=newSize-1;
        for(int i=0;i<num_nodes;i++){
            int sum;
            sum=0;
            dist=dijkstra(i);
            for(int j=0;j<num_nodes;j++){
                if(dist[j]!=-1){
                    sum+=dist[j];
                }
            }
            if(sum<min){
                min=sum;
                min_index=i;
            }
            
            
        }
        newCentroid[1]=min_index;

    }else{
        newCentroid=new int[newSize];
        newCentroid[0]=newSize-1;
        index=1;
        for(int i=0;i<num_nodes;i++){
            if(centroid[i]==1){
                newCentroid[index]=i;
                index++;
            }
        }
        
    }


    return newCentroid;
    
}

int* Graph::nodes_in_connected_component_with_centroid (int centroid_node){
    int sizeOfCompentArray;
    sizeOfCompentArray=0;
    int index;
    int* components=new int[num_nodes];
    for(int j=0;j<num_nodes;j++){
        if(adjMatrix[centroid_node][j]!=numeric_limits<int>::max()|| j==centroid_node){
            components[j]=1;
            sizeOfCompentArray++;
        }
    }
    int* newComponents=new int[sizeOfCompentArray];
    newComponents[0]=sizeOfCompentArray;
    index=1;
    for(int i=0;i<num_nodes;i++){
        if(components[i]==1){
            newComponents[index]=i;
            index++;
        }
    }


    return newComponents;

    
}


int Graph::get_centroid_of_connected_component_containing(int node){
    int* centroids = get_centroids();
    int num_centroids = centroids[0];
    for(int i = 1; i <= num_centroids; i++){
        int *nodes = nodes_in_connected_component_with_centroid(centroids[i]);
        for (int j = 1; j<= nodes[0];j++){
            if(node==nodes[j]){
                return centroids[i];
            }
        }
    }
}
