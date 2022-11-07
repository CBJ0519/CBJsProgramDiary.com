#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
double make_net(double W1,double X1,double W2,double X2,double b){
    return W1*X1+W2*X2+b;
}
int f(double net){
    if(net>=0)return 1;
    return -1;
}
double squ_loss_f(double Yd,int Y){
    return 0.5*(Yd-Y)*(Yd-Y);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    vector<tuple<double,double,double>>Cases;
    double W1,W2,b,alpha;
    int p,k;
    cin>>W1>>W2>>b>>alpha>>p>>k;
    while(k--){
        double X1,X2,Yd;
        cin>>X1>>X2>>Yd;
        Cases.push_back({X1,X2,Yd});
    }
    while(p--){
        for(auto Case:Cases){
            double X1=get<0>(Case);
            double X2=get<1>(Case);
            double Yd=get<2>(Case);
            double net=make_net(W1,X1,W2,X2,b);
            int Y=f(net);
            double ep=squ_loss_f(Yd,Y);
            W1=W1+(alpha*ep*X1);
            W2=W2+(alpha*ep*X2);
        }
    }
    cout<<fixed<<setprecision(2)<<W1<<" "<<W2<<"\n";
    return 0;
}
/*
0.5 0.5 0.5 0.1 4 4 0 0 0 1 1 1 0 1 1 1 0 1

0.5 0.5 0.5 0.1 4 4 0 0 0 1 1 1 0 1 0 1 0 0

0.5 0.5 0.5 0.1 100 4 0 0 0 1 1 1 0 1 0 1 0 0
*/
