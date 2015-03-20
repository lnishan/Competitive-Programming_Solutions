#include<iostream>
using namespace std;
int main(){
    int n,m,a[10000][2];
    while(scanf("%d",&n) && n!=0)
    {
                            long int c=0,m=0;
                            for(int i=0;i<n;i++)scanf("%d %d",&a[i][0],&a[i][1]);
                            for(int i=n-2;i>=0;i--)
                            {
                                    for(int j=0;j<=i;j++)
                                    {
                                            if(a[j][1]<a[j+1][1])
                                            {
                                                                 a[j][0]+=a[j+1][0];a[j+1][0]=a[j][0]-a[j+1][0];a[j][0]-=a[j+1][0];
                                                                 a[j][1]+=a[j+1][1];a[j+1][1]=a[j][1]-a[j+1][1];a[j][1]-=a[j+1][1];
                                            }
                                    }
                            }
                            for(int i=0;i<n;i++)
                            {
                                    c+=a[i][0];
                                    m=max(m,c+a[i][1]);
                            }
                            printf("%d\n",m);
    }
    return 0;
}
