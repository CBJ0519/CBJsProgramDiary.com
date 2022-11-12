#include<iostream>
#include<vector>  //內含vector
#include<utility>  //內含pair
#include<algorithm>  //內含max()(取兩數最大值)
using namespace std;

int m;  //天數
vector<int>a,b; //存放股價

//   solve({股票價格,股票來源}, 當前利潤, 當前天數)
int solve(pair<int,char> stock, int profit, int day){
    
    //終止條件
    if(day == m){
        return profit;
    }
    
    //假如手上有股票
    if(stock.first != -1){
        //假如手上是A股票
        if(stock.second == 'A')
            return max( solve({-1,'\0'}, profit+(a[day]-stock.first), day+1),   //賣掉A股票並進入下一天
                        solve(stock, profit, day+1) );  //跳過今天
        //否則是B股票
        else{
            return max( solve({-1,'\0'}, profit+(b[day]-stock.first), day+1),  //賣掉B股票並進入下一天
                        solve(stock, profit, day+1) );  //跳過今天
        }
    }
    
    //手上沒股票
    return max( solve({a[day],'A'}, profit, day+1),  //買A股票並進入下一天
                max(solve({b[day],'B'}, profit, day+1),  //買B股票並進入下一天
                    solve({-1,'\0'}, profit, day+1) ));  //跳過今天
}
int main(){
    cin>>m;  //輸入天數m
    
    //讀入A,B的內容(m天的股價)
    for(int i=0;i<m;i++){
        int x;cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<m;i++){
        int x;cin>>x;
        b.push_back(x);
    }
    
    cout<<solve({-1,'\0'},0,0)<<"\n";  //輸出答案
    
    return 0;
}
