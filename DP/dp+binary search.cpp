/*

// http://www.spoj.com/problems/RENT/

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

struct plane{
       public:
       int s,e;long long p;
       
       bool operator<(const plane& x) const{
            
            if(s<x.s)
               return 1;
             if(s>x.s)
                return 0;
             if(e<x.e)
                return 1;
             if(e>x.e)
                return 0;
             
             return p<x.p;
       }
};
plane a[10001];
long long profit[10001];
int n;
int binarysearch(int start,int i,int j){
   
    
    if(i>j)return -1;
    if(i==j) if (a[i].s>start) return i; else return -1;
    if(i==j-1){
               if(a[i].s>start)
                  return i;
               if(a[j].s>start)
                  return j;
               return -1;
    }
   
    int m=(i+j)/2;
    
    if(a[m].s>start)
      return binarysearch(start,i,m);
      
    return binarysearch(start,m+1,j);
}
int main()
{
    //freopen("C:\\Users\\VISHU\\Desktop\\output.txt","w",stdout);
    //freopen("C:\\Users\\VISHU\\Desktop\\input.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)  
          {scanf("%d %d %lld",&a[i].s,&a[i].e,&a[i].p);a[i].e=a[i].e+a[i].s;} 
         
        sort(a,a+n);
        
        profit[n-1]=a[n-1].p;
        for(int i=n-2;i>=0;i--){
                
                int x=binarysearch(a[i].e,i+1,n-1);
                
                if(x==-1)
                   profit[i]=a[i].p;
                else
                   profit[i]=a[i].p+profit[x];
                  
                profit[i]=max(profit[i],profit[i+1]);
                
        }
        
             
    
        printf("%lld\n",profit[0]);
    }
   return 0;
}
