#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<vector<pair<int,int>>> &adj) {
    vector<int> vis(n, 0);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    pq.push({0, 0, -1});
    int total = 0;

    while (!pq.empty()) {
        auto vec = pq.top();
        pq.pop();

        int wt = vec[0];
        int node = vec[1];
        int parent = vec[2];

        if (vis[node]) continue;
        vis[node] = 1;
        total += wt;

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int adjWt = it.second;

            if (!vis[adjNode]) {
                pq.push({adjWt, adjNode, node});
            }
        }
    }

    return total;
}

int main() {
    int n = 5;
    vector<vector<pair<int,int>>> adj(n);

    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    adj[3].push_back({4, 9});
    adj[4].push_back({3, 9});

    int totalWeight = solve(n, adj);
    cout << totalWeight;
}
