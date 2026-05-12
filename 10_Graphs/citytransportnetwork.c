/*

City Transport Network
Imagine a city transportation authority is planning to analyze and optimize the direct routes between various cities. They want to represent the transportation network in the form of a graph, where:
Each city is represented by a node.
A direct route between two cities is represented by an edge.
To model this system, the transportation authority uses an adjacency matrix to represent whether there is a direct route between two cities. The matrix will help determine which cities are connected directly and which are not.
For example, a 1 in the matrix at position (i, j) means that there is a direct route from city i to city j. A 0 indicates no direct route between the two cities.
You are tasked with implementing the adjacency matrix for this city transport system. The program should allow users to:
Define the number of cities (nodes).
Input the direct routes between cities (edges).
Display the adjacency matrix to show the direct connections between the cities.

Input Format
An integer n representing the number of cities (nodes).
An integer m representing the number of direct routes (edges).
m pairs of integers where each pair (u, v) represents a direct route from city u to city v.

Output Format
The adjacency matrix representation of the graph.

Sample Input
5
6
1 2
1 3
2 4
3 4
4 5
5 1

Sample Output
0 1 1 0 0
0 0 0 1 0
0 0 0 1 0
0 0 0 0 1
1 0 0 0 0

Explanation
Cities (nodes): There are 5 cities, represented as nodes: 1, 2, 3, 4, 5.
Direct routes (edges): There are 6 direct routes between cities:
A route from city 1 to city 2 (1 → 2).
A route from city 1 to city 3 (1 → 3).
A route from city 2 to city 4 (2 → 4).
A route from city 3 to city 4 (3 → 4).
A route from city 4 to city 5 (4 → 5).
A route from city 5 to city 1 (5 → 1).
The adjacency matrix is built based on these direct routes. The matrix represents whether there is a direct route between each pair of cities. For example:
adjMatrix[0][1] = 1 indicates a direct route from city 1 to city 2.
adjMatrix[1][3] = 1 indicates a direct route from city 2 to city 4.
adjMatrix[4][0] = 1 indicates a direct route from city 5 back to city 1.


*/


#include <stdio.h>
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int adj[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    int u, v;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u - 1][v - 1] = 1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    return 0;
}
