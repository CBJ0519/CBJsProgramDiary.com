n=int(input()) #讀入n
for i in range(n): #做n次
    a,b,c,d=map(int,input().split()) #讀入1~4項
 
    #假如是等差
    if (b-a) == (c-b) == (d-c): print(a,b,c,d,d+(d-c))
     
    #否則是等比
    else: print(a,b,c,d,d*(d//c))
