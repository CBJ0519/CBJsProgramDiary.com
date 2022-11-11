#include<bits/stdc++.h>
#define int long long
using namespace std;
int m,base[100][100],ans=1e18;

vector<vector<pair<int,int>>>v={ { {0,0},{0,1},{0,2},{-1,1} },
                                 { {0,0},{0,1},{0,2},{1,1} },
                                 { {0,0},{0,1},{-1,1},{1,1} },
                                 { {0,0},{0,1},{-1,0},{1,0} } };
void solve(int n){
    switch(n){
    case 0:{
        for(int i=1;i<=m-1;i++){
            for(int j=0;j<=m-3;j++){
                int sum=0;
                for(pair<int,int> p:v[0]){
                    int newx=p.first;
                    int newy=p.second;

                    sum += base[i+newx][j+newy];
                }

                ans=min(ans,sum);
            }
        }
    }break;
    case 1:{
        for(int i=0;i<=m-2;i++){
            for(int j=0;j<=m-3;j++){
                int sum=0;
                for(pair<int,int> p:v[1]){
                    int newx=p.first;
                    int newy=p.second;

                    sum += base[i+newx][j+newy];
                }

                ans=min(ans,sum);
            }
        }
    }break;
    case 2:{
        for(int i=1;i<=m-2;i++){
            for(int j=0;j<=m-2;j++){
                int sum=0;
                for(pair<int,int> p:v[2]){
                    int newx=p.first;
                    int newy=p.second;

                    sum += base[i+newx][j+newy];
                }

                ans=min(ans,sum);
            }
        }
    }break;
    case 3:{
        for(int i=1;i<=m-2;i++){
            for(int j=0;j<=m-2;j++){
                int sum=0;
                for(pair<int,int> p:v[3]){
                    int newx=p.first;
                    int newy=p.second;

                    sum += base[i+newx][j+newy];
                }

                ans=min(ans,sum);
            }
        }
    }break;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>m;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>base[i][j];
        }
    }
    for(int i=0;i<4;i++){
        solve(i);
    }

    cout<<ans<<"\n";

    return 0;
}
/*
4
2 5 2 7
3 2 5 8
1 2 3 9
8 2 1 2
*/
