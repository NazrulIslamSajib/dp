#include<bits/stdc++.h>
using namespace std;
///https://atcoder.jp/contests/dp/tasks/dp_n
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
        long long n;
        cin>>n;
        long long arr[n+10];
        arr[0]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
            arr[i]=arr[i-1]+arr[i];
        }
        vector<vector<long long>>dp(n+2,vector<long long>(n+2,0));
        for(int l=n;l>=1;l--)
        {
            for(int r=l;r<=n;r++)
            {
                if(l==r)
                {
                    dp[l][r]=0;
                }
                else
                {
                    dp[l][r]=1e18;
                    for(int x=l;x<=r-1;x++)
                    {
                        dp[l][r]=min(dp[l][r],dp[l][x]+dp[x+1][r]+(arr[r]-arr[l-1]));
                        ///l r hbe  eder abar 2 ta sub array er sum sahte to interval er sum lagbei
                    }

                }
            }
        }
        cout<<dp[1][n]<<endl;
    }
    return 0;
}



