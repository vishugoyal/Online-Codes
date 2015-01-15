/*

// http://www.spoj.com/problems/ANARC09A/

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

string s;
int l,op,cl,ans;
stack<char> st;
int kase=0;
int main()
{
    
    cin>>s;
    while(s[0]!='-'){
      ++kase;               
     l=s.length();
     st.push(s[0]);               
     for(int i=1;i<l;i++){
             if(s[i]=='}' && (!st.empty() && st.top()=='{')) st.pop();
             else st.push(s[i]); }
             
     op=0,cl=0;
     while(!st.empty() && st.top()=='{'){
       op++;st.pop();
     }
     
     while( !st.empty() && st.top()=='}' ){
       cl++;st.pop();
     }
    ans=op/2+cl/2;
    if(op%2==1)
      ans+=2;
      printf("%d. %d\n",kase,ans);
    cin>>s;                
    }
   return 0;
}
