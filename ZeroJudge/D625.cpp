#include<iostream>
using namespace std;
int n,x,y,bpos[10000][2],bc=0,a[105][105],tx[]={1,1,1,0,0,-1,-1,-1},ty[]={1,0,-1,1,-1,1,0,-1};
int main(){
    scanf("%d",&n);
    char c=getchar();
    for(int i=1;i<=n;i++)
    {
            for(int j=1;j<=n;j++)
            {
                    c=getchar();
                    if(c=='-')a[i][j]=48;
                    else{
                        a[i][j]=c;
                        bpos[bc++][0]=i;
                        bpos[bc-1][1]=j;
                    }
            }
            c=getchar();
    }
    for(int i=0;i<bc;i++)
            for(int j=0;j<8;j++)
            {
                    x=bpos[i][0]+tx[j];
                    y=bpos[i][1]+ty[j];
                    if(a[x][y]!='*')a[x][y]++;
            }
    for(int i=1;i<=n;i++)
    {
            for(int j=1;j<=n;j++)
            {
                    if(a[i][j]==48)putchar('-');
                    else putchar(a[i][j]);
            }
            putchar('\n');
    }
    return 0;
}
