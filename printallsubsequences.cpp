#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
vector<vector<int>> result;
void recure(int idx, vector<int>& res) {
    if (idx >= res.size()) {
        for (auto x : ans) cout << x << " ";
        cout << endl;
        result.push_back(ans);
        return;
    }
    ans.push_back(res[idx]);
    recure(idx + 1, res);
    ans.pop_back();
    recure(idx + 1, res);
}
int main() {
    vector<int> res = {3, 1, 2};
    recure(0, res);
    return 0;
}
