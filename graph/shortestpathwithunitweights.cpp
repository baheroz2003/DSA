// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int>adj[N];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>dist(N,INT_MAX);
        for(int i=0;i<N;i++)
        {
            dist[i]=999;
        }
        dist[src]=0;
        queue<int>q;
        q.push(src);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(dist[node]+1<dist[it])
                {
                    dist[it]=dist[node]+1;
                    q.push(it);
                }
            }
        }
        vector<int>ans(N,-1);
        for(int i=0;i<N;i++)
        {
            if(dist[i]!=999)
            {
                ans[i]=dist[i];
            }
        }
        return ans;
    }
};
