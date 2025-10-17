#include <bits/stdc++.h>
using namespace std;
//power using odd and even using recursion
//revision
//utilize in terms of base and power
double calc(double x,int n){
    double ans=1.0;
    long long nn=n;
    if(nn<0){
        nn=(-1)*nn;
    }
    while(nn>0){
        if(nn&1==0){
            x=x*x;
            nn/=2;
        }
        else{
            ans=ans*x;
            nn--;
        }
    }
    if(n<0){
        ans=(double)(1.0)/(double)(ans);
    }
    return ans;
}
int main(){
    cout<<calc(2.0,8);
    return 0;
}
