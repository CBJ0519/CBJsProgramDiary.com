#include<iostream>
#include<iomanip>  //內含fixed+setprecision()(控制輸出的小數點位數)
#include<cmath>  //內含pow()(計算次方)
#define TNT 4184000  //預先定義好TNT
using namespace std;

double trans(double d){
    return pow(10,d*1.5+4.8);  //回傳10的(d*1.5+4.8)次方
}
int main(){
    int n;cin>>n;  //輸入n
    while(n--){  //做n次
        double d;
        cin>>d;   //輸入芮氏規模
        double E=trans(d);  //計算E(能量)
        cout<<fixed<<setprecision(1)<<E/(double)TNT<<"\n";  //以小數點後1位的方式輸出(fixed + setprecision)
    }
    return 0;
}
