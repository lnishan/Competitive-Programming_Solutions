#include<iostream>
using namespace std;
int main(){
    char c;
    long int a[2],ct=0;
    while((c=getchar())!=EOF)
    {
                             if(c>=48&&c<=57)
                             {
                                             a[ct]=c-48;
                                             while((c=getchar())>=48&&c<=57)a[ct]=a[ct]*10+c-48;
                                             ct++;
                             }
    }
    long long int ans=a[0]+a[1];
    printf("%d %d ",a[0],a[1]);
    if(ans<0)printf("4200000000\n");else printf("%d\n",ans);
    return 0;
}
