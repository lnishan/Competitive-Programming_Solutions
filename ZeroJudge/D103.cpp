#include<iostream>
using namespace std;
int main(){
    char c;
    int a[9];
    while(1)
    {
            if((c=getchar())==EOF)break;
            int n=c-48;
            a[0]=n;
            c=getchar();
            for(int i=2;i<5;i++){c=getchar();a[i-1]=c-48;n+=a[i-1]*i;}
            c=getchar();
            for(int i=5;i<10;i++){c=getchar();a[i-1]=c-48;n+=a[i-1]*i;}
            c=getchar();c=getchar();
            n%=11;
            if(c-48==n||(n==10&&c=='X'))
                printf("Right\n");
            else
            {
                for(int i=0;i<9;i++)
                {
                        if(i==1||i==4)putchar('-');
                        putchar(a[i]+48);
                }
                putchar('-');
                if(n==10)putchar('X');else putchar(n+48);
                putchar('\n');
            }
    }
    return 0;
}
