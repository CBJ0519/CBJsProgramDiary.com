#include<iostream>
#include<utility>   //內含pair
#define MAXN 10005   //預先設定最大邊長
using namespace std;

pair<int,int>start;
char square[MAXN][MAXN];
int N;

bool check_right(){   //以start為起點往右下走
    int x=start.first,y=start.second;
    char pivot=square[x][y];  //中樞(起點的字)
    
    while(x<N && x>=0 && y<N && y>=0){
        if(square[x][y]!=pivot){  //出現和起點不同的字
            return false;  //失敗
        }
        x++; y++;  //更新x,y狀態
    }
    
    return true;
}
bool check_left(){    //以start為起點往左下走
    int x=start.first,y=start.second;
    char pivot=square[x][y];  //中樞(起點的字)
    
    while(x<N && x>=0 && y<N && y>=0){
        if(square[x][y]!=pivot){  //出現和起點不同的字
            return false;  //失敗
        }
        x++; y--;  //更新x,y狀態
    }
    
    return true;  //成功
}
int main(){
    int a;cin>>a;  //輸入邊長
    
    while(a--){
        cin>>N;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>square[i][j];  //讀入矩陣內容
            }
        }
        
        
        //檢查每個對角線(只有一個點的case不叫對角線,不必檢查)
        int cnt=0;
                                 //(O為檢查的部分(往右下))
        for(int i=0;i<N-1;i++){     //O _ _ _ _
            start={i,0};            //O O _ _ _
            if(check_right())cnt++; //O O O _ _
        }                           //O O O O _
                                    //_ O O O O
        
                                 //(O為檢查的部分(往右下))
        for(int j=1;j<N-1;j++){     //_ O O O _
            start={0,j};            //_ _ O O O
            if(check_right())cnt++; //_ _ _ O O
        }                           //_ _ _ _ O
                                    //_ _ _ _ _
        
                                  //(O為檢查的部分(往左下))
        for(int j=1;j<N;j++){       //_ O O O O
            start={0,j};            //O O O O _
            if(check_left())cnt++;  //O O O _ _
        }                           //O O _ _ _
                                    //O _ _ _ _
                                    
                                  //(O為檢查的部分(往左下))
        for(int i=1;i<N-1;i++){     //_ _ _ _ _
            start={i,N-1};          //_ _ _ _ O
            if(check_left())cnt++;  //_ _ _ O O
        }                           //_ _ O O O
                                    //_ O O O _
                                    
        cout<<cnt<<"\n";  //輸出答案
    }
    return 0;
}
