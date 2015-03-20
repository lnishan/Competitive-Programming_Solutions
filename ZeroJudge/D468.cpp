#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
char s[10000];
char *ptr;
long long int sl,a,b,sn;
bool a1,a0,b0,m;

long long int execute(long long int a,long long int b){
    if(b==1)return a;
    else{
         long long int val=execute(a,b/2);
         if(b%2)return val*val*a;else return val*val;
    }
}
int main(){
    while(gets(s)&&strcmp(s,"0 0")!=0)
    {
         ptr=strtok(s," ");
         sl=strlen(ptr);
         a0=b0=true;a1=m=false;
         a=b=0;
         for(int i=0;i<sl;i++)
         {
                 if(i==sl-1 && a0 && ptr[i]=='1')a1=true;
                 if(ptr[i]!='0' && ptr[i]!='-')a0=false;
                 if(ptr[i]!='-')a=a*10+ptr[i]-48;else m=true; 
         }
         if(m)a=-a;
         if(a0)
                printf("0\n",ptr);
         else if(a1){
              if(ptr[0]=='-'){
                   ptr=strtok(NULL," ");
                   sl=strlen(ptr);
                   if(ptr[sl-1]%2)printf("-1\n");else printf("1\n");
              }else printf("1\n");
         }else{
               ptr=strtok(NULL," ");
               sl=strlen(ptr);
               for(int i=0;i<sl;i++)b=b*10+ptr[i]-48;
               for(int i=0;i<sl;i++)
                       if(ptr[i]!='0'&&ptr[i]!='-'){b0=false;break;}
               if(b0)
                     printf("1\n");
               else{
                    printf("%lld\n",execute(a,b));
               }
         }
    }
    printf("All Over.");
    return 0;
}
