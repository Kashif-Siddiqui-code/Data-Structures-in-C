/*
Exploring City Routes
Imagine you work for the City Transportation Department, and they are trying to analyze all possible road routes between various cities. The cities are represented as nodes, and the direct roads between the cities are represented as edges in a graph. Your goal is to simulate exploring all the routes starting from one city and traversing through neighboring cities before backtracking.
This traversal is conducted using the Depth-First Search (DFS) technique, which explores as far as possible along each branch before backtracking.
For example, the department might want to check the routes by starting from one city and moving through its connected cities one by one, deeply exploring each possible road path.
You are tasked with implementing a program to perform depth-first traversal on a graph representing cities and roads. The system will:
Input the number of cities and roads.
Perform a DFS traversal starting from a specified city.

Input Format
An integer n representing the number of cities (nodes).
An integer m representing the number of roads (edges).
m pairs of integers where each pair (u, v) represents a bidirectional road (undirected edge) between city u and city v.
An integer start representing the city to start the DFS traversal from.

Output Format
The order in which the cities are visited using the DFS traversal starting from the specified city.

Sample Input
5
6
1 2
1 3
2 4
3 4
4 5
5 1
3

Sample Output
3 1 2 4 5
*/

#include <stdio.h>
#define MAX 100

int adj[MAX][MAX];   // adjacency list
int size[MAX];       // number of neighbors
int visited[MAX];    // visited array

// DFS function
void dfs(int node) {
    printf("%d ", node);
    visited[node] = 1;

    for(int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];
        if(visited[neighbor] == 0) {
            dfs(neighbor);
        }
    }
}
int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    // Initialize
    for(int i = 0; i < n; i++) {
        size[i] = 0;
        visited[i] = 0;
    }

    // Input edges
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u; // undirected graph
    }
    int start;
    scanf("%d", &start);
    dfs(start);
    return 0;
}
