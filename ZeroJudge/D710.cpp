#include <iostream>

using namespace std;

struct car{
    char brand[100],color[100];
};
car a[1000];
int n,m,c=0;
char type[100],res[100];

int main(){
    int i,j;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(c++>0) putchar('\n');
        for(i=0;i<n;i++)
            scanf("%s %s",&a[i].brand,&a[i].color);
        for(i=0;i<m;i++)
        {
            scanf("%s %s",&type,&res);
            if(type[0]=='b'){
                for(j=0;j<n;j++)
                    if(strcmp(a[j].brand,res)==0)
                        printf("%s %s\n",a[j].brand,a[j].color);
            }else{
                for(j=0;j<n;j++)
                    if(strcmp(a[j].color,res)==0)
                        printf("%s %s\n",a[j].brand,a[j].color);
            }
        }
    }
    return 0;
}
