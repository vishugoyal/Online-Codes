/*

// http://www.spoj.com/problems/CPCRC1C/

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
long long a,b;
long long ds[10];
long long po[10];
long long nine[10];
long long sum(long long n){
     
     long long no=n;
     if(no==0) return 0;
     vector<long long> x;
     while(no>0){
                 x.pb(no%10);
                 no/=10;       
     }
     long long ans=0;
     int i=x.size()-1;
     ans+=po[i]*(x[i]>0?ds[x[i]-1]:0);
     ans+=x[i]*sum(nine[i]);
     ans+=x[i]*(n%po[i]+1);
     ans+=sum(n%po[i]);
            
           
     
     
     return ans;
}

int main()
{
    ds[0]=0;po[0]=1;nine[0]=0;
    for(int i=1;i<10;i++){
      ds[i]=i+ds[i-1];
      po[i]=10*po[i-1];
      nine[i]=nine[i-1]*10+9;
     }  
    
      
    scanf("%lld %lld",&a,&b);
    while(a!=-1){
        a--;
        printf("%lld\n",sum(b)-sum(a));       
        scanf("%lld %lld",&a,&b);
    }
   return 0;
}
