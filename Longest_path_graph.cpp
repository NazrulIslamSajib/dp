///https://atcoder.jp/contests/dp/tasks/dp_g 
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int mx=2e5+3;
bool vis[2000010];
vector<int>dp(mx,0);
vector<int>arr[200010];
void dfs(int i)
{
    if(vis[i]==true)
    {
        return;
    }
    vis[i]=true;
    for(auto x:arr[i])
    {
        if(vis[x]==false)
        {
            dfs(x);
        }
        dp[i]=max(dp[i],(dp[x]+1)%mod);
    }
}
int main()
{
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            arr[u].push_back(v);
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==false)
            {
                dfs(i);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(dp[i],ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}

