#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Define a structure to represent edges and their weights
struct Edge{
    int to, weight;
    Edge(int _to, int _weight) : to(_to), weight(_weight) {}
};

// Define a function to perform Dijkstra's algorithm
vector<int> dijkstra(vector<vector<Edge>> &graph, int start){
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);

    // Create a min-heap (priority queue) to store vertices and their distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialize the distance to the start vertex as 0
    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        // Explore all neighboring vertices of u
        for (const Edge &edge : graph[u])
        {
            int v = edge.to;
            int weight = edge.weight;

            // Relaxation step: update the distance if a shorter path is found
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

int main()
{
    int n = 6;     // Number of vertices
    int start = 0; // Starting vertex

    // Create a graph as an adjacency list
    vector<vector<Edge>> graph(n);

    // Add edges and their weights to the graph
    graph[0].emplace_back(1, 2); // Edge from 0 to 1 with weight 2
    graph[0].emplace_back(2, 4);
    graph[1].emplace_back(2, 1);
    graph[1].emplace_back(3, 7);
    graph[2].emplace_back(4, 3);
    graph[3].emplace_back(4, 2);
    graph[3].emplace_back(5, 5);
    graph[4].emplace_back(5, 1);

    vector<int> shortest_distances = dijkstra(graph, start);

    cout << "Shortest distances from vertex " << start << " to all other vertices:" << endl;
    for (int i = 0; i < n; ++i){
        cout << "Vertex " << i << ": " << shortest_distances[i] << endl;
    }

    return 0;
}
