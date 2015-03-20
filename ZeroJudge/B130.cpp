#include<iostream>
using namespace std;
int cmp(const void * a,const void * b);
int cmp(const void * a,const void * b){
    return *(int*)a-*(int*)b;
}
int main(){
    int n,a[1000];
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    int c=1;
    for(int i=1;i<n;i++)if(a[i]!=a[i-1])c++;
    printf("%d\n%d",c,a[0]);
    for(int i=1;i<n;i++)if(a[i]!=a[i-1])printf(" %d",a[i]);
    printf("\n");
    return 0;
}
