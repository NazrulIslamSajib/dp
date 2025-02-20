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
          sum=(total+1)%mod;  ///cur postion er jonno  value
          if(mp.find(c)==mp.end())  ///samne ei char na pele viyog deoya
          ///lagbe na
          {
              total=(total%mod+sum%mod)%mod;
          }
          else
          {
              total=(total%mod+(sum-mp[c]+mod)%mod)%mod;
          }
          mp[c]=sum;
      }
      cout<<total+1<<endl;
    }
}
