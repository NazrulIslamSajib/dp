#include<bits/stdc++.h>
using namespace std;
int const mod=100000007;
////https://lightoj.com/problem/coin-change-i
int main()
{
    long long tt;
    cin>>tt;
    for(int t=1;t<=tt;t++)
    {
        long long n,W;
        cin>>n>>W;
        long long dp[n+10][W+10];
        memset(dp,0,sizeof(dp));
        long long arr[n+10];
        map<long long,long long>mp;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        for(int j=1;j<=n;j++)
        {
            long long x;
            cin>>x;
            mp[arr[j]]=x;
        }
        for(int i=0;i<=n;i++)
        {
            for(int x=0;x<=W;x++)
            {
                if(x==0)
                {
                    dp[i][x]=1;
                    continue;
                }
                if(i==0)
                {
                    dp[i][x]=0;
                    continue;
                }
                dp[i][x]=dp[i-1][x];  ///ith element ta nilam na
                for(int l=1;l<=mp[arr[i]];l++)
                {
                    if(x>=(l*arr[i]))
                    {
                        dp[i][x]=(dp[i][x]%mod+dp[i-1][x-l*arr[i]]%mod)%mod;

                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        cout<<"Case "<<t<<": "<<dp[n][W]<<endl;
}
    return 0;
}

