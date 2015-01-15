/*

// http://www.spoj.com/problems/MMAXPER/

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
int a[2005];
int b[2005];
int dp[2005][2];
int n;


int main()
{
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
       scanf("%d %d",&a[i],&b[i]);
       
    dp[0][0]=a[0];dp[0][1]=b[0];
    
    
    for(int i=1;i<n;i++){
       
       dp[i][0]=max(abs(b[i]-b[i-1])+dp[i-1][0],abs(b[i]-a[i-1])+dp[i-1][1])+a[i]; 
       dp[i][1]=max(abs(a[i]-b[i-1])+dp[i-1][0],abs(a[i]-a[i-1])+dp[i-1][1])+b[i];    
           
    }
    printf("%d\n",max(dp[n-1][0],dp[n-1][1]));
   return 0;
}
