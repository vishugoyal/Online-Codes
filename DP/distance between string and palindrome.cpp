/*

// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1680

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
string s;int l;

int a[1001][1001];
int main()
{
    
    int t;
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {
        cin>>s;
        l=s.length();
        
        memset(a,0,sizeof(a));
        
        for(int j=0;j<l;j++)
          for(int i=j;i>=0;i--){
               
               if(i==j){a[i][j]=0;continue;}  
              
               if(s[i]==s[j])
                  a[i][j]=a[i+1][j-1];
               else
                  a[i][j]=1+min(a[i+1][j-1],min(a[i+1][j],a[i][j-1]));
                  
        }
        /*for(int j=0;j<l;j++){
          for(int i=0;i<l;i++)
             cout<<a[i][j]<<" ";
          cout<<endl;        
        }*/
        printf("Case %d: %d\n",kase,a[0][l-1]);
              
    }
   return 0;
}
