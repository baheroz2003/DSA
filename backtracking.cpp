#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // vector<vector<int>>ans;
        unordered_set<string>ans;
        // vector<string>temp;
        string temp="";
        void solve(string tiles,vector<int>&vis)
        {
            //base case
            ans.insert(temp);
            for(int i=0;i<tiles.size();i++){
                if(vis[i])continue;
            //do part
            vis[i]=1;
            temp.push_back(tiles[i]);
            solve(tiles,vis);
            //undo
            vis[i]=0;
            temp.pop_back();
            }
            // return ans.size();
        }
        
        int numTilePossibilities(string tiles) {
        //   sort(tiles.begin(), tiles.end());
            vector<int> vis(tiles.size(), 0);
            solve(tiles, vis);
            return ans.size()-1;
        }
    };