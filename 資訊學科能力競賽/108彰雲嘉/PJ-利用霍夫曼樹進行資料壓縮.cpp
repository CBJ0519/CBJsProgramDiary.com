#include<iostream>
#include<map>   //內含map
#include<string>  //內含string
#include<unordered_set>   //內含unordered_set
#include<queue>  //內含priority_queue
using namespace std;

//霍夫曼樹
struct tree{
    int cnt=0;   //出現頻率
    char elm='\0';   //字元名稱
    tree* left=nullptr;  //左邊的子樹
    tree* right=nullptr;  //右邊的子樹
};

//比較函式(宣告priority_queue時用)
struct cmp{
    bool operator()(tree *a, tree *b){
        return a->cnt > b->cnt;
    }
};

//存放編碼
map<char,string>huffman;

//dfs(當前的位置, 當前的編碼)
void dfs(tree *now,string code){
    if(now->elm!='\0'){   //假如有字元
        huffman[now->elm]=code;  //將編碼給此字元
        return;   //結束此次函式
    }
    
    //假如左右子樹仍有辦法走訪，則繼續遞迴(左子樹的編碼加上0, 右子樹的編碼加上1)
    if(now->left){
        dfs(now->left,code+"0");
    }
    if(now->right){
        dfs(now->right,code+"1");
    }
    
}
int main(){
    string s;cin>>s;
    unordered_set<char>st;  //存放出現過的字元(去除重複)
    map<char,tree*>mp;  //存放內容為(char)的子樹
    
    //去除重複
    for(char c:s){
        st.insert(c);
    }
    
    //建樹
    for(char c:st){
        mp[c]=new tree;
        mp[c]->elm=c;
    }
    
    //計算頻率
    for(char c:s){
        mp[c]->cnt++;
    }
    
    //霍夫曼編碼實作(每次取頻率最小兩個合併)
    priority_queue<tree*,vector<tree*>,cmp>pq;
    
    //將所有樹推入優先佇列
    for(char c:st){
        pq.push(mp[c]);
    }
    
    //合併每棵樹成一棵
    while(pq.size()>1){
        tree *a=pq.top(); pq.pop();
        tree *b=pq.top(); pq.pop();
        tree *c=new tree;
        c->cnt=a->cnt+b->cnt;
        c->left=a;
        c->right=b;
        pq.push(c);
    }
    
    dfs(pq.top(), ""); //開始從root(優先佇列僅存的那一棵)開始dfs, 初始的編碼為空
    
    //計算答案
    int bits=0;
    for(char c:s){
        bits+=huffman[c].length();  //所求為編碼後字串的長度,因此用length()來取得
    }
    
    //原字串的 bit數 為 byte數*8 (1 byte = 8 bits)
    int before=s.length()*8;
    
    cout<<before<<" "<<bits<<" "<<(before-bits)*100/before<<"%\n";  //輸出答案
    return 0;
}
