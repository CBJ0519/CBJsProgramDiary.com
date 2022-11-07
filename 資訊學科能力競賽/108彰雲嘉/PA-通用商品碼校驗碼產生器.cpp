#include<iostream>
#include<string>  //內含string
#include<cctype>  //內含isdigit()(判斷字串是否為數字)
using namespace std;
int main(){
    int n;
 
    cin>>n;  //讀入n
    while(n--){  //做n次
        string s;  
        cin>>s;   //輸入字串
 
        if(s.length()!=11){  //例外處理(長度不為11)
            cout<<-1<<"\n";
            return 0;  //結束程式
        }
 
        int total=0;  //總和
        for(int i=0;i<s.length();i++){  //走訪s
 
            if(!isdigit(s[i])){  //例外處理(不是數字)
                cout<<-1<<"\n";
                return 0;  //結束程式
            }
 
            if(i%2){  //假如 i%2 == 1(true),則為奇數位
                total+=s[i]-'0';  //s[i]轉整數後加入total
            }
            else{  //否則為偶數位
                total+=(s[i]-'0')*3;  //s[i]轉整數後*3加入total
            }
        }
 
        int ans=10-(total%10);  //任何數%10可得該數的個位數,將total%10再被10減即為所求
 
        cout<<ans<<"\n";   //輸出ans(校驗碼)
    }
    return 0;
}
