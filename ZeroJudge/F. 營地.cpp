#include <iostream>

using namespace std;

short a[5000][5000];
int r,c,d,maxside;

inline int inputD(){
    char c;
    for(c=getchar();c<48||c>57;c=getchar()) ;
    return c-48;
}

inline int inputRC(){
    char c;
    for(c=getchar();c<48||c>57;c=getchar()) ;
    int x=c-48;
    for(c=getchar();c>47&&c<58;c=getchar()) x=x*10+c-48;
    return x;
}

int min(short a,short b,short c){
    if(a<=b && a<=c)
        return a;
    else if(b<=a && b<=c)
        return b;
    else
        return c;
}

int main(){
    int i,j;
    freopen("pf.in","r",stdin);
    freopen("pf.out","w",stdout);
    while(r=inputRC(),c=inputRC(),r!=0 || c!=0)
    {
        maxside=-1;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                d=inputD();
                if(i==0 || j==0)
                    a[i][j]=d<2;
                else if(d<2)
                    a[i][j]=min(a[i-1][j-1],a[i-1][j],a[i][j-1])+1;
                else
                    a[i][j]=0;
                if(a[i][j]>maxside) maxside=a[i][j];
            }
        printf("%d\n",maxside*maxside);
    }
    return 0;
}
