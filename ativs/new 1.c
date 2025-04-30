#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, x2, y2, distancia;

    // Leitura dos valores de x1 e y1
    scanf("%lf %lf", &x1, &y1);
    // Leitura dos valores de x2 e y2
    scanf("%lf %lf", &x2, &y2);

    // Cálculo da distância usando a fórmula da distância euclidiana
    distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // Impressão do resultado com 4 casas decimais
    printf("%.4lf\n", distancia);

    return 0;
}
