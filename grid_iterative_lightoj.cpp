///https://lightoj.com/problem/monkey-banana-problem
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long tt;
    cin>>tt;
    for(int t=1;t<=tt;t++)
    {
       long long n;
       cin>>n;
       long long arr[2*n+10][2*n+10];
       long long dp[2*n+10][2*n+10];
       memset(dp,0,sizeof(dp));
       for(int i=1;i<=2*n;i++)
       {
           for(int j=1;j<=2*n;j++)
           {
               arr[i][j]=0;
           }
       }
       queue<long long>q;
       for(int i=1;i<=n*n;i++)
       {
           long long x;
           cin>>x;
           q.push(x);
       }
       long long need=n,gap=n-1;
       for(int i=1;i<=n;i++)
       {

           for(int j=need;j<=2*n-1-gap;j+=2)
           {
               arr[i][j]=q.front();
               q.pop();
           }
           gap--;
           need--;
       }
       need=2,gap=1;
       for(int i=n+1;i<=2*n-1;i++)
       {
           for(int j=need;j<=2*n-1-gap;j+=2)
           {
               arr[i][j]=q.front();
               q.pop();
           }
           gap++;
           need++;
       }
       /*
       for(int i=1;i<=2*n-1;i++)
       {
           for(int j=1;j<=2*n-1;j++)
           {
               cout<<arr[i][j]<<" ";
           }
           cout<<endl;
       }
       */
       for(int i=1;i<=2*n-1;i++)
       {
           for(int j=1;j<=2*n-1;j++)
           {   dp[i][j]=arr[i][j];
               long long max1=0;
               if(i-1>=1 && j-1>=1)
               {
                   max1=dp[i-1][j-1];
               }
               if(i-1>=1 && j+1<=2*n-1)
               {
                   max1=max(max1,dp[i-1][j+1]);
               }
               dp[i][j]+=max1;
           }
       }
       /*
       for(int i=1;i<=2*n-1;i++)
       {
           for(int j=1;j<=2*n-1;j++)
           {
               cout<<dp[i][j]<<" ";
           }
           cout<<endl;
       }
       */
       if(n==1) {
        cout<<"Case "<<t<<": "<<arr[1][1]<<endl;
        continue;
       }
        cout<<"Case "<<t<<": "<<dp[n*2-1][n]<<endl;
    }
}
