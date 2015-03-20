#include<iostream>
using namespace std;
int input();
int input(){
    char c;int x;
    while((c=getchar())==' '||c=='\n');
    x=c-48;
    while((c=getchar())!=' '&&c!='\n')x=x*10+c-48;
    return x;
}
int main(){
    int n,t;
    while(scanf("%d",&n)!=EOF)
    {
         putchar('1');t=input();
         for(int i=2;i<=n;i++){printf(" %d",i);t=input();}
         putchar('\n');
    }
    return 0;
}
