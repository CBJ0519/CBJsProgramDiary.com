#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);  //讀入整數n
  
    int tmp[100000][2];  //用來儲存{質因數,次方}
    int index=0,tmp_size=0;  //index紀錄資料當前要放的位置，tmp_size紀錄tmp的大小

    //從2跑到無限大(此處設無限大為1e9)
    for(int i=2;i<1e9;i++){
        if(n==1) break;  //終止條件
      
        int cnt=0;  //while迴圈執行次數=次方數
        while((n%i)==0){  //假如n%i==0，表示可整除
            cnt++;  //次方++
            n/=i;  //更新n
        }
        if(cnt){  //假如cnt不為0(至少有1次方)
            //將{i(必為質因數), cnt(必不為0)}推入tmp
            tmp[index][0]=i;
            tmp[index][1]=cnt;
          
            index++;  //現在的index有東西了，所以index+1
            tmp_size++;  //因為新增了一組資料，所以tmp_size+1
        }
    }
  
    //走訪tmp
    for(int i=0;i<tmp_size;i++){  
        if(i){ //除了第一次輸出以外，其他次都要先在前面加上 *
            printf(" * ");
        }
      
        //取出有用到的質因數和次方數(存於tmp)分別存入n和cnt
        int n=tmp[i][0];
        int cnt=tmp[i][1];
      
        //次方數大於1，需要另外輸出次方數
        if(cnt>1){
            printf("%d^%d",n,cnt);
        }
        //否則次方數為1，不需輸出次方
        else{
            printf("%d",n);
        }
    }
    printf("\n"); //最後的換行符
    return 0;
}
