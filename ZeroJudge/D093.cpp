#include<iostream>
#include<math.h>
using namespace std;
struct cord{
       char flag;
       double lx,ly,rx,ry;
};
int main(){
    cord a[10];
    int cc=0,pc=0;
    char c;
    double px,py;
    while(scanf("%c",&c)&&c!='*')
    {
         a[cc].flag=c;
         if(c=='r')scanf("%lf%lf%lf%lf",&a[cc].lx,&a[cc].ly,&a[cc].rx,&a[cc].ry);
         else scanf("%lf%lf%lf",&a[cc].lx,&a[cc].ly,&a[cc].rx);
         cc++;
         c=getchar();
    }
    while(scanf("%lf%lf",&px,&py)&&(px!=9999.9||py!=9999.9))
    {
         pc++;
         bool y=false;
         for(int i=0;i<cc;i++)
                 if(a[i].flag=='r'){
                      if(((a[i].lx<px && px<a[i].rx)||(a[i].lx>px && px>a[i].rx)) && ((a[i].ly<py && py<a[i].ry)||(a[i].ly>py && py>a[i].ry)))
                      {
                           y=true;
                           printf("Point %d is contained in figure %d\n",pc,i+1);
                      }
                 }else{
                      if(a[i].rx>sqrt((a[i].lx-px)*(a[i].lx-px)+(a[i].ly-py)*(a[i].ly-py)))
                      {
                           y=true;
                           printf("Point %d is contained in figure %d\n",pc,i+1);
                      }
                 }
         if(y==false)printf("Point %d is not contained in any figure\n",pc);
    }
    return 0;
}
