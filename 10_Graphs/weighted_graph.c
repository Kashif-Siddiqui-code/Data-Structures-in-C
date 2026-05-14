/*
Constructing a Weighted Graph
You are tasked with designing a transportation system in a city where each intersection is represented as a node and each road connecting the intersections is represented as an undirected edge with a specific weight (cost to travel). Your goal is to create a representation of this weighted graph and display the adjacency list.
Input Format
The first line contains integer n (the number of intersections)
Next line contains the integer m (the number of roads).
Each of the next m lines contains three integers u, v, and w, where u and v are the intersection IDs, and w is the weight of the edge (cost to travel between intersections u and v).

Output Format
Print the adjacency list representation of the weighted graph, where each line corresponds to an intersection and lists its connected intersections along with the corresponding weights.

Sample Input
5
6
1 2 4
1 3 3
2 3 1
2 4 2
3 5 5
4 5 3

Sample Output
1 -> (2, 4) -> (3, 3)
2 -> (1, 4) -> (3, 1) -> (4, 2)
3 -> (1, 3) -> (2, 1) -> (5, 5)
4 -> (2, 2) -> (5, 3)
5 -> (3, 5) -> (4, 3)
*/


#include <stdio.h>
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int adj[n][n];       // stores neighbors
    int weight[n][n];    // stores weights
    int size[n];         // number of neighbors
    for(int i = 0; i < n; i++) {
        size[i] = 0;
    }
    int u, v, w;
    // Input edges
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        // Convert to 0-based
        u = u - 1;
        v = v - 1;
        // Add edge u → v
        adj[u][size[u]] = v;
        weight[u][size[u]] = w;
        size[u]++;
        // Add edge v → u (undirected)
        adj[v][size[v]] = u;
        weight[v][size[v]] = w;
        size[v]++;
    }
    // Print adjacency list
    for(int i = 0; i < n; i++) {
        printf("%d", i + 1);
        for(int j = 0; j < size[i]; j++) {
            printf(" -> (%d, %d)", adj[i][j] + 1, weight[i][j]);
        }
        printf("\n");
    }
    return 0;
}
