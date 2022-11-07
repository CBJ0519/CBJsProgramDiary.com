#include<stdio.h>
int main(){
    int year;
    while(scanf("%d",&year)!=EOF){ //讀到EOF(檔案結尾)
        //閏年判斷式
        if((year%4==0 && year%100) || year%400==0) printf("閏年\n");
        //否則
        else printf("平年\n");
    }
    return 0;
}
