#include<iostream>
#include<iomanip>  //內含fixed+setpresision()(控制輸出的小數點位數)

//預先定義最大長寬
#define MAXI 100  
#define MAXJ 100

using namespace std;

int I,J; 
double table[MAXI][MAXJ];
double SA[MAXI]={0}, SB[MAXJ]={0};  //若要讓陣列內容全部為0可以這樣寫
double E[MAXI][MAXJ];

int main(){
    cin>>I>>J;
    double N=0, ans=0; 
    
    //根據題意進行填表和運算
    for(int i=0;i<I;i++){
        for(int j=0;j<J;j++){
            double a;
            cin>>a;
            table[i][j]=a;
            N+=a;
            SA[i]+=a;
            SB[j]+=a;
        }
    }
    
    //計算答案
    for(int i=0;i<I;i++){
        for(int j=0;j<J;j++){
            E[i][j]=(SA[i]*SB[j])/N;
            ans+=((table[i][j]-E[i][j])*(table[i][j]-E[i][j]))/E[i][j];
        }
    }
    
    //以小數點後2位的方式輸出(fixed + setprecision)
    cout<<fixed<<setprecision(2)<<ans<<"\n";
    return 0;
}
