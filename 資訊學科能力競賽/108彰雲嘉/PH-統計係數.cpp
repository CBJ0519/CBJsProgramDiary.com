#include<bits/stdc++.h>
#define int long long
#define double long double
#define MAXI 100
#define MAXJ 100
using namespace std;
int I,J;
double table[MAXI][MAXJ];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>I>>J;
    double N=0;
    double SA[MAXI]={0},SB[MAXJ]={0};
    double E[MAXI][MAXJ];
    double ans=0;
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
    for(int i=0;i<I;i++){
        for(int j=0;j<J;j++){
            E[i][j]=(double)(SA[i]*SB[j])/(double)N;
            ans+=((double)(table[i][j]-E[i][j])*(double)(table[i][j]-E[i][j]))/(double)E[i][j];
        }
    }
    cout<<fixed<<setprecision(2)<<ans<<"\n";
    return 0;
}
