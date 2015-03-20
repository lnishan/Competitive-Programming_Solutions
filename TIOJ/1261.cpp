#include <iostream>

using namespace std;

// 1 patted 0 unpatted
char v[20];
int m[1048576], a[20], n;

int getInd(){
    int i, a=0;
    for( i=0; i<20; i++ )
        a+=v[i]*(1<<i);
    return a;
}
int getT(int T, int f){
    if( T%f==0 )
        return T/f*f;
    else
        return T/f*f+f;
}
void DFS(int pos, int T){
    int i, tmp, ind;
    for( i=0; i<n; i++ )
        if( !v[i] )
        {
            tmp=getT(T+abs(pos-(i+1)), a[i]);
            v[i]=1; ind=getInd();
            if( tmp<m[ind] )
            {
                m[ind]=tmp;
                DFS(i+1, tmp);
            }
            v[i]=0;
        }
    return ;
}

int main(){
    int i, tmp=0;
    memset(v, 0, sizeof(v));
    scanf("%d", &n);
    for( i=0; i<n; i++ ) tmp+=(1<<i);
    for( i=0; i<=tmp; i++ ) m[i]=2147483647;
    for( i=0; i<n; i++ )
        scanf("%d", &a[i]);
    DFS(0, 0);
    printf("%d", m[tmp]);
    //while(1);
    return 0;
}