t = int(input())

for _ in range(t):
    string = input()
    if len(string) > 10:
        print(string[0]+str(len(string)-2)+string[-1])
    else:
        print(string)
