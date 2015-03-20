#include <iostream>

using namespace std;

int ch[91];
struct node{
    int n;
    char c;
};

bool cmp(node a, node b){
    if( a.n!=b.n )
        return a.n>b.n;
    else
        return ch[a.c]>ch[b.c];
}

int main(){
    int i, n, m;
    node a[52];
    ch['S']=4; ch['H']=3; ch['D']=2; ch['C']=1;
    scanf("%d", &n);
    for( i=0; i<n; i++ )
        cin>>a[i].c>>a[i].n;
    sort(a, a+n, cmp);
    scanf("%d", &m);
    printf("%c %d", a[m-1].c, a[m-1].n);
    //while(1);
    return 0;
}