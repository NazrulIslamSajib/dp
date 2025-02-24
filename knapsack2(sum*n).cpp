#include<bits/stdc++.h>
using namespace std;
///https://atcoder.jp/contests/dp/tasks/dp_e
///ekhane ami values er upore dp calacchi ami answer er upore . O(sum*n) //sum of weight
int main()
{
    long long tt=1;
   // cin>>tt;
    while(tt--)
    {
        long long n,W;
        cin>>n>>W;
        vector<long long>weights(n+10),values(n+10);
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>weights[i];
            cin>>values[i];
            sum+=values[i];
        }
        vector<vector<long long>>dp(n+10,vector<long long>(sum+10,INT_MAX)); /// dhoro correct value paite amar weight lage doro infinity . kintu I need weight minimum
        /// so coreect vaules er jonno weight minimum anar cesta korbo.
        dp[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int v=0;v<=sum;v++)
            {
                if(v==0)
                {
                    dp[i][v]=0;  /// jokhon dp[i-1][v-v[i]]  ,...v-v[i]=0 hbe tokhon dp[i][0] age values ney nai tahole weight 0 dite hbe
                    continue;
                }
                dp[i][v]=dp[i-1][v];  /// v values er jonno ager koto weight paichi seta niye nichi .
                if(v>=values[i])
                {
                    dp[i][v]=min(dp[i][v],dp[i-1][v-values[i]]+weights[i]);  /// correct v values jonno ager biyog dicchi
                }
            }
        }
        long long ans=0;
        for(long long v=1;v<=sum;v++)
        {
            if(dp[n][v]<=W)
            {
                ans=max(ans,v);  ///W er theke choto ei rokom maximum v ta nicchi
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}

