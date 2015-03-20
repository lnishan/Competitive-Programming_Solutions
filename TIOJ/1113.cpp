#include <iostream>

using namespace std;

int l, a[10], ad[10];
void DFS(int c){
    int i, t;
    if( c>l )
    {
        for( i=0; i<l; i++ )
            putchar(ad[i]);
        putchar('\n');
        return ;
    }
    for( i=0; i<l; i++ )
        if( a[i]>0 )
        {
            ad[c-1]=a[i];
            t=a[i];
            a[i]=0;
            DFS(c+1);
            a[i]=t;
        }
    return ;
}

int main(){
    char s[10];
    int i, d=0;
    while( gets(s) )
    {
        ++d;
        if( d>1 ) putchar('\n');
        l=strlen(s);
        for( i=0; i<l; i++ )
            a[i]=s[i];
        sort(a, a+l);
        DFS(1);
    }
    return 0;
}