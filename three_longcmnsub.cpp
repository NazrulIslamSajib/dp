////https://lightoj.com/problem/batman
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long tt;
    cin>>tt;
    for(int t1=1;t1<=tt;t1++)
    {
       string s,t,r;
       cin>>s>>t>>r;
       long long n1=s.size(),n2=t.size(),n3=r.size();
       long long dp[n1+2][n2+2][n3+2];
       memset(dp,0,sizeof(dp));
       for(int i=0;i<=n1;i++)
       {
           for(int j=0;j<=n2;j++)
           {
               for(int k=0;k<=n3;k++)
               {
                   if(i>0 && j>0 && k>0 && s[i-1]==t[j-1] && r[k-1]==s[i-1])
                   {
                     dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                   }
                   if(j>0 && k>0)
                   {
                       dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-1]);
                   }
                   if(i>0 && k>0)
                   {
                       dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]);
                   }
                   if(k>0)
                   {
                       dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]);
                   }
                   if(i>0 && j>0)
                   {
                       dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]);
                   }
                   if(j>0)
                   {
                       dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]);
                   }
                   if(i>0)
                   {
                       dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);
                   }

               }
           }
       }
       cout<<"Case "<<t1<<": "<<dp[n1][n2][n3]<<endl;

    }
     return 0;
}
