#include<bits/stdc++.h>
using namespace std;
int const mod=1e9+7;
////https://www.spoj.com/problems/DSUBSEQ/
int main()
{
    long long tt;
    cin>>tt;
    while(tt--)
    {

      string s;
      cin>>s;
      long long n=s.size();
      map<char,long long>mp;
     ///empty subsequence also a sub sequence
      long long total=0,sum=0;
      for(int i=0;i<n;i++)
      {
          char c=s[i];
          sum=(total+1)%mod;  ///pore biyoger jonno store kortechi. dp[cur] er jonno,niche dekho
          if(mp.find(c)==mp.end())  ///samne ei char na pele viyog deoya
          ///lagbe na
          {
              total=(total%mod+sum%mod)%mod;
          }
          else
          {
              total=(total%mod+(sum-mp[c]+mod)%mod)%mod; ///bigor kortechi kintu goto c er ta
          }
          mp[c]=sum;   ///pore biyoger jonno store kortechi.




      }
      cout<<total+1<<endl;
    }
}
///abca
/*
dekho amar c er jonno joto gula distinct value hoicilo seta kintu last er a jonnoi hbe tai
dp[4]=dp[3]+dp[2]+dp[1]+1; abca ekta subsequence tai jog korchi.
eta just dp[4] er jonno
amake to bolche total tai
total=dp[4]+dp[3]+dp[2]+dp[1];
bcdabcda
4th a gula biyog dibo 8th er kache asle
*/
