#include <iostream>
using namespace std;
int main()
{
    int M,D;
    cin>>M>>D;  //讀入M,D
    int S=(M*2+D)%3;  //計算S
 
    // 以下這種寫法比 if ... else if ... else 省空間
 
    if(S){  //假如S不為0(false), 則S為1或2
        if(S==1) cout<<"吉\n";  //假如S為1
        else cout<<"大吉\n";  //否則S為2
    }
    else cout<<"普通\n";  //否則S為0
    return 0;
}
