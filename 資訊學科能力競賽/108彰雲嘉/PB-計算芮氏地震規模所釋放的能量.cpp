#include<iostream>
#include<iomanip>
#include<cmath>
#define TNT 4184000
using namespace std;
double trans(double d){
    return pow(10,d*1.5+4.8);
}
int main(){
    int n;cin>>n;
    while(n--){
        double d;
        cin>>d;
        double E=trans(d);
        cout<<fixed<<setprecision(1)<<E/(double)TNT<<"\n";
    }
    return 0;
}
