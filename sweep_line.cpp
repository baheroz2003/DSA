class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        map<int,int> mp;  // time → change in count
        
        for (int i=0;i<arr.size();i++) {
            mp[arr[i]]++;       // arrival => +1
            mp[dep[i]+1]--;     // departure => -1 (next moment free ho gaya)
        }
        
        int cnt=0, maxi=0;
        for (auto &it: mp) {
            cnt += it.second;   // active trains update
            maxi = max(maxi, cnt);
        }
        
        return maxi;
    }
};
