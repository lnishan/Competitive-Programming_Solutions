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
                   cout << "�Ӧ����F��!�����Q���ڦ��I";
                }else{
                    cout << "���ˤj�H!���ˤj�H!�ڧ֨�F�I";
                }
            }else{
                  if(x1==x2 && x2==x3 && (y2>y3 && y3>y1 || y2<y3 && y3<y1))
                            cout << "�Ӧ����F��!�����Q���ڦ��I";
                  else
                      cout << "���ˤj�H!���ˤj�H!�ڧ֨�F�I";
            }
            cout << endl;
    }
    return 0;
}
// << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3
