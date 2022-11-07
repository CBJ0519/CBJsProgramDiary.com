//C++ language
#include<iostream>
#include<algorithm>  //內含fill()(填充函式，可填1)
#include<numeric>  //內含accumulate()(計算陣列總和)
using namespace std;
int main(){
    int L,M,a[10005];
    cin>>L>>M;
    fill(a,a+10005,1);  //用1填滿a
    while(M--){
        int start,end;
        cin>>start>>end;
        //[start,end]區間的樹全部拔除(填0)
        for(int i=start;i<=end;i++) a[i]=0;
    }
    //計算總和並輸出
    cout<<accumulate(a,a+L+1,0)<<"\n";
    return 0;
}
