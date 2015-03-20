#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int s;
    cin >> s;
    for(int i=0;i<s;i++){
            double x1,y1,x2,y2,x3,y3;
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            if(x2!=x1 && x3!=x2){
                if ( ((y2-y1)/(x2-x1))==((y3-y2)/(x3-x2)) && ( (x1<x3 && x3<x2) || (x1>x3 && x3>x2) ) ) {
                   cout << "該死的東西!竟敢想讓我死！";
                }else{
                    cout << "父親大人!母親大人!我快到了！";
                }
            }else{
                  if(x1==x2 && x2==x3 && (y2>y3 && y3>y1 || y2<y3 && y3<y1))
                            cout << "該死的東西!竟敢想讓我死！";
                  else
                      cout << "父親大人!母親大人!我快到了！";
            }
            cout << endl;
    }
    return 0;
}
// << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3
