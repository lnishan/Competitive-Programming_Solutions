#include <stdio.h>

char a[1000001];

int input(){
    char c;
    for(c=getchar();c<48||c>57;c=getchar()) ;
    int x=c-48;
    for(c=getchar();c>47&&c<58;c=getchar()) x=x*10+c-48;
    return x;
}

int main(){
    int i,j,n;
    for(i=4;i<1000001;i+=2) a[i]=0;
    for(i=3;i<1000001;i+=2) a[i]=1;
    a[1]=0; a[2]=1;
    for(i=3;i<1000;i+=2)
        if(a[i])
            for(j=i*i;j<1000001;j+=2*i)
                a[j]=0;
    while(n=input(),n>0)
        if(a[n]==1) puts("0");
        else puts("1");
    return 0;
}
