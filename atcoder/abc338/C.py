n = int(input())
q = [*map(int, input().split())]
a = [*map(int, input().split())]
b = [*map(int, input().split())]

aa = [0] * n
res = 0

for i in range(int(1e6) + 1):
    L = 0
    R = int(1e6) + 1
    ans = 0
    while L <= R:
        mid = (L + R) // 2
        db = True
        for j in range(n):
            if aa[j] + b[j] * mid > q[j]:
                db = False
        if db:
            ans = mid
            L = mid + 1
        else:
            R = mid - 1
    res = max(res, i + ans)
    can = True
    for j in range(n):
        aa[j] += a[j]
        if aa[j] > q[j]:
            can = False
    if not can:
        break;
print(res)
