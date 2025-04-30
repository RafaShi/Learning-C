#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char entrada[110];
        scanf("%s", entrada);

        int N = 0, K = 0;
        // Ler N e contar número de exclamações (K)
        for (int i = 0; entrada[i]; i++) {
            if (entrada[i] == '!') {
                K++;
            } else {
                N = N * 10 + (entrada[i] - '0');
            }
        }

        long long resultado = 1;
        for (int i = N; i >= 1; i -= K) {
            resultado *= i;
        }

        printf("%lld\n", resultado);
    }

    return 0;
}
