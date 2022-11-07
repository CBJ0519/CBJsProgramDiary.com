def make_net(W1,X1,W2,X2,b): return W1*X1+W2*X2+b 
def f(net):
    if net>=0: return 1 
    return -1
def squ_loss_f(Yd,Y): return 0.5*(Yd-Y)*(Yd-Y)

Cases=[]
_input=list(map(float,input().split()))  #整行一次讀入,用空白分隔,並全部轉成float

#取出前6個存入W1,W2,b,alpha,p,k
W1=_input.pop(0); W2=_input.pop(0); b=_input.pop(0)
alpha=_input.pop(0); p=int(_input.pop(0)); k=int(_input.pop(0))

#k次輸入
for i in range(k):
    X1=int(_input.pop(0)); X2=int(_input.pop(0)); Yd=int(_input.pop(0))
    Cases.append([X1,X2,Yd])

#p次更新(回合)
for i in range(p):
    for case in Cases:
        X1,X2,Yd=case 
        
        #依題意計算
        net=make_net(W1,X1,W2,X2,b)
        Y=f(net)
        ep=squ_loss_f(Yd,Y)
        
        #更新
        W1+=alpha*ep*X1
        W2+=alpha*ep*X2

print(f'{W1:.2f} {W2:.2f}')  #以小數點後2位的方式輸出
