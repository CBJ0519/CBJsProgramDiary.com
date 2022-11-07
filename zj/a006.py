from math import sqrt  #引入math套件的sqrt(開根號工具)
a,b,c=map(int,input().split())
judge=b*b-(4*a*c)  #判斷式
if judge<0:  #無實數根
    print("No real root")
    exit(0)  #結束程式
 
##計算兩根(+,-)
root1=int((-b + sqrt(judge))/(2*a))
root2=int((-b - sqrt(judge))/(2*a))
 
##假如重根
if root1==root2: print(f"Two same roots x={root1}")
##否則找出值較大的根放前面
elif root1>root2: print(f"Two different roots x1={root1} , x2={root2}")
else: print(f"Two different roots x1={root2} , x2={root1}")
 
##f"...{var}.."是f-string的用法, 有興趣可以去查
