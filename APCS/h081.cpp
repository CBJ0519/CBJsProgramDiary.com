#include<iostream>
#include<vector>
using namespace std;
int main(){
    int have,now,profit=0,n,D,sell=0;
    cin>>n>>D;
    vector<int>price(101);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    have=price.front();
    now=1;
    for(int i=1;i<n;i++){
        if(now){
            if(price[i]>=have+D){
                profit+=price[i]-have;
                sell=price[i];
                now=0;
            }
        }
        else if(price[i]<=sell-D){
            have=price[i];
            now=1;
        }
    }
    cout<<profit<<"\n";
}
