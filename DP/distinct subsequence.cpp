/*

// http://www.spoj.com/problems/DSUBSEQ/

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<set>
#include<stack>
#include<deque>
#include<queue>
#include <limits.h>
#define pb(x) push_back(x)
#define mod 1000000007
using namespace std;

string s;
int l;
int pos[26];
int ans[100001];
int main()
{
    
    int t;
    scanf("%d",&t);
    while(t--)
    {
              for(int i=0;i<26;i++)
                 pos[i]=-1;
              
              cin>>s;
              
             l=s.length();
             ans[0]=1;
             
             for(int i=1;i<=l;i++){
                     ans[i]=(ans[i-1]*2)%mod;
                     
                     
                     
                     
                     if(pos[s[i-1]-'A']!=-1)
                        ans[i]-=ans[pos[s[i-1]-'A']-1];
                     ans[i]=(ans[i]+mod)%mod;
                     pos[s[i-1]-'A']=i;
                     
             }
             
            cout<<ans[l]<<endl;
    }
   return 0;
}
