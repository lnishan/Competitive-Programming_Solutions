#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1,s2;
    int c1=0,c2=0;
    while(cin>>s1>>s2 && (s1!="Game"&&s2!="Over"))
    {
                      if((s1=="Stone"&&s2=="Paper")||(s1=="Paper"&&s2=="Scissors")||(s1=="Scissors"&&s2=="Stone"))
                      {
                           printf("靈夢獲勝\n");
                           c1++;
                      }else{
                            printf("紫獲勝\n");
                            c2++;
                      }
    }
    if(c1>c2)printf("悲慘的籌措起香油錢");else printf("螢火的蹤跡");
    return 0;
}
