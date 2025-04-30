#include <stdio.h>
#include <math.h>

// Verifica se um número é primo
int eh_primo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return 0;
    return 1;
}

int main() {
    int peso;
    scanf("%d", &peso);

    int count = 0, numero = peso;
    long long soma = 0;

    // Soma os 10 primeiros primos >= peso
    while (count < 10) {
        if (eh_primo(numero)) {
            soma += numero;
            count++;
        }
        numero++;
    }

    // Calcular tempo
    long long distancia = 60000000LL; // 60 milhões de km
    long long tempo_horas = distancia / soma;
    long long tempo_dias = tempo_horas / 24;

    // Saída
    printf("%lld km/h\n", soma);
    printf("Tempo aproximado: %lld horas ou %lld dias\n", tempo_horas, tempo_dias);

    return 0;
}
