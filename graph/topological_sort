#include <bits/stdc++.h>
using namespace std;

stack<int> st;
unordered_set<int> vis;

void dfs(int node, vector<vector<int>>& graph) {
    vis.insert(node);
    for (auto it : graph[node]) {
        if (!vis.count(it)) dfs(it, graph);
    }
    st.push(node);
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n);
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for (int i = 0; i < n; i++) {
        if (!vis.count(i)) dfs(i, graph);
    }
    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    for (auto x : ans) cout << x << " ";
    return 0;
}
