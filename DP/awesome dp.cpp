/*

// http://www.spoj.com/problems/POWERCAR/

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
int n,b;
char p[1001];
int o[1001][1001];
int s[1001][1001];

int main()
{
    
    int t;
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d %d",&n,&b);
              scanf("%s",&p);
              
              for(int i=0;i<=b;i++){
                o[0][i]=0;s[0][i]=2;
              }
              
              for(int i=1;i<n;i++)
                for(int j=0;j<=b;j++){
                        if(p[i]=='#'){
                         
                          if(j==0){o[i][j]=1000000;s[i][j]=s[i-1][j]+2;continue;}
                          
                          o[i][j]=min(o[i][j-1],o[i-1][j-1]+1);
                          if(p[i-1]!='#')o[i][j]=min(o[i][j],s[i-1][j-1]+3);
                          
                          s[i][j]=min(s[i][j-1],min(o[i][j]+2,s[i-1][j]+2));
                          continue;
                        }
                        
                        o[i][j]=min((j==0?1000000:o[i][j-1]),min(o[i-1][j]+1,s[i-1][j]+4));
                        if(p[i-1]!='#')o[i][j]=min(o[i][j],s[i-1][j]+3);
                        
                        s[i][j]=min((j==0?1000000:s[i][j-1]),min(o[i][j]+2,s[i-1][j]+2));
                }
              
                         
              printf("%d\n",min(o[n-1][b],s[n-1][b]+2));
              
    }
   return 0;
}
