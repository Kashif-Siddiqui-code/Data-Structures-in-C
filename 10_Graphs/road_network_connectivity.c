/*
Road Network Connectivity
Imagine you are working with a road management system that monitors cities and roads connecting them. Each road allows traffic to flow in one direction (represented by a directed edge in a graph). The management wants to know whether every city in the network is reachable from any other city, ensuring smooth transportation throughout the country.
In this scenario, cities are represented as nodes in a directed graph, and roads between cities as directed edges. The goal is to check if the road network is connected, meaning there is a path from any city to all other cities, and vice versa.
Problem Statement
You are given a directed graph representing cities and one-way roads. Write a program to check whether the graph is connected. A directed graph is connected if:
All nodes (cities) can be reached starting from any given node.
Every node must also have a path back to any other node.

Input Format
An integer n representing the number of cities (nodes).
An integer m representing the number of one-way roads (edges).
m pairs of integers, where each pair (u, v) represents a one-way road from city u to city v.

Output Format
Print "The road network is connected." if all nodes are reachable from any starting city.
Print "The road network is not connected." if there is any city that cannot be reached.

Example
Sample Input 1
4
5
1 2
2 3
3 4
4 1
2 4

Sample Output 1
The road network is not connected.

*/


#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];
int reverseGraph[MAX][MAX];
int visited[MAX];
int n;

// DFS function
void dfs(int node, int arr[MAX][MAX]) {
    visited[node] = 1;

    for(int i = 1; i <= n; i++) {
        if(arr[node][i] == 1 && !visited[i]) {
            dfs(i, arr);
        }
    }
}
// Function to reset visited array
void resetVisited() {
    for(int i = 1; i <= n; i++) {
        visited[i] = 0;
    }
}
int main() {
    int m;
    scanf("%d", &n);
    scanf("%d", &m);

    // Input edges
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        // reverse graph
        reverseGraph[v][u] = 1;
    }
    // DFS on original graph
    dfs(1, graph);
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            printf("The road network is not connected.");
            return 0;
        }
    }
    // Reset visited array
    resetVisited();
    // DFS on reversed graph
    dfs(1, reverseGraph);

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            printf("The road network is not connected.");
            return 0;
        }
    }
    printf("The road network is connected.");
    return 0;
}
