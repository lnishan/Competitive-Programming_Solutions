#include<iostream>
using namespace std;
int ds,ns,shr,smin,ehr,emin,nhr,minushr,nmin,rhr,rmin,rhr2,rmin2;
string s;
int main(){
    scanf("%d",&ds);
    for(int i=0;i<ds;i++)
    {
            scanf("%d %d:%d %d:%d",&ns,&shr,&smin,&ehr,&emin);
            for(int i=0;i<ns;i++)
            {
                    cin>>s;
                    scanf("%d:%d",&nhr,&nmin);
                    minushr=nhr;
                    rmin=smin-nmin;
                    if(rmin<0){minushr++;rmin+=60;}
                    rhr=shr-minushr;
                    if(rhr<0)rhr+=24;
                    
                    minushr=nhr;
                    rmin2=emin-nmin;
                    if(rmin2<0){minushr++;rmin2+=60;}
                    rhr2=ehr-minushr;
                    if(rhr2<0)rhr2+=24;
                    printf("%02d:%02d %02d:%02d\n",rhr,rmin,rhr2,rmin2);
            }
    }
    return 0;
}
