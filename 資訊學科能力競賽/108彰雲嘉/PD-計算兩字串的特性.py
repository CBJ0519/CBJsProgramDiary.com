a,b=input().split()   #讀入兩字串
Jia=Yi=0  #設甲=乙=0
for i in range(len(a)):  #遍歷a
    if a[i]==b[i]:   #假如同個位置有同個值
        Jia+=1   #更新甲
        continue  #跳過檢查乙特性
    target=b.find(a[i])  #找尋a[i]是否有在b裡
    if target!=-1: Yi+=1 #若回傳值不是-1,則表示有找到,更新乙
print(Jia,Yi)  #輸出甲,乙
