/*
City Transportation System
The city’s transportation department is tasked with managing a network of roads between several cities. They want to represent the direct road connections between cities in the form of a graph, where: Cities are represented as nodes. Roads (direct connections between cities) are represented as undirected edges, meaning a road between city u and city v connects both cities in both directions. Due to the size of the network and the need to quickly query connections, the transportation department has decided to use an adjacency list to represent the graph. The adjacency list provides an efficient way to store and process information about the roads. The adjacency list stores each city (node) as a list of its directly connected neighbouring cities (nodes). For example, if there is a road from city 1 to city 2, and another from city 1 to city 3, city 1 will store a list containing cities 2 and 3. You are required to implement the adjacency list representation of the city’s road network. The system will allow users to: Define the number of cities (nodes). Input the roads (edges) between the cities. Display the adjacency list to show which cities are connected by direct roads.

Input Format
An integer n representing the number of cities (nodes).
An integer m representing the number of roads (edges).
m pairs of integers where each pair (u, v) represents a direct road between city u and city v.

Output Format
The adjacency list representation of the graph showing the connections between cities.

Sample Input 1
5
6
1 2
1 3
2 4
3 4
4 5
5 1

Sample Output 1
City 1: 2 3 5
City 2: 1 4
City 3: 1 4
City 4: 2 3 5
City 5: 4 1
*/

#include <stdio.h>
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int adj[n][n];
    int size[n];
    for(int i = 0; i < n; i++) {
        size[i] = 0;
    }
    int u, v;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        // Convert to 0-based indexing
        u = u - 1;
        v = v - 1;
        // Add v to u's list
        adj[u][size[u]] = v;
        size[u]++;
        // Add u to v's list (undirected graph)
        adj[v][size[v]] = u;
        size[v]++;
    }
    // Print adjacency list
    for(int i = 0; i < n; i++) {
        printf("City %d: ", i + 1);
        for(int j = 0; j < size[i]; j++) {
            printf("%d ", adj[i][j] + 1); // convert back to 1-based
        }
        printf("\n");
    }
    return 0;
}
