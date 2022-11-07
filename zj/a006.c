#include<stdio.h>
#include<math.h>  //內含sqrt()(開根號工具)
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int judge=b*b-(4*a*c); //判斷式
    if(judge<0){  //無實數根
        printf("No real root\n");
        return 0;  //結束程式
    }
 
    //計算兩根(+,-)
    int root1=(-b + sqrt(judge))/(2*a);
    int root2=(-b - sqrt(judge))/(2*a);
 
    //假如重根
    if(root1==root2) printf("Two same roots x=%d\n",root1);
    //否則找出值較大的根放前面
    else if(root1>root2) printf("Two different roots x1=%d , x2=%d\n",root1,root2);
    else printf("Two different roots x1=%d , x2=%d\n",root2,root1);
    return 0;
}
