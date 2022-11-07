from sys import stdin
from bisect import insort  #insort()用來插入數字，且保持排序(實作上為二分搜找到插入點+insert())
 
for read in stdin:  #反覆讀資料
    n=int(read)   #轉整數給n
    if n==0: break   #終止條件
 
    digit=[int(x) for x in input().split()]
    digit.sort()  #由小到大排序
 
    ans=0   #初始ans(沒有long long的問題)
    while len(digit)>1:  #當digits的長度為1時終止迴圈
        a=digit.pop(0)  #pop()並取值(Python的pop()會回傳pop()掉的值)
        b=digit.pop(0)
 
        ans+=(a+b)  #更新答案
        insort(digit,a+b)  #insort a+b
 
    print(ans)  #輸出答案
