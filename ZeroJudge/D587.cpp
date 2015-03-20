#include<iostream>
using namespace std;
int input(){
    char c;
    while((c=getchar())==' '||c=='\n');
    int x=c-48;
    while((c=getchar())!=' '&&c!='\n')x=x*10+c-48;
    return x;
}
int main(){
    int ns=input(),c1=0,c2=0,c3=0,n;
    for(int i=0;i<ns;i++)
    {
            n=input();
            if(n==1)c1++;
            else if(n==2)c2++;
            else c3++;
    }
    for(int i=0;i<c1;i++){putchar(49);putchar(' ');}
    for(int i=0;i<c2;i++){putchar(50);putchar(' ');}
    for(int i=0;i<c3;i++){putchar(51);putchar(' ');}
    return 0;
}
