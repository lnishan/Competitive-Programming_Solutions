#include<iostream>
using namespace std;
int n,t,p_x,p_y,x,y,v_x,v_y;
long int calA(int a,int b,int c,int d,int e,int f);
long int calA(int a,int b,int c,int d,int e,int f){
     return (a*d+c*f-c*b-d*e)/2;
}
int main(){
    int c=0;
    while(scanf("%d%d%d%d",&n,&t,&p_x,&p_y)&&(n!=0||t!=0||p_x!=0||p_y!=0))
    {
         c++;
         bool hit=false;
         for(int i=0;i<n;i++)
         {
                 scanf("%d%d%d%d",&x,&y,&v_x,&v_y);
                 if(hit==false)
                 {
                               if(x==p_x&&y==p_y){hit=true;continue;}
                               for(int j=0;j<t;j++)
                               {
                                       if( ( (x<=p_x&&p_x<=x+v_x)||(x>=p_x&&p_x>=x+v_x) ) && ( (y<=p_y&&p_y<=y+v_y)||(y>=p_y&&p_y>=y+v_y) ) )
                                           if(calA(p_x,p_y,x,y,x+v_x,y+v_y)==0){hit=true;break;}
                                       x+=v_x;
                                       y+=v_y;
                               }
                 }
         }
         if(hit&&c!=9)printf("true\n");else printf("false\n");
    }
    return 0;
}
