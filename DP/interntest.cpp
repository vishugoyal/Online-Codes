/*
   DP: given a matrix with start and end. you can move up,down, left,right. you need to minimize no of right angled turns
   
 */
#include <iostream>
#include<cstdio>
#include<queue>

using namespace std;
int n,m;
char mat[101][101];
bool vis[101][101][2];

bool isvalid(int i,int j,int k){
    return (i>=0 && j>=0 && i<n && j<m && mat[i][j]!='#' && !vis[i][j][k]);    
}

class mydata{
    public:
    int x;
    int y;
    int dir;
    int t;
    
    bool operator<(const mydata& p) const{
         return (t > p.t);
    }
};

int main() {
   
    
    
    
    int sx,sy;
    
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        cin>>mat[i];
        for(int j=0;j<m;j++) 
            if(mat[i][j]=='S'){
                sx=i;
                sy=j;
             }
    }
    
    for(int i=0;i<101;i++)
        for(int j=0;j<101;j++)
           for(int k=0;k<2;k++)
              vis[i][j][k]=0;
        
    priority_queue< mydata > q;
    
    mydata temp;
    bool poss=false;
    int ans;
    
    temp.x=sx;temp.y=sy;temp.dir=0;temp.t=0;
    q.push(temp);
    temp.dir=1;
    q.push(temp);
    
    
    
    int a,b,c,d;
    while(!q.empty()){
        
        temp=q.top();q.pop();
        a=temp.x;
        b=temp.y;
        c=temp.dir;
        d=temp.t;
        
        vis[a][b][c]=1;
        if(mat[a][b]=='E'){
            poss=1;
            ans=d;
            break;
        }
        
        if(c==0){
             
            if(isvalid(a,b+1,1)){
                temp.x=a;
                temp.y=b+1;
                temp.dir=1;
                temp.t=d+1;
                q.push(temp);
            }
            if(isvalid(a,b-1,1)){
                temp.x=a;
                temp.y=b-1;
                temp.dir=1;
                temp.t=d+1;
                q.push(temp);
            }
            if(isvalid(a-1,b,0)){
                temp.x=a-1;
                temp.y=b;
                temp.dir=0;
                temp.t=d;
                q.push(temp);
            }
            if(isvalid(a+1,b,0)){
                temp.x=a+1;
                temp.y=b;
                temp.dir=0;
                temp.t=d;
                q.push(temp);
            }
        }
        else{
            
            if(isvalid(a,b+1,1)){
                temp.x=a;
                temp.y=b+1;
                temp.dir=1;
                temp.t=d;
                q.push(temp);
            }
            if(isvalid(a,b-1,1)){
                temp.x=a;
                temp.y=b-1;
                temp.dir=1;
                temp.t=d;
                q.push(temp);
            }
            if(isvalid(a-1,b,0)){
                temp.x=a-1;
                temp.y=b;
                temp.dir=0;
                temp.t=d+1;
                q.push(temp);
            }
            if(isvalid(a+1,b,0)){
                temp.x=a+1;
                temp.y=b;
                temp.dir=0;
                temp.t=d+1;
                q.push(temp);
            }
        }
        
    }
    
    if(poss)printf("%d\n",ans);
    else printf("IMPOSSIBLE\n");
return 0;
}
