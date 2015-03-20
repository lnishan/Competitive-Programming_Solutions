#include <iostream>

using namespace std;

struct node{ long long int x, y; } a[100000], b[100000];
long long int sx, sy;

long long int cross(long long int x1, long long int y1, long long int x2, long long int y2){ return (x1*y2-y1*x2); }
long long int Abs(long long int n){ return (n<0)?-n:n; }
bool cmp(node a, node b){
    long long int r=cross(a.x-sx, a.y-sy, b.x-sx, b.y-sy);
    if( r!=0 )
        return r>0;
    else
        return a.x-sx+Abs(a.y-sy)<b.x-sx+Abs(b.y-sy);
}

int main(){
    int i, j, n, bc;
    sx=sy=2147483647; bc=2;
    scanf("%d", &n);
    for( i=0; i<n; i++ )
    {
        scanf("%I64d%I64d", &a[i].x, &a[i].y);
        if( (a[i].x<sx)||(a[i].x==sx && a[i].y<sy) )
            sx=a[i].x, sy=a[i].y;
    }
    sort(a, a+n, cmp);
    b[0].x=a[0].x; b[0].y=a[0].y;
    b[1].x=a[1].x; b[1].y=a[1].y;
    for( i=2; i<n; i++ )
        if( cross(a[i].x-b[0].x, a[i].y-b[0].y, b[1].x-b[0].x, b[1].y-b[0].y)==0 )
            b[1].x=a[i].x, b[1].y=a[i].y;
        else
            break;
    for( ; i<n; i++ )
    {
        if( cross(b[bc-1].x-b[bc-2].x, b[bc-1].y-b[bc-2].y, a[i].x-b[bc-1].x, a[i].y-b[bc-1].y)>0 )
        {
            b[bc  ].x=a[i].x; b[bc++].y=a[i].y;
            for( j=i+1; j<=n; j++ )
                if( cross(b[bc-1].x-b[bc-2].x, b[bc-1].y-b[bc-2].y, a[j%n].x-b[bc-2].x, a[j%n].y-b[bc-2].y)==0 )
                    b[bc-1].x=a[j%n].x, b[bc-1].y=a[j%n].y;
                else
                    break;
            i=j-1;
        }
        else
        {
            for( j=bc-1; j>0; j-- )
                if( cross(b[j].x-b[j-1].x, b[j].y-b[j-1].y, a[i].x-b[j].x, a[i].y-b[j].y)<=0 )
                    bc--;
                else
                    break;
            b[bc  ].x=a[i].x; b[bc++].y=a[i].y;
        }
    }
    if( b[0].x==b[bc-1].x && b[0].y==b[bc-1].y && bc>1 ) bc--;
    if( bc<3 )
        putchar('0');
    else
        printf("%d", bc);
    //while(1);
    return 0;
}