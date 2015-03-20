#include<iostream>
using namespace std;
double h,u,d,f,ude,curh;
int main(){
    while(cin>>h>>u>>d>>f && (h!=0||u!=0||d!=0||f!=0))
    {
                          ude=u*f/100;
                          curh=0;
                          int day;
                          for(int i=1;;i++)
                          {
                                 curh+=u;
                                 if(curh>h){day=i; break;}
                                 curh-=d;
                                 if(curh<0){day=-i; break;}
                                 if(u>=ude)u-=ude;
                          }
                          if(day>0)printf("success on day %d\n",day); else printf("failure on day %d\n",-day);
    }
    return 0;
}
