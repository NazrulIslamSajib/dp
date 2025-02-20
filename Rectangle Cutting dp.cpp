#include<bits/stdc++.h>
using namespace std;
///https://cses.fi/alon/task/1744/
int main()
{
    long long tt=1;
   // cin>>tt;
    while(tt--)
    {
        long long n,m;
        cin>>n>>m;
        long long dp[n+10][m+10];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j]=1e15;
                if(i==j)
                {
                    dp[i][j]=0;
                    continue;
                }
                for(int k=1;k<i;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1); /// column thik thakbe row 2 vag hoye jabe
                }
                for(int k=1;k<j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1); /// row thik thakbe column ke 2 vag korbo
                }
            }
        }
        cout<<dp[n][m]<<endl;
    }
}
