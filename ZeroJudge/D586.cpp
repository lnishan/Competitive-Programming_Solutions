#include<iostream>
#include<string>
#include<ctype.h>
#include<math.h>
using namespace std;
int a[10000],ns,n,no,ct;
int main(){
    string s,fs,a="uzrmatifxopnhwvbslekycqjgd",b="mjqhofawcpnsexdkvgtzblryui",ch;
    scanf("%d",&ns);
    for(int i=0;i<ns;i++)
    {
            scanf("%d",&n);
            cin>>s;
            if(atoi(s.c_str())!=0){
                 fs=b[atoi(s.c_str())-1];
                 for(int j=1;j<n;j++)
                 {
                         scanf("%d",&no);
                         fs+=b[no-1];
                 }
                 cout<<fs<<endl;
            }else{
                 ct=a.find(s)+1;
                 for(int j=1;j<n;j++)
                 {
                         cin>>ch;
                         ct+=a.find(ch)+1;
                 }
                 printf("%d\n",ct);
            }
    }
    return 0;
}
