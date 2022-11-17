def f(s):  #題目中的f()
    if(len(s)==1): return s  #題目所述的終止條件
    return f(Sum(s))  #遞迴呼叫f(sum(s)) (依題目所述)
  
def Sum(S):  #計算陣列總和，並回傳總和轉成字串的結果
    ans=0  #總和
    for i in S:  #遍歷s
        ans+=int(i)  #累加總和
    return str(ans)  #回傳字串型態的總和
  
while True:
    n=input()
    if n=='0': break  #假如輸入字串為"0"，則結束程式(跳出迴圈)
    print(f(n))  #否則輸出f(n)
