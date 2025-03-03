//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

//sprinkle water plants gfg
//hackerrank hackerland radio transmission
//gfg police thief
//leetcode water plant jaisa kuchh
class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<pair<int, int>> range;
        for(int i=0; i<n; i++){
            if(gallery[i] != -1){
                int left = max(i - gallery[i], 0);
                int right = min(i + gallery[i], n-1);
                range.push_back({left, right});
            }
        }
        
        sort(range.begin(), range.end());
        
        int target = 0;
        int i=0;
        int cnt = 0;
        
        while(target < n){
            int maxRight = -1;
            while(i < range.size()){
                if(range[i].first <= target){
                    maxRight = max(maxRight, range[i].second);
                    i++;
                }
                else{
                    break;
                }
            }
            if(maxRight < target){
                return -1;
            }
            cnt++;
            target = maxRight + 1;
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends