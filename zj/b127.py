from sys import stdin
 
## 預先實作費氏數列
f=[0]*50
f[1]=1
for i in range(2,50): f[i]=f[i-1]+f[i-2]
 
## 主程式
for read in stdin: ## 讀到檔案結尾
    n=int(read)   ## 轉成整數存入n
    print(f[n+1])  ## 輸出f[n+1]的值
