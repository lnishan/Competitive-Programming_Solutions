#include<iostream>
using namespace std;
int main(){
    int m,n,wi,le,mdat[10][40][40],pdat[10][40][40];
    char ch;
    scanf("%d%d%d%d",&m,&n,&wi,&le);ch=getchar();
    for(int i=0;i<m;i++)
    {
            for(int j=0;j<le;j++)
            {
                    for(int k=0;k<wi;k++){ch=getchar();mdat[i][j][k]=int(ch);}
                    ch=getchar();
            }
    }
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<le;j++)
            {
                    for(int k=0;k<wi;k++){ch=getchar();pdat[i][j][k]=int(ch);}
                    ch=getchar();
            }
            bool fpic=false;
            for(int j=0;j<m;j++)
            {
                    int cor=0,incor=0;
                    for(int k=0;k<le;k++)
                            for(int l=0;l<wi;l++)
                                    if(mdat[j][k][l]!=45)
                                                          if(mdat[j][k][l]==pdat[i][k][l])cor++;else incor++;
                    if(cor>=incor*4){fpic=true;break;}
            }
            if(fpic)printf("Y\n");else printf("N\n");
    }
    return 0;
}
