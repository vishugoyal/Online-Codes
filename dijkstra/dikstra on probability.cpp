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
vector<int> g[201];
vector<double> p[201];
bool vis[201];
double prob[201];
int a,b;
double w;
int main()
{
    int n,m;
    
    scanf("%d %d",&n,&m);
    while(n!=0){
                
        for(int i=0;i<201;i++){
             g[i].clear();p[i].clear();vis[i]=0;prob[i]=0.0;
        }
        
        for(int i=0;i<m;i++){
            scanf("%d %d %lf",&a,&b,&w);
            a--;b--;w/=100.0;
            
            g[a].pb(b);p[a].pb(w);
            g[b].pb(a);p[b].pb(w);
        }
        
        priority_queue< pair<double,int> > q;
        prob[0]=1.0;
        q.push(make_pair(prob[0],0));
        
        while(!q.empty() ){
        
              pair<double,int> temp=q.top();q.pop();
              int ind=temp.second;
              
              if(vis[ind])continue;
              vis[ind]=1;
              
              for(int i=0;i<g[ind].size();i++){
                      
                      if(prob[g[ind][i]]>=prob[ind]*p[ind][i])continue;
                      prob[g[ind][i]]=prob[ind]*p[ind][i];
                      q.push(make_pair(prob[g[ind][i]],g[ind][i]));
                      
              }
                         
        }
        
        printf("%0.6lf percent\n",prob[n-1]*100.0);
        scanf("%d %d",&n,&m);
    }
   return 0;
}
