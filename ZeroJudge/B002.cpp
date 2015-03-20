#include <iostream>

using namespace std;

const int row=10;
const int col=10;

bool a[row][col],aDFS[2][col],aExe[row][col];
int t;
char s[row+1];

void clickD(int x,int y){
    aDFS[x][y]^=1;
    if(x>0) aDFS[x-1][y]^=1;
    if(y>0) aDFS[x][y-1]^=1;
    if(x<row-1) aDFS[x+1][y]^=1;
    if(y<col-1) aDFS[x][y+1]^=1;
}

void clickE(int x,int y){
    aExe[x][y]^=1;
    if(x>0) aExe[x-1][y]^=1;
    if(y>0) aExe[x][y-1]^=1;
    if(x<row-1) aExe[x+1][y]^=1;
    if(y<col-1) aExe[x][y+1]^=1;
}

void execute(int ct){
    int bct=ct;
    for(int i=1;i<row;i++)
        for(int j=0;j<col;j++)
            if(!aExe[i-1][j]){
                clickE(i,j);
                ct++;
            }
    for(int j=0;j<col;j++)
        if(!aExe[row-1][j]) return ;
    printf("%d\n",ct);
}

void dfs(int count,int clicks){
    if(count<col){
        dfs(count+1,clicks);
        clickD(0,count);
        dfs(count+1,clicks+1);
        clickD(0,count);
    }else{
        for(int i=0;i<2;i++)
            for(int j=0;j<col;j++)
                aExe[i][j]=aDFS[i][j];
        for(int i=2;i<row;i++)
            for(int j=0;j<col;j++)
                aExe[i][j]=a[i][j];
        execute(clicks);
    }
}

int main(){
    scanf("%d",&t);
    gets(s);
    for(int d=0;d<t;d++)
    {
        gets(s);
        for(int i=0;i<row;i++)
        {
            gets(s);
            for(int j=0;j<col;j++)
            {
                a[i][j]=s[j]=='#';
                if(i<2) aDFS[i][j]=s[j]=='#';
            }
        }
        dfs(0,0);
    }
    return 0;
}
