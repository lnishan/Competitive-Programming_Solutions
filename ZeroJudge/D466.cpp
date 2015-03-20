/**********************************************************************************/
/*  Problem: d466 "今天是第幾天呢" from 麗山高中迴圈36題            */
/*  Language: C++                                                                 */
/*  Result: AC (6ms, 702KB) on ZeroJudge                                          */
/*  Author: linishan at 2009-12-03 21:47:36                                       */
/**********************************************************************************/


#include<iostream>
using namespace std;
int main(){
    int am[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int y,m,d;
    while(cin>>y>>m>>d){
        if((y%4==0 && y%100!=0)||(y%400==0)) am[2]=29; else am[2]=28;
        if(d>am[m] || m>12 || y<1 || m<1 || d<1){
            cout << "Error" << endl;
        }else{
            int c=0;
            for(int i=1;i<m;i++)
                c+=am[i];
            c+=d;
            cout << "It is " << c << ((c==1)?" day":" days") << " in " << y << endl;
        }
    }
    return 0;
}

