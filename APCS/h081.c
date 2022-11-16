#include<stdio.h>
int main(){
    //have=當前手上股票價格, now=現在有沒有股票(0->沒有, 1->有), profit=總利潤(答案)
    //n,D,price[101]=輸入資料, i,j=迴圈用, sell=上次賣出價
    int have,now,profit=0,n,D,i,j,sell=0,price[101];
    
    scanf("%d%d",&n,&D);  //讀入資料
    for(i=0;i<n;i++){
        scanf("%d",&price[i]);  //讀入股價數列
    }
    
    have = price[0];  //第一個一定要買
    now = 1;  //現在有股票
    
    //從index 1的地方開始到最後
    for(j=1;j<n;j++){
        //假如有股票
        if(now){
            //若符合題目要求的賣出條件
            if(price[j]>=(have+D)){
                profit+=(price[j]-have);  //更新利潤(現在股價-上次買入價)
                sell = price[j]; //更改上次的賣出價
                now = 0;  //現在沒有股票(已售出)
            }
        //若沒有股票且符合題目要求的買入條件
        }else if(price[j]<=(sell-D)){
            have = price[j];  //更新上次的買入價
            now = 1;  //現在持有股票(已買入)
        }
    }
    
    printf("%d\n",profit);  //輸出總利潤
}
