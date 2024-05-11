s = input()
x = [s.count(chr(x + ord('a'))) for x in range(0, 27)]
mx = max(x)
for i in range(27):
    if (x[i] == mx):
        print(chr(i + ord('a')))
        break
