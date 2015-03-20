#include<iostream>
using namespace std;
bool a[51][51],lost;
int mx,my,rx,ry,nx,ny,dir,clen,tx[4]={0,1,0,-1},ty[4]={1,0,-1,0};
char c,clist[101];
int main(){
    scanf("%d%d",&mx,&my);
    memset(a,0,sizeof(a));
    while(scanf("%d %d %c",&rx,&ry,&c)==3)
    {
         lost=false;
         if(c=='N')dir=0;
         else if(c=='E')dir=1;
         else if(c=='S')dir=2;
         else if(c=='W')dir=3;
         c=getchar();
         gets(clist);
         clen=strlen(clist);
         for(int i=0;i<clen;i++)
         {
                 if(clist[i]=='L'){
                      dir--;
                      if(dir<0)dir+=4;
                 }else if(clist[i]=='R'){
                      dir++;
                      if(dir>3)dir-=4;
                 }else if(clist[i]=='F'){
                      nx=rx+tx[dir];
                      ny=ry+ty[dir];
                      if(nx>=0&&ny>=0&&nx<=mx&&ny<=my){
                           rx=nx;
                           ry=ny;
                      }else if((nx<0||ny<0||nx>mx||ny>my) && (!a[rx][ry])){
                           lost=true;
                           a[rx][ry]=true;
                           break;
                      }
                 }
         }
         printf("%d %d ",rx,ry);
         if(dir==0)putchar('N');
         else if(dir==1)putchar('E');
         else if(dir==2)putchar('S');
         else if(dir==3)putchar('W');
         if(lost)printf(" LOST");
         putchar('\n');
    }
    return 0;
}
