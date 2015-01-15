/*

minimum number of characters to be removed to make palindrome

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
int l;
char s[5001];
int a[5001];
int b[5001];

int main()
{
    
    int t;
    scanf("%d",&l);
    
               
         scanf("%s",&s);
         
          
         for(int i=0;i<l;i++)
           b[0]=0;
           b[0]=1;
          for(int j=1;j<l;j++) {
          for(int i=j;i>=0;i--){
                  if(i==j) {a[i]=1;}
                  else
                  if(s[i]==s[j])
                        a[i]=2+b[i+1];
                  else
                        a[i]=max(a[i+1],b[i]);   
                  
        }
        for(int i=0;i<=j;i++)
          b[i]=a[i];
        }         
        printf("%d\n",l-a[0]);   
                
    
   return 0;
}
