#include<iostream>
using namespace std;
int main(){
    char s[1000];   //曾嘗試宣告100的大小，但輸入不只100(題目沒有提到，所以要自己試)

    //fgets(存放的字串,輸入大小(允許高估),輸入流(反正就填stdin(標準輸入)就對了))
    fgets(s,1001,stdin); //讀入字元陣列

    for(char &c:s){  //遍歷s(記得c前面要加&, 因為會更改c的值)
        if(c=='\n') break;  //終止條件
        c-=7;  //更改值(如果沒有&, 則此行無作用)
    }

    cout<<s;  //輸出s(自帶換行)
    return 0;
}
