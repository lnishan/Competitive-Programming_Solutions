#include<iostream>
using namespace std;
int input();
int d[1000000];
int input(){
    int x;char c;
    while((c=getchar())==' '||c=='\n');
    x=c-48;
    while((c=getchar())!=' '&&c!='\n')x=x*10+c-48;
    return x;
}
int main(){
    int n=input(),m,a,b;
    for(int i=0;i<n;i++)
    {
            m=input();
            for(int j=0;j<m;j++)
            {
                    a=input();b=input();
                    d[j]=a+b;
            }
            for(int j=m-1;j>=0;j--)if(d[j]>9){d[j]-=10;d[j-1]+=1;}
            for(int j=0;j<m;j++)printf("%d",d[j]);
            printf("\n");
    }
    return 0;
}
