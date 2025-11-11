#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<pair<int,int>>> adj(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int src = 1;
    vector<ll> dist(n+1, INF);
    dist[src] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF) cout << -1;
        else cout << dist[i];
        if (i < n) cout << ' ';
    }
    cout << '\n';
    return 0;
}
//method 2:
#include <bits/stdc++.h>
using namespace std;
void solve(map<int,vector<pair<int,int>>>&adj,vector<int>&dist,int src){
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty()){
        auto vec=pq.top();
        pq.pop();
        int d=vec[0];
        int node=vec[1];
        if(d>dist[node])continue;
        for(auto it:adj[node]){
            int next=it.first;
            int wt=it.second;
            if(dist[next]>wt+d){
                dist[next]=wt+d;
                pq.push({dist[next],next});
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
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " -> " << dist[i] << endl;
    }
    return 0;
}

