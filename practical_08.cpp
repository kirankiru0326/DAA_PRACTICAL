#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

int main() {
    vector<vector<int>> adj = {
        {1, 2}, {0, 3, 4}, {0, 4}, {1}, {1, 2}
    };

    cout << "BFS: ";
    bfs(0, adj);

    vector<bool> visited(adj.size(), false);
    cout << "\nDFS: ";
    dfs(0, adj, visited);

    return 0;
}
