/*   0
    8 1
   7   2
  6 5 4 3  */
#include<iostream>
#include<vector>  //內含vector
#include<string>   //內含string
#include<algorithm>  //內含sort()(排序函式)
using namespace std;

vector<string>ans;  //用於存放答案(答案可能不只一個)
vector<bool>used(10,false);  //記錄1~9有無被使用過
vector<int>put(9);   //如最上方的圖形所示,put[0]為圖中0的位置,以此類推

int a,b,c;

//判斷是否為內定的三個數,若不是則return true,否則return false
bool legal(int i){
    return (i!=a && i!=b && i!=c);   
}

//結算函式(當湊滿9個時呼叫)
void sattle(){
    int line1=put[0]+put[1]+put[2]+put[3];
    int line2=put[3]+put[4]+put[5]+put[6];
    int line3=put[6]+put[7]+put[8]+put[0];
 
    //把答案轉成string,方便排序時比較
    string cur_ans="";
    for(int i=0;i<=8;i++){
        cur_ans+=(char)(put[i]+'0'); 
    }

    if(line1==line2 && line2==line3){  //找到答案
        ans.push_back(cur_ans);  //將答案推入ans
    }
    put.erase(put.begin(),put.end());   //清除put中所有元素
}


int main(){
    cin>>a>>b>>c;  //讀入內定資料
    used[0]=used[a]=used[b]=used[c]=true;  //0,a,b,c不可被使用到,故設為已使用

    //枚舉過程(6層迴圈)
    for(int i1=1;i1<=9;i1++){
        if(!legal(i1) || used[i1])continue;   //若和a,b,c重疊 或 已使用過則跳過此次迴圈
        used[i1]=true;   //正在使用i1(迴圈最後一行會把used[i1]重新設回false)(line 90)

        //其他迴圈以此類推
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
                             
                            //湊到9個,分別放入剩餘的位置
                            put[0]=i1; put[1]=a; put[2]=i2; put[3]=i3;
                            put[4]=b; put[5]=i4; put[6]=i5; put[7]=c; put[8]=i6;

                            sattle();  //結算

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
 
    //如果答案只有一個,就不需要排序,直接輸出ans[0](省時間)
    if(ans.size()==1){
        cout<<ans[0]<<"\n";
    }
    else{   //有多個答案,依題目要求,輸出數值(=字典序)最小的
        sort(ans.begin(),ans.end(),cmp); 
        cout<<ans[0]<<"\n";
    }
    return 0;
}
