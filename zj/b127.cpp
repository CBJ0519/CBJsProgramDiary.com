#include <iostream>
using namespace std;
int main()
{
    // 預先實作費氏數列
    int f[50];
    f[0]=0;
    f[1]=1;
    for(int i=2;i<50;i++) f[i]=f[i-1]+f[i-2];
     
    // 主程式
    int n;
    while(cin>>n){  // 讀到檔案結尾
        cout<<f[n+1]<<"\n";  // 輸出f[n+1]的值
    }
    return 0;
}
