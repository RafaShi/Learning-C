#include <stdio.h>
#include <string.h>

int fatorial(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}

int main() {
    char acm[10];
    
    while (1) {
        scanf("%s", acm);
        if (strcmp(acm, "0") == 0)
            break;

        int len = strlen(acm);
        int resultado = 0;

        for (int i = 0; i < len; i++) {
            int digito = acm[i] - '0';
            int pos = len - i; // posições começam do 1 para a direita
            resultado += digito * fatorial(pos);
        }

        printf("%d\n", resultado);
    }

    return 0;
}
