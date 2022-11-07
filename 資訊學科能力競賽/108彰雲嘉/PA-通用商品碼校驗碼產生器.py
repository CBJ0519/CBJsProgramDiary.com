n=int(input())
for i in range(n):
    s=input()
    if len(s)!=11:
        print(-1)
        exit(0)
    total=0
    for j in range(len(s)):
        if not s[j].isdigit():
            print(-1)
            exit(0)
        if j%2: total+=int(s[j])
        else: total+=int(s[j])*3
    print(10-(total%10))