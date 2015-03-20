#include<iostream>
using namespace std;
int main(){
    char c;
    long long int x,ct=0;
    do
    {
            while((c=getchar())==' ');
            if(c=='\n')break;
            x=c-48;
            while((c=getchar())!=' '&&c!='\n')x=x*10+c-48;
            ct+=x;
    }while(c!='\n');
    printf("%lld",ct);
    return 0;
}
