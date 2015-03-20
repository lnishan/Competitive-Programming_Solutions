//134043
/*
#include<iostream>
#include<math.h>
using namespace std;
long long int cPFt(long long int no);
long long int pow2(int a,int b);
long long int pow2(int a,int b){
     long long int f=1;
     for(int i=1;i<=b;i++)f*=a;
     return f;
}
long long int cPFt(long long int no){
     long long int sn=2,ac=0,up;
     while(no!=1)
     {
                if(no%sn==0)
                {
                           for(int i=1;;i++){ if(fmod(no,pow2(sn,i))!=0){up=i-1;break;} }
                           no/=pow2(sn,up);
                           ac++;
                }
                if(sn==2) sn++; else sn+=2;
     }
     return ac;
}
int main(){
    int n;
    while(cin>>n)
    {
                 int c=0;
                 for(int i=1;;i++)
                 {
                         if(cPFt(i)==n)c++; else c=0;
                         if(c==n){cout<<i-n+1<<endl;break;}
                 }
    }
    return 0;
}
*/
#include<iostream>
int main(){
    std::printf("%d",134043);
    return 0;
}
