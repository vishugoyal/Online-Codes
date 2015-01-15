/*

// https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=816

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
int n,m;
long long a[1005][1005];
char x,c;

long long maximumrect(int k){
    
    stack<long long> val;
    stack<int> index;
    
    long long mul;
    long long ambi=0;
    long long tempv;
    
    for(int i=0;i<m;i++){       
       while(!val.empty() && val.top()>a[k][i]) {
             index.pop();
             tempv=val.top();val.pop();
             
             mul=i-(index.empty()?0:index.top()+1);
             ambi=max(ambi,tempv*mul);
        } 
       
       val.push(a[k][i]);
       index.push(i);
        
    }
    
    while(!val.empty()){
       index.pop();
       tempv=val.top();val.pop();
       mul=m-(index.empty()?0:index.top()+1);
       ambi=max(ambi,tempv*mul);                  
    }
    
    return ambi;
}
int main()
{
    
    int t;
    long long ans;
    scanf("%d",&t);
    while(t--)
    {  ans=0;
       scanf("\n%d %d\n",&n,&m);
       
       for(int i=0;i<n;i++) 
         for(int j=0;j<m;j++){
            scanf("%c",&c);
            if(c=='R')  a[i][j]=0;
            else if(c=='F')a[i][j]=1; 
            else {j--;continue;}  
       }
      
       for(int i=1;i<n;i++)
          for(int j=0;j<m;j++)
            if(a[i][j]==1)a[i][j]=1+a[i-1][j];
            else a[i][j]=0;
       
       for(int i=0;i<n;i++)
           ans=max(ans,maximumrect(i));
          
       printf("%lld\n",3*ans);
       //scanf("%c",&c);   
          
    }
   return 0;
}
