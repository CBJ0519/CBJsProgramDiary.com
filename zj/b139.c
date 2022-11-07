#include<stdio.h>
#include<string.h>  //內含memset()(填充函式)
int main(){
    int L,M,a[10005];
    scanf("%d%d",&L,&M);
    memset(a,-1,sizeof(a));  //填充a(memset只能填0或-1)
    while(M--){
        int start,end;
        scanf("%d%d",&start,&end);
        //[start,end]區間的樹全部拔除(填0)
        for(int i=start;i<=end;i++) a[i]=0;
    }
    int sum=0;
    //計算總和
    for(int i=0;i<=L;i++) sum+=(-a[i]); //將-1轉1(memset只能填0或-1)
    printf("%d\n",sum);
    return 0;
}
