///https://lightoj.com/problem/coin-change-ii
///Though eta accepted hoy nai.

#include<bits/stdc++.h>
using namespace std;
int const mod=1e9+7;
int main()
{
    long long tt;
    cin>>tt;
    for(int t=1;t<=tt;t++)
    {
       long long n,k;
       cin>>n>>k;
       vector<int>arr(n+1);
       for(int i=1;i<=n;i++)
       {
           cin>>arr[i];
       }
       long long dp[k+2][n+2];
       memset(dp,0,sizeof(dp));
       for(int i=0;i<=n;i++)
       {
           dp[0][i]=1;
       }
       for(int x=1;x<=k;x++)
       {
           for(int i=1;i<=n;i++)
           {
               dp[x][i]=dp[x][i-1]%mod; /// i er ag pojjonto coin nichi
               if(x>=arr[i])
               {
                   dp[x][i]=(dp[x][i]%mod+dp[x-arr[i]][i])%mod; /// i ta nile x theke koto baki sdta likte hbe
               }
               dp[x][i]=dp[x][i]%mod;
           }
       }
       cout<<"Case "<<t<<": "<<dp[k][n]<<endl;
    }
}
