///https://atcoder.jp/contests/dp/tasks/dp_f 
///longest common subsequence
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
       string s1,s2;
       cin>>s1>>s2;
       long long n1=s1.size(),n2=s2.size();
       long long dp[n1+10][n2+10];
       memset(dp,0,sizeof(dp));
       for(int i=0;i<=n1;i++)
       {
           for(int j=0;j<=n2;j++)
           {
               if(i-1>=0 && j-1>=0 && s1[i-1]==s2[j-1])
               {
                   dp[i][j]+=dp[i-1][j-1]+1;
               }
               if(i-1>=0)
               {
                   dp[i][j]=max(dp[i][j],dp[i-1][j]);
               }
               if(j-1>=0)
               {
                   dp[i][j]=max(dp[i][j],dp[i][j-1]);
               }
           }
       }
       vector<char>ans;
       long long cnt1=n1,cnt2=n2;
       while(cnt1>0 && cnt2>0)
       {
           if(dp[cnt1][cnt2]==dp[cnt1][cnt2-1])
           {
               cnt2--;
               continue;
           }
           if(dp[cnt1][cnt2]==dp[cnt1-1][cnt2])
           {
               cnt1--;
               continue;
           }
           ans.push_back(s1[cnt1-1]);
           cnt1--;
           cnt2--;
       }
       reverse(ans.begin(),ans.end());
       for(auto x:ans)
       {
           cout<<x<<"";
       }
       cout<<endl;
    }
}

