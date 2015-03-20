#include <cstdio>
#include <cstring>

using namespace std;

char s[10000], s1[10000], s2[10000];
int main(){
    char *ptr;
    int i, j, n, l, si, si2, nc;
    scanf("%d\n", &n);
    while( n-- )
    {
        si=si2=0;
        gets(s);
        ptr=strtok(s, " "); ptr=strtok(NULL, " ");
        while( strcmp(ptr, "THEN")!=0 )
        {
            nc=0;
            while( strcmp(ptr, "not")==0 )
            {
                nc++;
                ptr=strtok(NULL, " ");
            }
            if( nc%2==0 ){ s1[si]=' '; s1[si+1]='n'; s1[si+2]='o'; s1[si+3]='t'; si+=4; }
            l=strlen(ptr);
            s1[si]=' ';
            for( i=0; i<l; i++ )
                s1[si+i+1]=ptr[i];
            si+=l+1;
            ptr=strtok(NULL, " ");
            if( strcmp(ptr, "THEN")==0 )
                break;
            else if( strcmp(ptr, "or")==0 )
                { s1[si]=' '; s1[si+1]='a'; s1[si+2]='n'; s1[si+3]='d'; si+=4; }
            else if( strcmp(ptr, "and")==0 )
                { s1[si]=' '; s1[si+1]='o'; s1[si+2]='r'; si+=3; }
            ptr=strtok(NULL, " ");
        }
        s1[si]='\0';
        ptr=strtok(NULL, " ");
        while( ptr!=NULL )
        {
            nc=0;
            while( strcmp(ptr, "not")==0 )
            {
                nc++;
                ptr=strtok(NULL, " ");
            }
            if( nc%2==0 ){ s2[si2]=' '; s2[si2+1]='n'; s2[si2+2]='o'; s2[si2+3]='t'; si2+=4; }
            l=strlen(ptr);
            s2[si2]=' ';
            for( i=0; i<l; i++ )
                s2[si2+i+1]=ptr[i];
            si2+=l+1;
            ptr=strtok(NULL, " ");
            if( ptr==NULL ) break;
            else if( strcmp(ptr, "or")==0 )
                { s2[si2]=' '; s2[si2+1]='a'; s2[si2+2]='n'; s2[si2+3]='d'; si2+=4; }
            else if( strcmp(ptr, "and")==0 )
                { s2[si2]=' '; s2[si2+1]='o'; s2[si2+2]='r'; si2+=3; }
            ptr=strtok(NULL, " ");
        }
        s2[si2]='\0';
        printf("IF%s THEN%s\n", s2, s1);
    }
    return 0;
}
