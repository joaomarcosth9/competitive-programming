#include <stdio.h>
#include <stdlib.h>

void list(){
    int len;
    scanf("%d", &len);

    int *app = malloc(len*sizeof(int));
    for (int i = 0; i < len; i++){
        app[i]=0;
    }

    // funciona na minha maquina, na do enzo tb, na do Replit tb, so n funciona no Codeforces
    // Hipotese: versao do gcc
    int res = -1;
    for (int i=0; i < len; i++){
        int j;
        scanf("%d", &j);
        app[j]++;
        if (app[j] == 3){
             res = j;
        }
    }
    printf("%d\n", res);
}

int main(){
    int testcases;
    scanf("%d", &testcases);
    for (int i = 0; i < testcases; i++){
        list();
    }
    return 0;
}
