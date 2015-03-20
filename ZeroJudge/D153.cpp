#include<iostream>
#include<stdlib.h>
using namespace std;
int ds,n,a[40000];
int compare (const void * a, const void * b)
{
    return ( *(int*)b - *(int*)a );
}
int main(){
    while(scanf("%d",&n) && n!=0)
    {
            for(int i=0;i<n;i++)scanf("%d",&a[i]);
            qsort(a,n,sizeof(int),compare);
            for(int i=0;i<n;i++){if(i!=0)printf(" ");printf("%d",a[i]);}
            printf("\n");
    }
    return 0;
}
