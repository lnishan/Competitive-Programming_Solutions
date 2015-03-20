#include <iostream>

using namespace std;

char m[20001];
int a,b,c;
bool y;

int main(){
    int i;
    while(scanf("%d%d%d",&a,&b,&c)==3)
    {
        for(i=1;i<=c*2;i++) m[i]=0;
        for(i=0;i<=c*2;i+=a)
            m[i]=1;
        for(i=0;i<=c*2-b;i++)
            if(m[i])
                m[i+b]=1;
        y=true;
        for(i=c;i<=c*2;i++)
            if(!m[i]){
                y=false;
                break;
            }
        puts(y?"Yes":"No");
    }
    return 0;
}
