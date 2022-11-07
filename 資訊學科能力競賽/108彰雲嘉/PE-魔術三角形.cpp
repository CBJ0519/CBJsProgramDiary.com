#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<string>ans;
vector<bool>used(10,false);
vector<int>put(9);
int a,b,c;
/*
     0
    8 1
   7   2
  6 5 4 3
*/
bool legal(int i){
    return (i!=a && i!=b && i!=c);
}
bool cmp(string x,string y){
    return x<y;
}
void sattle(){
    int line1=put[0]+put[1]+put[2]+put[3];
    int line2=put[3]+put[4]+put[5]+put[6];
    int line3=put[6]+put[7]+put[8]+put[0];

    string cur_ans="";
    for(int i=0;i<=8;i++){
        cur_ans+=(char)(put[i]+'0');
    }

    if(line1==line2 && line2==line3){
        ans.push_back(cur_ans);
    }
    put.erase(put.begin(),put.end());
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>a>>b>>c;
    used[0]=used[a]=used[b]=used[c]=true;

    for(int i1=1;i1<=9;i1++){
        if(!legal(i1) || used[i1])continue;
        used[i1]=true;

        for(int i2=1;i2<=9;i2++){
            if(!legal(i2) || used[i2])continue;
            used[i2]=true;

            for(int i3=1;i3<=9;i3++){
                if(!legal(i3) || used[i3])continue;
                used[i3]=true;

                for(int i4=1;i4<=9;i4++){
                    if(!legal(i4) || used[i4])continue;
                    used[i4]=true;

                    for(int i5=1;i5<=9;i5++){
                        if(!legal(i5) || used[i5])continue;
                        used[i5]=true;

                        for(int i6=1;i6<=9;i6++){
                            if(!legal(i6) || used[i6])continue;

                            put[0]=i1; put[1]=a; put[2]=i2; put[3]=i3;
                            put[4]=b; put[5]=i4; put[6]=i5; put[7]=c; put[8]=i6;

                            sattle();

                        }

                        used[i5]=false;
                    }

                    used[i4]=false;
                }

                used[i3]=false;
            }

            used[i2]=false;
        }

        used[i1]=false;
    }

    if(ans.size()==1){
        cout<<ans[0]<<"\n";
    }
    else{
        sort(ans.begin(),ans.end(),cmp);
        cout<<ans[0]<<"\n";
    }
    return 0;
}
