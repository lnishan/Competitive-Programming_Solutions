#include <iostream>

using namespace std;

char s[1000], *ptr;

int main(){
    int i, j;
    for( i=1; i<=3; i++ )
    {
        gets(s);
        ptr=strtok(s, " ");
        for( j=1; ptr!=NULL; j++ )
        {
            if( strcmp(ptr, "BILL")==0 ) break;
            ptr=strtok(NULL, " ");
        }
        if( ptr!=NULL ) break;
    }
    if( ptr==NULL )
        puts("NO");
    else
        printf("%d %d\n", i, j);
    //while(1);
    return 0;
}
