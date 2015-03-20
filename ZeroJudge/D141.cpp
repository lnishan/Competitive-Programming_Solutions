#include<iostream>
using namespace std;
int main(){
    int n,ax,ay,bx,by,cx,cy;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            scanf("%d,%d %d,%d %d,%d",&ax,&ay,&bx,&by,&cx,&cy);
            if( (ax*by+bx*cy+cx*ay-ay*bx-by*cx-cy*ax)==0 )printf("collinear\n");else printf("not collinear\n");
    }
    return 0;
}
