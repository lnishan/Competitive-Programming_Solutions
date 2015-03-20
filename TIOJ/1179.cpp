#include <iostream>

using namespace std;

int main(){
    int a, t, tP, tM;
    while(1)
    {
        scanf("%d", &a);
        if( a==0 ) break;
        tP=1;
        tM=a;
        while( scanf("%d", &t) && t>0 )
        {
            tP++;
            tM+=t;
        }
        printf("%d %d %d\n", a, tP, tM);
    }
    return 0;
}