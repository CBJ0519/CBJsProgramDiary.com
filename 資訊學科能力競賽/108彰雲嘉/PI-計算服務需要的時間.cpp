#include<bits/stdc++.h>
#define int long long
#define MAXN 1000
#define MAXK 1000
using namespace std;
int cost[MAXN][MAXK];
int self[MAXN][MAXK];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int N,K;
    cin>>N>>K;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            cin>>self[i][j];
        }
    }
    for(int i=0;i<=N;i++){
        cost[i][0]=0;
        for(int j=0;j<=K;j++){
            cost[0][j]=0;

            cost[i][j]=max(cost[i-1][j],cost[i][j-1])+self[i][j];

        }
    }
    cout<<cost[N][K]<<"\n";
    return 0;
}
