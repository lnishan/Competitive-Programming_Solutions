#include <iostream>

using namespace std;

int main(){
    freopen("Q599_output.txt","w",stdout);
    for(int i=0;i<14;i++)
        for(int j=0;j<=26-i*2;j++)
            printf("strcat(o[%d][%d],\"There are %d tree(s) and %d acorn(s).\");\n",i,j,i,j);
    return 0;
}
