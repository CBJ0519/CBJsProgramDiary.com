#include<iostream>
using namespace std;
int main(){
    int year;
    while(cin>>year){ //讀到不能讀為止
        //閏年判斷式
        if((year%4==0 and year%100) or year%400==0) cout<<"閏年\n";
        //否則
        else cout<<"平年\n";
    }
    return 0;
}
