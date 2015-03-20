#include <iostream>
#include <cstring>

using namespace std;

char name[10002][40],cmd[10002][2][40];
int pc=0,t,acp=0,c=0,slen,ind;
bool bname[10002];

int findName(char s[]){
    for(int i=0;i<pc;i++)
        if(strcmp(s,name[i])==0)
            return i;
    return -1;
}

int main(){
    scanf("%d",&t);
    memset(bname,0,sizeof(bname));
    for(int i=t-1;i>=0;i--)
        scanf("%s %s",cmd[i][0],cmd[i][1]);
    for(int i=0;i<t;i++)
    {
        ind=findName(cmd[i][0]);
        if(strcmp(cmd[i][1],"AC")==0){
            if(ind==-1){
                c++; acp++;
                bname[pc]=true;
            }else if(!bname[ind]){
                acp++;
                bname[ind]=true;
            }
        }
        if(ind==-1){
            slen=strlen(cmd[i][0]);
            for(int j=0;j<slen;j++)
                name[pc][j]=cmd[i][0][j];
            pc++;
        }
    }
    printf("%d",c*100/acp);
    putchar('%');
    return 0;
}
