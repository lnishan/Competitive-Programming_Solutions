#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char yr[1002];
    int l,oddct,evenct;
    while(gets(yr))
    {
         l=strlen(yr);
         bool c1,c2,c3;
         if(  (((yr[l-2]-48)*10+yr[l-1]-48)%4==0&&(yr[l-2]!=48||yr[l-1]!=48)) || ((yr[l-2]==48&&yr[l-1]==48)&&((yr[l-4]-48)*10+yr[l-3]-48)%4==0)   ){
              printf("This is leap year.\n");
              c1=true;
         }else c1=false;
         oddct=evenct=0;
         for(int i=0;i<l;i++)
                 if(i%2)oddct+=yr[i];else evenct+=yr[i];
         if((oddct+evenct)%3==0&&(yr[l-1]==53||yr[l-1]==48)){
              printf("This is huluculu festival year.\n");
              c2=true;
         }else c2=false;
         if((oddct-evenct)%11==0&&(yr[l-1]==53||yr[l-1]==48)&&c1){
              printf("This is bulukulu festival year.\n");
              c3=true;
         }else c3=false;
         if(!c1&&!c2&&!c3) printf("This is an ordinary year.\n");
         putchar('\n');
    }
    return 0;
}
