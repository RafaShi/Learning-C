#include <stdio.h>
#include <math.h>

int main() {
    int D, VF, VG;

    while (scanf("%d %d %d", &D, &VF, &VG) != EOF) {
        double tempoFugitivo = 12.0 / VF;
        double distanciaGuarda = sqrt(D * D + 144.0); // 12^2 = 144
        double tempoGuarda = distanciaGuarda / VG;

        if (tempoGuarda <= tempoFugitivo)
            printf("S\n");
        else
            printf("N\n");
    }

    return 0;
}
