#include <stdio.h>
int main()
{
    int M,D;
    scanf("%d%d",&M,&D);  //讀入M,D
    int S=(M*2+D)%3;   //計算S
    switch(S){    //使用switch...case...break實作
        case 0:{  //S為0
            printf("普通\n");
        }
        break;
        case 1:{  //S為1
            printf("吉\n");
        }
        break;
        case 2:{  //S為2
            printf("大吉\n");
        }
        break;
    }
    return 0;
}
