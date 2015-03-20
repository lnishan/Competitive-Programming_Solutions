#include <iostream>

using namespace std;

char s[7][10], ss[10];
int main(){
    int i, a, b;
    strcat(s[0],"Sunday");
    strcat(s[1],"Monday");
    strcat(s[2],"Tuesday");
    strcat(s[3],"Wednesday");
    strcat(s[4],"Thursday");
    strcat(s[5],"Friday");
    strcat(s[6],"Saturday");
    gets(ss);
    for( i=0; i<7; i++ )
        if( strcmp(ss, s[i])==0 )
        {
            a=i;
            break;
        }
    scanf("%d", &b);
    a+=b; a%=7;
    printf("%s\n", s[a]);
    //while(1);
    return 0;
}