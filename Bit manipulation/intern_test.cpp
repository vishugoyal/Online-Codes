/*
  calculate the bit mask of a given set of IP addresses.
  
 */
#include<bits/stdc++.h>
using namespace std;
int main() {

    int n;
    cin>>n;
    int a[1001][4];
    
    for(int i=0;i<n;i++)
          scanf("%d.%d.%d.%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
    
       
    int mask=0,k;
    
    int ans[4];
    for(int i=0;i<4;i++)
        ans[i]=0;
    
    for(int i=0;i<4;i++){
      for(int j=7;j>=0;j--){
        k=1;
        int curr= a[0][i]&(1<<j);  
        for(k=1;k<n;k++){
            
            if((a[k][i] & (1<<j)) == curr)
                 continue;
            break;
        }
       
        if(k!=n)break;
        mask++;
        ans[i]|=curr;
    }
    
        if(k!=n) break;
    } 
   
   printf("%d.%d.%d.%d/%d\n",ans[0],ans[1],ans[2],ans[3],mask);
   return 0;
}
