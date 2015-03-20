#include<iostream>
#include<stack>
using namespace std;
int ns,a[1000],ni;
stack<int> stk;
inline int input(){
       char c;
       while((c=getchar())==' '||c=='\n');
       int x=c-48;
       while((c=getchar())!=' '&&c!='\n')x=x*10+c-48;
       return x;
}
int main(){
    while(1)
    {
         ns=input();
         if(ns==0)break;
         while(1)
         {
              a[0]=input();
              if(a[0]==0)break;
              for(int i=1;i<ns;i++)a[i]=input();
              ni=0;
              for(int i=1;i<=ns;i++)
              {
                      stk.push(i);
                      if(stk.top()==a[ni])
                      {
                           do
                           {
                                if(stk.top()==a[ni])
                                {
                                     stk.pop();
                                     ni++;
                                }else break;
                           }while(!stk.empty());
                      }
              }
              if(ni==ns)printf("Yes\n");else printf("No\n");
              while(!stk.empty())stk.pop();
         }
         putchar('\n');
    }
    return 0;
}
