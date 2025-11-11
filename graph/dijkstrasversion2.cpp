#include <bits/stdc++.h>
using namespace std;

void solve(map<int, vector<pair<int,int>>>& adj, vector<int>& dist, int src) {
    multiset<pair<int,int>> pq;
    pq.insert({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        auto [d, node] = *pq.begin();
        pq.erase(pq.begin());
        if (d > dist[node]) continue;
        for (auto& it : adj[node]) {
            int next = it.first;
            int wt = it.second;
            if (dist[next] > d + wt) {
                auto old = pq.find({dist[next], next});
                if (old != pq.end()) pq.erase(old);
                dist[next] = d + wt;
                pq.insert({dist[next], next});
            }
        }
    }
}

int main() {
    map<int, vector<pair<int,int>>> adj;
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[2].push_back({1, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 5});

    int n = 4;
    vector<int> dist(n, 1e9);
    solve(adj, dist, 0);

    for (int i = 0; i < n; i++) cout << "Node " << i << " -> " << dist[i] << endl;
    return 0;
}
