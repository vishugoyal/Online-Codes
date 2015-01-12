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
#define MAX 101
using namespace std;

int t,n,m,sx,sy,gx,gy;
bool ans;int pans;
char f[MAX][MAX];
bool done[MAX][MAX][4];

bool isvalid(int i,int j){
     
     return (i>=0 && j>=0 && i<n && j<m && (f[i][j]=='.' || f[i][j]=='S' || f[i][j]=='G'));
}

void setdone(int x,int y,int i,int j,int ind){
     
                   while(isvalid(x,y)){
                       done[x][y][ind]=1;
                       x+=i;y+=j;
                   }
}
int main()
{
    freopen("C:\\Users\\VISHU\\Desktop\\output.txt","w",stdout);
    freopen("C:\\Users\\VISHU\\Desktop\\input.txt","r",stdin);
    
    
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {
      
      memset(done,0,sizeof(done));
      ans=0;
      
      scanf("%d %d",&n,&m); 
      for(int i=0;i<n;i++) 
        scanf("%s",&f[i]);
       
      for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
                
                if(f[i][j]=='.') 
                    continue;
                    
                if(f[i][j]=='S'){
                   sx=i;sy=j;
                   continue;
                }
                
                if(f[i][j]=='G'){
                   gx=i;gy=j;
                   continue;
                }
                
                if(f[i][j]=='<'){
                   setdone(i,j-1,0,-1,0);
                   setdone(i-1,j,-1,0,1);
                   setdone(i,j+1,0,1,2);
                   setdone(i+1,j,1,0,3); 
                }else
                if(f[i][j]=='^'){
                   setdone(i-1,j,-1,0,0);
                   setdone(i,j+1,0,1,1);
                   setdone(i+1,j,1,0,2);  
                   setdone(i,j-1,0,-1,3);                               
                }else
                if(f[i][j]=='>'){
                   setdone(i,j+1,0,1,0);
                   setdone(i+1,j,1,0,1);  
                   setdone(i,j-1,0,-1,2); 
                   setdone(i-1,j,-1,0,3);        
                }else
                if(f[i][j]=='v'){
                   setdone(i+1,j,1,0,0);  
                   setdone(i,j-1,0,-1,1); 
                   setdone(i-1,j,-1,0,2); 
                   setdone(i,j+1,0,1,3);             
                }
                
                for(int k=0;k<4;k++)
                  done[i][j][k]=1;
        }
       
       
       queue<int> qx,qy,qt;
       qx.push(sx);qy.push(sy);qt.push(0);
       done[sx][sy][0]=1;
       int x,y,t;
       
       while(!qx.empty()){
              
              x=qx.front();qx.pop();
              y=qy.front();qy.pop();
              t=qt.front();qt.pop();
              
              if(x==gx && y==gy){
                       
                       pans=t;
                       ans=1;
                       break;
              }
              
              for(int i=-1;i<=1;i++) 
                for(int j=-1;j<=1;j++){
                      
                      if((i==0 && j==0) || !(i==0 || j==0) || !isvalid(x+i,y+j))
                         continue;  
                      
                      if(done[x+i][y+j][(t+1)%4]) 
                         continue; 
                      
                      done[x+i][y+j][(t+1)%4]=1;
                      qx.push(x+i);
                      qy.push(y+j);
                      qt.push(t+1);
                }        
       }
       
        
       if(ans) printf("Case #%d: %d\n",kase,pans);  
       else printf("Case #%d: impossible\n",kase);
        
    }
   return 0;
}
