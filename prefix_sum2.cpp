// //top left se bottom right me prefix sum
// #include <bits/stdc++.h>
// using namespace std;
// const int N=1e3+10;
// int arr[N][N];
// int main()
// {
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             cin>>arr[i][j];
//         }
//     }
//     int q;
//     cin>>q;
//     while(q--)
//     {
//         int a,b,c,d;
//         cin>>a>>b>>c>>d;
//         long long sum=0;
//         for(int i=a;i<=c;i++)
//         {
//             for(int j=b;j<=d;j++)
//             {
//                 sum+=arr[i][j];
//             }
//         }
//         cout<<sum<<endl;
//         }
//     }
//method 2 using prefix sum 2d
#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int arr[N][N];
int pf[N][N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>arr[i][j];
            pf[i][j]=arr[i][j]+pf[i-1][j]+pf[i][j-1]-pf[i-1][j-1];
        }
    }
    int q;
    while(q--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<pf[c][d]-pf[a-1][d]-pf[c][b-1]+pf[a-1][b-1]<<endl;
    }
    }
    


