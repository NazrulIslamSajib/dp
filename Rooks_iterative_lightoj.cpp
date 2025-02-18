////https://lightoj.com/problem/rooks
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long tt;
    cin>>tt;
    for(int t=1;t<=tt;t++)
    {
       int n,k;
       cin>>n>>k;
       if(k>n)
       {
           cout<<"Case "<<t<<": "<<0<<endl;
           continue;
       }
       long long dp[n+10][n+10];
       memset(dp,0,sizeof(dp));
       dp[0][0]=1;
       for(int i=1;i<=n;i++)
       {
           for(int j=0;j<=min(k,i);j++)
           {

               dp[i][j]=dp[i-1][j];
               if(j-1>=0)
               {
                   dp[i][j]+=dp[i-1][j-1]*(n-j+1);
               }
           }
       }
       cout<<"Case "<<t<<": "<<dp[n][k]<<endl;

    }
}
