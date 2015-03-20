#include <iostream>

using namespace std;

struct d{ int n,p; };
d a[1000000];
int n,t;

inline int input(){
    char c;
    for(c=getchar();c<48||c>57;c=getchar()) ;
    int x=c-48;
    for(c=getchar();c>47&&c<58;c=getchar()) x=x*10+c-48;
    return x;
}

bool cmp(d a,d b){
    return a.n<b.n;
}

int main(){
    int i;
    n=input();
    for(i=0;i<n;i++)
    {
        a[i].n=input();
        a[i].p=i;
    }
    sort(a,a+i,cmp);
    for(i=0;i<n;i++)
    {
        t=1000000001;
        if(a[i].p>0)
            if(a[i])