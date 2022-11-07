#include<bits/stdc++.h>
#define int long long
#define double long double
#define TNT 4184000
using namespace std;
double trans(double d){
    return pow(10,d*1.5+4.8);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--){
        double d;
        cin>>d;
        double E=trans(d);
        cout<<fixed<<setprecision(1)<<E/(double)TNT<<"\n";
    }
    return 0;
}
/*
6
1.0
3.0
5.4
7.9
9.1
10.0
*/
