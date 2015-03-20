#include<iostream>
using namespace std;
int cmp(const void * a, const void * b);
int cmp(const void * a, const void * b){
    return (*(int*)b-*(int*)a);
}
int main(){
    long int a[100002];
    int ac=0;
    while(scanf("%d",&a[ac])!=EOF)ac++;
    qsort(a,ac,sizeof(long int),cmp);
    for(int i=0;i<ac;i++){if(i!=0)printf(" ");printf("%d",a[i]);}
    return 0;
}
