#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;

map<char,int> order;
bool cmp(pair<char,int> &a, pair<char,int> &b){
    return order[a.first] < order[b.first];
}

struct node{
    int num;
    vector<int> linked;
    char color_with_prev;
};

map<int,node*> nodes;
map<char,int>times;

void trace(int now, int target, map<int,node*> &prev, char color){
    //cout<<"trace("<<now<<","<<target<<","<<color<<")\n";
    if(now==target) return;

    if(color != nodes[now]->color_with_prev){
        nodes[now]->color_with_prev=color;
        times[color]++;
    }

    trace(prev[nodes[now]->num]->num,target,prev,color);
}

void bfs(int from,int to,char color){
    //cout<<"bfs("<<from<<","<<to<<","<<color<<")\n";
    queue<node*>q;
    set<node*>visited;
    map<int,node*> prev;

    q.push(nodes[from]);
    while(!q.empty()){
        node* cur=q.front();

        if(nodes[cur->num] == nodes[to]){
            trace(to,from,prev,color);
        }

        visited.insert(nodes[cur->num]);

        for(int a:nodes[cur->num]->linked){
            if(visited.find(nodes[a]) != visited.end()){
                continue;
            }
            q.push(nodes[a]);
            prev[a]=cur;
        }

        q.pop();
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    times['R']=times['O']=times['Y']=times['G']=times['B']=times['I']=times['V']=0;
    order['R']=0; order['O']=1; order['Y']=2;
    order['G']=3; order['B']=4; order['I']=5; order['V']=6;

    unordered_set<int>st;
    cin>>n;
    for(int i=1;i<n;i++){

        int x,y;
        cin>>x>>y;

        if(st.find(x)==st.end()){
            nodes[x]=new node;
            nodes[x]->num=x;
        }

        nodes[x]->linked.push_back(y);

        if(st.find(y)==st.end()){
            nodes[y]=new node;
            nodes[y]->num=y;
        }

        nodes[y]->linked.push_back(x);

        st.insert(x);
        st.insert(y);
    }

    cin>>m;
    while(m--){
        int x,y;
        char c;
        cin>>x>>y>>c;
        bfs(x,y,c);
    }

    vector<pair<char,int>> ans;

    for(char c:"ROYGBIV"){
        if(times[c] != 0) ans.push_back({c,times[c]});
    }

    sort(ans.begin(),ans.end(),cmp);

    for(pair<char,int> p: ans){
        cout<<p.first<<" "<<p.second<<"\n";
    }

    return 0;
}
/*
8
0 1
1 2
1 3
3 4
4 5
4 6
4 7
4
0 7 B
2 0 B
3 7 R
5 7 V

0:{1}
1:{0,2,3}
2:{1}
3:{1,4}
4:{3,5,6,7}
5:{4}
6:{4}
7:{4}
*/
