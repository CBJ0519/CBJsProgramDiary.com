#include<iostream>
#include<algorithm>  //內含sort()(排序函式)
#include<queue>   //內含priority_queue(優先佇列)
using namespace std;
int main(){
    int n;
    while(cin>>n){
        if(!n) break;  //假如n==0則break(技巧寫法)(not 0 = not false = true -> 啟動if)
        priority_queue<int,vector<int>,greater<int>>digits;  //傳說中的優先佇列(C沒有所以很麻煩)

        //讀資料放入digits
        for(int i=0;i<n;i++){
            int x; cin>>x;
            digits.push(x);
        }

        //設定ans初始為0(記得開long long(題目有提到))
        long long ans=0;

        //當digits剩一個的時候終止迴圈
        while(digits.size()>1){
            //取出前兩個數, 並pop()掉
            int a=digits.top();
            digits.pop();
            int b=digits.top();
            digits.pop();
  
            //更新答案
            ans+=(a+b);

            //把a+b丟回去
            digits.push(a+b);
        }
        cout<<ans<<"\n";  //輸出答案
    }
    return 0;
}
