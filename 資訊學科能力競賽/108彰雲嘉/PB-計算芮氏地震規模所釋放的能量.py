n=int(input())
TNT=4184000
for i in range(n):
    d=float(input())
    E=10**(d*1.5+4.8)
    print(f'{E/TNT:.1f}')
