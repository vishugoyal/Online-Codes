/*

// http://www.spoj.com/problems/RPLB/

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
int a[10000];
int b[1001][1001];
int n,k,maxi;

int main()
{
    //freopen("C:\\Users\\VISHU\\Desktop\\output.txt","w",stdout);
    //freopen("C:\\Users\\VISHU\\Desktop\\input.in","r",stdin);
    int t;
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {   int ans=0;
    
        scanf("%d %d",&n,&k);
        
        for(int i=0;i<n;i++)
          scanf("%d",&a[i]);
          
         
        for(int i=0;i<=k;i++)
         if(a[n-1]<=i)b[n-1][i]=a[n-1];
          else b[n-1][i]=0;
         ans=max(ans,b[n-1][k]);
         
          
        
        for(int i=n-2;i>=0;i--){
                b[i][0]=0;
                for(int j=1;j<=k;j++){
                        b[i][j]=max(b[i+1][j],b[i][j-1]);
                        if(j>=a[i]) b[i][j]=max(b[i][j],a[i]+(i+2<n?b[i+2][j-a[i]]:0));
                }
               ans=max(ans,b[i][k]);  
        }
       
        printf("Scenario #%d: %d\n",kase,ans);      
    }
   return 0;
}
