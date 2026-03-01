#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5; // number of nodes
    int source = 0; // starting node

    // adjacency list: graph[u] = vector of {v, weight}
    vector<vector<pair<int,int>>> graph(n);
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 7});
    graph[2].push_back({4, 3});
    graph[3].push_back({4, 1});

    vector<int> distances(n, INT_MAX);
    distances[source] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
    heap.push({0, source});

    while (!heap.empty()) {
        int currDist = heap.top().first;
        int node = heap.top().second;
        heap.pop();

        if (currDist > distances[node]) {
            continue;
        }

        for (auto edge : graph[node]) {
            int nei = edge.first;
            int weight = edge.second;
            int dist = currDist + weight;

            if (dist < distances[nei]) {
                distances[nei] = dist;
                heap.push({dist, nei});
            }
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; i++) {
        cout << "Distance from " << source << " to " << i << " = ";
        if (distances[i] == INT_MAX) cout << "INF\n";
        else cout << distances[i] << "\n";
    }

    return 0;
}