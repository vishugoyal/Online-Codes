/*

// http://www.spoj.com/problems/MST/
// can can not be applied on directed graphs
// http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2124

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
#define getcx getchar_unlocked
using namespace std;

int n,m,a,b;long long c,ans;
vector<int> g[10001];
vector<long long> w[10001];
long long d[10001];
bool vis[10001];


class mydata{
     
     public:
            int ind;
            long long val;
     bool operator<(const mydata& v) const{
          return val>v.val;
     } 
}temp;

void init(){
     
     for(int i=0;i<n;i++){
        g[i].clear();
        w[i].clear();
        d[i]=10000000;
        vis[i]=0;
        ans=0;
     }
}
int main()
{
    
   scanf("%d %d",&n,&m);
   
   init();
   
   for(int i=0;i<m;i++){
         scanf("%d %d %lld",&a,&b,&c);
         a--;b--;
         g[a].push_back(b);w[a].push_back(c);
         g[b].push_back(a);w[b].push_back(c);
   }
   
   
   d[0]=0;
   temp.ind=0;temp.val=0;
   
   
   priority_queue< mydata > q;q.push(temp);
   while(!q.empty()){
                     
             temp=q.top();q.pop();
             a=temp.ind;
             
             if(vis[a])  continue;
             vis[a]=1;ans+=d[a];
             
             for(int i=0;i<g[a].size();i++){
                    if(vis[g[a][i]])continue;
                    if(d[g[a][i]]>w[a][i]){
                          temp.ind=g[a][i];
                          
                          d[g[a][i]]=w[a][i];
                          temp.val=d[g[a][i]];
                          q.push(temp);
                    }
                       
              }     
   }
   
   printf("%lld\n",ans);
   
   return 0;
}
