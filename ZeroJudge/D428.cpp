#include<iostream>
#include<ctype.h>
using namespace std;
int main(){
    char c;
    unsigned int x;
    do
    {
         while(!isdigit(c=getchar())&&c!='\n');
         if(c=='\n')break;else x=c-48;
         while(isdigit(c=getchar()))x=x*10+c-48;
         printf("%d\n",x);
    }while(c!='\n');
    return 0;
}
