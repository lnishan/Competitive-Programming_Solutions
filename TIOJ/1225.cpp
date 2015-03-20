#include <iostream>

using namespace std;

int stk[1000000];

inline int input(){
    char c;
    for( c=getchar(); c<48||c>57; c=getchar() ) ;
    int x=c-48;
    for( c=getchar(); c>47&&c<58; c=getchar() ) x=x*10+c-48;
    return x;
}

int main(){
    int n, a, top=0;
    long long int ans=0;
    stk[0]=2147483647;
    n=input();
    while( n-- )
    {
        a=input();
        while( top>0 )
            if( a<stk[top] )
                break;
            else
            {
                ans+=min(stk[top-1], a);
                top--;
            }
        stk[++top]=a;
    }
    while( top>1 )
        ans+=stk[--top];
    printf("%I64d", ans);
    //while(1);
    return 0;
}