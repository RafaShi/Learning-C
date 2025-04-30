#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    // Pré-calcular os fatoriais até 10! (pois 10! = 3628800 > 10^5)
    int fat[11];
    fat[0] = 1;
    for (int i = 1; i <= 10; i++) {
        fat[i] = fat[i - 1] * i;
    }

    int count = 0;
    // Começar do maior fatorial e ir diminuindo
    for (int i = 10; i >= 1; i--) {
        while (N >= fat[i]) {
            N -= fat[i];
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}
