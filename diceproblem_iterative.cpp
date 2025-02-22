////https://cses.fi/problemset/task/1633/ 
#include<bits/stdc++.h>
using namespace std;
int const mod=1e9+7;
int main()
{
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
       long long n;
       cin>>n;
       long long dp[n+10];
       memset(dp,0,sizeof(dp));
       dp[0]=0;
       for(int i=1;i<=6;i++)
       {
           dp[i]=1;
       }
       for(int x=1;x<=n;x++)
       {
           for(int i=1;i<=6;i++)
           {
               if(x>=i)
               {
                   dp[x]=(dp[x]%mod+dp[x-i]%mod)%mod;
               }
           }
       }
       cout<<dp[n]%mod<<endl;
    }
}
