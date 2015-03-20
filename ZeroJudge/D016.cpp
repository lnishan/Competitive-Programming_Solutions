#include<iostream>
#include<cstring>
#include<math.h>
#include<stack>
using namespace std;
int main(){
    int a,b;
    stack<int> stk;
    char ch[10000];
    char *ptr;
    while(gets(ch))
    {
         ptr=strtok(ch," ");
         while(ptr!=NULL)
         {
              if(isdigit(*ptr))
                   stk.push(atoi(ptr));
              else
              {
                   a=stk.top();
                   stk.pop();
                   b=stk.top();
                   stk.pop();
                   if(*ptr=='+')
                        stk.push(a+b);
                   else if(*ptr=='-')
                        stk.push(b-a);
                   else if(*ptr=='*')
                        stk.push(a*b);
                   else if(*ptr=='/')
                        stk.push(b/a);
                   else
                        stk.push(b%a);
              }
              ptr=strtok(NULL," ");
         }
         printf("%d\n",stk.top());
    }
    return 0;
}
