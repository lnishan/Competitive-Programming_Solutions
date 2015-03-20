#include<iostream>
using namespace std;
int n,v,w,chk[101],update[101][2],upc,maxw;
int main(){
    scanf("%d",&n);
    chk[0]=maxw=0;
    for(int i=1;i<=100;i++)chk[i]=-1;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&v,&w);
        upc=0;
        for(int j=0;j<=100;j++)
            if(chk[j]>=0 && j+v<=100)
                if(chk[j]+w>chk[j+v]){
                    update[upc][0]=j;
                    update[upc++][1]=chk[j]+w;
                }
        for(int j=0;j<upc;j++)
        {
            chk[update[j][0]+v]=update[j][1];
            maxw=max(maxw,chk[update[j][0]+v]);
        }
    }
    printf("%d\n",maxw);
    return 0;
}
