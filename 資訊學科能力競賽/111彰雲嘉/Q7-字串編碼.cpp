#include<iostream>
#include<string>  //內含string
using namespace std;

int main(){
    string s;
    getline(cin,s);  //因為輸入可能含有空白，所以用getline()讀
    
    char last=s[0];  //前一個字元
    int cnt=1;  //前一個字元出現次數
    
    //遍歷s
    for(int i=1;i<s.length();i++){
        //假如當前字元等於前一個字元
        if(s[i]==last) cnt++;
        else{
            //先輸出前面的統計結果
            cout<<cnt<<last;
            
            //將前一個字元改成當前字元，並將cnt歸回1(因為現在這個也要算)
            last=s[i];
            cnt=1;
        }
    }
    
    cout<<cnt<<last<<"\n";  //輸出最後沒被輸出的統計
    return 0;
}
