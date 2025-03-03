#include <bits/stdc++.h>
using namespace std;

//395. Longest Substring with At Least K Repeating Characters

class Solution {
public:
    int recure(string &s, int &k, int st, int en){
        if(en - st < k) return 0;

        int m[26] = {0};
        for(int i=st; i<en; i++) m[s[i] -'a']++;

        for(int i=st; i<en; i++){
            if(m[s[i] -'a'] >= k) continue;

            return max(recure(s, k, i+1, en), recure(s, k, st, i));
        }
        return en - st;
    }

    int longestSubstring(string s, int k) {
        return recure(s, k, 0, s.length());
    }
};

//sort a list, sorted list to bst