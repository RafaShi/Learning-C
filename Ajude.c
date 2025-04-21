#include <stdio.h>
#include <string.h>

#define max_prob 26

int main() {
    int N;

    while (scanf("%d", &N), N != 0) {
        int tempo_resolvido[max_prob] = {0};
        int penalidades[max_prob] = {0};
        int resolvido[max_prob] = {0};

        for (int i = 0; i < N; i++) {
            char problema;
            int tempo;
            char resultado[10];

            scanf(" %c %d %s", &problema, &tempo, resultado);
            int idx = problema - 'A';

            if (resolvido[idx])
                continue;

            if (strcmp(resultado, "correct") == 0) {
                tempo_resolvido[idx] = tempo;
                resolvido[idx] = 1;
            } else if (strcmp(resultado, "incorrect") == 0) {
                penalidades[idx] += 20;
            }
        }

        int problemas_certos = 0, tempo_total = 0;

        for (int i = 0; i < max_prob; i++) {
            if (resolvido[i]) {
                problemas_certos++;
                tempo_total += tempo_resolvido[i] + penalidades[i];
            }
        }

        printf("%d %d\n", problemas_certos, tempo_total);
    }

    return 0;
}

