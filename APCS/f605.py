n,d=map(int,input().split())  #讀入商品數n, 題目敘述中的「差異」d

#計算平均
def average(price):
    return sum(price)//3  #總和 / 陣列長度(保證為3)
  
#初始化總和 & 購買數
Sum=count=0

#跑n次
for i in range(n):
    price=[int(x) for x in input().split()]  #讀入陣列
    
    #假如最大值和最小值的差異 >= d, 則更新總和 & 購買數
    if max(price)-min(price)>=d:
        count+=1
        Sum+=average(price)
        
#輸出購買數 & 總和
print(count,Sum)
