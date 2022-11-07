#include<stdio.h>
int main(){
    char s[1000];  //曾嘗試宣告100的大小，但輸入不只100(題目沒有提到，所以要自己試)
    
    //fgets(存放的字串,輸入大小(允許高估),輸入流(反正就填stdin(標準輸入)就對了))
    fgets(s,1001,stdin);  //讀入字元陣列
    
    for(int i=0;s[i]!='\n';i++){  //終止條件為s[i]為換行字元時(fgets會把'\n'一起讀進來)
        s[i]=s[i]-7;  //關鍵轉換式
    }
    
    printf("%s",s);  //輸出s, 不需換行(fgets已經吃一個'\n'了)
    return 0;
}
