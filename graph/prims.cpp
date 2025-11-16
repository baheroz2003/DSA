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
//method 2
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        map<int,vector<pair<int,int>>>adj;
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
    pq.push({0,0});
    vector<bool>visited(V,0);
    int ans=0;
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        int wt=p[0];
        int node=p[1];
        if(visited[node]==1)continue;
        visited[node]=1;
        ans+=wt;
        for(auto it:adj[node]){
            int pwt=it.second;
            int par=it.first;
            if(visited[par]==0){
                pq.push({pwt,par});
            }
        }
    }
        return ans;
    }
};
