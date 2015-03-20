#include <iostream>

using namespace std;

int main(){
    int t;
    char s[51];
    scanf("%d\n", &t);
    while( t-- )
    {
        gets(s);
        printf("%s, happy new year!!!\n", s);
    }
    return 0;
}