#include<bits/stdc++.h>
using namespace std;
long long dp[100010][110]; 
///https://atcoder.jp/contests/dp/tasks/dp_d
int main()
{
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
       long long n,W;
       cin>>n>>W;
       vector<long long>weight(n+10);
       vector<long long>costs(n+10);
       for(int i=1;i<=n;i++)
       {
           cin>>weight[i];
           cin>>costs[i];
       }
       for(int x=0;x<=W;x++)
       {
           for(int i=0;i<=n;i++)
           {
               if(x==0)  ///initialization
               {
                   dp[x][i]=0;
                   continue;
               }
               if(i==0)   //// initialization 
               {
                   dp[x][i]=0;
                   continue;
               }
               dp[x][i]=max(dp[x][i],dp[x][i-1]);  ///etar mane hocche i-th element ta ami nilam i na,and eta tar picnoner theke maximum niye nicche
               if(x>=weight[i])
               dp[x][i]=max(dp[x][i],dp[x-weight[i]][i-1]+costs[i]);  ///etao i-1 hobe karon etar possibility hote th arek bar nichi previously
           }
       }
       long long ans=0;
       for(int x=0;x<=W;x++)
       {
          ans=max(dp[x][n],ans);
       }
       cout<<ans<<endl;
    }
}

