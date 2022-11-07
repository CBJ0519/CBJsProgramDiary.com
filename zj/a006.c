//C++ language
//solution link(含註解): https://github.com/CBJ0519/CBJsProgramDiary.com/blob/main/zj/a006.cpp
#include<iostream>
#include<cmath> //等於C語言的<math.h>，內含sqrt()(開根號工具)
#include<algorithm> //內含max()(求最大值), min()(求最小值)
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int judge=b*b-(4*a*c);  //判斷式
    if(judge<0){  //無實數根
        printf("No real root\n");
        exit(0);  //結束程式(也可用 return 0)
    }

    //計算兩根(+,-)
    int root1=(-b + sqrt(judge))/(2*a);
    int root2=(-b - sqrt(judge))/(2*a);

    //假如重根
    if(root1==root2) cout<<"Two same roots x="<<root1<<"\n";
    //否則找出值較大的根放前面
    else cout<<"Two different roots x1="<<max(root1,root2)<<" , x2="<<min(root1,root2)<<"\n";
    return 0;
}
