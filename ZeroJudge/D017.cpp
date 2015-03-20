#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char str[1001];
    int ct=1;
    while(gets(str)){
        printf("AB Circle #%d:\n",ct++);
        int l=strlen(str),t,ta=0,tb=0;
        for(int i=0;i<l;++i)
            if(str[i]=='a')ta++;
        tb=l-ta;
        t=ta;
        ta=min(ta,tb);
        tb=max(t,tb);
        if(ta==tb)
            for(int i=0;i<l-ta;i++)
                printf("%d,%d\n",i,i+ta);
        else{
            for(int i=0;i<l-tb;i++)
                printf("%d,%d\n%d,%d\n",i,i+ta,i,i+tb);
            for(int i=l-tb;i<l-ta;i++)
                printf("%d,%d\n",i,i+ta);
        }
    }
    return 0;
}
