#include <bits/stdc++.h>
using namespace std;
int lb(vector<int>&nums,int target){
    int l=0;
    int h=nums.size()-1;
    while(h-l>1){
        int mid=l+h>>1;
        if(nums[mid]<target){
            l=mid+1;
        }
        else{
            h=mid;
        }
    }
    if(nums[l]>=target){
        return l;
    }
    if(nums[h]>=target){
        return h;
    }
    return -1;
}
int ub(vector<int>&nums,int target){
    int l=0;
    int h=nums.size()-1;
    while(h-l>1){
        int mid=l+h>>1;
        if(nums[mid]<=target){
            l=mid+1;
        }
        else{
            h=mid;
        }
    }
    if(nums[l]>target){
        return l;
    }
    if(nums[h]>target){
        return h;
    }
    return -1;
}
int main(){
    vector<int>nums={1,2,3,4,5,6,7,8,9};
    int target=5;
    int res=ub(nums,target);
    cout<<res<<endl;
    res=lb(nums,target);
    cout<<res<<endl;
    return 0;
}
