#include <cstdio>
#include <cstring>

using namespace std;

char s[205];
int a[11], b[11], tmp[11];

void add(int s, int e)
{
    int i;
    for( i=s; i<=e; i++ )
    {
        if( a[i]==0 ) b[i]++;
        a[i]++;
    }
    return ;
}

void proc(char c){
    switch(c)
    {
        case 'c':
            add(2, 4);
            add(7, 10);
            break;
        case 'd':
            add(2, 4);
            add(7, 9);
            break;
        case 'e':
            add(2, 4);
            add(7, 8);
            break;
        case 'f':
            add(2, 4);
            add(7, 7);
            break;
        case 'g':
            add(2, 4);
            break;
        case 'a':
            add(2, 3);
            break;
        case 'b':
            add(2, 2);
            break;
        case 'C':
            add(3, 3);
            break;
        case 'D':
            add(1, 4);
            add(7, 9);
            break;
        case 'E':
            add(1, 4);
            add(7, 8);
            break;
        case 'F':
            add(1, 4);
            add(7, 7);
            break;
        case 'G':
            add(1, 4);
            break;
        case 'A':
            add(1, 3);
            break;
        case 'B':
            add(1, 2);
    }
    return ;
}

int main()
{
    int i, j, t, l;
    scanf("%d", &t);
    scanf("\n");
    while( t-- )
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        gets(s);
        l=strlen(s);
        proc(s[0]);
        for( i=1; i<l; i++ )
        {
            proc(s[i]);
            for( j=1; j<=10; j++ )
                tmp[j]=b[j];
            memset(a, 0, sizeof(a));
            proc(s[i]);
            for( j=1; j<=10; j++ )
                b[j]=tmp[j];
        }
        for( i=1; i<=10; i++ )
        {
            if( i>1 ) putchar(' ');
            printf("%d", b[i]);
        }
        putchar('\n');
    }
    return 0;
}
