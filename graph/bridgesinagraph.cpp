class Solution {
public:
    vector<vector<int>> result;
    void dfs(int node, int parent, int &timer,
             vector<int> &disc, vector<int> &low,
             map<int, vector<int>> &adj,
             vector<int> &vis)
    {
        vis[node] = 1;
        disc[node] = low[node] = timer++;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (!vis[it]) {
                dfs(it, node, timer, disc, low, adj, vis);
                low[node] = min(low[node], low[it]);
                if (low[it] > disc[node]) {
                    result.push_back({node, it});
                }
            }
            else {
                low[node] = min(low[node], disc[it]);
            }
        }
    }

    vector<vector<int>> findBridges(vector<vector<int>> &edges, int v) {
        map<int, vector<int>> adj;

        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int timer = 0;
        vector<int> disc(v, -1);
        vector<int> low(v, -1);
        vector<int> vis(v, 0);

        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                dfs(i, -1, timer, disc, low, adj, vis);
            }
        }

        return result;
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        result.clear();
        findBridges(edges, V);
        for (auto &x : result) {
            if ((x[0] == c && x[1] == d) ||
                (x[0] == d && x[1] == c))
                return true;
        }
        return false;
    }
};
