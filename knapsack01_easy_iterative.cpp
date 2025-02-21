#include<bits/stdc++.h>
using namespace std;
long long dp[110][1000010]; 
////https://atcoder.jp/contests/dp/tasks/dp_d
int main()
{
    long long tt=1;
   // cin>>tt;
    while(tt--)
    {
       long long n,W;
       cin>>n>>W;
       vector<long long>cost(n+10),weight(n+10);
       for(int i=1;i<=n;i++)
       {
           cin>>weight[i];
           cin>>cost[i];
       }
       for(int i=0;i<=n;i++)
       {
           for(int x=0;x<=W;x++)
           {
               if(i==0)
               {
                   dp[i][x]=0;
                   continue;
               }
               if(x==0)
               {
                   dp[i][x]=0;
                   continue;
               }
               dp[i][x]=dp[i-1][x];
               if(x>=weight[i])
               {
                   dp[i][x]=max(dp[i][x],dp[i-1][x-weight[i]]+cost[i]);
               }

           }
       }
        /*
       for(int i=0;i<=n;i++)
       {
           for(int x=0;x<=W;x++)
           {

               cout<<dp[i][x]<<" ";

           }
           cout<<endl;
       } 
       */
       long long ans=0;

      // cout<<dp[n][W]<<endl; shudhu eta dileo answer same asto

       for(int x=0;x<=W;x++)
       {
           ans=max(dp[n][x],ans);
       }
       cout<<ans<<endl;
    }
}
