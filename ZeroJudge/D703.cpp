#include <iostream>

using namespace std;

int s,l,a[20];

void dfs(int ind,int rm){
    int i;
    if(rm>0)
        for(i=ind;i<=s+l-rm;i++)
        {
            a[i]='S';
            dfs(i+1,rm-1);
            a[i]='L';
        }
    else{
        for(i=0;i<s+l;i++)
            putchar(a[i]);
        putchar('\n');
    }
}

int main(){
    int i;
    for(i=0;i<20;i++) a[i]='L';
    while(scanf("%d%d",&s,&l)==2)
    {
        dfs(0,s);
        putchar('\n');
    }
    return 0;
}