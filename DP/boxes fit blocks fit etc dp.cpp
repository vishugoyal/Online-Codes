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
int a[101][101];
int ans=0;
int x,y;

int main()
{
    
    int n;
    scanf("%d",&n);
    while(n!=0)
    {
       memset(a,0,sizeof(a));
       
       for(int i=0;i<n;i++){
         scanf("%d %d",&x,&y);
         a[x][y]++;
       }  
       
       for(int i=99;i>=0;i--){
               a[i][100]+=a[i+1][100];
               a[100][i]+=a[100][i+1];
       }
       for(int i=99;i>=0;i--)  
         for(int j=99;j>=0;j--)
           a[i][j]+=max(a[i+1][j],max(a[i][j+1],a[i+1][j+1]));
       
       printf("%d\n",a[0][0]);
       scanf("%d",&n);
    }
   return 0;
}
