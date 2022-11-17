#include<iostream>
#include<string>  //內含string, to_string()(將值轉為字串(不一定是整數))
using namespace std;

string sum(string s){  //計算陣列總和，並回傳總和轉成字串的結果
    int ans=0;  //總和
    for(char i:s){  //遍歷s
        ans+=(i-'0');  //字元轉整數技巧(運用ASCII)
    }
    string ret=to_string(ans);  //將整數ans轉成字串存入ret
    return ret;  //回傳ret
}

string f(string s){
    if(s.length()==1) return s;  //題目所述的終止條件
    return f(sum(s));  //遞迴呼叫f(sum(s)) (依題目所述)
}

int main(){
    string n;
    while(cin>>n){  //反覆讀取
        if(n=="0") break;  //假如輸入字串為"0"，則結束程式(跳出迴圈)
        cout<<f(n)<<"\n";  //否則輸出f(n)
    }
    return 0;
}
