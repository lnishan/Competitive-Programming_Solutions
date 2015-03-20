#include<iostream>
#include<math.h>
using namespace std;
double a2(double ax,double ay,double bx,double by,double cx,double cy){
       double r=ax*by+bx*cy+cx*ay-ay*bx-by*cx-cy*ax;
       return ((r<0)?-r:r);
}
struct cord{
       char flag;
       double lx,ly,rx,ry,mx,my;
       double x[3],y[3];
};
cord a[10];
int IsInTri( double x , double y , int where )
{
	int i , yes=1 ;
	double wcx , wcy ; /* weight center */
	for( wcx=0.0 , wcy=0.0 , i=0 ; i<3 ; i++ ){
		wcx += a[where].x[i] ;
		wcy += a[where].y[i] ;
	}
	wcx /= 3.0 ;
	wcy /= 3.0 ;
	/* ( x-x1 )( y1-y2 ) = ( x1-x2 )( y-y1 ) */
	for( i=0 ; i<3 ; i++ )
		if( ( ( x-a[where].x[i] )*( a[where].y[i]-a[where].y[(i+1)%3] ) -
			  ( y-a[where].y[i] )*( a[where].x[i]-a[where].x[(i+1)%3] ) ) *
			( ( wcx-a[where].x[i] )*( a[where].y[i]-a[where].y[(i+1)%3] ) -
			  ( wcy-a[where].y[i] )*( a[where].x[i]-a[where].x[(i+1)%3] ) ) <= 0.0 ){
			yes = 0 ;
			break ;
		}
	return yes ;
}
int main(){
    int cc=0,pc=0;
    char c;
    double px,py;
    while(scanf("%c",&c)&&c!='*')
    {
         a[cc].flag=c;
         if(c=='r') scanf("%lf%lf%lf%lf",&a[cc].lx,&a[cc].ly,&a[cc].rx,&a[cc].ry);
         else if(c=='c') scanf("%lf%lf%lf",&a[cc].lx,&a[cc].ly,&a[cc].rx);
         else if(c=='t') scanf("%lf%lf%lf%lf%lf%lf",&a[cc].x[0],&a[cc].y[0],&a[cc].x[1],&a[cc].y[1],&a[cc].x[2],&a[cc].y[2]);
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
                 }else if(a[i].flag=='c'){
                      if(a[i].rx>sqrt((a[i].lx-px)*(a[i].lx-px)+(a[i].ly-py)*(a[i].ly-py)))
                      {
                           y=true;
                           printf("Point %d is contained in figure %d\n",pc,i+1);
                      }
                 }else if(a[i].flag=='t'){                      
                      if(IsInTri(px,py,i))
                      {
                           y=true;
                           printf("Point %d is contained in figure %d\n",pc,i+1);
                      }
                 }
         if(y==false)printf("Point %d is not contained in any figure\n",pc);
    }
    return 0;
}
