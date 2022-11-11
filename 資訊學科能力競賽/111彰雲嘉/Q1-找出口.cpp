#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int x;
    cin>>x;

    bool isneg=false;
    if(x<0) isneg=true;

    int now=0;
    int base=1;
    int dir=1;
    int times=0;
    while(1){
        if((isneg && now<=x) || (!isneg && now>=x)){
            break;
        }
        now+=base*base*dir;
        base++;
        dir*=-1;
        times++;
    }

    cout<<times<<"\n";

    return 0;
}
