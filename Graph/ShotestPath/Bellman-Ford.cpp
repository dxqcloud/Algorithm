
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// a structure to represent a weighted edge in graph
struct Edge {
    int src, dest, weight;
};


struct Graph {
    int VSize, ESize;
    struct Edge* edge;
};


// A utility function used to print the solution
void printArr(int dist[], int n)
{
    printf("Vertex   Distance from Sourcen");
    for (int i = 0; i < n; ++i)
        printf("%d tt %dn", i, dist[i]);
}

void BellmanFord(struct Graph* graph, int src) {
    int V = graph->VSize;
    int E = graph->ESize;
    int dist[V];

    //初始化距离为无穷大
    for (int i = 0; i < V; i++)
        dist[i]   = INT_MAX;
    dist[src] = 0;


    //
    for (int i = 1; i <= V-1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Step 3: check for negative-weight cycles.  The above step
    // guarantees shortest distances if graph doesn't contain
    // negative weight cycle.  If we get a shorter path, then there
    // is a cycle.
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            printf("Graph contains negative weight cycle");
    }

    printArr(dist, V);
    return;
}
