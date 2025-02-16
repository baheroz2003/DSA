#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rt return 1;
#define rf return 0;
#define MOD 1e9+7;
int main()
{
   
    int w1,w2;
    cin>>w1>>w2;
    int year=1;
    if(w1==w2)
    {
        cout<<year;
    }
    while(w1<=w2)
    {
        w1*=3;
        w2*=2;
          year++;
    }
    cout<<year<<endl;
    return 0;
}