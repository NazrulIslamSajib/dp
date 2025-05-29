///https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution{
public:
    int largestRectangleArea(vector<int>& heights) {
    
        stack<pair<long long,long long>>st,st1;
        long long n=heights.size();
        long long dp[n+10],dp1[n+10];
        long long arr[n+10];
        for(int i=1;i<=n;i++)
        {
            arr[i]=heights[i-1];
        }
        for(int i=n;i>=1;i--)
        {
            if(!st.empty())
            {
                long long index=i;
                while(st.size()>=1 && st.top().first>=arr[i])
                {
                    index=st.top().second;
                    st.pop();

                }
                dp[i]=index;
                st.push({arr[i],index});

            }
            else
            {
                st.push({arr[i],i});
                dp[i]=st.top().second;
                ////cout<<"sajib : "<<i<<" "<<dp[i]<<endl;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(!st1.empty())
            {
                long long index=i;
                while(st1.size()>=1 && st1.top().first>=arr[i])
                {
                    index=st1.top().second;
                    st1.pop();

                }
                dp1[i]=index;
                st1.push({arr[i],index});

            }
            else
            {
                st1.push({arr[i],i});
                dp1[i]=st1.top().second;
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            ///cout<<dp[i]<<" "<<dp1[i]<<endl;
            ans=max(ans,(dp[i]-dp1[i]+1)*arr[i]);
        }
        return ans;

    }
};
