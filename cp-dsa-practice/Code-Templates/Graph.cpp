
#include <bits/stdc++.h>
using namespace std;

const int START_NODE = 0; // Adjust based on your problem (0 or 1)
unordered_set<int> seen;

int dfs(int node, const vector<vector<int>>& graph) {
    int ans = 0;
    
    // do some logic
    
    for (int neighbor : graph[node]) {
        if (!seen.count(neighbor)) { // .count() ensures compatibility with older compilers
            seen.insert(neighbor);
            ans += dfs(neighbor, graph);
        }
    }

    return ans;
}

int fn(const vector<vector<int>>& graph) {
    seen.clear(); // Resets state in case of multiple test cases
    seen.insert(START_NODE);
    return dfs(START_NODE, graph);
}

//dfs iterative graph
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

int dfsTemplate(vector<vector<int>>& graph, int START_NODE) {
    stack<int> st;
    unordered_set<int> seen;
    st.push(START_NODE);
    seen.insert(START_NODE);

    int ans = 0; // placeholder for any logic you want

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        // ---- Do your custom logic here ----
        // Example: count nodes
        ans++;

        for (int neighbor : graph[node]) {
            if (!seen.count(neighbor)) {
                seen.insert(neighbor);
                st.push(neighbor);
            }
        }
    }

    return ans; // return whatever result your logic computes
}

#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;


// BFS Template graph.
int bfsTemplate(vector<vector<int>>& graph, int START_NODE) {
    queue<int> q;
    unordered_set<int> seen;
    q.push(START_NODE);
    seen.insert(START_NODE);

    int ans = 0; // placeholder for your logic

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // ---- Do your custom logic here ----
        // Example: count nodes
        ans++;

        for (int neighbor : graph[node]) {
            if (!seen.count(neighbor)) {
                seen.insert(neighbor);
                q.push(neighbor);
            }
        }
    }

    return ans; // return whatever result your logic computes
}
