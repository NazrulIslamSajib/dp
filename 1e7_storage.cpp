#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int dp[1002][40005];
bool is_valid(int i)
{
    long long original=i,rev=0;
    while(i>0)
    {
        long long digit=i%10;
        rev=rev*10+digit;
        i=i/10;
    }
    return original==rev;
}
int main()
{
    long long tt;
    vector<long long>v;
    long long sum=4e4+2;
    for(int i=1;i<=sum;i++)
    {
        if(is_valid(i))
        {
            v.push_back(i);
        }
    }
    /// cout<<v.size()<<endl;
     int sz=v.size()+2;
     memset(dp,0,sizeof(dp));
     for(int i=0;i<v.size();i++)
     {
           for(int x=0;x<=sum;x++)
           {
               if(x==0)
               {
                   dp[i][x]=1;
                   continue;
               }
               if(i>=1)
               dp[i][x]=dp[i-1][x];
               if(x>=v[i])
               {
                   dp[i][x]=(dp[i][x]+dp[i][x-v[i]])%mod;
               }
           }
     }
    cin>>tt;
    while(tt--)
    {
       long long n;
       cin>>n;
       long long take=upper_bound(v.begin(),v.end(),n)-v.begin();
       take--;
       cout<<dp[take][n]<<endl;

    }
    return 0;
}
