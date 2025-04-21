#include <stdio.h>

// Função para calcular o fatorial
long long int fatorial(int n) 
{
    long long int resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int main() 
{
    int M, N;
    
    while (scanf("%d %d", &M, &N) != EOF) {
       long long int soma = fatorial(M) + fatorial(N);
        printf("%lld\n", soma);
    }

    return 0;
}
