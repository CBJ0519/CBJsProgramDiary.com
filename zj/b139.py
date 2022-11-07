L,M=map(int,input().split())
a=[1]*(L+1)  #複製(L+1)個[1] ([1,1,1,1, ... ,1])
for i in range(M):
    start,end=map(int,input().split())
    #[start,end]區間的樹全部拔除(填0)
    for j in range(start,end+1): a[j]=0
print(sum(a))  #輸出a的總和
