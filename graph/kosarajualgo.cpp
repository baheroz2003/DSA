//Position this line where user code will be pasted.
class Solution {
  public:
    void dfsfill(int u,vector<vector<int>>&adj,vector<bool>&visited,stack<int>&st){
        visited[u]=true;
        for(auto v:adj[u]){
            if(!visited[v])dfsfill(v,adj,visited,st);
        }
        st.push(u);
    }
    void dfstraversal(int u,vector<vector<int>>&adjrev,vector<bool>&vis1){
        vis1[u]=1;
        for(auto v:adjrev[u]){
            if(!vis1[v]){
                dfstraversal(v,adjrev,vis1);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        stack<int>st;
        int V=adj.size();
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfsfill(i,adj,visited,st);
            }
        }
        //reverse the direction of the edges
        vector<vector<int>>adjrev(V);
        for(int u=0;u<V;u++){
            for(int v:adj[u]){
                adjrev[v].push_back(u);
            }
        }
        //count the scc
        int cntscc=0;
        vector<bool>vis1(V,false);
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis1[node]){
                dfstraversal(node,adjrev,vis1);
                cntscc++;
            }
        }
      return cntscc;  
    }
};
