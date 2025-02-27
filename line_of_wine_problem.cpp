#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long tt;
    cin>>tt;
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
                   dp[l][r]=arr[l]*n;
                   continue;
               }
               dp[l][r]=max(dp[l+1][r]+arr[l]*(n-(r-l)),dp[l][r-1]+arr[r]*(n-(r-l)));
           }
       }
       cout<<dp[1][n]<<endl;
    }
    return 0;
}
///either left most theke pick korte paro neither right most theke pick korte paro . 
///jeta pick kora oita kon year e sell kortecho seta diye oi year diye gun diba . 
/// ekhane sub array niye kaj korteche mane ekta sub array thakbe baki gula delete , oi subarry eiher left ta delete korchi,neither right most elemnet ta delete korchi
