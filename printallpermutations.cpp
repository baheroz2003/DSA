#include <bits/stdc++.h>
using namespace std;
void per(int idx,vector<int>&nums){
    if(idx>=nums.size()){
        for(auto x:nums){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=idx;i<nums.size();i++){
        swap(nums[idx],nums[i]);
        per(idx+1,nums);
        swap(nums[idx],nums[i]);
    }
}
int main(){
    vector<int>nums={1,2,3};
    per(0,nums);
}
