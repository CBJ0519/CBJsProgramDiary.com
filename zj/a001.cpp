#include<iostream>
#include<string> //使用string要記得include
using namespace std;
int main(){
    string s; //宣告字串叫做s
    cin>>s; //讀入測試資料存入s
    cout<<"hello, " + s; //輸出 "hello, " + s
    return 0;
}
