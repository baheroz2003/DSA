#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        long long sum=0;
        for(int i=l;i<=r;i++)
        {
            sum+=a[i];
        }
        cout<<sum<<endl;
    }
}
//method 2 prefix sum
#include <bits/stdc++.h>
using namespace std;
int a[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int q;
    cin>>q;
    int prefix_sum[N];
    for(int i=1;i<=n;i++)
    {
        prefix_sum[i]=prefix_sum[i-1]+a[i];
    }
    // l se r ka chahiye 
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<prefix_sum[r]-prefix_sum[l-1]<<endl;
        // isse total sum is s then remaining is s-k
    }
}
// class Solution {
// public:
//     vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
//         vector<int> ans;
//         unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
//         vector<int> prefixSum(words.size() + 1, 0);  
//         for (int i = 0; i < words.size(); i++) {
//             if (vowels.count(words[i][0]) && vowels.count(words[i].back())) {
//                 prefixSum[i+1] = prefixSum[i] + 1;
//             } else {
//                 prefixSum[i+1] = prefixSum[i];
//             }
//         }
//         for (auto& q : queries) {
//             int start = q[0];
//             int end = q[1];
//             ans.push_back(prefixSum[end + 1] - prefixSum[start]);
//         }
//         return ans;
//     }
// };
