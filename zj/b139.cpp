#include<iostream>
#include<algorithm>  //內含fill()(填充函式，可填1)
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
    int sum=0;
    //計算總和
    for(int i=0;i<=L;i++) sum+=a[i];
    cout<<sum<<"\n";
    return 0;
}
