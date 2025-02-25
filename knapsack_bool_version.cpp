#include<bits/stdc++.h>
using namespace std;
///https://cses.fi/problemset/task/1745/
///knapsack bool version
int main()
{
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
       long long n;
       cin>>n;
       long long arr[n+10],sum=0;
       for(int i=1;i<=n;i++)
       {
           cin>>arr[i];
           sum+=arr[i];
       }
       bool dp[sum+10][n+10];
       memset(dp,false,sizeof(dp));
       dp[0][0]=true; ///base case
       for(int x=0;x<=sum;x++)
       {
           for(int i=1;i<=n;i++)
           {
              if(x==0)
              {
                  dp[x][i]=true;  ///0 hole to true ditei hbe baki kketre false
                  continue;
              }
              if(x>=arr[i])
              dp[x][i]=dp[x][i-1] || dp[x-arr[i]][i-1];  /// dekho x ki age true kina if na hoye
                                                         /// then arr[i] eta use kore dekhi age true kina
              if(dp[x][i-1])
              {
                  dp[x][i]=true;
              }
           }
       }
       set<long long>ans;
       for(int x=1;x<=sum;x++)
       {
           for(int i=1;i<=n;i++)
           {
               if(dp[x][i]==true)
               {

                ans.insert(x);
               }
           }

       }
       cout<<ans.size()<<endl;
       for(auto x:ans)
       {
           cout<<x<<" ";
       }
       cout<<endl;
    }
    return 0;
}

