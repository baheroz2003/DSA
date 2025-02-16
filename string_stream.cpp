#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s="I am Baher";
    stringstream ss(s);
    string word;
    string token="";
    while(ss>>word)
    {

        cout<<word<<" "<<endl;
        token+=word;
    }
    return 0;
}
