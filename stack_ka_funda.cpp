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
//in terms of index also
#include <bits/stdc++.h>
using namespace std;

void computeIndexes(vector<int>& arr) {
    int n = arr.size();

    vector<int> NSL(n), NSR(n), NGL(n), NGR(n);
    stack<int> st;

    // NSL (Next Smaller to Left)
    while (!st.empty()) st.pop();
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        NSL[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // NSR (Next Smaller to Right)
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
        NSR[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    // NGL (Next Greater to Left)
    while (!st.empty()) st.pop();
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        NGL[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // NGR (Next Greater to Right)
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
        NGR[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    // Print results
    cout << "NSL: "; for (int x : NSL) cout << x << " "; cout << "\n";
    cout << "NSR: "; for (int x : NSR) cout << x << " "; cout << "\n";
    cout << "NGL: "; for (int x : NGL) cout << x << " "; cout << "\n";
    cout << "NGR: "; for (int x : NGR) cout << x << " "; cout << "\n";
}

int main() {
    vector<int> arr = {3, 1, 2, 4};
    computeIndexes(arr);
    return 0;
}
