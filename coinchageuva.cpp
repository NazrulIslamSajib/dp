#include<bits/stdc++.h>
using namespace std; 
///https://vjudge.net/problem/uva-357
int main()
{
    long long tt=1;
   /// cin>>tt;
    while(tt--)
    {
         vector<long long>v={1,5,10,25,50};
         long long n;
         long long arr[7];
         for(int i=1;i<=5;i++)
         {
            arr[i]=v[i-1];
         }
         while(cin>>n)
         {
             long long dp[7][n+10];
             memset(dp,0,sizeof(dp));
             dp[0][0]=1;
             for(int i=1;i<=5;i++)
             {
                 for(int x=0;x<=n;x++)
                 {
                     dp[i][x]=dp[i-1][x];
                     if(x>=arr[i])
                     {
                         dp[i][x]+=dp[i][x-arr[i]];
                     }
                 }

             }


             if(dp[5][n]==1)
             {
                 cout<<"There is only "<<dp[5][n]<<" way to produce "<<n<<" cents change."<<endl;
             }
             else
             {
                  cout<<"There are "<<dp[5][n]<<" ways to produce "<<n<<" cents change."<<endl;
             }
         }
    }
}

