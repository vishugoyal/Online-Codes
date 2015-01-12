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

class nutrient{
      public:
      int n[3];
};
      
bool isequal(nutrient req, nutrient given){
     for(int i=0;i<3;i++)
       if(req.n[i]!=given.n[i])
          return 0;
     return 1;
}

int main()
{
    freopen("C:\\Users\\VISHU\\Desktop\\output.txt","w",stdout);
    freopen("C:\\Users\\VISHU\\Desktop\\input.txt","r",stdin);
    int t,k;
    nutrient a[21],req,ex;
    bool poss;
    
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {
      for(int i=0;i<3;i++) 
          scanf("%d",&req.n[i]);
      scanf("%d",&k);   
      for(int j=0;j<k;j++)   
        for(int i=0;i<3;i++) 
          scanf("%d",&a[j].n[i]);
      
      
      
      queue<nutrient> q,q1;
      
      for(int i=0;i<3;i++)
         ex.n[i]=0;
      
      q.push(ex);
      poss=false;
      if(isequal(req,ex))poss=1;
      
      for(int j=0;j<k ;j++){
              while(!q.empty()){
                      
                      ex=q.front();q.pop();
                      q1.push(ex);
                      
                      /*for(int i=0;i<3;i++)
                        cout<<" "<<ex.n[i]<<" "; 
                     cout<<endl;*/
                     
                      for(int i=0;i<3;i++)
                        ex.n[i]+=a[j].n[i];
                      q1.push(ex); 
                      
                      if(isequal(req,ex)){
                          poss=1;
                          break;
                      } 
                       
                     /*for(int i=0;i<3;i++)
                        cout<<" "<<ex.n[i]<<" "; 
                     cout<<endl;  */     
              }
              
              if(poss) break;
              
              while(!q1.empty()){
                       q.push(q1.front());
                       q1.pop();
              }
      }
      
       if(poss)
          printf("Case #%d: yes\n",kase);
       else
          printf("Case #%d: no\n",kase);
       
    }
   return 0;
}
