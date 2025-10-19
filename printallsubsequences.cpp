#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
vector<vector<int>> result;
void recure(int idx, vector<int>& res) {
    if (idx >= res.size()) {
        for (auto x : ans) cout << x << " ";
        if(ans.size()==0)cout<<"{}";
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
#problem 2:print subsequence with sum=k
#include <bits/stdc++.h>
using namespace std;
void recure(int idx,int s,int target,vector<int>&res,vector<int>&ds){
    if(idx>=res.size()){
        if(s==target){
            for(auto x:ds){
                cout<<x<<" ";
            }
            cout<<"\n";
        }
        return;
    }
    ds.push_back(res[idx]);
    recure(idx+1,s+res[idx],target,res,ds);
    ds.pop_back();
    recure(idx+1,s,target,res,ds);
}
int main(){
    vector<int>res={1,2,3,4};
    vector<int>ds;
    recure(0,0,5,res,ds);
    return 0;
}
#3print only one subsequence:
#include <bits/stdc++.h>
using namespace std;
bool recure(int idx,int s,int target,vector<int>&res,vector<int>&ds){
    if(idx>=res.size()){
        if(s==target){
            for(auto x:ds){
                cout<<x<<" ";
            }
            cout<<"\n";
            return true;
        }
        return false;
    }
    ds.push_back(res[idx]);
    if(recure(idx+1,s+res[idx],target,res,ds)==true)return true;
    ds.pop_back();
    if(recure(idx+1,s,target,res,ds)==true)return true;
    return false;
}
int main(){
    vector<int>res={1,2,3,4};
    vector<int>ds;
    recure(0,0,5,res,ds);
    return 0;
}
