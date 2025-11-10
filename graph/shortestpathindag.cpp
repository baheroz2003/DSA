#include <bits/stdc++.h>
using namespace std;

void topo(int u, map<int, vector<pair<int,int>>>& adj, vector<int>& vis, stack<int>& st) {
    vis[u] = 1;
    for (auto [v, w] : adj[u])
        if (!vis[v]) topo(v, adj, vis, st);
    st.push(u);
}

vector<int> dagShortest(int n, map<int, vector<pair<int,int>>>& adj, int src) {
    vector<int> vis(n, 0), dist(n, 1e9);
    stack<int> st;
    for (int i = 0; i < n; i++) if (!vis[i]) topo(i, adj, vis, st);
    dist[src] = 0;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (dist[u] == 1e9) continue;
        for (auto [v, w] : adj[u])
            dist[v] = min(dist[v], dist[u] + w);
    }
    return dist;
}

int main() {
    map<int, vector<pair<int,int>>> adj = {
        {0, {{1,2},{4,1}}},
        {1, {{2,3}}},
        {4, {{2,2},{5,4}}},
        {2, {{3,6}}},
        {5, {{3,1}}}
    };
    int src = 0;
    auto dist = dagShortest(6, adj, src);
    for (int d : dist) cout << (d == 1e9 ? "INF " : to_string(d) + " ");
}
