#include <bits/stdc++.h>
using namespace std;

/*Given an array arr[ ] of N positive integers,the task is to find the greatest element on 
the left of every element in the array which isstrictly smaller than itself, if this element
does not exist for an index print "-1". smaller on left gfg*/
vector<int> Smallestonleft(int arr[], int n) {
    set<int> s;
    vector<int> ans(n);
    
    for(int i=0; i<n; i++){
        auto itr = s.lower_bound(arr[i]);
        
        if(itr == s.begin()) ans[i] = -1;
        else ans[i] = *(--itr);
        
        s.insert(arr[i]);
    }
    return ans;
}