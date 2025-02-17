////https://atcoder.jp/contests/dp/tasks/dp_h
#include<bits/stdc++.h>
using namespace std;
int const mod=1e9+7;
int main()
{
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
       long long n,m;
       cin>>n>>m;
       char arr[n+10][m+10];
        for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=m;j++)
           {
               cin>>arr[i][j];
           }
       }
       long long dp[n+10][m+10];
       memset(dp,0,sizeof(dp));
       dp[1][1]=1;
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=m;j++)
           {
               if(arr[i][j]=='#')
               {
                   dp[i][j]=0;
                   continue;
               }
               if(arr[i][j-1]=='.' && arr[i-1][j]=='.')
               {
                   dp[i][j]=(dp[i-1][j]%mod+dp[i][j-1]%mod)%mod;
               }
               else if(arr[i][j-1]=='.')
               {
                   dp[i][j]=dp[i][j-1];
               }
               else if(arr[i-1][j]=='.')
               {
                   dp[i][j]=dp[i-1][j];
               }
           }
       }
       cout<<dp[n][m]<<endl;
    }
}
