#include<iostream>
using namespace std;
int main(){
    int ns,a,b,gcd;
    scanf("%d",&ns);
    char c=getchar();
    for(int i=0;i<ns;i++)
    {
            a=b=0;
            while((c=getchar())!='\n')a=a*2+c-48;
            while((c=getchar())!='\n')b=b*2+c-48;
            while(a!=0&&b!=0) if(a>b)a%=b;else b%=a;
            gcd=(a==0)?b:a;
            printf("Pair #%d: ",i+1);
            if(gcd==1)printf("Love is not all you need!\n");else printf("All you need is love!\n");
    }
    return 0;
}
