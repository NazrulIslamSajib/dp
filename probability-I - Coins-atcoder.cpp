////https://atcoder.jp/contests/dp/tasks/dp_i 
///problem says head>tail 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    //cin>>tt;
    while(tt--)
    {
           int n;
           cin>>n;
           double arr[n+2];
           for(int i=1;i<=n;i++)
           {
               cin>>arr[i];
           }
           double dp[n+2][n+2];
           memset(dp,0,sizeof(dp));
           dp[0][0]=1;
           for(int i=1;i<=n;i++)
           {
               for(int j=0;j<=i;j++)
               {
                     if(j==0)
                     {
                         dp[i][j]=dp[i-1][j]*(1-arr[i]);
                     }
                     else
                     {
                         dp[i][j]=dp[i-1][j]*(1-arr[i])+(dp[i-1][j-1]*arr[i]);
                     }
               }
           }
           double ans=0;
           for(int i=(n+1)/2;i<=n;i++)
           {
               ans+=dp[n][i];
           }
           cout<<setprecision(10)<<ans<<endl;
    }
    return 0;
}
