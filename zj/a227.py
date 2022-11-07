from sys import stdin
#hanoi(起點, 終點, 另外那一個, 環的數量, 最上層的環編號)
def hanoi(From, To, Another, Amount, Num):
    if Amount==1: #剩一個(終止條件)
        print(f"Move ring {Num} from {From} to {To}")
        return
    #先把上面擋住的都移到另一個去
    hanoi(From, Another, To, Amount-1, 1)
    #把最底下(編號n)的那個移到終點
    hanoi(From, To, Another, 1, Amount)
    #把剛剛丟去另一個的那些移到終點
    hanoi(Another, To, From, Amount-1, 1)
for read in stdin:  #讀到檔案結尾
    n=int(read)  #將讀入內容(字串)轉整數給n
    hanoi('A','C','B',n,1);  #根據定義傳入初始參數
