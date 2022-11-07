#include<bits/stdc++.h>
#define int long long
#define MAXN 10005
using namespace std;
pair<int,int>start;
char square[MAXN][MAXN];
int N;
bool check_right(){
    int x=start.first,y=start.second;
    char pivot=square[x][y];
    while(x<N && x>=0 && y<N && y>=0){
        if(square[x][y]!=pivot){
            return false;
        }
        x++;y++;
    }
    return true;
}
bool check_left(){
    int x=start.first,y=start.second;
    char pivot=square[x][y];
    while(x<N && x>=0 && y<N && y>=0){
        if(square[x][y]!=pivot){
            return false;
        }
        x++;y--;
    }
    return true;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int a;cin>>a;
    while(a--){
        cin>>N;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>square[i][j];
            }
        }
        int cnt=0;
        for(int i=0;i<N-1;i++){
            start={i,0};
            if(check_right())cnt++;
        }
        for(int j=1;j<N-1;j++){
            start={0,j};
            if(check_right())cnt++;
        }
        for(int j=1;j<N;j++){
            start={0,j};
            if(check_left())cnt++;
        }
        for(int i=1;i<N-1;i++){
            start={i,N-1};
            if(check_left())cnt++;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
/*
1
5
A B C D E
B A B C D
C B A B C
D C C A B
E D C B A
*/
