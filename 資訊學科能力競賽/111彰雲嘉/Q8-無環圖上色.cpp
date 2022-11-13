#include<iostream>
#include<map>   //內含map
#include<utility>  //內含pair
#include<vector>   //內含vector
#include<queue>  //內含queue
#include<set>   //內含set
#include<unordered_set>   //內含unordered_set
#include<algorithm>  //內含sort()(排序函式)
using namespace std;

int n,m;
map<char,int> order;  //定義彩虹順序(詳見79,80行)

//排序比較函式(依照彩虹順序排序)
bool cmp(pair<char,int> &a, pair<char,int> &b){
    return order[a.first] < order[b.first];
}

//無環圖的結點
struct node{
    int num;  //編號
    vector<int> linked;  //有連結的點
    char color_with_prev;  //和(走訪順序)前一個結點連線的顏色
};

map<int,node*> nodes;  //map[i]存放編號是i的節點
map<char,int>times;  //存放顏色被塗的次數

//找到目標後回溯回去起點，中途對線段上色
void trace(int now, int target, map<int,node*> &prev, char color){
    if(now==target) return;  //已經回到起點，結束trace()
    
    if(color != nodes[now]->color_with_prev){  //假如線段顏色不同於要塗的顏色
        nodes[now]->color_with_prev=color;  //塗色
        times[color]++;      //該顏色次數++
    }
    
    trace( prev[ nodes[now]->num ] -> num, target, prev, color);   //往回一層
}

//bfs(起點, 終點, 顏色)
void bfs(int from,int to,char color){
    
    //bfs必備工具
    queue<node*>q;
    set<node*>visited;
    
    //map[i]紀錄i的前一個結點
    map<int,node*> prev;
    
    //bfs核心
    q.push(nodes[from]);
    while(!q.empty()){
        node* cur=q.front();  //現在走訪到的節點
        
        //假如已經找到終點
        if(nodes[cur->num] == nodes[to]){
            trace(to, from, prev, color);  //回溯並塗色
        }
        
        //紀錄為已走訪
        visited.insert(nodes[cur->num]);
        
        for(int a:nodes[cur->num]->linked){  //走訪相鄰的點
            if(visited.find(nodes[a]) != visited.end()){   //已經拜訪過
                continue;
            }
            
            q.push(nodes[a]);
            prev[a]=cur;  //所有相鄰的點的上一層都是cur(以走訪順序來說)
        }
        q.pop();
    }
}
int main(){
    times['R']=times['O']=times['Y']=times['G']=times['B']=times['I']=times['V']=0;  //初始化次數為0
    
    //定義彩虹順序(排序會使用到)
    order['R']=0; order['O']=1; order['Y']=2;
    order['G']=3; order['B']=4; order['I']=5; order['V']=6;
    
    //去除重複用
    unordered_set<int>st;
    
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        
        //假如現在的x之前沒有輸入過，則要開一個新結點
        if(st.find(x)==st.end()){
            nodes[x]=new node;   //開新結點
            nodes[x]->num=x;  //編號 = x
        }
        
        //將x和y相鄰
        nodes[x]->linked.push_back(y);
        
        //作法同x
        if(st.find(y)==st.end()){
            nodes[y]=new node;
            nodes[y]->num=y;
        }
        
        nodes[y]->linked.push_back(x);
        
        //紀錄為曾經輸入過
        st.insert(x);
        st.insert(y);
    }
    
    cin>>m;  //指令數
    while(m--){  //做m次
        int x,y;
        char c;
        cin>>x>>y>>c;   //讀入指令
        
        bfs(x,y,c);  //以x為起點到y,做bfs
    }
    
    vector<pair<char,int>> ans;  //存放答案
    for(char c:"ROYGBIV"){
        if(times[c] != 0) ans.push_back({c,times[c]});  //不是0的就丟入ans
    }
    
    //依照order[]來排序(題目要求)
    sort(ans.begin(),ans.end(),cmp);
    
    //輸出答案
    for(pair<char,int> p: ans){
        cout<<p.first<<" "<<p.second<<"\n";
    }
    
    return 0;
}
