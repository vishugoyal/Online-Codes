/*

// http://www.spoj.com/problems/HOTELS/

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
int n;
long long m;
long long ans=0;
long long a[300005];

int main()
{
    
   
    scanf("%d %lld",&n,&m);
    
    for(int i=1;i<=n;i++)
      scanf("%lld",&a[i]);
    
    a[0]=0;
    for(int i=1;i<=n;i++) 
       a[i]+=a[i-1];
    
    int u=n,l=n;
    
    while(u>=0 && l>=0){
              
               if(a[u]-a[l]>m)u--;
               else if(a[u]-a[l]==m){ans=m;break;}
               else {
                    ans=max(ans,a[u]-a[l]);
                    l--;
                    }
    }
    cout<<ans<<endl;
   return 0;
}
