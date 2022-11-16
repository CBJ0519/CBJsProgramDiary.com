n=int(input())
tmp=[]
for i in range(2,int(1e9)):  #從2跑到無限大(此處設無限大為1e9)
    if n==1: break  #終止條件
      
    cnt=0  # while迴圈執行次數=次方數
    
    while not n%i:  #假如n%i==0，表示可整除 (not 0 = true)
        cnt+=1  #次方+1
        n//=i  #更新n(整數除法用 "//")
        
    #假如cnt不為0(至少有1次方)，則將[i(必為質因數), cnt(必不為0)]推入tmp
    if cnt: tmp.append([i,cnt])

ans=[]  #存放要輸出的陣列(不需要存 *，輸出時會加入)

for i,cnt in tmp:  #依序取出tmp所存放的所有[i,cnt]
    if cnt>1: ans.append(f'{i}^{cnt}')  #次方數大於1，需要另外加上次方數
    else: ans.append(i) #否則次方數為1，不需加上次方
      
print(*ans,sep=' * ')  #輸出並加入 * 在每個ans值的中間
