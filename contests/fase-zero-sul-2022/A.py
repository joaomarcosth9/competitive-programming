n = int(input())
for i in range(2*n):
    if i % 2 == 0:
        nome = input().split()
        for i in range(len(nome)):
            if i != len(nome)-1:
                print(nome[i], end = " ")
            else:
                print(nome[i], end = ": ")
    else:
        notas = input().split()
        for i in range(len(notas)):
            notas[i] = round(float(notas[i])*10)
        t = len(notas)
        nf = 0
        if t == 1:
            nf += notas[0]/2
        elif t == 2:
            nf += (notas[0] + notas[1])/2
        elif t == 3:
            nf += (notas[0] + notas[1] + notas[2])/3
        elif t == 4:
            trabfinal = notas[3]
            notas[3] = 10000000
            notas.sort()
            if trabfinal > notas[0]:
                notas[0] = trabfinal
            nf += (notas[0] + notas[1] + notas[2])/3
        print(round(nf/10, 1))
