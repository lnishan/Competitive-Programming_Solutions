#include<iostream>
using namespace std;
int main(){
    int ds,a[4];
    scanf("%d",&ds);
    for(int i=0;i<ds;i++)
    {
            scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
            if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3])
                                                  printf("square\n");
            else
            {
                for(int i=2;i>=0;i--)
                        for(int j=0;j<=i;j++){if(a[j]>a[j+1]){a[j]+=a[j+1];a[j+1]=a[j]-a[j+1];a[j]-=a[j+1];}}
                if(a[0]==a[1]&&a[2]==a[3])
                                          printf("rectangle\n");
                else if(a[0]+a[1]+a[2]>a[3])
                                            printf("quadrangle\n");
                else
                                            printf("banana\n");
            }
    }
    return 0;
}
