/* 12/25/2010 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int main(){
    int i, n, nn;
    v.push_back(0);
    scanf("%d", &n);
    for( i=1; i<=n; i++ )
        v.push_back(i);
    nn=2;
    while( v.size()>2 )
    {
        /*
        for( i=0; i<v.size(); i++ )
            printf("%d ", v[i]);
        putchar('\n');
        */
        for( i=nn; ; i++ )
        {
            if( i<v.size() )
                v.erase(v.begin()+i);
            else
                break;
        }
        //printf("%d %d\n", i, v.size());
        if( i==v.size() ) nn=1; else nn=2;
    }
    printf("%d", v[1]);
    //while(1);
    return 0;
}
