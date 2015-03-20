#include <iostream>
#include <cstdlib>
#define NUM 5

using namespace std;

const int value[NUM]={1, 5, 10, 20, 50};

int main()
{
    int n, c, p[NUM], total, total2, r, r2, i, j, t;
    
    cin >> n;
    for (i=0; i<n; i++)
    {
        cin >> c;
        for (j=0, total=0; j<NUM; j++)
        {
            cin >> t;
            total+=(t*value[j]);
            p[j]=t;
        }
        for (j=0; j<NUM; j++)
        {
            cin >> t;
            p[j]+=t;
        }
        total-=c; // ³Ñ¤Uªº¿ú 
        j=NUM-1;
        t=total/value[j];
        if (t>p[j]) t=p[j];
        r=t;
        r2=t-1;
        total-=(value[j]*r);
        total2=total+value[j];
        for (j=NUM-2; j>=0; j--)
        {
            t=total/value[j];
            if (t>p[j]) t=p[j];
            r+=t;
            total-=(value[j]*t);
            t=total2/value[j];
            if (t>p[j]) t=p[j];
            r2+=t;
            total2-=(value[j]*t);
        }
        cout << ( ( total==0 ) ? r : r2 ) << endl;
    }
    
//    system("PAUSE");
    return 0;
}