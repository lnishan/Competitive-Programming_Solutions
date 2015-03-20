#include <stdio.h>
#include <cstring>

char pre[27], mid[27];
int pos[91], len, curI;
struct node{
    int a[2];   // 0 left 1 right
} tree[27];     // 26 used as 0's parent

void BuildTree(int m, int p, int st, int ed){
    int t=curI;
    if( ed-st<0 )
        return ;
    if( st<=pos[pre[curI]] && pos[pre[curI]]<=ed ){
        tree[p].a[m]=curI++;
        BuildTree(0, t, st, pos[pre[t]]-1);
        BuildTree(1, t, pos[pre[t]]+1, ed);
    }
}

void PrintTree(int root){
    if( tree[root].a[0]>=0 ) PrintTree(tree[root].a[0]);
    if( tree[root].a[1]>=0 ) PrintTree(tree[root].a[1]);
    putchar(pre[root]);
}

int main(){
    int i;
    while( scanf("%s %s", &pre, &mid)==2 )
    {
        len=strlen(pre);
        for(i=0; i<len; i++)
        {
            tree[i].a[0]=tree[i].a[1]=-1;
            pos[mid[i]]=i;
        }
        curI=0;
        BuildTree(0, 26, 0, len-1);
        PrintTree(0);
        putchar('\n');
    }
    return 0;
}