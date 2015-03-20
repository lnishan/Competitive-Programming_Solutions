#include <iostream>
#include <ctype.h>

using namespace std;

char c=getchar();

int main(){
    if(isdigit(c))
        printf("\"Math\\");
    else if(isalpha(c))
        printf("\"English\\");
    else
        printf("\"Chinese\\");
    puts("n\"");
    return 0;
}
