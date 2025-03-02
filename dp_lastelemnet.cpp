#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
///https://cses.fi/problemset/result/12218319/
bool is_valid(int k,int m)
{
    if(k>=1 && k<=m)
    {
        return true;
    }
    return false;
}
int main()
{
    long long tt=1;
    //cin>>tt;
    while(tt--)
    {
       long  long n,m;
       cin>>n>>m;
       long long arr[n+10];
       for(int i=1;i<=n;i++)
       {
           cin>>arr[i];
       }
       long long dp[n+3][m+3];
       memset(dp,0,sizeof(dp));
       for(int x=1;x<=m;x++)
       {
           if(arr[1]==x || arr[1]==0)
           {
               dp[1][x]=1;
           }
       }
       for(int i=2;i<=n;i++)
       {
           for(int x=1;x<=m;x++)
           {
               if(arr[i]!=0)
               {
                  for(int k=arr[i]-1;k<=arr[i]+1;k++)
                  {
                      if(is_valid(k,m))
                      {
                          dp[i][arr[i]]=(dp[i][arr[i]]+dp[i-1][k])%mod;
                      }
                  }
                  break;
               }
               else
               {
                  for(int k=x-1;k<=x+1;k++)
                  {
                      if(is_valid(k,m))
                      {
                          dp[i][x]=(dp[i][x]+dp[i-1][k])%mod;
                      }
                  }
               }
           }
       }
       if(arr[n]==0)
       {
       long long sum=0;
       for(int x=1;x<=m;x++)
       {
           sum=(sum+dp[n][x])%mod;
       }
       cout<<sum<<endl;
       }
       else
       {
           cout<<dp[n][arr[n]]<<endl;
       }
    }
    return 0;
}

