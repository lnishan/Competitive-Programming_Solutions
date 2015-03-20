#include<iostream>

using namespace std;

bool valid,found,row[9][10],col[9][10],box[3][3][10];
int a,a2,su[9][9],testct=0;

int input(){
    char c;
    for(c=getchar();c<48||c>57;c=getchar());
    return c-48;
}

int DFS(int x,int y){
    for(int i=x;i<a2;i++)
        for(int j=(i==x)?y:0;j<a2;j++)
        {
            if(su[i][j]==0){
                for(int n=1;n<=a2;n++)
                    if( (!row[i][n]) && (!col[j][n]) && (!box[i/a][j/a][n]) ){
                        su[i][j]=n;
                        row[i][n]=col[j][n]=box[i/a][j/a][n]=true;
                        DFS(i,j); if(found)return 0;
                        su[i][j]=0;
                        row[i][n]=col[j][n]=box[i/a][j/a][n]=false;
                    }
                return 0;
            }
            if(i==a2-1&&j==a2-1){
                found=true;
                for(int i=0;i<a2;i++)
                {
                    for(int j=0;j<a2;j++){ if(j!=0)putchar(' '); putchar(su[i][j]+48); }
                    putchar('\n');
                }
            }
        }
    return 0;
}
int main(){
    while(scanf("%d",&a)==1)
    {
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(box,0,sizeof(box));
        found=false;
        valid=true;
        a2=a*a;
        for(int i=0;i<a2;i++)
            for(int j=0;j<a2;j++)
            {
                su[i][j]=input();
                if(su[i][j]!=0)
                    if(row[i][su[i][j]] || col[j][su[i][j]] || box[i/a][j/a][su[i][j]]) valid=false;
                    else row[i][su[i][j]]=col[j][su[i][j]]=box[i/a][j/a][su[i][j]]=true;
            }
        if((testct++)!=0) putchar('\n');
        if(valid) DFS(0,0);
        if(!found) puts("NO SOLUTION");
    }
    return 0;
}
