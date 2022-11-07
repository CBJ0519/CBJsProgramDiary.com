#include<bits/stdc++.h>
#define int long long
using namespace std;
pair<int,int>target;
int X,Y;
bool inrange(int x,int y){
    return x>=0 && x<X && y>=0 && y<Y;
}
int dir[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
int bfs(int x,int y){
    queue<tuple<int,int,int>>q;
    q.push({x,y,0});
    map<pair<int,int>,bool>visited;
    while(!q.empty()){
        x=get<0>(q.front());
        y=get<1>(q.front());
        int step=get<2>(q.front());
        if(make_pair(x,y)==target)return step;
        q.pop();
        for(auto i:dir){
            int newx=x+i[0],newy=y+i[1];
            if(inrange(newx,newy) && !visited[{newx,newy}]){
                q.push({newx,newy,step+1});
                visited[{newx,newy}]=true;
            }
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--){
        int a,b,c,d;
        cin>>X>>Y>>a>>b>>c>>d;
        target={c,d};
        int cnt=bfs(a,b);
        cout<<cnt<<"\n";
    }
    return 0;
}
