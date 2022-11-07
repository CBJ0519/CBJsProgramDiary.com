#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n; //讀入n
    while(n--){  //做n次
        int a,b,c,d; //宣告第1~4項
        int ans;
        cin>>a>>b>>c>>d; //輸入1~4項
 
        //假如是等差
        if((b-a)==(c-b) and (c-b)==(d-c)) ans=d+(d-c);
         
        //否則是等比
        else ans=d*(d/c);
 
        //輸出第5項(ans)
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<ans<<"\n";
    }
    return 0;
}
