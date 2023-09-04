s=input()  #輸入字串
ans=''   #因為字串無法作改值的動作, 所以另外開一個變數記錄答案
for i in s:   #把s裡的東西一個一個取出來稱做i
    ans+=chr(ord(i)-7)  #用ord()取出i的ascii碼,更改後再轉回char(使用chr()函式)併入ans
print(ans)  #輸出答案
