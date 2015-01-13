/*
    DFS application
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
bool vis[100001];
int trav(int i){
    
    if(vis[i]) return 0;
    vis[i]=1;
    int toret=1;
    for(int j=0;j<graph[i].size();j++)
        toret+=trav(graph[i][j]);
     
    return toret;
}
int main() {
    
    int n,m;
    cin>>n>>m;
    
    int x,y;
    
    for(int i=0;i<m;i++){
       cin>>x>>y;
       x--;y--;
       graph[x].push_back(y);
       graph[y].push_back(x);
    }
    
    memset(vis,0,sizeof(vis));
    int ans=0;
    for(int i=0;i<n;i++){
       
        if(vis[i])
            continue;
        
        ans+=ceil(sqrt(trav(i)));
        
    }
    
    printf("%d\n",ans);
    return 0;
}
