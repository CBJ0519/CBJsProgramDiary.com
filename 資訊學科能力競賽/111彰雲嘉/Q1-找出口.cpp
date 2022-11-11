#include<iostream>
using namespace std;

int main(){
    int x; cin>>x;  //讀入出口位置
    
    //預先判斷x是否為負
    bool isneg=false;
    if(x<0) isneg=true;
    
    int now=0;   //現在位置
    int base=1;  //要走base*base步(base每次++)
    int dir=1;   //往左或往右(往左就要乘上-1)
    int times=0; //花費次數
    
    while(1){   //跑無窮迴圈
        
        //假如找到出口(x為負 && 當前位置 < x) || (x為正 && 當前位置 > x)
        if((isneg && now<=x) || (!isneg && now>=x)){   
            break;
        }
        
        now += base*base*dir;  //更新now並乘上方向
        base++;  //1 -> 2 -> 3 ...
        dir*=-1;  //方向改變(1 -> -1, -1 -> 1)
        times++;  //次數++
    }
    
    cout<<times<<"\n";  //輸出次數
    return 0;
}
