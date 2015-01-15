/*

// http://www.spoj.com/problems/PARTPALI/

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
long long m;int s,t;
long long po[20];
long long a[1001][20];
long long b[1001][20];

int main()
{
    
    po[0]=1;
    for(int i=1;i<20;i++)
      po[i]=10*po[i-1];
        
    scanf("%d",&t);
    while(t--)
    {
       scanf("%lld %d",&m,&s);
       
       memset(a,0,sizeof(a));
       memset(b,0,sizeof(b));
       
       int p,i=0,lim;
           
       
       if(s%2==0){
             p=1;lim=s/2-1; 
             for(;i<lim;i++,p+=2) 
                for(long long j=0;j<=9;j++)
                   if(p!=0)a[(((j*po[p]+j)%m)*po[lim-i])%m][i]++;
                    else a[(((j)%m)*po[lim-i])%m][i]++;
                      
       }else{
            p=0;lim=s/2;
            for(;i<lim;i++,p+=2) 
             for(long long j=0;j<=9;j++)
               if(p!=0)a[(((j*po[p]+j)%m)*po[lim-i])%m][i]++;
               else a[(((j)%m)*po[lim-i])%m][i]++;   
       }
       for(long long j=1;j<=9;j++)
               if(p!=0)a[(j*po[p]+j)%m][i]++;
                else a[(j)%m][i]++; 
                
       for(int u=0;u<m;u++)
          b[u][0]=a[u][0];
       
       for(int j=1;j<=i;j++)
               for(int u=0;u<m;u++)
                 for(int v=0;v<m;v++)
                    { b[(u+v)%m][j]+=a[u][j]*b[v][j-1];}
                     //cout<<u <<" "<<v<<" "<<(u+v)%m<<" "<<b[(u+v)%m][j]<<" "<<a[u][j]<<" "<<b[v][j-1]<<endl;system("pause");}
               
       
       printf("%lld\n",b[0][i]); 
              
    }
   return 0;
}
