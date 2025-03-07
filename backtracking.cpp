#type 1:order matters but move to next index
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
#type 2:
//move to next index  order doesn't matters
void subsetHelper(int index, vector<int>& nums, vector<int>& ds, vector<vector<int>>& result) {
    result.push_back(ds);
    for (int i = index; i < nums.size(); i++) {
        ds.push_back(nums[i]);
        subsetHelper(i + 1, nums, ds, result);
        ds.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> ds;
    subsetHelper(0, nums, ds, result);
    return result;
}
#type 3:
//order doesn't matters but stay at same index
void combinationHelper(int index, vector<int>& nums, int target, vector<int>& ds, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(ds);
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        if (nums[i] > target) continue;
        ds.push_back(nums[i]);
        combinationHelper(i, nums, target - nums[i], ds, result);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    vector<int> ds;
    combinationHelper(0, nums, target, ds, result);
    return result;
}

