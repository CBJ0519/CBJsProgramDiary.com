#include<stdio.h>
int main(){
    char s[100]; //宣告字元陣列叫做s，大小為100
    scanf("%s",s); //讀入測試資料存入s
    printf("hello, %s\n",s); // 輸出 "hello, {s}"
    return 0;
}
