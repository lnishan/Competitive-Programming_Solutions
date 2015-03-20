#include<iostream>
#include<string>
using namespace std;
int m[10],n,a,b;
string name[10],gi,re;
int reInd(string sn);
int reInd(string sn){
    int ind;
    for(int i=0;i<n;i++)if(name[i]==sn){ind=i;break;}
    return ind;
}
int main(){
    memset(m,0,sizeof(m));
    scanf("%d",&n);
    for(int i=0;i<n;i++)cin>>name[i];
    for(int i=0;i<n;i++)
    {
            cin>>gi;
            scanf("%d%d",&a,&b);
            if(a!=0)
            {
                    for(int j=0;j<b;j++)
                    {
                            cin>>re;
                            m[reInd(re)]+=(a/b);
                    }
                    m[reInd(gi)]-=(a/b*b);
            }else for(int j=0;j<b;j++)cin>>re;
    }
    for(int i=0;i<n;i++)cout<<name[i]<<" "<<m[i]<<endl;
    return 0;
}
