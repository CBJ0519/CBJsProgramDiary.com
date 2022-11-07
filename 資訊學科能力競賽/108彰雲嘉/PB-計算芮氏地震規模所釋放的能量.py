n=int(input())  #輸入n
TNT=4184000  #定義TNT
for i in range(n):  #做n次
    d=float(input())  #輸入芮氏規模
    E=10**(d*1.5+4.8)  #計算E(能量)
    print(f'{E/TNT:.1f}')  #輸出E/TNT並取到小數點後1位
