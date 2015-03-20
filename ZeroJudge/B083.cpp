#include<iostream>
using namespace std;
struct data{
       char name[101];
       int a,b;
       double c;
};
bool cmp1(data d1, data d2){
     if(d1.a!=d2.a)
          return (d1.a>d2.a);
     else if(d1.b!=d2.b)
          return (d1.b<d2.b);
     else
         return (d1.c<d2.c);
}
bool cmp2(data d1, data d2){
     if(d1.a!=d2.a)
          return (d1.a>d2.a);
     else if(d1.b!=d2.b)
          return (d1.b>d2.b);
     else
         return (d1.c>d2.c);
}
data p[1000],b[1000];
int main(){
    int ds,ns;
    scanf("%d",&ds);
    for(int i=0;i<ds;i++)
    {
            int pc=0,bc=0;
            scanf("%d",&ns);
            char pt=getchar();
            for(int j=0;j<ns;j++)
            {
                    pt=getchar();
                    if(pt=='P'){
                               scanf(" %s %d %d %lf",&p[pc].name,&p[pc].a,&p[pc].b,&p[pc].c);
                               pc++;
                    }else{
                          scanf(" %s %d %d %lf",&b[bc].name,&b[bc].a,&b[bc].b,&b[bc].c);
                          bc++;
                    }
                    pt=getchar();
            }
            sort(p,p+pc,cmp1);
            sort(b,b+bc,cmp2);
            for(int j=0;j<pc;j++) printf("%c %s\n",'P',p[j].name);
            for(int j=0;j<bc;j++) printf("%c %s\n",'B',b[j].name);
            if(i+1!=ds)printf("=====\n");
    }
    return 0;
}
