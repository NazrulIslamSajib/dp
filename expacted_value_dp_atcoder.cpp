///https://atcoder.jp/contests/dp/tasks/dp_j
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        double dp[n+2][n+2][n+2];
        int arr[n+2];
        vector<int>cnt(4,0);
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
            cnt[arr[i]]++;
        }
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=0;
        for(int three=0;three<=n;three++)
        {
              for(int two=0;two<=n;two++)
              {
                   for(int one=0;one<=n;one++)
                   {
                        int zero=n-one-two-three;
                        if(zero==n) continue;
                        if(zero<0) continue;

                        double val=1.0;
                        if(three>=1)
                        val+=(1.0*three/n)*(dp[three-1][two+1][one]);
                        if(two>=1)
                        val+=(1.0*two/n)*(dp[three][two-1][one+1]);
                        if(one>=1)
                        val+=(1.0*one/n)*(dp[three][two][one-1]);

                        dp[three][two][one]=val/(1.0-(1.0*zero/n));
                   }
              }
        }
        cout<<setprecision(10)<<dp[cnt[3]][cnt[2]][cnt[1]]<<endl;
    }
    return 0;
}

