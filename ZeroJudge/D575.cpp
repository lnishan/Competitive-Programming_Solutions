#include<iostream>
using namespace std;
long long int xx1,xx2,yy1,yy2,range;
long long int input(long long int x,int mode);
char cha;
int main(){
    while(1)
    {
            cha=getchar();
            if(cha==EOF)break;
            xx1=input(cha-48,1);
            yy1=input(0,0);
            xx2=input(0,0);
            yy2=input(0,0);
            range=input(0,0);
            if(((xx2-xx1<0)?xx1-xx2:xx2-xx1)+((yy2-yy1<0)?yy1-yy2:yy2-yy1)<=range) printf("die\n"); else printf("alive\n");
    }
    return 0;
}
long long int input(long long int x,int mode){
     char c;bool m;
     if(x+48=='-'){m=true;mode=0;}else{m=false;}
     if(mode==0){
                 while((c=getchar())==' '||c=='\n'||c=='-')
                                        if(c=='-')m=true;
                 x=c-48;
     }
     while((c=getchar())!=' '&&c!='\n')x=x*10+c-48;
     if(m)x=-x;
     return x;
}
