#include<iostream>
#include<math.h>
using namespace std;
int main(){
    bool a[3000];
    int ns,n,pn;
    while(scanf("%d",&ns)!=EOF)
    {
                               for(int i=1;i<ns;i++)a[i]=false;
                               scanf("%d",&pn);
                               for(int i=1;i<ns;i++)
                               {
                                       scanf("%d",&n);
                                       a[abs(n-pn)]=true;
                                       pn=n;
                               }
                               bool y=true;
                               for(int i=1;i<ns;i++)if(a[i]==false){y=false;break;}
                               if(y)printf("Jolly\n");else printf("Not jolly\n");
    }
    return 0;
}
