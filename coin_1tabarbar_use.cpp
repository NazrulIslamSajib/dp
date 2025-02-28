#include<bits/stdc++.h>
using namespace std;
int const mod=1e9+7;
const int mx=1e6+2;
int dp[mx];
int arr[110];
///https://cses.fi/problemset/task/1635/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
       long long n,W;
       cin>>n>>W;
       for(int i=1;i<=n;i++)
       {
           cin>>arr[i];
       }
       dp[0]=1;
       for(int x=1;x<=W;x++)
       {
           for(int i=1;i<=n;i++)
           {
               if(x>=arr[i])
               {
                   dp[x] = (dp[x]+dp[x - arr[i]]) % mod; //// 2 bar mod korte vitore khabo tle
               }
           }
       }
       cout<<dp[W];
    }
    return 0;
}

