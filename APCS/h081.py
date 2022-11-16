sell=profit=0  #sell=上次賣出價, profit=總利潤(答案)
n,d=map(int,input().split())  #讀入資料
price=[int(x) for x in input().split()]  #讀入股價

have=price[0]  #第一個一定要買
now=1  #現在有股票

#從index 1的地方開始到最後
for i in price[1:]:
    #假如有股票
    if now:
        #若符合題目要求的賣出條件
        if i>=(have+d):
            profit+=(i-have) #更新利潤(現在股價-上次買入價)
            sell=i  #更改上次的賣出價
            now=0  #現在沒有股票(已售出)
    #若沒有股票且符合題目要求的買入條件
    elif i<=(sell-d):
        have=i  #更新上次的買入價
        now=1  #現在持有股票(已買入)

print(profit)  #輸出總利潤
