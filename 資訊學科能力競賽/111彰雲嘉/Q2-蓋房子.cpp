#include<iostream>
#include<vector>  //內含vector
#include<utility>  //內含pair
using namespace std;

int m,base[100][100],ans=1e9;  //邊長m, 建地base. 答案ans

/*                             __     __
    __        ________      __|  |   |  |__
 __|  |__    |__    __|    |__   |   |   __|
|________|      |__|          |__|   |__| 

                              -1,1  -1,0
   -1,1      0,0 0,1 0,2   0,0 0,1   0,0 0,1
0,0 0,1 0,2      1,1           1,1   1,0

   v[0]         v[1]          v[2]   v[3]
*/
vector<vector<pair<int,int>>>v={ { {0,0},{0,1},{0,2},{-1,1} },   
                                 { {0,0},{0,1},{0,2},{1,1} },
                                 { {0,0},{0,1},{-1,1},{1,1} },
                                 { {0,0},{0,1},{-1,0},{1,0} } };

//solve(n)表示用v[n]的樣式來走訪建地
//此處用的是switch...case...break的寫法，但筆者當時比賽時是分成四個函式在寫
void solve(int n){
    switch(n){
    //此處只對case 0進行註解，因為另外三個都是一樣的做法
    case 0:{
        for(int i=1;i<=m-1;i++){     //case 0中i的範圍是1~m-1
            for(int j=0;j<=m-3;j++){  //case 0中j的範圍是0~m-3
              
                int sum=0;  //四格總和
                for(pair<int,int> p:v[n]){   //v[n] = v[0] = { {0,0},{0,1},{0,2},{-1,1} }
                    int newx=p.first;
                    int newy=p.second;
                  
                    sum += base[i+newx][j+newy];   //更新sum
                }
              
                ans=min(ans,sum);   //更新ans
            }
        }
    }break;
        
    case 1:{
        for(int i=0;i<=m-2;i++){
            for(int j=0;j<=m-3;j++){
                int sum=0;
                for(pair<int,int> p:v[n]){
                    int newx=p.first;
                    int newy=p.second;
                    sum += base[i+newx][j+newy];
                }
                ans=min(ans,sum);
            }
        }
    }break;
        
    case 2:{
        for(int i=1;i<=m-2;i++){
            for(int j=0;j<=m-2;j++){
                int sum=0;
                for(pair<int,int> p:v[n]){
                    int newx=p.first;
                    int newy=p.second;
                    sum += base[i+newx][j+newy];
                }
                ans=min(ans,sum);
            }
        }
    }break;
        
    case 3:{
        for(int i=1;i<=m-2;i++){
            for(int j=0;j<=m-2;j++){
                int sum=0;
                for(pair<int,int> p:v[n]){
                    int newx=p.first;
                    int newy=p.second;
                    sum += base[i+newx][j+newy];
                }
                ans=min(ans,sum);
            }
        }
    }break;
    }
}
int main(){
    cin>>m;  //輸入邊長
  
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>base[i][j];   //輸入建地成本
        }
    }
  
    for(int i=0;i<4;i++){
        solve(i);   //solve(0), solve(1), solve(2), solve(3)
    }
  
    cout<<ans<<"\n";   //輸出ans(最小成本)
    return 0;
}
