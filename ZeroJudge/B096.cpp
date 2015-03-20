#include<iostream>
using namespace std;
int php,patt,pdef,mhp,matt,mdef,wl;
int main(){
    while(cin>>php>>patt>>pdef>>mhp>>matt>>mdef && (php!=0||patt!=0||pdef!=0||mhp!=0||matt!=0||mdef!=0))
    {
        for(int i=1;;i++)
        {
                 mhp-=(patt-mdef);
                 if(mhp<=0) {wl=i; break;}
                 php-=(matt-pdef);
                 if(php<=0) {wl=-i; break;}
        }
        cout << "You " << ((wl>0)?"win":"lose") << " in " << ((wl>0)?wl:-wl) << " round(s)." <<endl;
    }
    return 0;
}
