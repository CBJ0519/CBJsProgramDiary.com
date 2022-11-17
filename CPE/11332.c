#include<stdio.h>
#include<ctype.h>  //內含isdigit()(判斷字元是否為整數)

char ret[11];  //儲存整數轉字串的結果

int len(char s[11]){  //計算字串長度
    int cnt=0;
    for(int i=0;isdigit(s[i]);i++){  //假如出現非數值，則結束for迴圈
        cnt++;
    }
    return cnt;
}

void sum(char s[11]){
    int ans=0;
    for(int i=0;isdigit(s[i]);i++){  //假如出現非數值，則結束for迴圈
        ans+=(s[i]-'0');  //字元轉數值技巧(運用ASCII)
    }
    sprintf(ret,"%d",ans);  //將整數ans轉成字串並用ret[]儲存
}

char* f(char s[11]){
    if(len(s)==1) return s;  //題目所述的終止條件
    sum(s);  //呼叫sum(s)來計算s的總和並更新ret
    return f(ret);  //遞迴呼叫f(字串總和)
}

int main(){
    char n[11];  //儲存輸入的字串
    while(scanf("%s",n)!=EOF){  //讀到輸入檔結尾(scanf中的n不需要加上&，因為陣列名稱本身就是位址)
        if(len(n)==1 && n[0]=='0') break;  //題目要求的中止輸入條件
        printf("%s\n",f(n));  //輸出f(n)的結果
    }
    return 0;
}
