#include<iostream>

//預先定義最大的N和K
#define MAXN 1000
#define MAXK 1000

using namespace std;

int cost[MAXN][MAXK];  //定義為第i個人完成第j個服務時累積的時間
int self[MAXN][MAXK];  //定義為第i個人需要在第j個櫃台待多久( = 輸入的資料 )

int main(){
    int N,K;
    cin>>N>>K;
    
    //讀入資料
    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            cin>>self[i][j];
        }
    }
    
    //處理初始狀態
    for(int i=0;i<=N;i++){
        cost[i][0]=0;
    }
    for(int j=0;j<=K;j++){
        cost[0][j]=0;
    }
    
    //DP轉移式
    for(int i=0;i<=N;i++){
        for(int j=0;j<=K;j++){
            cost[i][j]=max(cost[i-1][j],cost[i][j-1])+self[i][j];
        }
    }
    
    cout<<cost[N][K]<<"\n";  //輸出答案
    return 0;
}
