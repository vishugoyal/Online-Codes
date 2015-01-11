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

int main()
{
    freopen("C:\\Users\\VISHU\\Desktop\\output.txt","w",stdout);
    freopen("C:\\Users\\VISHU\\Desktop\\input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    
    char s[10],x[10],y[10],ec;
    int l,j,i;
    int curr;
    for(int kase=1;kase<=t;kase++){
            
       cin>>s;
       l=strlen(s);
       for(i=0;i<l;i++)
          x[i]=y[i]=s[i];
        
      for(i=0;i<l-1 ;i++){
         curr=-1;
         for(j=i+1;j<l;j++){
            
            if(x[j]>x[i]){
                if(curr==-1)
                  curr=j;
                else if(x[curr]<=x[j])
                   curr=j;
            }                
         }
         
         if(curr!=-1){
             ec=x[i];
             x[i]=x[curr];
             x[curr]=ec;
             break;
         }
         
       }
       
      
       
       for(i=0;i<l-1 ;i++){
         curr=-1;
         for(j=i+1;j<l;j++){
                       
            if(i==0 && y[j]=='0') 
              continue;
            
            if(y[j]<y[i]){
                if(curr==-1)
                  curr=j;
                else if(y[curr]>=y[j])
                   curr=j;
            }                
         }
         
         if(curr!=-1){
             ec=y[i];
             y[i]=y[curr];
             y[curr]=ec;
             break;
         }
         
       } 
       printf("Case #%d: ",kase); 
       
       for(i=0;i<l;i++)  
         printf("%c",y[i]);
       printf(" ");
       for(i=0;i<l;i++)  
         printf("%c",x[i]);
       printf("\n");
         
            
    }
   return 0;
}
