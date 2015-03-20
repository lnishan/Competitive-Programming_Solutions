#include <iostream>

using namespace std;

int main(){
    int t, son, mom, c;
    scanf("%d", &t);
    while( t-- )
    {
        c=0;
        scanf("%d%d", &son, &mom);
        printf("%d/%d = ", son, mom);
        while(1)
        {
            printf("%d", son/mom);
            if( son%mom==0 )
                break;
            else
            {
                son%=mom;
                printf("+1/");
                swap(son, mom);
                if( son%mom!=0 ){ putchar('{'); c++; }
            }
        }
        while( c-- )
            putchar('}');
        putchar('\n');
    }
    return 0;
}