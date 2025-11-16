class Solution {
  public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(x==parent[x])return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x ,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        if(x_parent==y_parent)return;
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
    int kruskal(vector<vector<int>>& edges){
        int sum=0;
        for(auto temp:edges){
            int u=temp[0];
            int v=temp[1];
            int wt=temp[2];
            int parent_u=find(u);
            int parent_v=find(v);
            if(parent_u!=parent_v){
                Union(u,v);
                sum+=wt;
            }
        }
        return sum;
    }
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        parent.resize(V);
        rank.resize(V,0);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        auto comp=[&](vector<int>&vec1,vector<int>&vec2){
            return vec1[2]<vec2[2];
        };
        sort(edges.begin(),edges.end(),comp);
        return kruskal(edges);
        
    }
};
