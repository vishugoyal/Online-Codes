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
using namespace std;
int n,k;
int a[10005];
bool pf[10005][101];
bool pb[10005][101];
bool poss;
// http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=977
int mod(int i){
    i=i%k;
    while(i<0)
      i+=k;
    
    return i%k;
}
int main()
{
    
    int t;
    scanf("%d",&t);
    while(t--)
    {
              memset(pf,0,sizeof(pf));
              memset(pb,0,sizeof(pb));
              
              scanf("%d %d",&n,&k);
              
              for(int i=0;i<n;i++)
                 scanf("%d",&a[i]);
              
              pf[0][mod(a[0])]=1;
              
              for(int i=1;i<n;i++)
                 for(int j=0;j<k;j++){
                   
                   if(!pf[i-1][j])continue;
                  
                   pf[i][mod(j-a[i])]=1;
                   pf[i][mod(j+a[i])]=1; 
                        
              }
           
              pb[n][0]=1;
              
              for(int i=n-1;i>0;i--)
                for(int j=0;j<k;j++){
                        if(!pb[i+1][j])continue;
                        
                        pb[i][mod(j-a[i])]=1;
                        pb[i][mod(j+a[i])]=1;
              }
              
            poss=false;
            for(int i=0;i<n &&!poss;i++){
                    for(int j=0;j<k && !poss;j++){
                            if(pf[i][j] && pb[i+1][mod(k-j)])
                              poss=1;
                    }    
            } 
           if(poss)
             printf("Divisible\n");
           else
             printf("Not divisible\n");  
              
    }
   return 0;
}
