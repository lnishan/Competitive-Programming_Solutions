#include<iostream>
using namespace std;
struct cord{
       double lx,ly,rx,ry;
};
int main(){
    cord a[10];
    int cc=0,pc=0;
    char c;
    double px,py;
    while(scanf("%c",&c)&&c!='*')
    {
         scanf("%lf%lf%lf%lf",&a[cc].lx,&a[cc].ly,&a[cc].rx,&a[cc].ry);
         cc++;
         c=getchar();
    }
    while(scanf("%lf%lf",&px,&py)&&(px!=9999.9||py!=9999.9))
    {
         pc++;
         bool y=false;
         for(int i=0;i<cc;i++)
                 if(((a[i].lx<px && px<a[i].rx)||(a[i].lx>px && px>a[i].rx)) && ((a[i].ly<py && py<a[i].ry)||(a[i].ly>py && py>a[i].ry)))
                 {
                      y=true;
                      printf("Point %d is contained in figure %d\n",pc,i+1);
                 }
         if(y==false)printf("Point %d is not contained in any figure\n",pc);
    }
    return 0;
}
