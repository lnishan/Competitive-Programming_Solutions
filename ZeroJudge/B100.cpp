#include <iostream>

using namespace std;

bool compare(int a,int b,int c,int d){
    return a*d>b*c;
}

int a,b,p[2][2],m[2],t[2];

int main(){
    while(scanf("%d%d",&a,&b),a>0 && b>0)
    {
        p[0][0]=0; p[0][1]=1;
        p[1][0]=1; p[1][1]=0;
        m[0]=1; m[1]=1;
        while(a!=m[0] || b!=m[1])
        {
            if(compare(p[1][0],p[1][1],a,b) && compare(a,b,m[0],m[1])){
                t[0]=m[0]; t[1]=m[1];
                m[0]+=p[1][0];
                m[1]+=p[1][1];
                p[0][0]=t[0];
                p[0][1]=t[1];
                putchar('R');
            }else{
                t[0]=m[0]; t[1]=m[1];
                m[0]+=p[0][0];
                m[1]+=p[0][1];
                p[1][0]=t[0];
                p[1][1]=t[1];
                putchar('L');
            }
        }
        putchar('\n');
    }
    return 0;
}
