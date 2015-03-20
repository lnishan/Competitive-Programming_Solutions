#include<iostream>
using namespace std;
int a[100000],sa[100000],sb[100000],ns,ct=0;
int input(){
    char c;
    while((c=getchar())==' '||c=='\n');
    int x=c-48;
    while((c=getchar())!=' '&&c!='\n')x=x*10+c-48;
    return x;
}
int main(){
    ns=input();
    for(int i=0;i<ns;i++)
    {
            a[i]=input();
            if(i==0)sa[0]=a[i];else sa[i]=a[i]+sa[i-1];
    }
    sb[0]=a[ns-1];
    for(int i=1;i<ns;i++)
            sb[i]=sb[i-1]+a[ns-1-i];
    for(int i=0,j=0;i<ns&&j<ns;)
    {
            if(sa[i]>sb[j])j++;
            else if(sa[i]<sb[j])i++;
            else {ct++;i++;j++;}
    }
    printf("%d",ct);
    return 0;
}
