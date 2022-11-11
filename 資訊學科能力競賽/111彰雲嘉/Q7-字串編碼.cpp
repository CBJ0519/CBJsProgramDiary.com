#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    string s;
    getline(cin,s);

    char now=s[0];
    int cnt=1;
    for(int i=1;i<s.length();i++){
        if(s[i]==now) cnt++;
        else{
            cout<<cnt<<now;
            now=s[i];
            cnt=1;
        }
    }
    cout<<cnt<<now<<"\n";

    return 0;
}
