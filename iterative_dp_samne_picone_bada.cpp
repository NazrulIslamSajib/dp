////https://acm.timus.ru/problem.aspx?space=1&num=1225
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
        long long n;
        cin>>n;
        long long dp[n+10][3];
        memset(dp,0,sizeof(dp));
        dp[1][0]=1;
        dp[1][1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i][0]=dp[i-1][1]+dp[i-2][1];
            dp[i][1]=dp[i-1][0]+dp[i-2][0];
        }
        cout<<dp[n][0]+dp[n][1]<<endl;
    }
}
