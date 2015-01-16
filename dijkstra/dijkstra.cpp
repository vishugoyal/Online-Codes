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
struct mydata{
       public:
       int node;
       int val;
       bool operator<(const mydata& x) const{
            return (val>x.val);
        }
}temp;
int v,k,u;
int sr,de;
int s,d,ww;
vector<int> g[10001];
vector<int> w[10001];
bool vis[10001];
int sh[10001];

void init(){
     for(int i=0;i<10001;i++)
                 {g[i].clear();w[i].clear();vis[i]=0;sh[i]=INT_MAX;}    
}


int main()
{
    
    int t;
    scanf("%d",&t);
    while(t--)
    {
              
              init();
              scanf("%d %d",&v,&k);
              for(int i=0;i<k;i++){
                     scanf("%d %d %d",&s,&d,&ww); 
                     s--;d--;
                     g[s].pb(d);w[s].pb(ww);
              }
              scanf("%d %d",&sr,&de);
              sr--;de--;
              priority_queue<mydata> pq;
              temp.node=sr;temp.val=0;
              
              pq.push(temp);
              sh[sr]=0;
              while(!pq.empty()){
                  temp=pq.top();pq.pop();
                  v=temp.node;
                 //cout<<v<<endl;
                  if(vis[v])continue;
                  vis[v]=1;
                 
                 
                 for(int i=0;i<g[v].size();i++){
                         if(sh[g[v][i]]>sh[v]+w[v][i] && !vis[g[v][i]]){
                              sh[g[v][i]]=sh[v]+w[v][i];
                              temp.node=g[v][i];
                              temp.val=sh[g[v][i]];
                              pq.push(temp);
                         }
                  }
                 
              }
            if(vis[de])  
            cout<<sh[de]<<endl;
            else
            cout<<"NO"<<endl;  
              
              
    }
   return 0;
}
