#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n)
    {
                 int a[n][n],cc,ivld_c=0,rc,ivld_r=0,c,r;
                 for(int i=0;i<n;i++)
                 {
                         cc=0;
                         for(int j=0;j<n;j++)
                         {
                                 scanf("%d",&a[i][j]);
                                 cc+=a[i][j];
                         }
                         if(cc%2==1){ivld_c++;c=i+1;}
                 }
                 for(int j=0;j<n;j++)
                 {
                         rc=0;
                         for(int i=0;i<n;i++)rc+=a[i][j];
                         if(rc%2==1){ivld_r++;r=j+1;}
                 }
                 if(ivld_c==0&&ivld_r==0)printf("OK\n");else if(ivld_c==1&&ivld_r==1)printf("Change bit (%d,%d)\n",c,r);else printf("Corrupt\n");
    }
    return 0;
}
