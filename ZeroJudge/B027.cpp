#include <iostream>

using namespace std;

int n,m,pt;
char s[200],*ptr;
short cc[91],c;

int main(){
    int i;
    while(scanf("%d%d",&n,&m) && !(n==0 && m==0))
    {
        scanf("\n");
        pt=0;
        memset(cc,0,sizeof(cc));
        gets(s);
        ptr=strtok(s," ");
        for(i=0;i<m;i++)
        {
            c=(ptr[0]=='+' || ptr[0]=='-')?ptr[1]:ptr[0];
            cc[c]++;
            if(cc[c]>4){ pt=100; break; }
            if(isdigit(ptr[0])){
                if(ptr[0]!='4' && ptr[0]!='5')
                    pt+=ptr[0]-48;
                if(pt>99) break;
            }else if(ptr[0]=='A')
                pt=0;
            else if(ptr[0]=='K')
                pt=99;
            else if(ptr[0]=='+'){
                pt+=(ptr[1]=='Q')?20:10;
                if(pt>99) break;
            }else if(ptr[0]=='-'){
                pt-=(ptr[1]=='Q')?20:10;
                if(pt<0) pt=0;
            }
            ptr=strtok(NULL," ");
        }
        if(pt>99)
            puts("Unfair game");
        else
            printf("%d\n",pt);
    }
    return 0;
}