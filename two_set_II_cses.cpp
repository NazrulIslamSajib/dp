#include<bits/stdc++.h>
using namespace std;
int const mod=1e9+7;
///https://cses.fi/problemset/task/1093/
long long power(long long base, long long power)
{
        long long res=1;
        while(power)
        {
            if(power%2==1)
            {
                res=(base%mod)*(res%mod);
                power--;
            }
            else
            {
                base=(base%mod)*(base%mod);
                power=power/2;
            }
        }
        return res%mod;
}
int main()
{
    long long tt=1;
   /// cin>>tt;
    while(tt--)
    {
       long long n;
       cin>>n;

       long long sum=(n*(n+1))/2;
       if(sum%2)
       {
           cout<<0<<endl;
           continue;
       }
       long long need=sum/2;
       long long dp[n+2][need+2];
       memset(dp,0,sizeof(dp));
       dp[0][0]=1;
       for(int i=1;i<=n;i++)
       {
           for(int x=0;x<=need;x++)
           {
               if(x==0)
               {
                   dp[i][x]=1;
                   continue;
               }
               dp[i][x]=dp[i-1][x];
               if(x>=i)
               {
                   dp[i][x]=(dp[i][x]+dp[i-1][x-i])%mod;
               }
           }
       }
       /*
        for(int i=1;i<=n;i++)
       {
           for(int x=0;x<=need;x++)
           {
              cout<<dp[i][x]<<" ";
           }
           cout<<endl;
       }
       */
       long long p=1e9+7;
       long long take=power(2LL,p-2);
       cout<<(dp[n][need]*(take))%mod<<endl;
    }
    return 0;
}
