#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct data{
    char str[1000];
};
data s[52];
int n;

bool cmp(data a,data b){
    int alen=strlen(a.str),blen=strlen(b.str),mlen=min(alen,blen);
    for(int i=0;i<mlen;i++)
        if(a.str[i]!=b.str[i]) return (a.str[i]>b.str[i]);
    if(alen>blen){
        for(int i=blen,j=0;i<alen;i++,j++)
        {
            if(j>=blen) j=0;
            if(a.str[i]!=b.str[j]) return (a.str[i]>b.str[j]);
        }
        return false;
    }else if(alen<blen){
        for(int i=0,j=alen;j<blen;i++,j++)
        {
            if(i>=alen) i=0;
            if(a.str[i]!=b.str[j]) return (a.str[i]>b.str[j]);
        }
        return true;
    }
    return true;
}

int main(){
    while(scanf("%d",&n)==1&&n!=0)
    {
        for(int i=0;i<n;i++)
            scanf("%s",&s[i].str);
        sort(s,s+n,cmp);
        for(int i=0;i<n;i++)
            printf("%s",s[i].str);
        putchar('\n');
    }
    return 0;
}
