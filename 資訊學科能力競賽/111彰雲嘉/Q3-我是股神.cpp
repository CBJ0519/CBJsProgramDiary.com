#include<bits/stdc++.h>
#define int long long
using namespace std;
int m;
vector<int>a,b;

//   solve({布基,布ㄓ方}, 讽玡柬, 讽玡ぱ计)
int solve(pair<int,char> stock, int profit, int day){
    //cout<<"solve( {"<<stock.first<<","<<stock.second<<"}, "<<profit<<","<<day<<")\n";
    if(profit<0) return -1e18;
    if(day == m){
        return profit;
    }
    if(stock.first != -1){
        if(stock.second == 'A')
            return max( solve({-1,'\0'}, profit+(a[day]-stock.first), day+1),
                        solve(stock, profit, day+1) );
        else{
            return max( solve({-1,'\0'}, profit+(b[day]-stock.first), day+1),
                        solve(stock, profit, day+1) );
        }
    }
    return max( solve({a[day],'A'}, profit, day+1),
                max(solve({b[day],'B'}, profit, day+1),
                    solve({-1,'\0'}, profit, day+1) ));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>m;
    for(int i=0;i<m;i++){
        int x;cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<m;i++){
        int x;cin>>x;
        b.push_back(x);
    }

    cout<<solve({-1,'\0'},0,0)<<"\n";

    return 0;
}
