#include<stdio.h>
int main(){
    int q[6];  //宣告整數陣列q
    int ans,n;
    scanf("%d",&n);  //讀入n
    while(n--){  //做n次
        for(int i=0;i<4;i++) scanf("%d",&q[i]);
 
        //假如是等差
        if((q[1]-q[0]) == (q[2]-q[1]) && (q[2]-q[1]) == (q[3]-q[2])) ans=q[3]+(q[3]-q[2]);
 
        //否則是等比
        else ans=q[3]*(q[3]/q[2]);
 
        //輸出第5項(ans)
        printf("%d %d %d %d %d\n",q[0],q[1],q[2],q[3],ans);
    }
    return 0;
}
