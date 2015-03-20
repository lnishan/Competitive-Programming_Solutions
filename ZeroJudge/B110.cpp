#include <iostream>

using namespace std;

int sp,mx[4]={-1,-1,0,0},my[4]={1,0,0,1};
bool a[130][130];
char c;

bool check(int LDx,int LDy,int span){
    if(LDx<0 || LDx>=sp || LDy<0 || LDy>=sp) return false;
    for(int i=LDx-span+1;i<=LDx;i++)
        for(int j=LDy;j<LDy+span;j++)
            if(a[i][j]) return true;
    return false;
}

bool checkFull(int LDx,int LDy,int span){
    if(LDx<0 || LDx>=sp || LDy<0 || LDy>=sp) return false;
    for(int i=LDx-span+1;i<=LDx;i++)
        for(int j=LDy;j<LDy+span;j++)
            if(!a[i][j]) return false;
    return true;
}

void dfs(int x,int y,int span){
    bool ac[4],copen;
    memset(ac,0,sizeof(ac));
    if(checkFull(x,y,span)){
        if(!(x==sp-1 && y==0 && span==sp)) putchar(' ');
        putchar('b');
    }else{
        copen=false;
        for(int i=0;i<4;i++)
        {
            ac[i]=check(x+mx[i]*(span/2),y+my[i]*(span/2),span/2);
            if(ac[i]) copen=true;
        }
        if(copen){
            if(!(x==sp-1 && y==0 && span==sp)) putchar(' ');
            putchar('g');
            for(int i=0;i<4;i++)
                if(ac[i])
                    dfs(x+mx[i]*(span/2),y+my[i]*(span/2),span/2);
                else
                    printf(" w");
        }else{
            if(!(x==sp-1 && y==0 && span==sp)) putchar(' ');
            putchar('w');
        }
    }
}

int main(){
    while(scanf("%d",&sp)==1)
    {
        for(int i=0;i<sp;i++)
        {
            c=getchar();
            for(int j=0;j<sp;j++)
            {
                c=getchar();
                a[i][j]=c-48;
            }
        }
        dfs(sp-1,0,sp);
        putchar('\n');
    }
    return 0;
}
