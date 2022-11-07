#include<bits/stdc++.h>
#define int long long
using namespace std;
struct tree{
    int cnt=0;
    char elm='\0';
    tree* left=nullptr;
    tree* right=nullptr;
};
struct cmp{
    bool operator()(tree *a, tree *b){
        return a->cnt > b->cnt;
    }
};
map<char,string>huffman;
void dfs(tree *now,string code){
    if(now->elm!='\0'){
        huffman[now->elm]=code;
        return;
    }
    if(now->left){
        dfs(now->left,code+"0");
    }
    if(now->right){
        dfs(now->right,code+"1");
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s;cin>>s;
    unordered_set<char>st;
    map<char,tree*>mp;

    for(auto c:s){
        mp[c]=new tree;
        mp[c]->elm=c;
        mp[c]->cnt++;
        st.insert(c);
    }

    priority_queue<tree*,vector<tree*>,cmp>pq;
    for(char c:st){
        pq.push(mp[c]);
    }
    while(pq.size()>1){
        auto a=pq.top(); pq.pop();
        auto b=pq.top(); pq.pop();
        auto c=new tree;
        c->cnt=a->cnt+b->cnt;
        c->left=a;
        c->right=b;
        pq.push(c);
    }
    auto now=pq.top();
    dfs(now,"");
    int bits=0;
    for(char c:s){
        bits+=huffman[c].length();
    }
    int before=s.length()*8;
    cout<<before<<" "<<bits<<" "<<(before-bits)*100/before<<"%\n";
    return 0;
}
