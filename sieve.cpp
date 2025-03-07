#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<bool>store(n,true);
    store[0] = store[1] = false;

    for(int i=0; i<n; i++){
        if(store[i]){
            for(int j = i*2; j<n; j += i){
                store[j] = false;
            }
        }
    }

    for(int i=0; i<n; i++){
        if(store[i]) cout << i << endl;
    }
}

#modified sieve optimised
#include <bits./stdc++.h>
using namespace std;
vector<int> store;  
void seive(int n) {
    store.assign(n + 1, 1);
    store[0] = store[1] = 0;
    for(int i = 2; i * i <= n; i++) {
        if(store[i]) {
            for(int j = i * i; j <= n; j += i) {
                store[j] = 0;
            }
        }
    }
}
