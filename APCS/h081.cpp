#include<iostream>
#include<vector>  //內含vector
using namespace std;

int main(){
    //have=當前手上股票價格, now=現在有沒有股票(0->沒有, 1->有)
    //profit=總利潤(答案), n,D=輸入資料, sell=上次賣出價
    int have,now,profit=0,n,D,sell=0;
    
    cin>>n>>D;  //讀入資料
    vector<int>price(101);  //存放輸入的股價
    
    for(int i=0;i<n;i++){
        cin>>price[i];  //讀入股價
    }
    
    //第一個一定要買
    have=price.front();
    now=1;  //現在有股票
    
    //從index 1的地方開始到最後
    for(int i=1;i<n;i++){
        //假如有股票
        if(now){
            //若符合題目要求的賣出條件
            if(price[i]>=have+D){
                profit+=price[i]-have;  //更新利潤(現在股價-上次買入價)
                sell=price[i]; //更改上次的賣出價
                now=0;  //現在沒有股票(已售出)
            }
        }
        //若沒有股票且符合題目要求的買入條件
        else if(price[i]<=sell-D){
            have=price[i]; //更新上次的買入價
            now=1;  //現在持有股票(已買入)
        }
    }
    
    cout<<profit<<"\n";  //輸出總利潤
}
