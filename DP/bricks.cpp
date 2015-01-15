/*

// http://acm.timus.ru/problem.aspx?space=1&num=1017

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
int a[1000][1000]={0};
int ans;int n;

int main()
{
    
    
    for(int i=0;i<501;i++)
       a[0][i]=1;
       
    for(int i=1;i<501;i++){
      for(int j=0;j<501;j++){  
           if(i>=j)
             a[i][j]=a[i][j-1]+a[i-j][j-1]; 
           else
             a[i][j]=a[i][j-1];
      }     
    }
    scanf("%d",&n);
    cout<<a[n][500]-1;
    system("pause");
   return 0;
}
