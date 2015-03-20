#include<iostream>
using namespace std;
int main(){
    int ns;
    char c;
    scanf("%d",&ns);
    while((c=getchar())!='\n');
    for(int i=0;i<ns;i++)
    {
            int clet=0,ct[2]={0,0},f;
            while((c=getchar())!='\n')
            {
                                      ct[clet%2]+=(c-48);
                                      clet++;
            }
            if(clet%2==1)f=ct[0]+ct[1]*2;else f=ct[0]*2+ct[1];
            if(f%3==0)printf("Yes\n");else printf("No\n");
    }
    return 0;
}
