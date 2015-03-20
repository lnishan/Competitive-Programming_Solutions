#include <iostream>

using namespace std;

int main(){
    char s[10];
    int n, c=0;
    scanf("%d\n", &n);
    while( n-- )
    {
        gets(s);
        if( s[2]==s[3] && s[3]==s[4] && s[4]==s[5] )
            c+=2000;
        else if( s[2]==s[3] && s[4]==s[5] )
            c+=1500;
        else if( (s[2]==s[3]&&s[3]==s[4])||(s[3]==s[4]&&s[4]==s[5]) )
            c+=1000;
    }
    printf("%d\n", c);
    //while(1);
    return 0;
}