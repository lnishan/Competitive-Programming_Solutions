#include <iostream>

using namespace std;

struct road{
    short s,e,val;
} r[1000000];
int ns, rs, father[10001];

bool cmp(road a, road b){
    return a.val < b.val;
}

int FindFather(int ind){
    if( father[father[ind]]==father[ind] )
        return father[ind];
    else
        father[ind]=FindFather(father[ind]);
}

int Kruskal(){
    int i, f1, f2, mincost=0;
    for(i=1; i<=ns; i++)
        father[i]=i;
    sort(r, r+rs, cmp);
    for(i=0; i<rs; i++)
    {
        f1=FindFather(r[i].s);
        f2=FindFather(r[i].e);
        if( f1!=f2 ){
            father[f1]=f2;
            mincost+=r[i].val;
        }
    }
    father[1]=FindFather(1);
    for(i=2; i<=ns; i++)
    {
        father[i]=FindFather(i);
        if( father[i]!=father[i-1] ){ mincost=-1; break; }
    }
    return mincost;
}

int main(){
    int i;
    while(scanf("%d%d", &ns, &rs)==2, ns>0 || rs>0)
    {
        for(i=0; i<rs; i++)
            scanf("%d%d%d", &r[i].s, &r[i].e, &r[i].val);
        printf("%d\n", Kruskal());
    }
    return 0;
}