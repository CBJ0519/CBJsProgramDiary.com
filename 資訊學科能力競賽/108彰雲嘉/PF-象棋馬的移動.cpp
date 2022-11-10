#include<iostream>
#include<utility>   //內含pair
#include<queue>   //內含queue
#include<tuple>  //內含tuple
#include<map>  //內含map
using namespace std;

pair<int,int>target;   //終點位置{x,y}
int X,Y;   //X*Y的座標平面

bool inrange(int x,int y){  //判斷是否x,y都仍在範圍內
    return x>=0 && x<X && y>=0 && y<Y;
}

int dir[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};  //移動方式(8個方向)

int bfs(int x,int y){   //廣度優先搜尋
    queue<tuple<int,int,int>>q;   //存放{當前x值,當前y值,走到此處花的步數}
    q.push({x,y,0});  //丟入起點資訊
    map<pair<int,int>,bool>visited; //紀錄是否走訪過(不重複走訪)
    
    //bfs模板
    while(!q.empty()){
        x=get<0>(q.front());
        y=get<1>(q.front());
        int step=get<2>(q.front());
        
        if(make_pair(x,y)==target)return step;  //假如找到終點，則此時的step必是最短距離(bfs的特性)
        q.pop();
        
        //將新的點丟入queue(未來的走訪對象)
        for(auto i:dir){ 
            int newx=x+i[0],newy=y+i[1];
            if(inrange(newx,newy) && !visited[{newx,newy}]){
                q.push({newx,newy,step+1});
                visited[{newx,newy}]=true;
            }
        }
    }
    return -1;  //因為宣告的是回傳int，所以函式尾端要return一個數值(但此處不會執行到)
}
int main(){
    int n;cin>>n;
    while(n--){
        int a,b,c,d;
        cin>>X>>Y>>a>>b>>c>>d;  //讀入資料
        target={c,d};  //設定目標
        cout<<bfs(a,b)<<"\n";  //輸出bfs()的回傳值(step)
    }
    return 0;
}
