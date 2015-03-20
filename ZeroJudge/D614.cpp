#include<iostream>
using namespace std;
int main(){
    int n;char c;bool nst=true;
    scanf("%d",&n);
    c=getchar();
    for(int i=0;i<n;i++)
    {
            long long int ct=0,x=0;
            do
            {
                 c=getchar();
                 if(c>=48&&c<=57)
                 {
                                 x=c-48;
                                 while((c=getchar())!=' '&&c!='+'&&c!='\n')x=x*10+c-48;
                                 ct+=x;
                 }
            }while(c!='\n');
            printf("%d\n",ct);
    }
    return 0;
}
