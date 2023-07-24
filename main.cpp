#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
using namespace std;

// Function to find loops using Depth-First Search
void findLoopsDFS() {
   
}

int main() {
    
    ifstream csvFile("input.csv"); 
    
    //unordered will be converter from the string to an index thus can be stored in adjacency matrix.
    unordered_map<string, int> nodeIndices;
    vector<vector<int>> adjacencyList;
    string sourceNode, targetNode;
    
    
    //read csv file
    int idx{0};
    while (csvFile >> sourceNode >> targetNode) {
        if (nodeIndices.find(sourceNode) == nodeIndices.end()) {
            nodeIndices[sourceNode] = idx++;
            adjacencyList.emplace_back(); 
        }

        if (nodeIndices.find(targetNode) == nodeIndices.end()) {
            nodeIndices[targetNode] = idx;
            adjacencyList.emplace_back(); 
        }

        int sourceIndex = nodeIndices[sourceNode];
        int targetIndex = nodeIndices[targetNode];
        adjacencyList[sourceIndex].push_back(targetIndex);
    }

    // Find loops in the graph using DFS
    vector<bool> visited(nodeIndices.size(), false);
    vector<int> path;

    for (int i = 0; i < idx; ++i) {
        if (!visited[i]) {
            findLoopsDFS();
        }
    }

    

    return 0;
}