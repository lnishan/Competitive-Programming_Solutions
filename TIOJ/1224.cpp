/* 2/18/2011 */
#include <cstdio>
#include <algorithm>

using namespace std;

int seg[2000000][6], segc=0;  // 0-value 1-LBound 2-UBound 3-left 4-right 5-add
int shx[1000001], xc=0;
long long int x[200000];
struct inputdata{ int l, r, d, u; } s[100000], e[100000];
bool cmp1(inputdata a, inputdata b){ return a.l<b.l; }
bool cmp2(inputdata a, inputdata b){ return a.r<b.r; }
inline int input(){
    char c;
    for( c=getchar(); c<48||c>57; c=getchar() ) ;
    int x=c-48;
    for( c=getchar(); c>47&&c<58; c=getchar() ) x=x*10+c-48;
    return x;
}

int BuildSeg(int lb, int ub){
    int mid=(lb+ub-1)/2, t=segc;
    seg[t][5]=0;
    seg[t][1]=lb; seg[t][2]=ub;
    if( ub-lb==0 ){ seg[t][0]=0; ++segc; return seg[t][0]; }
    seg[t][3]=++segc;
    seg[t][0]=BuildSeg(lb, mid);
    seg[t][4]=segc;
    seg[t][0]+=BuildSeg(mid+1, ub);
    return seg[t][0];
}

void upValue(int i, int lb, int ub, int n){
    int mid=(seg[i][1]+seg[i][2]-1)/2, l=seg[i][3], r=seg[i][4];
    if( seg[i][1]>=lb && seg[i][2]<=ub ){ seg[i][5]+=n; return ; }
    if( lb<=mid )
        upValue(l, lb, ub, n);
    if( ub>mid )
        upValue(r, lb, ub, n);
    seg[i][0]=((seg[l][5])?seg[l][2]-seg[l][1]+1:seg[l][0]) + ((seg[r][5])?seg[r][2]-seg[r][1]+1:seg[r][0]);
}

int main(){
    int i, i1=0, i2=0, n, l, r, d, u, miny=1000000, maxy=0;
    long long int ans=0;
    n=input();
    for( i=0; i<n; i++ )
    {
        e[i].l=input(); e[i].r=input(); e[i].d=input(); e[i].u=input();
        shx[e[i].l]=shx[e[i].r]=1;
        miny=min(miny, e[i].d);
        maxy=max(maxy, e[i].u);
    }
    for( i=0; i<=1000000; i++ )
        if( shx[i] ) x[xc++]=i;
    sort(e, e+n, cmp1);
    for( i=0; i<n; i++ ) s[i]=e[i];
    sort(e, e+n, cmp2);
    BuildSeg(miny, maxy);
    for( i=0; i<xc-1; i++ )
    {
        while( i2<n && e[i2].r<=x[i] )
        {
            upValue(0, e[i2].d+1, e[i2].u, -1);
            i2++;
        }
        while( i1<n && s[i1].l==x[i] )
        {
            upValue(0, s[i1].d+1, s[i1].u, 1);
            i1++;
        }
        ans+=(x[i+1]-x[i])*((seg[0][5])?seg[0][2]-seg[0][1]+1:seg[0][0]);
    }
    printf("%lld\n", ans);
    //while(1);
    return 0;
}
