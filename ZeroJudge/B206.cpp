#include<iostream>
#include<string>
using namespace std;
int main(){
    char ch;
    int n,ra,rb,ac,bc;
    scanf("%d",&n);ch=getchar();
    for(int i=0;i<n;i++)
    {
            ra=5;rb=5;ac=0;bc=0;
            while((ch=getchar())!='\n'){if(ch=='O')ac++;ra--;}
            while((ch=getchar())!='\n'){if(ch=='O')bc++;rb--;}
            if(ra<0||rb<0)
                          if(ra<rb){ra=0;rb=1;}else if(ra>rb){ra=1;rb=0;}else{ra=0;rb=0;}
            if(ac>bc+rb)printf("A\n");else if(bc>ac+ra)printf("B\n");else printf("NO\n");
    }
    return 0;
}
