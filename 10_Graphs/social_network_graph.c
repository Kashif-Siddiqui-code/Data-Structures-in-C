/*
Constructing a Social Network Graph
In a social network, different users are connected through friendships. You need to represent the connectivity of these users using an undirected graph. Each user is represented as a vertex, and each friendship connecting two users is represented as an edge. Your task is to create an adjacency matrix representation of this graph. Additionally, you should allow the user to input the number of users and the friendships that connect them.
Input Format
The first line contains an integer n, the number of nodes (people) in the graph.
The second line contains an integer m, the number of edges (connections) in the graph.
The next m lines each contain two space-separated integers u and v, representing an edge between nodes u and v.
Output Format
Print the adjacency matrix of the graph.

Sample Input
4
5
1 2
1 3
2 4
3 4
1 4

Sample Output
0 1 1 1
1 0 0 1
1 0 0 1
1 1 1 0

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
        adj[v - 1][u - 1] = 1;  // undirected graph
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    return 0;
}
