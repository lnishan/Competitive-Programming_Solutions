#include<iostream>
using namespace std;
int main(){
    int ns,ma,mb;long int a[3000][2],ml,tx,ty;
    while(scanf("%d",&ns)&&ns!=0)
    {
                                 for(int i=0;i<ns;i++)scanf("%d%d",&a[i][0],&a[i][1]);
                                 ml=0;
                                 for(int i=0;i<ns;i++)
                                         for(int j=i+1;j<ns;j++)
                                         {
                                                 tx=a[i][0]-a[j][0];
                                                 ty=a[i][1]-a[j][1];
                                                 if(tx*tx+ty*ty>ml){ml=tx*tx+ty*ty;ma=i;mb=j;}
                                         }
                                 printf("%d %d\n",ma,mb);
    }
    return 0;
}
