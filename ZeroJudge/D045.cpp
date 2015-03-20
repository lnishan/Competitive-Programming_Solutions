#include<iostream>

using namespace std;

int t,qs,q,ponly[10001][3],pc[3],maxc;
bool a[10001][3];

int input(){
    char c;
    for(c=getchar();c<48||c>57;c=getchar());
    int x=c-48;
    for(c=getchar();c>47&&c<58;c=getchar())x=x*10+c-48;
    return x;
}

int main(){
    t=input();
    for(int d=1;d<=t;d++)
    {
        printf("Case #%d:\n",d);
        memset(a,0,sizeof(a));
        memset(pc,0,sizeof(pc));
        for(int i=0;i<3;i++)
        {
            qs=input();
            for(int j=0;j<qs;j++)
            {
                q=input();
                a[q][i]=true;
            }
        }
        for(int i=1;i<=10000;i++)
        {
            if(a[i][0] && (!a[i][1]) && (!a[i][2])) ponly[pc[0]++][0]=i;
            if(a[i][1] && (!a[i][0]) && (!a[i][2])) ponly[pc[1]++][1]=i;
            if(a[i][2] && (!a[i][0]) && (!a[i][1])) ponly[pc[2]++][2]=i;
            maxc=max(pc[0],pc[1]);
            maxc=max(maxc,pc[2]);
        }
        for(int i=0;i<3;i++)
            if(pc[i]==maxc){
                putchar(i+49);
                printf(" %d",maxc);
                for(int j=0;j<maxc;j++)
                    printf(" %d",ponly[j][i]);
                putchar('\n');
            }
    }
    return 0;
}
