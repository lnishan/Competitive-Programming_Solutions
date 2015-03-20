#include<iostream>
using namespace std;
int a[6][5];
void DFS(bool vpath[6][6],int lnode,int avpath[],int pathlen){
    if(pathlen==9){
          for(int i=0;i<9;i++)
                  printf("%d",avpath[i]);
          putchar('\n');
    }else{
          pathlen++;
          for(int i=1;i<=a[lnode][0];i++)
          {
                  if(vpath[lnode][a[lnode][i]]==0 && vpath[a[lnode][i]][lnode]==0)
                  {
                       vpath[lnode][a[lnode][i]]=true;
                       avpath[pathlen-1]=a[lnode][i];
                       DFS(vpath,a[lnode][i],avpath,pathlen);
                       vpath[lnode][a[lnode][i]]=false;
                  }
          }
    }
}
int main(){
    bool vpath[6][6];
    int avpath[10];
    memset(vpath,0,sizeof(vpath));
    a[1][0]=3;a[1][1]=2;a[1][2]=3;a[1][3]=5;
    a[2][0]=3;a[2][1]=1;a[2][2]=3;a[2][3]=5;
    a[3][0]=4;a[3][1]=1;a[3][2]=2;a[3][3]=4;a[3][4]=5;
    a[4][0]=2;a[4][1]=3;a[4][2]=5;
    a[5][0]=4;a[5][1]=1;a[5][2]=2;a[5][3]=3;a[5][4]=4;
    avpath[0]=1;
    DFS(vpath,1,avpath,1);
    system("pause");
    return 0;
}
