#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;
int getN(char cha);
int getN(char cha){
    if(isdigit(cha)) return cha-48; else return cha-55;
}
int main(){
    char c;
    printf("�Q���i���ܪk  �۹������Q�i���ܪk\n");
    while(1)
    {
            if((c=getchar())==EOF)break;
            string s;s+=c;
            int n=getN(c);
            while((c=getchar())!='\n'){s+=c;n=n*16+getN(c);}
            printf("      ");cout<<s;printf("                 %d\n",n);
    }
    return 0;
}
