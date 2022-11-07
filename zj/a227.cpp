#include<iostream>
using namespace std;
//hanoi(char 起點, char 終點, char 另外那一個, int 環的數量, int 最上層的環編號)
void hanoi(char from, char to, char another, int amount, int num){
    if(amount==1){  //剩一個(終止條件)
        cout<<"Move ring "<<num<<" from "<<from<<" to "<<to<<"\n";
        return;
    }
    //先把上面擋住的都移到另一個去
    hanoi(from, another, to, amount-1, 1);
    //把最底下(編號n)的那個移到終點
    hanoi(from, to, another, 1, amount);
    //把剛剛丟去另一個的那些移到終點
    hanoi(another, to, from, amount-1, 1);
}
int main(){
    int n;
    while(cin>>n){ //讀到檔案結尾
        hanoi('A','C','B',n,1);  //根據定義傳入初始參數
    }
    return 0;
}
