#include<iostream>
using namespace std;
int input();
int input(){
    int x;char c;
    while((c=getchar())==' '||c=='\n');
    x=c-48;
    while((c=getchar())!=' '&&c!='\n')x=x*10+c-48;
    return x;
}
int main(){
    int ds,ans[100][5],stus,qs,opts,t,tsc,maxsc,maxno,wrc;
    ds=input();
    for(int i=0;i<ds;i++)
    {
            stus=input();qs=input();opts=input();
            for(int j=0;j<qs;j++) for(int k=0;k<opts;k++) ans[j][k]=input();
            maxsc=-201;
            for(int j=0;j<stus;j++)
            {
                    tsc=100;wrc=0;
                    for(int k=0;k<qs;k++)
                            for(int l=0;l<opts;l++)
                            {
                                    t=input();
                                    if(t!=ans[k][l])wrc++;
                            }
                    tsc-=(wrc*200/(qs*opts));
                    if(tsc<0)printf("=  =\"\n");else printf("%d\n",tsc);
                    if(tsc>maxsc){maxsc=tsc;maxno=j+1;}
            }
            printf("The Highest : No.%d %dpoint",maxno,maxsc);
            if(maxsc!=0&&maxsc!=1)printf("s");
            printf("\n");
    }
    return 0;
}
