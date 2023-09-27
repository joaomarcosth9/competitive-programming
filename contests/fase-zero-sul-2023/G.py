n = int(input())
numbers = []
for i in range(n):
    linha = input()
    linha = linha.replace('  ', ' # ')
    linha = linha.replace(' ,', ' # ')
    linha = linha.replace(' .', ' # ')
    linha = linha.replace(', ', ' # ')
    linha = linha.replace(',,', ' # ')
    linha = linha.replace(',.', ' # ')
    linha = linha.replace('. ', ' # ')
    linha = linha.replace('.,', ' # ')
    linha = linha.replace('..', ' # ')
    linha = linha.replace(',', ' ')
    linha = linha.replace('.', ' ')
    linha = linha.split(' ')

    # print(linha)
    newlinha = []
    tam = len(linha)
    i = 0
    while(True):
        if(i >= tam):
            break
        x = 0
        nova = ""
        while(i + x < tam and linha[i + x].isnumeric()):
            nova += linha[i + x]
            x += 1
        i += x + 1
        if nova == "":
            continue
        newlinha.append(nova)

    # print(linha)
    # print(newlinha)
    for i in newlinha:
        if(i.isnumeric()):
            numbers.append(int(i))


a = dict()
for i in numbers:
    a[i] = 0
    a[i - 1] = 0
    a[i - 2] = 0

time = 1

for i in numbers:
    a[i] = t
    time += 1
    if(a[i] > 0 and a[i - 1] > 0 and a[i - 2] > 0):
        print("123")
        exit(0)

print(":)")
