#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string a,b;
    cin>>a>>b;
    vector<char>in_b;
    for(char c:b)in_b.push_back(c);
    int Jia=0,Yi=0;
    for(int i=0;i<a.length();i++){
        if(a[i]==b[i]){
            Jia++;
            continue;
        }
        auto target=find(in_b.begin(),in_b.end(),a[i]);
        if(target!=in_b.end()){
            Yi++;
        }
    }
    cout<<Jia<<" "<<Yi<<"\n";
    return 0;
}
