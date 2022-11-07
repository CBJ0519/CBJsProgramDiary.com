#include<iostream>
#include<string>  //內含string
#include<vector>  //內含vector
#include<algorithm>  //內含find()(用於尋找的函數)
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    vector<char>in_b;   
    for(char c:b)in_b.push_back(c);  //將b的所有內容丟入in_b
    
    int Jia=0,Yi=0;
    for(int i=0;i<a.length();i++){   //遍歷a
        if(a[i]==b[i]){  //假如同個位置有同個值
            Jia++;   //更新甲
            continue;  //跳過檢查乙特性
        }
        
        auto target=find(in_b.begin(),in_b.end(),a[i]);  //找尋a[i]是否有在b裡
        if(target!=in_b.end()){  //若回傳值不是in_b.end(),則表示有找到
            Yi++;  //更新乙
        }
    }
    
    cout<<Jia<<" "<<Yi<<"\n";  //輸出甲,乙
    return 0;
}
