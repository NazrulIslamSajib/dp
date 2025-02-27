#include<bits/stdc++.h>
using namespace std;
///https://cses.fi/problemset/task/1097
int main()
{
    long long tt=1;
   // cin>>tt;
    while(tt--)
    {
       long long n;
       cin>>n;
       long long arr[n+10];
       for(int i=1;i<=n;i++)
       {
           cin>>arr[i];
       }
       long long dp[n+10][n+10];
       memset(dp,0,sizeof(dp));
       for(int l=n;l>=1;l--)
       {
           for(int r=l;r<=n;r++)
           {
               if(l==r)
               {
                   dp[l][r]=arr[l];  ///jodi ekta hoy tahole to setai nibo
                   continue;
               }
               if((r-l)==1)
               {
                   dp[l][r]=max(arr[l],arr[r]); ///jodi 2 hoy then max ta nibo
                   continue;
               }
               dp[l][r]=max(arr[l]+min(dp[l+1][r-1],dp[l+2][r]),arr[r]+min(dp[l+1][r-1],dp[l][r-2]));
               ///ekhane ache l,r sub array eder modde either l,r element nite hbe , tahole ami amon vabe nibo jeno 2nd player ta minimum
               ///pay amar move er pore ei jonno ami tar 2 rkm possibility niyechi . dekho ami jodi l ni, tar kache thakteche l+1,r
               ///so se abar l+1 choose korte pare abar r choose korte pare ei vabe combinarion toiri korchi .
               ///sesh mesh ekta sub array thake boro sub array ta . ... 1 theke n subarray

           }
       }
       cout<<dp[1][n]<<endl;
    }
    return 0;
}

