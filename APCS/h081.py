sell=profit=0
n,d=map(int,input().split())
price=[int(x) for x in input().split()]
have=price[0]
now=1
for i in price[1:]:
    if now:
        if i>=(have+d):
            profit+=(i-have)
            sell=i
            now=0
    elif i<=(sell-d):
        have=i
        now=1
print(profit)
