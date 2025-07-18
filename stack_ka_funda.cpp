#include <bits/stdc++.h>
using namespace std;

vector<int> NSL(vector<int>& arr) {
    vector<int> res(arr.size());
    stack<int> st;
    for(int i = 0; i < arr.size(); i++) {
        while(!st.empty() && st.top() >= arr[i]) st.pop();
        res[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return res;
}

vector<int> NSR(vector<int>& arr) {
    vector<int> res(arr.size());
    stack<int> st;
    for(int i = arr.size()-1; i >= 0; i--) {
        while(!st.empty() && st.top() >= arr[i]) st.pop();
        res[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return res;
}

vector<int> NGL(vector<int>& arr) {
    vector<int> res(arr.size());
    stack<int> st;
    for(int i = 0; i < arr.size(); i++) {
        while(!st.empty() && st.top() <= arr[i]) st.pop();
        res[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return res;
}

vector<int> NGR(vector<int>& arr) {
    vector<int> res(arr.size());
    stack<int> st;
    for(int i = arr.size()-1; i >= 0; i--) {
        while(!st.empty() && st.top() <= arr[i]) st.pop();
        res[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return res;
}

int main() {
    vector<int> arr = {3,1,2,4};
    
    auto nsl = NSL(arr);
    auto nsr = NSR(arr);
    auto ngl = NGL(arr);
    auto ngr = NGR(arr);
    
    cout << "NSL: "; for(auto x : nsl) cout << x << " "; cout << "\n";
    cout << "NSR: "; for(auto x : nsr) cout << x << " "; cout << "\n";
    cout << "NGL: "; for(auto x : ngl) cout << x << " "; cout << "\n";
    cout << "NGR: "; for(auto x : ngr) cout << x << " "; cout << "\n";
}
