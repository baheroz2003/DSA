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

//eriuuhvr

/*#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    n++;
    
    vector<bool>store(n,true);
    store[0] = store[1] = false;

    for(int i=0; i<n; i++){
        if(store[i]){
            for(int j = i*2; j<n; j += i){
                store[j] = false;
            }
        }
    }
    
    int sum=0;

    for(int i=0; i<n; i++){
        if(store[i]) sum += i;
    }
    cout << sum << endl;
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}*/
