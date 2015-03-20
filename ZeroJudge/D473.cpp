#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
char s[10000];
char *ptr;
int sl,a,b,exLns=0;
bool a1,a0,b0;

int execute(int a,int b){
    if(b==1)return a;
    else{
         int val=execute(a,b/2);
         if(b%2)return val*val*a;else return val*val;
    }
}
int main(){
    while(gets(s)&&strcmp(s,"0 0")!=0)
    {
         ptr=strtok(s," ");
         sl=strlen(ptr);
         a0=b0=true;a1=false;
         for(int i=0;i<sl;i++)
         {
                 if(i==sl-1 && a0 && s[i]=='1')a1=true;
                 if(ptr[i]!='0'&&ptr[i]!='-')a0=false;
         }
         if(a0)
                printf("0\n",ptr);
         else if(a1){
              if(ptr[0]=='-')
              {
                   ptr=strtok(NULL," ");
                   if(atoi(ptr)%2)printf("-1\n");else printf("1\n");
              }else printf("1\n");
         }else{
               a=atoi(ptr);
               ptr=strtok(NULL," ");
               sl=strlen(ptr);
               for(int i=0;i<sl;i++)if(ptr[i]!='0'&&ptr[i]!='-'){b0=false;break;}
               if(b0)
                     printf("1\n");
               else{
                    b=atoi(ptr);
                    printf("%d\n",execute(a,b));
               }
         }
    }
    while(gets(s))exLns++;
    printf("All Over. Exceeded %d lines!",exLns);
    return 0;
}
