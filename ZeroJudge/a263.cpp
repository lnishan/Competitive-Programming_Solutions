#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>

using namespace std;

int y[10000], m[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool lunar( int i ){
    return (i%4==0&&i%100!=0) || (i%400==0);
}

int cdays(int yr, int mt, int dy){
    int i, d;
    if( yr>0 )
        d=y[yr-1];
    else
        d=0;
    if( lunar(yr) )
        m[2]=29;
    else
        m[2]=28;
    for( i=1; i<mt; i++ )
        d+=m[i];
    d+=dy;
    return d;
}

int main(){
    int i, a, b, c, d, e, f;
    for( i=0; i<10000; i++ )
        if( lunar(i) )
            y[i]=y[i-1]+366;
        else
            y[i]=y[i-1]+365;
    while( scanf("%d%d%d", &a, &b, &c)==3 )
    {
        scanf("%d%d%d", &d, &e, &f);
        printf("%d\n", abs(cdays(a, b, c)-cdays(d, e, f)));
    }
    return 0;
}
