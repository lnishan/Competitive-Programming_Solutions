#include <iostream>

using namespace std;

char s[2][1000002];
int len[2],t,zero,spos[2];

void Reverse(){
    int i,j;
    for(i=0;i<2;i++)
        for(j=0;j<=(len[i]-1)/2;j++)
            swap(s[i][j],s[i][len[i]-j-1]);
}

int Compare(){
    int i;
    if(len[0]-spos[0]!=len[1]-spos[1])
        return int(len[0]-spos[0]<len[1]-spos[1]);
    else if(len[0]==spos[0]+1)
        return 1;
    else if(len[1]==spos[1]+1)
        return 0;
    else
        for(i=len[0]-spos[0]-1;i>=0;i--)
            if(s[0][i+spos[0]]!=s[1][i+spos[1]])
                return int(s[0][i+spos[0]]<s[1][i+spos[1]]);
    return 0;
}

void Minus(){
    int i,j,tlen=len[t],pos;
    for(i=spos[t];i<len[t];i++)
    {
        pos=i-spos[t]+spos[1-t];
        if(pos<len[1-t])
            s[t][i]=s[t][i]-s[1-t][pos]+48;
        if(s[t][i]<48){
            s[t][i]+=2;
            s[t][i+1]--;
        }
        if(s[t][i]!=48) tlen=i+1;
    }
    len[t]=tlen;
}

int main(){
    int i,j;
    gets(s[0]);
    gets(s[1]);
    len[0]=strlen(s[0]);
    len[1]=strlen(s[1]);
    Reverse();
    spos[0]=spos[1]=0;
    t=Compare();
    zero=0;
    while(len[0]-spos[0]>1 && len[1]-spos[1]>1)
    {
        if(s[0][spos[0]]==48 && s[1][spos[1]]==48){
            zero++;
            spos[0]++;
            spos[1]++;
        }else if(s[0][spos[0]]==48) spos[0]++;
        else if(s[1][spos[1]]==48) spos[1]++;
        else{
            Minus();
            spos[t]++;
        }
        t=Compare();
    }
    for(i=len[t]-1;i>=spos[t];i--)
        putchar(s[t][i]);
    for(i=0;i<zero;i++)
        putchar(48);
    return 0;
}
