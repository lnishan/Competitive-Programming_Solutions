#include<iostream>
using namespace std;
int input(){
    char c;
    for(c=getchar();c<48||c>57;c=getchar());
    int x=c-48;
    for(c=getchar();c>47&&c<58;c=getchar())x=x*10+c-48;
    return x;
}
void printNumber(int n){
    if(n==0) putchar(48);
    else{
        int a[3],c=0;
        while(n>0)
        {
            a[c++]=n%10;
            n/=10;
        }
        for(int i=c-1;i>=0;i--) putchar(a[i]+48);
    }
}
int main(){
    int n,a[100],pos;
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++) a[i]=input();
        bool dir=true;int tpos=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=tpos;j<=i+tpos;j++)
            {
                if(dir)pos=j;else pos=n-1-j;
                if(j!=tpos)putchar(' ');
                printNumber(a[pos]);
            }
            putchar('\n');
            if(dir)dir=false;else{ dir=true; tpos++; }
        }
    }
    return 0;
}
