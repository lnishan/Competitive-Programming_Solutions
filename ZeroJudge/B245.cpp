#include<iostream>
using namespace std;
int ds,ns,n,prevn,maxb,maxi;
int input(){
    char c;int x;
    while((c=getchar())==' '||c=='\n');
    x=c-48;
    while((c=getchar())!=' '&&c!='\n')x=x*10+c-48;
    return x;
}
int main(){
    ds=input();
    for(int i=0;i<ds;i++)
    {
            ns=input();
            prevn=input();
            maxb=0;
            for(int i=1;i<ns;i++)
            {
                    n=input();
                    if(n-prevn>maxb){maxb=n-prevn;maxi=i;}
                    prevn=n;
            }
            printf("%d\n",maxi);
    }
    return 0;
}
