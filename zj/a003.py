M,D=map(int,input().split()) # 讀入M,D並分別轉成int
S=((M*2)+D)%3  # 計算S
if S==0: print('普通') # S為0
elif S==1: print('吉') # S為1
else: print('大吉') # S為2
