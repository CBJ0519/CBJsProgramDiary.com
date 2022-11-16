#include<stdio.h>
int main(){
    int have,now,profit=0,n,D,i,j,sell=0,price[101];
    scanf("%d%d",&n,&D);
    for(i=0;i<n;i++){
        scanf("%d",&price[i]);
    }
    have = price[0];
    now = 1;
    for(j=1;j<n;j++){
        if(now){
            if(price[j]>=(have+D)){
                profit+=(price[j]-have);
                sell = price[j];
                now = 0;
            }
        }else if(price[j]<=(sell-D)){
            have = price[j];
            now = 1;
        }
    }
    printf("%d\n",profit);
}
