Problem:You are given a string s consisting of lowercase English letters.
You will also be given multiple queries, each containing two integers l and r (1-based indices).
For each query, consider the substring s[l...r].
Your task is to determine whether it is possible to rearrange the characters of this substring to form a palindrome.
Input Format:
The first line contains the string s of length n.
The second line contains an integer q — the number of queries.
Each of the next q lines contains two integers l and r — denoting the range of the substring.
Output Format:
For each query, print
"YES" if the substring s[l...r] can be rearranged into a palindrome,
otherwise print "NO".
eg:
i/p:
aabcd
3
1 3
2 5
1 5
o/p:
YES
NO
NO
------------------------------------------------------------------------
#brute force:
include <bits/stdc++.h>
using namespace std;

bool pos(string s) {
    map<char, int> mpp;
    for (auto x : s) mpp[x]++;
    int cnt = 0;
    for (auto it : mpp) if (it.second % 2 != 0) cnt++;
    return cnt <= 1;
}

int main() {
    string s;
    cin >> s;

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        string res = s.substr(l - 1, r - l + 1);
        if (pos(res))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
#optimized prefix sum+hashing
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    vector<vector<int>>pref(n+1,vector<int>(26,0));
    for(int i=0;i<s.size();i++){
        pref[i+1]=pref[i];
        pref[i+1][s[i]-'a']++;
    }
    int q;
    cin>>q;
    while(q--){
    int l,r;
    cin>>l>>r;
    int odd=0;
    for(int i=0;i<26;i++){
        int cnt=pref[r+1][i]-pref[l][i];
        if(cnt%2)odd++;
    }
    if(odd<=1){
        cout<<"Yes"<<endl;
    }
    else{
    cout<<"No"<<endl;
    }
    }
    return 0;
}
