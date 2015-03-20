#include <iostream>

using namespace std;

int n,cases=0,my[100002],x,y,p[100000][2],pc;

int input(){
    char c;
    for(c=getchar();c<48||c>57;c=getchar());
    int x=c-48;
    for(c=getchar();c>47&&c<58;c=getchar()) x=x*10+c-48;
    return x;
}

int main(){
    int i;
    while(scanf("%d",&n)==1)
    {
        memset(my,-1,sizeof(my));
        pc=0;
        for(i=0;i<n;i++)
        {
            x=input();
            y=input();
            if(y>my[x])
                my[x]=y;
        }
        for(i=100000;i>=0;i--)
            if(my[i]>my[i+1]){
                p[pc][0]=i;
                p[pc++][1]=my[i];
            }else
                my[i]=my[i+1];
        printf("Case %d:\n",++cases);
        printf("Dominate Point: %d\n",pc);
        for(i=pc-1;i>=0;i--)
            printf("(%d,%d)\n",p[i][0],p[i][1]);
    }
    return 0;
}
