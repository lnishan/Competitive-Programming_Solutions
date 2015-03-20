/**********************************************************************************/
/*  Problem: d053 "10970 - Big Chocolate" from UVa ACM 10970                      */
/*  Language: C++                                                                 */
/*  Result: CE on ZeroJudge                                                       */
/*  Author: linishan at 2010-02-09 10:38:54                                       */
/**********************************************************************************/

#include<iostream>
using namespace std;
int main(){
int m,n;
while(scanf("%d%d",&m,&n)==2)printf("%d\n",(m-1)+(n-1)*m);
return 0;}
