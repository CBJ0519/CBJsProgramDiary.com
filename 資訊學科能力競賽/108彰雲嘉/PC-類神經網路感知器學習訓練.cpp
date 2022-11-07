#include<iostream>
#include<vector>   //內含vector
#include<tuple>   //內含tuple
#include<iomanip>  //內含fixed+setprecision()(控制輸出的小數點位數)
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

int main(){
    vector<tuple<double,double,double>>Cases;  //用來裝輸入的參數
    double W1,W2,b,alpha;
    int p,k;
    cin>>W1>>W2>>b>>alpha>>p>>k;  //讀取資料
    
    while(k--){  //k次輸入
        double X1,X2,Yd;
        cin>>X1>>X2>>Yd;  //輸入
        Cases.push_back({X1,X2,Yd});   //推入Cases
    }
    
    while(p--){  //p次更新(回合)
        for(auto Case:Cases){
            double X1=get<0>(Case);  //get<index>(tuple)可取得tuple第index個資料
            double X2=get<1>(Case);
            double Yd=get<2>(Case);
            
            //依題意計算
            double net=make_net(W1,X1,W2,X2,b);
            int Y=f(net);
            double ep=squ_loss_f(Yd,Y);
            
            //更新
            W1=W1+(alpha*ep*X1);
            W2=W2+(alpha*ep*X2);
        }
    }
    cout<<fixed<<setprecision(2)<<W1<<" "<<W2<<"\n";  //以小數點後2位的方式輸出(fixed + setprecision)
    return 0;
}
