#include <stdio.h>

int i,ns,n,a[1000][3];

int input(){
    char c;
    for(c=getchar();c<48||c>57;c=getchar());
    int x=c-48;
    for(c=getchar();c>47&&c<58;c=getchar()) x=x*10+c-48;
    return x;
}

void insert(int ind){
    if(n>a[ind][0]){
        if(a[ind][2]==0){
            a[ind][2]=i;
            a[i][0]=n;
        }else
            insert(a[ind][2]);
    }else if(n<a[ind][0]){
        if(a[ind][1]==0){
            a[ind][1]=i;
            a[i][0]=n;
        }else
            insert(a[ind][1]);
    }
}

void dfs(int ind){
    int i;
    for(i=1;i<=2;i++)
        if(a[ind][i]!=0){
            printf(" %d",a[a[ind][i]][0]);
            dfs(a[ind][i]);
        }
}

int main(){
    while(scanf("%d",&ns)==1)
    {
        memset(a,0,sizeof(a));
        a[0][0]=input();
        for(i=1;i<ns;i++)
        {
            n=input();
            insert(0);
        }
        printf("%d",a[0][0]);
        dfs(0);
        putchar('\n');
    }
    return 0;
}
