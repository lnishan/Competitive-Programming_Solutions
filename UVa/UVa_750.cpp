#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

int t,x,y,c,path[9];
bool row[9],dia1[15],dia2[17];

int input(){
    char c;
    for(c=getchar();!isdigit(c);c=getchar());
    int x=c-48;
    for(c=getchar();isdigit(c);c=getchar())x=x*10+c-48;
    return x;
}

void dfs(int ind){
    if(ind==y)
        dfs(ind+1);
    else{
        if(ind>8){
            printf("%d     ",++c);
            for(int i=1;i<9;i++)
                printf(" %d",path[i]);
            putchar('\n');
        }else
            for(int i=1;i<9;i++)
                if(!row[i] && !dia1[ind-i+7] && !dia2[i+ind]){
                    row[i]=dia1[ind-i+7]=dia2[i+ind]=true;
                    path[ind]=i;
                    dfs(ind+1);
                    row[i]=dia1[ind-i+7]=dia2[i+ind]=false;
                }
    }
}

int main(){
    t=input();
    for(int i=0;i<t;i++)
    {
        memset(row,0,sizeof(row));
        memset(dia1,0,sizeof(dia1));
        memset(dia2,0,sizeof(dia2));
        c=0;
        printf("SOLN       COLUMN\n#      1 2 3 4 5 6 7 8\n\n");
        x=input();
        y=input();
        path[y]=x;
        row[x]=dia1[y-x+7]=dia2[x+y]=true;
        dfs(1);
        putchar('\n');
    }
    return 0;
}
