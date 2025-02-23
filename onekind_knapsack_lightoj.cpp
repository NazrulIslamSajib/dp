////https://lightoj.com/problem/thief 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long tt;
    cin>>tt;
    for(int t=1;t<=tt;t++)
    {
       long long n,W;
       cin>>n>>W;
       long long sum=0;
       long long arr[n+10],brr[n+10];
       for(int i=1;i<=n;i++)
       {
         long long a,b,c;
         cin>>a>>b>>c;
         sum+=(b*c);
         arr[i]=c;
         brr[i]=a;
       }
       if(sum>W)
       {
           cout<<"Case "<<t<<": "<<"Impossible"<<endl;
           continue;
       }
       long long w=W-sum;
       long long dp[n+10][w+10];
       memset(dp,0,sizeof(dp));
       for(int i=1;i<=n;i++)
       {
          for(int x=1;x<=w;x++)
          {
             dp[i][x]=dp[i-1][x];
             if(x>=arr[i])
             {
                 dp[i][x]=max(dp[i][x],dp[i][x-arr[i]]+brr[i]);
                 ///ekta onek bar nite parbo tai i-1 di nai.
             }
          }
       }
       cout<<"Case "<<t<<": "<<dp[n][w]<<endl;
    }
}

