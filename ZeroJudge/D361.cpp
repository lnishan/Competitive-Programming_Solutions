#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int n1,n2,nlen,ct=0,a[10][5]={{1,0},{1,1},{4,6,2,4,8},{4,1,3,9,7},{2,6,4},{1,5},{1,6},{4,1,7,9,3},{4,6,8,4,2},{2,1,9}};
    char s[205];
    char *ptr;
    while(gets(s),strcmp(s,"0 0")!=0)
    {
         ptr=strtok(s," ");
         n1=ptr[strlen(ptr)-1]-48;
         ptr=strtok(NULL," ");
         nlen=strlen(ptr);
         n2=ptr[nlen-1]-48;
         if(nlen>1)n2+=(ptr[nlen-2]-48)*10;
         if(n2==0&&nlen==1)putchar(49);else putchar( a[n1][(n2%a[n1][0])+1] +48 );
         putchar('\n');
    }
    return 0;
}
