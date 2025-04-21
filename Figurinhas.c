#include <stdio.h>

// Função que calcula o MDC usando o algoritmo de Euclides
int mdc(int a, int b) {
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

int main() {
    int n;
    scanf("%d", &n);  // Número de casos de teste

    for (int i = 0; i < n; i++) {
        int f1, f2;
        scanf("%d %d", &f1, &f2);
        printf("%d\n", mdc(f1, f2));  // Imprime o tamanho máximo da pilha
    }

    return 0;
}
