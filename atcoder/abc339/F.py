n = int(input())
a = []
freq = dict()
for i in range(n):
    ai = int(input())
    if not ai in freq:
        freq[ai] = 0
    freq[ai] += 1
    a.append(ai)

res = 0
for i in range(n):
    for j in range(n):
        ak = a[i] * a[j];
        if ak in freq:
            res += freq[ak]

print(res)
