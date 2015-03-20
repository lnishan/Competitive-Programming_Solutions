#include <iostream>

using namespace std;

int a[5],i;
char s[1000],*ptr;

int main(){
    while(gets(s))
    {
        for(i=0;i<5;i++){ a[i]=s[i]-48; putchar(s[i]); }
        ptr=strtok(s," ");
        while(1)
        {
            ptr=strtok(NULL," ");
            if(ptr==NULL) break;
            if(ptr[0]==97){
                printf("&&");
                ptr=strtok(NULL," ");
                for(i=0;i<5;i++){ a[i]&=(ptr[i]-48); putchar(ptr[i]); }
            }else if(ptr[0]==111){
                printf("||");
                ptr=strtok(NULL," ");
                for(i=0;i<5;i++){ a[i]|=(ptr[i]-48); putchar(ptr[i]); }
            }
        }
        printf(" = ");
        for(i=0;i<5;i++) putchar(a[i]+48);
        putchar('\n');
    }
    return 0;
}
