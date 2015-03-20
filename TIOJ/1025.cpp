#include<iostream>

using namespace std;

bool row[9][10],col[9][10],box[3][3][10];
int a=3,a2,su[9][9],solc;

int input(){
    char c;
    for(c=getchar();c<48||c>57;c=getchar());
    return c-48;
}

int DFS(int x,int y){
    int i, j;
    for(i=x;i<a2;i++)
        for(j=(i==x)?y:0;j<a2;j++)
        {
            if(su[i][j]==0){
                for(int n=1;n<=a2;n++)
                    if( (!row[i][n]) && (!col[j][n]) && (!box[i/a][j/a][n]) ){
                        su[i][j]=n;
                        row[i][n]=col[j][n]=box[i/a][j/a][n]=true;
                        DFS(i,j);
                        su[i][j]=0;
                        row[i][n]=col[j][n]=box[i/a][j/a][n]=false;
                    }
                return 0;
            }
            if(i==a2-1&&j==a2-1){
                solc++;
                for(i=0;i<a2;i++)
                {
                    for(j=0;j<a2;j++){ if(j>0) putchar(' '); putchar(su[i][j]+48); }
                    putchar('\n');
                }
                putchar('\n');
            }
        }
    return 0;
}
int main(){
    int i, j;
    memset(row,0,sizeof(row));
    memset(col,0,sizeof(col));
    memset(box,0,sizeof(box));
    solc=0;
    a2=a*a;
    for(i=0;i<a2;i++)
        for(j=0;j<a2;j++)
        {
            su[i][j]=input();
            if(su[i][j]!=0)
                row[i][su[i][j]]=col[j][su[i][j]]=box[i/a][j/a][su[i][j]]=true;
        }
    DFS(0,0);
    printf("there are a total of %d solution(s).\n", solc);
    //while(1);
    return 0;
}