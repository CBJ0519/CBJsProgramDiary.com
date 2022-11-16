#include<iostream>
#include<vector>  //內含vector
#include<utility>  //內含pair
#include<string>  //內含string
using namespace std;

int main(){
    int n; cin>>n;  //讀入整數n
    vector<pair<int,int>>tmp;  //用來儲存{質因數,次方}
    
    for(int i=2;i<1e9;i++){  //從2跑到無限大(此處設無限大為1e9)
        if(n==1) break;  //終止條件
      
        int cnt=0;  //while迴圈執行次數=次方數
        while(not (n%i)){  //假如n%i==0，表示可整除 (not 0 = true)
            cnt++;  //次方++
            n/=i;  //更新n
        }
        if(cnt){  //假如cnt不為0(至少有1次方)
            tmp.push_back({i,cnt});  //將{i(必為質因數), cnt(必不為0)}推入tmp
        }
    }
    
    //走訪tmp
    for(int i=0;i<tmp.size();i++){
        if(i) cout<<" * "; //除了第一次輸出以外，其他次都要先在前面加上 *
        
        //取出有用到的質因數和次方數分別存入n和cnt
        int n=tmp[i].first;
        int cnt=tmp[i].second;
      
        //次方數大於1，需要另外輸出次方數
        if(cnt>1){
            cout<<n<<"^"<<cnt;
        }
        //否則次方數為1，不需輸出次方
        else{
            cout<<n;
        }
    }
    cout<<"\n";  //最後的換行符
    return 0;
}
