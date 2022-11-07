#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(s.length()!=11){
            cout<<-1<<"\n";
            return 0;
        }
        int total=0;
        for(int i=0;i<s.length();i++){
            if(!isdigit(s[i])){
                cout<<-1<<"\n";
                return 0;
            }
            if(i%2){
                total+=s[i]-'0';
            }
            else{
                total+=(s[i]-'0')*3;
            }
        }
        int ans=10-(total%10);
        cout<<ans<<"\n";
    }
    return 0;
}
