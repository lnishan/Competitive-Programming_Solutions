#include<iostream>
using namespace std;
int main(){
    int n,c;
    bool a[401];
    while(scanf("%d",&n) && n!=0)
    {
                         int r[n],ct=0;
                         for(int i=1;i<=20*n;i++)a[i]=false;
                         for(int i=0;i<n;i++){scanf("%d",&r[i]);ct+=r[i];}
                         for(int i=0;i<n;i++)
                         {
                                 c=r[i];
                                 a[c]=true;
                                 for(int j=i+1;j<n;j++)
                                 {
                                         c+=r[j];
                                         a[c]=true;
                                 }
                         }
                         bool f=true;
                         for(int i=1;i<=ct;i++) if(a[i]==false){f=false;break;}
                         if(f&&n<ct)printf("YES\n");else printf("NO\n");
    }
    return 0;
}
