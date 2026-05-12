/*
City Infrastructure Planning
Imagine you work as a city planner, and your department is responsible for designing and maintaining road networks between different districts of a city. Each district is represented as a node, and the roads between the districts are represented as edges in a graph. Your task is to simulate how transportation would expand outward from one district to all others, where roads are directly connected to the cities(undirectired graph).
To do this, you need to use the Breadth-First Search (BFS) traversal method, which explores all the neighbours at the present depth prior to moving on to nodes at the next depth level.
This would help city planners evaluate the shortest route between two districts and how the transportation network can be improved or expanded efficiently.
Given a graph representing a city’s road network with districts as nodes and direct roads as edges, implement a breadth-first traversal starting from a specified district. The BFS traversal visits all the directly connected districts before moving on to their neighbours.

Input Format
An integer n representing the number of districts (nodes).
An integer m representing the number of roads (edges).
m pairs of integers where each pair (u, v) represents a direct road between district u and district v.
An integer start representing the district to start the BFS traversal from.

Output Format
The order in which the districts are visited using the BFS traversal starting from the specified district.

Sample Input
6
7
1 2
1 3
2 4
3 4
4 5
4 6
5 6
2
Sample Output
2 1 4 3 5 6
*/


#include <stdio.h>
#include <stdbool.h>

int adj[100][100];
int size[100];

void bfs(int start, int n) {
    bool visited[100] = {false};
    int queue[100];
    int front = 0;
    int rear = 0;
    visited[start] = true;
    queue[rear++] = start;
    while(front < rear) {
        int district = queue[front++];
        printf("%d ", district + 1);
        for(int i = 0; i < size[district]; i++) {
            int neighbor = adj[district][i];
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                queue[rear++] = neighbor;
            }
        }
    }
}
int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 0; i < n; i++) {
        size[i] = 0;
    }
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }
    int start;
    scanf("%d", &start);
    start--;
    bfs(start, n);
    return 0;
}
