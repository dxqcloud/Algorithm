// Program to find Dijkstra's shortest path using
// priority_queue in STL

#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

// iPair ==>  Integer Pair
typedef pair<int, int> iPair;

//图的关联矩阵表示
class Graph {
    int VSize;
    list< pair<int, int> > *adj;

public:
    Graph(int VSize);
    void addEdge(int u, int v, int w);
    void Dijkstra(int s);
};

// VSize个点分配list空间
Graph::Graph(int VSize) {
    this->VSize = VSize;
    adj = new list<iPair> [VSize];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
void Graph::Dijkstra(int src) {

    //优先级队列找最近的点
    //pair: first: 距离 second：边号 方便优先级队列的比较
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    vector<int> dist(VSize, INF);
    dist[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {

        int u = pq.top().second;
        pq.pop();

        list< pair<int, int> >::iterator it;
        for (it = adj[u].begin(); it != adj[u].end(); ++it) {

            int v = it->first;
            int weight = it->second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < VSize; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Driver program to test methods of graph class
//int main() {
//    // create the graph given in above fugure
//    int VSize = 9;
//    Graph g(VSize);
//
//    //  making above shown graph
//    g.addEdge(0, 1, 4);
//    g.addEdge(0, 7, 8);
//    g.addEdge(1, 2, 8);
//    g.addEdge(1, 7, 11);
//    g.addEdge(2, 3, 7);
//    g.addEdge(2, 8, 2);
//    g.addEdge(2, 5, 4);
//    g.addEdge(3, 4, 9);
//    g.addEdge(3, 5, 14);
//    g.addEdge(4, 5, 10);
//    g.addEdge(5, 6, 2);
//    g.addEdge(6, 7, 1);
//    g.addEdge(6, 8, 6);
//    g.addEdge(7, 8, 7);
//
//    g.Dijkstra(0);
//
//    return 0;
//}