#include<stdio.h>
#include<stdlib.h> //內含qsort()(排序函式)
#include<string.h> //內含memset()(填充函式)
 
// qsort()必備的比較函式(模板，有興趣可以去查)
int cmp(const void *a,const void *b){
    return *(int*)a - *(int*)b;
}
 
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){  //讀到檔案結尾
        if(n==0) break;  //結束條件
        int digits[10005];  //用來裝數字(因為rcnt會右移，所以開2n+5的大小，開n會RE(Segmentation fault))
        memset(digits,-1,sizeof(digits)); //填充(-1表示沒用到的空間)
 
        //讀入數字
        for(int i=0;i<n;i++){
            scanf("%d",&digits[i]);  
        }
 
        //排序
        //qsort(要排序的陣列,排多少個,每個元素大小,比較函式)
        qsort(digits,n,sizeof(int),cmp);
 
        //設定ans初始為0(記得開long long(題目有提到))
        long long ans=0;
 
        //維護[lcnt,rcnt)為有內容的區間(值不是-1的地帶)
        int lcnt=0, rcnt=n;
 
        //(rcnt-lcnt)即為len(digits), 等於1時終止(剩1個)
        while((rcnt - lcnt) > 1){
 
            //取出數字並將lcnt往後push一格(等同於pop()的功能)
            int a=digits[lcnt];
            digits[lcnt++]=-1;  //等同於(digit[lcnt]=-1; lcnt++;)，此處為一行寫法(偷懶)
            int b=digits[lcnt];
            digits[lcnt++]=-1;
             
            //更新答案
            ans+=(a+b);
             
            //二分搜尋要插入的點(在lcnt~rcnt間搜尋)
            int L=lcnt-1,R=rcnt;
            while(R-L > 1){
                int m=(L+R)>>1;
                if(digits[m] > (a+b)) R=m;
                else L=m;
            }
             
            //把所有大於等於插入點的都向後推一格(從尾巴(rcnt)做回來)
            for(int i=rcnt;i>R;i--) digits[i]=digits[i-1];
            //最後把a+b放進插入點
            digits[R]=(a+b);
 
            //記得要讓rcnt++(每個東西往後推一格)
            rcnt++;
        }
        printf("%lld\n",ans);  //輸出答案(long long 記得要用 %lld)
    }
    return 0;
}
