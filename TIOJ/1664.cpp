#include <iostream>

using namespace std;

char s[7][20];
int main(){
    int n;
    strcat(s[0], "Friday");
    strcat(s[1], "Saturday");
    strcat(s[2], "Sunday");
    strcat(s[3], "Monday");
    strcat(s[4], "Tuesday");
    strcat(s[5], "Wednesday");
    strcat(s[6], "Thursday");
    while( scanf("%d", &n)==1 )
        puts(s[n%7]);
    return 0;
}